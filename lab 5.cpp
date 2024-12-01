#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        throw "Incorrect input. Please enter valid data.";
    }
}

void checkValidParams(int n) {
    if (n <= 4) {
        throw "Invalid parameter. 'n' must be > 4.";
    }
}

double calculateY(double n, double x) {
    double SigmaOut = 0.0;
    double SigmaIn = 0.0;
    double product = 1.0;
    double y = 0.0;

    if (x <= 0) {
        for (int i = 0; i <= (n - 1); i++) {
            product *= (i * i - x);
        }
        y = x + product;
    }
    else {
        for (int i = 1; i <= (n - 1); i++) {
            SigmaIn = 0;
            for (int j = 0; j <= (n - 1); j++) {
                SigmaIn += (x / (i + j));
            }
            SigmaOut += SigmaIn;
        }
        y = SigmaOut;
    }
    return y;
}

int main() {
    int n;
    double x;

    cout << fixed << showpoint;
    cout << setprecision(10);

    try {
        cout << "Input an integer n (n > 4): ";
        cin >> n;
        checkValidInput();
        checkValidParams(n);

        cout << "Input a number x: ";
        cin >> x;
        checkValidInput();

        double y = calculateY(n, x);
        cout << "Result: x = " << x << "; y = " << y << endl;
    }
    catch (const char* ex) {
        cerr << "Error: " << ex << endl;
        return -1;
    }
    catch (...) {
        cerr << "An unexpected error occurred." << endl;
        return -2;
    }

    return 0;
}
