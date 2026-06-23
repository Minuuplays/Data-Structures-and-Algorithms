#include <bits/stdc++.h>
using namespace std;

template <class T>
class stck{
    T *arr;
    int top;
    int size;
    
public:
    stck(int n):top(-1),size(n){
        arr = new T[n];
    }

    void push(T x)
    {
        if(top == size-1) return;  
        arr[++top] = x;
    }

    T pop()
    {
        if(top == -1) return T(); 
        return arr[top--];
    }

    T Top()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(string s)
{
    string res;
    int n = s.length();
    stck<char> s1(n);  

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (isalnum(ch))
        {
            res += ch;
        }

        else if (ch == '(')
        {
            s1.push(ch);
        }

        else if (ch == ')')
        {
            while (!s1.isEmpty() && s1.Top() != '(')
            {
                res += s1.pop();
            }
            s1.pop(); // removing '('
        }

        else
        {
            while (!s1.isEmpty() && 
                   precedence(s1.Top()) >= precedence(ch))
            {
                res += s1.pop();
            }
            s1.push(ch);
        }
    }

    while (!s1.isEmpty())
    {
        res += s1.pop();
    }

    return res;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(') { s[i] = ')'; }
        else if(s[i] == ')') { s[i] = '('; }
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int operation(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluatePostfix(string s)
{
    int n = s.length();
    stck<int> s1(n);

    for(int i = 0; i < n; i++)
    {
        char ch = s[i];

        if(isalnum(ch))
        {
            s1.push(ch - '0');
        }
        else   // operator
        {
            int operand2 = s1.pop();
            int operand1 = s1.pop();

            int result = operation(operand1, operand2, ch);

            s1.push(result);
        }
    }

    return s1.pop();
}

int evaluatePrefix(string s)
{
    int n = s.length();
    stck<int> s1(n);

    for(int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];

        if(isalnum(ch))
        {
            s1.push(ch); // s1.push (ch - '0')
        }
        else 
        {
            int operand1 = s1.pop();
            int operand2 = s1.pop();

            int result = operation(operand1, operand2, ch);

            s1.push(result);
        }
    }

    return s1.pop();
}

int main()
{
    string str = "T+M*(x-y)";
    string post = infixToPostfix(str) ;
    string pre = infixToPrefix(str) ;

    cout << "Postfix: " << post << endl ;
    cout << "Prefix: " << pre << endl ; 

    int postev = evaluatePostfix(post);
    int preev = evaluatePrefix(pre);

    cout << "Postfix Evalution = " << postev << endl;
    cout << "Prefix Evalution = " << preev << endl;

    return 0;
}