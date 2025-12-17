#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nextGreaterElement2(arr);
    for(int x : ans){
        cout<<x<<" ";
    } cout<<endl;
    return 0;
}