#include "calculator.h"
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

long long factorial(int n) {
    long long product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    return product;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}

double subtract(double a, double b) {
    return a-b;
}

double divide(double a, double b) {
    return a/b;
}

int randomNumber(int min, int max) {
    return rand() % (max-min+1)+min;
}

double equanswer(string expr) {
    stack<double> nums;
    stack<char> ops;

    for (size_t i = 0; i < expr.size(); i++) {
        char ch = expr[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            double number = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                number = number * 10 + (expr[i] - '0');
                i++;
            }

            if (i < expr.size() && expr[i] == '.') {
                i++;
                double frac = 0.1;
                while (i < expr.size() && isdigit(expr[i])) {
                    number += (expr[i] - '0') * frac;
                    frac *= 0.1;
                    i++;
                }
            }

            nums.push(number);
            i--;
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = nums.top(); nums.pop();
                double a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
                else if (op == '/') nums.push(a / b);
            }
            ops.pop();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!ops.empty() && (
                       ((ch == '+' || ch == '-') && (ops.top() == '*' || ops.top() == '/')) ||
                       ((ch == '+' || ch == '-') && (ops.top() == '+' || ops.top() == '-')) ||
                       ((ch == '*' || ch == '/') && (ops.top() == '*' || ops.top() == '/'))
                       )) {
                double b = nums.top(); nums.pop();
                double a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();

                if (op == '+') nums.push(a + b);
                else if (op == '-') nums.push(a - b);
                else if (op == '*') nums.push(a * b);
                else if (op == '/') nums.push(a / b);
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        double b = nums.top(); nums.pop();
        double a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();

        if (op == '+') nums.push(a + b);
        else if (op == '-') nums.push(a - b);
        else if (op == '*') nums.push(a * b);
        else if (op == '/') nums.push(a / b);
    }

    return nums.top();
}
