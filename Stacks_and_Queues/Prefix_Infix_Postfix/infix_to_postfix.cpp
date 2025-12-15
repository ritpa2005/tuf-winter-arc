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

string infixToPostfix(string infix) {
    stack<char> ops;
    string post;

    for(char c: infix){
        if(isalnum(c)){
            post += c;
        } 
        else if(c == '('){
            ops.push(c);
        } 
        else if(c == ')'){
            while(!ops.empty() && ops.top() != '('){
                post += ops.top();
                ops.pop();
            }
            ops.pop();
        } 
        else{
            while(!ops.empty() && precedence(ops.top()) >= precedence(c)){
                post += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while(!ops.empty()){
        post += ops.top();
        ops.pop();
    }

    return post;
}

int main(){
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    string postfix = infixToPostfix(infix);
    cout<<"Postfix expression: "<<postfix<<endl;

    return 0;
}