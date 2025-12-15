#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=1;
        sort(arr, arr+n);
        for(int i=1;i<n-1;i+=2){
            if(arr[i]!=arr[i+1]) ans=0;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}