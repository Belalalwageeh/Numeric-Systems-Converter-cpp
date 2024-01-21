#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// تحويل عدد من النظام العشري إلى نظام ثنائي
string decimalToBinary(double num) {
    int intPart = int(num);
    double fracPart = num - intPart;

    string intBinary = "";
    while (intPart > 0) {
        intBinary = to_string(intPart % 2) + intBinary;
        intPart /= 2;
    }

    string fracBinary = "";
    const int maxFracDigits = 12; // تحديد عدد أقصى للأرقام البعد العشري
    while (fracPart > 0 && fracBinary.length() < maxFracDigits) {
        fracPart *= 2;
        fracBinary += to_string(int(fracPart));
        fracPart -= int(fracPart);
    }

    if (fracBinary.empty()) {
        return intBinary;
    } else {
        return intBinary + "." + fracBinary;
    }
}

// تحويل عدد من النظام الثنائي إلى نظام عشري
double binaryToDecimal(const string& binary) {
    size_t pointPos = binary.find('.');
    double intPart = 0;
    double fracPart = 0;

    if (pointPos != string::npos) {
        string intStr = binary.substr(0, pointPos);
        string fracStr = binary.substr(pointPos + 1);

        for (size_t i = 0; i < intStr.length(); i++) {
            intPart += (intStr[i] - '0') * pow(2, intStr.length() - i - 1);
        }

        for (size_t i = 0; i < fracStr.length(); i++) {
            fracPart += (fracStr[i] - '0') / pow(2, i + 1);
        }
    } else {
        for (size_t i = 0; i < binary.length(); i++) {
            intPart += (binary[i] - '0') * pow(2, binary.length() - i - 1);
        }
    }

    return intPart + fracPart;
}

// تحويل عدد من النظام العشري إلى نظام ثماني
string decimalToOctal(double num) {
    int intPart = int(num);
    double fracPart = num - intPart;

    string octalIntPart = "";
    while (intPart > 0) {
        octalIntPart = to_string(intPart % 8) + octalIntPart;
        intPart /= 8;
    }

    string octalFracPart = "";
    const int maxFracDigits = 12; // تحديد عدد أقصى للأرقام البعد العشري
    while (fracPart > 0 && octalFracPart.length() < maxFracDigits) {
        fracPart *= 8;
        octalFracPart += to_string(int(fracPart));
        fracPart -= int(fracPart);
    }

    if (octalFracPart.empty()) {
        return octalIntPart;
    } else {
        return octalIntPart + "." + octalFracPart;
    }
}

// تحويل عدد من النظام الثنائي إلى نظام ثماني
string binaryToOctal(const string& binary) {
    double decimal = binaryToDecimal(binary);
    return decimalToOctal(decimal);
}

// تحويل عدد من النظام العشري إلى نظام سداسي عشري
string decimalToHexadecimal(double num) {
    int intPart = int(num);
    double fracPart = num - intPart;

    string hexIntPart = "";
    while (intPart > 0) {
        int remainder = intPart % 16;
        if (remainder < 10) {
            hexIntPart = char('0' + remainder) + hexIntPart;
        } else {
            hexIntPart = char('A' + remainder - 10) + hexIntPart;
        }
        intPart /= 16;
    }

    string hexFracPart = "";
    const int maxFracDigits = 12; // تحديد عدد أقصى للأرقام البعد العشري
    while (fracPart > 0 && hexFracPart.length() < maxFracDigits) {
        fracPart *= 16;
        int hexDigit = int(fracPart);
        if (hexDigit < 10) {
            hexFracPart += char('0' + hexDigit);
        } else {
            hexFracPart += char('A' + hexDigit - 10);
        }
        fracPart -= hexDigit;
    }

    if (hexIntPart.empty()) {
        hexIntPart = "0";
    }

    if (hexFracPart.empty()) {
        return hexIntPart;
    } else {
        return hexIntPart + "." + hexFracPart;
    }
}

// تحويل نص إلى عدد سداسي عشري
double hexStringToDecimal(const string& hex) {
    double result = 0;
    for (size_t i = 0; i < hex.length(); i++) {
        char digit = hex[i];
        if (isdigit(digit)) {
            result = result * 16 + (digit - '0');
        } else {
            digit = toupper(digit);
            result = result * 16 + (digit - 'A' + 10);
        }
    }
    return result;
}

// تحويل عدد من النظام الثنائي إلى نظام سداسي عشري
string binaryToHexadecimal(const string& binary) {
    double decimal = binaryToDecimal(binary);
    int intPart = int(decimal);
    double fracPart = decimal - intPart;

    string hexIntPart = "";
    while (intPart > 0) {
        int remainder = intPart % 16;
        if (remainder < 10) {
            hexIntPart = char('0' + remainder) + hexIntPart;
        } else {
            hexIntPart = char('A' + remainder - 10) + hexIntPart;
        }
        intPart /= 16;
    }

    string hexFracPart = "";
    const int maxFracDigits = 12; // تحديد عدد أقصى للأرقام البعد العشري
    while (fracPart > 0 && hexFracPart.length() < maxFracDigits) {
        fracPart *= 16;
        int hexDigit = int(fracPart);
        if (hexDigit < 10) {
            hexFracPart += char('0' + hexDigit);
        } else {
            hexFracPart += char('A' + hexDigit - 10);
        }
        fracPart -= hexDigit;
    }

    if (hexIntPart.empty()) {
        hexIntPart = "0";
    }

    if (hexFracPart.empty()) {
        return hexIntPart;
    } else {
        return hexIntPart + "." + hexFracPart;
    }
}

int main() {
    int base;
    string inputNumber;

    cout << "أدخل النظام (2 للنظام الثنائي، 8 للنظام الثماني، 10 للنظام العشري، 16 للنظام السداسي عشري): "<<endl;
    cin >> base;

    if (base != 2 && base != 8 && base != 10 && base != 16) {
        cout << "نظام غير صالح. الرجاء إدخال 2، 8، 10، أو 16." << endl;
        return 1;
    }

    cout << "أدخل العدد في النظام المحدد: "<<endl;
    cin >> inputNumber;

    double num = 0;

    if (base == 10) {
        num = stod(inputNumber);
    } else if (base == 2) {
        num = binaryToDecimal(inputNumber);
    } else if (base == 8) {
        // تحويل النص إلى عدد عشري ثم إلى النظام الثماني
        num = stod(inputNumber);
    } else if (base == 16) {
        // تحويل النص إلى عدد عشري ثم إلى النظام السداسي عشري
        num = hexStringToDecimal(inputNumber);
    }

    cout << endl; // سطر فارغ

    cout << "النظام الثنائي: "<<endl << decimalToBinary(num) << endl;
    cout << "النظام الثماني: "<<endl << decimalToOctal(num) << endl;
    cout << "النظام العشري: " <<endl<< num << endl;
    cout << "النظام السداسي عشري: "<<endl << decimalToHexadecimal(num) << endl;

    return 0;
}
