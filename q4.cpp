#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int size;
    int top;
    char *S;

    Stack(int size) {
        this->size = size;
        top = -1;
        S = new char[size];
    }

    void push(char x) {
        if (top == size - 1) {
            cout << "Stack Overflow.\n";
        } else {
            S[++top] = x;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow.\n";
            return '\0';
        } else {
            return S[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    char stackTop() {
        if (top == -1) return '\0';
        return S[top];
    }

    ~Stack() {
        delete[] S;
    }
};

bool isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

string InfixToPostfix(string infix) {
    Stack st(infix.length());
    string postfix = "";
    int i = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix += infix[i++];
        } else {
            while (!st.isEmpty() && precedence(st.stackTop()) >= precedence(infix[i])) {
                postfix += st.pop();
            }
            st.push(infix[i++]);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*c+d-e/f";
    string postfix = InfixToPostfix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}
