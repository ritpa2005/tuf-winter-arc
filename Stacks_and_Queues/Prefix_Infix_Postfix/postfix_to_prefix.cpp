#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string postfixToPrefix(string postfix) {
    int n = postfix.length();
    stack<string> st;
    for(char c: postfix){
        if(isalnum(c)){
            st.push(string(1,c));
        }
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push(c + op1 + op2);
        }
    }
    return st.top();
}

int main(){
    string postfix;
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    string prefix = postfixToPrefix(postfix);
    cout<<"Prefix expression: "<<prefix<<endl;

    return 0;
}