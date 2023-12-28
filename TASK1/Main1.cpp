#include "Fraction.cpp"

int main(){
    Fraction frac1;
    Fraction frac2;
    cout << "The first fractional number input: " << endl;
    cin >> frac1;
    cout << "The second fractional number input: " << endl;
    cin >> frac2;
    /* Arithmetic operator: */
    Fraction frac3;
    frac3 = frac1 + frac2;
    cout << frac1 << " + " << frac2 << " = " << frac3 << endl;
    frac3 = frac1 - frac2;
    cout << frac1 << " - " << frac2 << " = " << frac3 << endl;
    frac3 = frac1 * frac2;
    cout << frac1 << " * " << frac2 << " = " << frac3 << endl;
    frac3 = frac1 / frac2;
    cout << frac1 << " / " << frac2 << " = " << frac3 << endl;
    /* Arithmetic compare operator */
    cout << "------------- " << endl;
    cout << frac1 << " == " << frac2 << " : " << (frac1 == frac2) << endl;
    cout << frac1 << " != " << frac2 << " : " << (frac1 != frac2) << endl;
    cout << frac1 << " < " << frac2 << " : " << (frac1 < frac2) << endl;
    cout << frac1 << " > " << frac2 << " : " << (frac1 > frac2) << endl;
    cout << frac1 << " <= " << frac2 << " : " << (frac1 <= frac2) << endl;
    cout << frac1 << " >= " << frac2 << " : " << (frac1 >= frac2) << endl;
    /* Assignment operator */
    cout << "------------- " << endl;
    frac3 = frac1;
    frac1 += frac1;
    cout << frac3 << " += " << frac3 << " = " << frac1 << endl;
    frac1 = frac3;
    frac1 -= frac1;
    cout << frac3 << " -= " << frac3 << " = " << frac1 << endl;
    frac1 = frac3;
    frac1 *= frac1;
    cout << frac3 << " *= " << frac3 << " = " << frac1 << endl;
    frac1 = frac3;
    frac1 /= frac1;
    cout << frac3 << " /= " << frac3 << " = " << frac1 << endl;
    frac1 = frac3;
    ++frac1;
    cout << "++"<< frac3 << " = " << frac1 << endl;
    frac1 = frac3;
    --frac1;
    cout << "--"<< frac3 << " = " << frac1 << endl;
    /* Convert Fraction to Double */
    double num;
    num = frac1.convertFractionToDouble();
    cout << "Convert first fraction number to double: " << num << endl;
    num = frac2.convertFractionToDouble();
    cout << "Convert second fraction number to double: " << num << endl;
}