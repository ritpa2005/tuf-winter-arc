#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string prefixToPostfix(string prefix) {
    int n = prefix.length();
    stack<string> s;
    for(int i=n-1;i>=0;i--){
        char c = prefix[i];
        if(isalnum(c)){
            s.push(string(1, c));
        } 
        else{
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = op1 + op2 + c;
            s.push(expr);
        }
    }
    return s.top();
}

int main(){
    string prefix;
    cout<<"Enter prefix expression: ";
    cin>>prefix;
    string postfix = prefixToPostfix(prefix);
    cout<<"Postfix expression: "<<postfix<<endl;

    return 0;
}