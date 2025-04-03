#include "calculator.h"
#include <iostream>

double add(double a,double b)
{
    return a+b;
}

double multiply(double a,double b)
{
    return a*b;
}



long long factorial(int n)
{
    int product;
    for (int i=1;i<=n;i++)
    {
        product *= i;
    }
    return product;
}

int gcd(int a, int b){
int temp;
while( b!=0){
int temp=b;
b= a%b;
a= temp;
}
return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}


double subtract(double a, double b){
return a-b;
}

double divide(double a, double b){
return a/b;
}

int randomNumber(int min, int max){
return rand()%(max-min+1) +min;
}

