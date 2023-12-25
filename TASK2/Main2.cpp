#include "Vector.cpp"
using namespace std;

int main() {
    // Test the Vector class
    array<double, 3> values1 = {-1.0, -2.0, -3.0};
    Vector v1(values1);
    // Vector v1;
    // cin >> v1;
    array<double, 3> values2 = {1.0, 2.0, 3.0};
    Vector v2(values2);
    
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector sum = v1 + v2;
    cout << "Sum of two vectors : " << sum << endl;

    Vector difference = v1 - v2;
    cout << "Difference of two vectors : " << difference << endl;

    double dotProduct = v1 * v2;
    cout << "Dot(Scalar) Product: " << dotProduct << endl;

    Vector Productwithnumber = v1 * 2.5;
    cout << "Product one vector with a number: " << Productwithnumber << endl;

    cout << "Module of vector v1: " << v1.moduleVector() << endl;
    
    cout << "Module of vector v2: " << v2.moduleVector() << endl;
    bool x, y;
    x = (v1 == v2);
    y = (v1 != v2);

    cout << "Compare two vectors are the same: " << x << endl;

    cout << "Compare two vectors are different: " << y << endl;
    return 0;
}