#include <bits/stdc++.h>
using namespace std;

template <class T>
class stck {
    T *arr;
    int top;
    int size;
public:
    stck(int n) : top(-1), size(n) {
        arr = new T[n];
    }
    void push(T x) {
        top++;
        arr[top] = x;
    }
    T pop() {
        T temp = arr[top];
        top--;
        return temp;
    }
    T Top() {
        return arr[top];
    }
    bool isEmpty() {
        return (top == -1) ? 1 : 0;
    }
};

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^')              return 3;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string infixToPostfix(string s) {
    char ch;
    string res = "";
    int n = s.length();
    stck<char> s1(n);

    for (int i = 0; i < n; i++) {
        ch = s[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            res += ch;
        }
        else if (ch == '(') {
            s1.push(ch);
        }
        else if (ch == ')') {
            while (!s1.isEmpty() && s1.Top() != '(') {
                res += s1.pop();
            }
            if (!s1.isEmpty()) s1.pop(); 
        }

        else if (isOperator(ch)) {
            while (!s1.isEmpty() && precedence(s1.Top()) >= precedence(ch)) {
                res += s1.pop();
            }
            s1.push(ch);
        }
    }

    while (!s1.isEmpty()) {
        res += s1.pop();
    }

    return res;
}

int main() {
    char line[500];
    cout << "Enter a line: ";
    cin.getline(line, 500);

    char extracted[100][100];
    int count = 0;            

    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '{') {
            i++;
            int j = 0;
            while (line[i] != '}' && line[i] != '\0') {
                extracted[count][j++] = line[i++];
            }
            extracted[count][j] = '\0';   
            count++;
        } else {
            i++;
        }
    }

    cout << "Total Expressions Found: " << count << endl;

    cout << "\nPostfix expressions:\n";
    for(int k = 0; k < count; k++) {
        string postfix = infixToPostfix(extracted[k]);
        cout << postfix << endl;
    }
    
    return 0;
}