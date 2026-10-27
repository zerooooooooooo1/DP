#include <iostream>
#include <climits>
#include <stdexcept>
using namespace std;

int safeAdd(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b))
        throw overflow_error("Integer overflow detected in addition");

    return a + b;
}

int safeMultiply(int a, int b) {
    if (a != 0 && b != 0) {
        if ((a > 0 && b > 0 && a > INT_MAX / b) ||
            (a < 0 && b < 0 && a < INT_MAX / b) ||
            (a > 0 && b < 0 && b < INT_MIN / a) ||
            (a < 0 && b > 0 && a < INT_MIN / b))
            throw overflow_error("Integer overflow detected in multiply");
    }

    return a * b;
}

int main() {
    try {
        cout << "10 + 20 = " << safeAdd(10, 20) << endl;
        cout << "5 * 6 = " << safeMultiply(5, 6) << endl;

        safeAdd(INT_MAX, 1);
    } catch (const overflow_error& e) {
        cout << "Caught: " << e.what() << endl;
    }

    try {
        safeMultiply(INT_MAX, 2);
    } catch (const overflow_error& e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
