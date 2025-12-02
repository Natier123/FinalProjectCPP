#include "Vector.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

// Helper to create/edit a vector
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

// Helper to create/edit a matrix
void createMatrix(Matrix &M, const string &name) {
    size_t r, c;
    cout << "Enter number of rows for matrix " << name << ": ";
    cin >> r;
    cout << "Enter number of columns for matrix " << name << ": ";
    cin >> c;

    M = Matrix(r, c);
    cout << "Enter " << r * c << " values for " << name << " (row by row):" << endl;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            cin >> M[i][j];
        }
    }
}

int main() {
    bool run = true;

    // Vectors
    Vector v;  // main vector
    Vector w;  // second vector

    // Matrices
    Matrix M;  // main matrix
    Matrix N;  // second matrix

    while (run) {
        int option = 0;
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "---- Vector Operations ----" << endl;
        cout << " 1.  Create / Edit vector v" << endl;
        cout << " 2.  Create / Edit vector w" << endl;
        cout << " 3.  Print v and w" << endl;
        cout << " 4.  v + w" << endl;
        cout << " 5.  v - w" << endl;
        cout << " 6.  Scalar multiply (a * v and v * a)" << endl;
        cout << " 7.  Scalar division (v / a)" << endl;
        cout << " 8.  Unary negation (-v)" << endl;
        cout << " 9.  Compare v and w (== and !=)" << endl;
        cout << "10.  Increment v (++v and v++)" << endl;
        cout << "11.  Decrement v (--v and v--)" << endl;
        cout << "12.  norm(v) and inner product(v, w)" << endl;

        cout << "\n---- Matrix Operations ----" << endl;
        cout << "13.  Create / Edit matrix M" << endl;
        cout << "14.  Create / Edit matrix N" << endl;
        cout << "15.  Print M and N" << endl;
        cout << "16.  M + N" << endl;
        cout << "17.  M - N" << endl;
        cout << "18.  M * N" << endl;
        cout << "19.  M * v (matrix vector multiplication)" << endl;
        cout << "20.  Matrix scalar division (M / a)" << endl;
        cout << "21.  Unary negation (-M)" << endl;
        cout << "22.  Compare M and N (== and !=)" << endl;
        cout << "23.  Increment M (++M and M++)" << endl;
        cout << "24.  Decrement M (--M and M--)" << endl;
        cout << "25.  norm(M) and transpose(M)" << endl;

        cout << "\n26.  Exit" << endl;
        cout << "Choose option: ";

        cin >> option;

        // ===== VECTOR PART =====
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

            cout << "After prefix ++v:" << endl;
            Vector pre = ++v;
            cout << "v = " << v << ", returned = " << pre << endl;

            cout << "After postfix v++:" << endl;
            Vector post = v++;
            cout << "v = " << v << ", returned = " << post << endl;
        }
        else if (option == 11) {
            cout << "Initial v = " << v << endl;

            cout << "After prefix --v:" << endl;
            Vector pre = --v;
            cout << "v = " << v << ", returned = " << pre << endl;

            cout << "After postfix v--:" << endl;
            Vector post = v--;
            cout << "v = " << v << ", returned = " << post << endl;
        }
        else if (option == 12) {
            cout << "v = " << v << endl;
            cout << "w = " << w << endl;
            cout << "norm(v) = " << v.norm() << endl;
            try {
                cout << "inner product (v, w) = " << v.innerProduct(w) << endl;
            } catch (const exception &e) {
                cout << "Error computing inner product: " << e.what() << endl;
            }
        }

        // ===== MATRIX PART =====
        else if (option == 13) {
            createMatrix(M, "M");
        }
        else if (option == 14) {
            createMatrix(N, "N");
        }
        else if (option == 15) {
            cout << "M = " << endl << M;
            cout << "N = " << endl << N;
        }
        else if (option == 16) {
            try {
                Matrix result = M + N;
                cout << "M + N =" << endl << result;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 17) {
            try {
                Matrix result = M - N;
                cout << "M - N =" << endl << result;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 18) {
            try {
                Matrix result = M * N;
                cout << "M * N =" << endl << result;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 19) {
            try {
                Vector result = M * v;
                cout << "M * v = " << result << endl;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 20) {
            double a;
            cout << "Enter scalar a (non-zero): ";
            cin >> a;

            try {
                Matrix result = M / a;
                cout << "M / a =" << endl << result;
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (option == 21) {
            Matrix neg = -M;
            cout << "-M =" << endl << neg;
        }
        else if (option == 22) {
            cout << "M =" << endl << M;
            cout << "N =" << endl << N;

            if (M == N) {
                cout << "M == N is true" << endl;
            } else {
                cout << "M == N is false" << endl;
            }

            if (M != N) {
                cout << "M != N is true" << endl;
            } else {
                cout << "M != N is false" << endl;
            }
        }
        else if (option == 23) {
            cout << "Initial M =" << endl << M;

            cout << "After prefix ++M:" << endl;
            Matrix pre = ++M;
            cout << "M =" << endl << M;
            cout << "returned =" << endl << pre;

            cout << "After postfix M++:" << endl;
            Matrix post = M++;
            cout << "M =" << endl << M;
            cout << "returned =" << endl << post;
        }
        else if (option == 24) {
            cout << "Initial M =" << endl << M;

            cout << "After prefix --M:" << endl;
            Matrix pre = --M;
            cout << "M =" << endl << M;
            cout << "returned =" << endl << pre;

            cout << "After postfix M--:" << endl;
            Matrix post = M--;
            cout << "M =" << endl << M;
            cout << "returned =" << endl << post;
        }
        else if (option == 25) {
            cout << "M =" << endl << M;
            cout << "norm(M) = " << M.norm() << endl;
            cout << "transpose(M) =" << endl << M.transpose();
        }

        // ===== EXIT =====
        else if (option == 26) {
            run = false;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
