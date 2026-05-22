#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a + (-b);
}

double multiply(double a, double b) {
    double result = 0;
    int sign = 1;
    if (b < 0) {
        sign = -1;
        b = -b;
    }
    for (int i = 0; i < b; ++i) {
        result = result + a;
    }
    return result * sign;
}

double power(double base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) {
        std::cerr << "Error: exp < 0" << std::endl;
	exit(1);
    }
    double result = 1;
    for (int i = 0; i < exp; ++i) {
        result = multiply(result, base);
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <operand1> <operand2> <operator(+,-,^)>" << endl;
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    string op = argv[3];
    double result = 0;

    if (op == "+") {
        result = add(a, b);
    } else if (op == "-") {
        result = subtract(a, b);
    } else if (op == "^") {
        int exp = static_cast<int>(b);
        if (fabs(b - exp) > 1e-9) {
            cerr << "Error: exp no int" << endl;
            return 1;
        }
        result = power(a, exp);
    } else {
        cerr << "Error" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
