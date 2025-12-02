#include "Vector.h"
#include <iostream>

using namespace std;

void createVector(Vector &v, const string &name) {
    size_t n;
    cout << "Enter size for vector " << name << ": ";
    cin >> n;

    v = Vector(n);
    cout << "Enter " << n << " values for " << name << ":" << endl;
    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    bool run = true;

    Vector v;  // main vector
    Vector w;  // second vector

    while (run) {
        int option = 0;
        cout << "\n=== Vector Menu ===" << endl;
        cout << "1. Create / Edit vector v" << endl;
        cout << "2. Create / Edit vector w" << endl;
        cout << "3. Print v and w" << endl;
        cout << "4. v + w" << endl;
        cout << "5. v - w" << endl;
        cout << "6. Scalar multiply (a * v and v * a)" << endl;
        cout << "7. Scalar division (v / a)" << endl;
        cout << "8. Unary negation (-v)" << endl;
        cout << "9. Compare v and w (== and !=)" << endl;
        cout << "10. Increment v (++v and v++)" << endl;
        cout << "11. Decrement v (--v and v--)" << endl;
        cout << "12. Exit" << endl;
        cout << "Choose option: ";

        cin >> option;

        if (option == 1) {
            createVector(v, "v");
        }
        else if (option == 2) {
            createVector(w, "w");
        }
        else if (option == 3) {
            cout << "v = " << v << endl;
            cout << "w = " << w << endl;
        }
        else if (option == 4) {
            try {
                Vector result = v + w;
                cout << "v + w = " << result << endl;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 5) {
            try {
                Vector result = v - w;
                cout << "v - w = " << result << endl;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 6) {
            double a;
            cout << "Enter scalar a: ";
            cin >> a;

            cout << "a * v = " << (a * v) << endl;
            cout << "v * a = " << (v * a) << endl;
        }
        else if (option == 7) {
            double a;
            cout << "Enter scalar a (non-zero): ";
            cin >> a;

            try {
                Vector result = v / a;
                cout << "v / a = " << result << endl;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 8) {
            Vector neg = -v;
            cout << "-v = " << neg << endl;
        }
        else if (option == 9) {
            cout << "v = " << v << endl;
            cout << "w = " << w << endl;

            if (v == w) {
                cout << "v == w is true" << endl;
            } else {
                cout << "v == w is false" << endl;
            }

            if (v != w) {
                cout << "v != w is true" << endl;
            } else {
                cout << "v != w is false" << endl;
            }
        }
        else if (option == 10) {
            cout << "Initial v = " << v << endl;

            cout << "After prefix ++v: ";
            Vector pre = ++v;
            cout << "v = " << v << ", returned = " << pre << endl;

            cout << "After postfix v++: ";
            Vector post = v++;
            cout << "v = " << v << ", returned = " << post << endl;
        }
        else if (option == 11) {
            cout << "Initial v = " << v << endl;

            cout << "After prefix --v: ";
            Vector pre = --v;
            cout << "v = " << v << ", returned = " << pre << endl;

            cout << "After postfix v--: ";
            Vector post = v--;
            cout << "v = " << v << ", returned = " << post << endl;
        }
        else if (option == 12) {
            run = false;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
