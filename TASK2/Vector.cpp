#include <iostream>
#include <array>
#include <cmath>
using namespace std;

class Vector {
private:
    array<double, 3> vect;
public:
/* Constructor */

    Vector (){
        for (int i = 0; i < sizeof(this->vect) / sizeof(vect[0]); i++){
            this->vect[i] = 0.0;
        }
    }
    Vector (array <double,3 > &ele){
        this->vect  = ele;
    }
/* Setter and Getter */

    void setVector(array <double, 3> &ele){
        this->vect  = ele;
    }
    array <double, 3> &getVector(){
        return this->vect;
    }
/* Calculate module of Vector */
    double moduleVector(){
        return (double)sqrt( pow(vect[0],2) + pow(vect[1],2) + pow(vect[2],2) );
    }
/* Overloaded operators */

    /* Operator + */
    Vector operator +(Vector &other){
        Vector result;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            result.getVector()[i] = this->vect[i] + other.getVector()[i];
        }
        return result;
    }
    /* Operator - */
    Vector operator -(Vector &other){
        Vector result;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            result.getVector()[i] = this->vect[i] - other.getVector()[i];
        }
        return result;
    }
    /* Scalar product( Dot product ) */
    double operator *(Vector &other){
        double result = 0.0;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            result += this->vect[i] * other.getVector()[i];
        }
        return result;
    }    
    /* Scalar multiplication */
    Vector operator *(double k){
        Vector result;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            result.getVector()[i] = this->vect[i] * k;
        }
        return result;
    }
    /* Operator assignment += */
    Vector operator += (Vector &other){
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            this->vect[i] = this->vect[i] + other.getVector()[i];
        }
        return *this;
    }
    /* Operator assignment -= */
    Vector operator -= (Vector &other){
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            this->vect[i] = this->vect[i] - other.getVector()[i];
        }
        return *this;
    }
    /* Operator assignment( Scalar product / Dot product ) *= */
    double operator *=(Vector &other){
        double result = 0.0;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            result += this->vect[i] * this->vect[i];
        }
        return result;
    } 
    /* Operator assignment( Scalar multiplication ) *= */
    Vector operator *= (double k){
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            this->vect[i] = this->vect[i] * k;
        }
        return *this;
    }
/* Operator to compare */

    /* Compare two vector are the same */
    bool operator == (Vector &other){
        int count = 0;
        for (int i = 0; i < sizeof(this->vect) / sizeof(this->vect[0]); i++){
            if (this->vect[i] == other.getVector()[i]){
                count += 1;
            }
        }
        if (count == 3){
            return 1;
        }
        return 0;
    }
    /* Compare two vector are different */
    bool operator != (Vector &other){
        return !(*this == other);
    }
    /* Compare module (length) of two vectors */
    bool operator > (Vector &other){
        return (this->moduleVector() > other.moduleVector());
    }
    bool operator < (Vector &other){
        return !(*this > other);
    }
    bool operator >= (Vector &other){
        if ((*this > other) || (this->moduleVector() == other.moduleVector())){
            return 1;
        }
        return 0;
    }
    bool operator <= (Vector &other){
        if ((*this < other) || (this->moduleVector() == other.moduleVector())){
            return 1;
        }
        return 0;
    }
/* Initialize stream ouput and input operators */
    friend ostream& operator<<(ostream& os, Vector& vec);
    friend istream& operator>>(istream& is, Vector& vec);
};

/* Stream output operator */ 
ostream& operator<<(ostream& cout, Vector& vec) {
    cout << "(";
    for (size_t i = 0; i < vec.getVector().size(); ++i) {
        cout << vec.getVector()[i];
        if (i < vec.getVector().size() - 1) {
            cout << ", ";
        }
    }
    cout << ")";
    return cout;
}
/* Stream input operator */ 
    istream& operator>>(istream& cin, Vector& vec) {
    char c;
    cin >> c;  // Read '('
    vec.getVector().fill(0.0);

    for (size_t i = 0; i < vec.getVector().size() - 1; ++i) {
        cin >> vec.getVector()[i];
        cin >> c;  // Read ',' or ')'
        if (c == ')') {
            break;
        }
    }
    return cin;
}

    


