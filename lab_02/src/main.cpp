#include <iostream>
#include <chrono>
#include <limits>
#include <cmath>

using namespace std;
using namespace chrono;

double compute(double x){
    return x*x - x*x + x*4 - x*5 + x + x;
}

int main() {
    bool again = true;
    while (again) {
        cout << "N= ";
        double userInput;
        cin >> userInput;

        int n = userInput;
        auto start = high_resolution_clock::now();

        double result = 0.0;
        for (int i = 0; i < n; ++i) {
            result = compute(static_cast<double>(i));
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "Result: " << result << endl;
        cout << "N= " << n << " Time all " << duration.count() << " mcs" << endl;

        cout << "Run again? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            again = false;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
