#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    double radius,volume;

    cout << "Enter a radius ";
    cin >> radius;

    volume = 4.0/3*M_PI*pow(radius,3);

    cout << "The volume of your sphere is " << volume << endl;

    return 0;
}