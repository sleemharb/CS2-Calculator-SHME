#include <iostream>
#include <cstdlib>
#include "calculator.h"
using namespace std;

int main()
{

double a = 2.5;
double b = 3.3;
double addedVal= add(a,b);
cout<<"Addition Result of 2.5 and 3.3: "<< addedVal<<endl;


double subVal = subtract(10.3, 2.7);
cout<<"Subtraction Result of 10.3 and 2.7: "<<subVal<<endl;


double v1;
double v2;
cout<<"enter value 1 for multiplication: "<<endl;
cin>>v1;
cout<<"enter value 2 for multiplication: "<<endl;
cin>>v2;
double multipliedVal = multiply(v1, v2);
cout<<"Multiplication Result : "<< multipliedVal<<endl;

double v3;
double v4;
cout<<"enter value 1 for division; "<<endl;
cin>>v1;
cout<<"enter value 2 for division; "<<endl;
cin>>v2;
double divideanswer = divide(v1, v2);
cout<<"Division Result : "<< divideanswer<<endl;

int val;
cout<<"value to get factorial: "<<endl;
cin>>val;
long long factVal= factorial(val);
cout<<"Factorial Result :" << factVal<<endl;

int gcdVal= gcd(16,4);
cout<<"gcd Result of 16 and 4 : "<<gcdVal<<endl;

int lcmVal= lcm(16,4);
cout<<"lcm Result of 16 and 4 : "<< lcmVal<<endl;

srand(time(0));
int min;
int max;
do
{
cout<<"enter minimum value for random number: "<<endl;
cin>>min;
cout<<"enter maximum value for random number: "<<endl;
cin>>max;
}
while (min>max);
int RandVal= randomNumber(min, max);
cout<<"Random Value: "<<RandVal<<endl;

cin.ignore(numeric_limits<streamsize>::max(), '\n');

string expression;
cout << "Enter an equation: ";
getline(cin, expression);
double result = equanswer(expression);
cout << "Result: " << result << endl;

return 0;

}
