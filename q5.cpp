#include <iostream>
#include <string>
using namespace std;

class Stack {
    int size;
    int top;
    int *arr;  // store integers (used for evaluation)
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
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

// Convert infix to postfix
string InfixToPostfix(string infix) {
    Stack st(infix.size());
    string postfix = "";

    for (int i = 0; i < infix.size(); i++) {
        if (isOperand(infix[i])) {
            postfix += infix[i];
        } else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(infix[i])) {
                postfix += (char)st.pop();
            }
            st.push(infix[i]);
        }
    }
    while (!st.isEmpty()) {
        postfix += (char)st.pop();
    }

    return postfix;
}

// Evaluate postfix expression
int EvaluatePostfix(string postfix) {
    Stack st(postfix.size());

    for (int i = 0; i < postfix.size(); i++) {
        if (isOperand(postfix[i])) {
            st.push(postfix[i] - '0');  // convert char digit to int
        } else {
            int x2 = st.pop();
            int x1 = st.pop();
            int r = 0;
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            st.push(r);
        }
    }
    return st.pop();
}

int main() {
    string infix = "3+7*5+4-5/2";

    string postfix = InfixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    int result = EvaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
