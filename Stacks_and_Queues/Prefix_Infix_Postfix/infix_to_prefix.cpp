#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPrefix(string infix) {
    stack<char> ops;
    string pre;
    reverse(infix.begin(), infix.end());
    for(char &c: infix){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    for(char c: infix){
        if(isalnum(c)){
            pre += c;
        } 
        else if(c == '('){
            ops.push(c);
        } 
        else if(c == ')'){
            while(!ops.empty() && ops.top() != '('){
                pre += ops.top();
                ops.pop();
            }
            ops.pop();
        } 
        else{
            while(!ops.empty() && precedence(ops.top()) > precedence(c)){
                pre += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while(!ops.empty()){
        pre += ops.top();
        ops.pop();
    }
    reverse(pre.begin(), pre.end());
    return pre;
}

int main(){
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    string prefix = infixToPrefix(infix);
    cout<<"Prefix expression: "<<prefix<<endl;

    return 0;
}