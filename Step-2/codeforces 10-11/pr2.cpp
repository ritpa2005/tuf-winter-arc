#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        string x; cin>>x;
        int m = x.length();
        
        if(x[0]=='1' || x[m-1]=='1'){
            cout<<-1<<endl;
            continue;
        }

        vector<pair<int, int>> segments;
        for(int i=0;i<m;i++){
            if(x[i]=='1'){
                int j=i;
                while(i<n && x[i]=='1') i++;
            }
            i--;
            segments.push_back({j, i});
        }

        int mxi = max_element(arr, arr+n)-arr;
        int mni = min_element(arr, arr+n)-arr;

/*
You are given a permutation∗ p of every integer from 1 to n
. You also own a binary† string s of size n where si=0 for all 1≤i≤n
. You may do the following operation at most 5 times:

Choose any two integers l and r such that 1≤l≤r≤n
. Then, for every i such that l<i<r and min(pl,pr)<pi<max(pl,pr)
 hold at the same time, you will set si to 1
.
You are also given a binary string x  of size n
. After performing operations, it must hold for every 1≤i≤n
 that if xi=1  then si=1 . Note that if xi=0 , then si
 can have any value.

Figure out any sequence of at most 5 operations such that the 
aforementioned condition is satisfied, or report that it is 
impossible to do so. Note that you do not have to minimize the 
number of operations you make.
 */
        set<pair<int, int>> operations;
        vector<pair<int, int>> new_segments;
        for(auto seg: segments){
            int l=seg.first, r=seg.second;
            if(l>mni && r<mxi){
                operations.insert({mni, mxi});
            }
            else if(l>mxi && r<mni){
                operations.insert({mxi, mni});
            }
            else if(l>mni && l>mxi){
                int mxa = arr[l];
                for(int i=l;i<=r;i++){
                    mxa = max(mxa, arr[i]);
                }
                int j = r+1;
                while(j<n && arr[j]<mxa) j++;
                if(j<n) operations.insert({mni, j});
                else{
                    int mna = arr[l];
                    for(int i=l;i<=r;i++){
                        mna = min(mxa, arr[i]);
                    }
                    j = r+1;
                    while(j<n && arr[j]>mna) j++;
                    if(j<n) operations.insert({mxi, j});
                    else{
                        new_segments.push_back({l, r});
                    }
                }
            }
            else if(r<mni && r<mxi){
                int mxa = arr[l];
                for(int i=l;i<=r;i++){
                    mxa = max(mxa, arr[i]);
                }
                int j = l-1;
                while(j>=0 && arr[j]<mxa) j--;
                if(j>=0) operations.insert({j, mni});
                else{
                    int mna = arr[l];
                    for(int i=l;i<=r;i++){
                        mna = min(mxa, arr[i]);
                    }
                    j = l-1;
                    while(j>=0 && arr[j]>mna) j++;
                    if(j>=0) operations.insert({j, mxi});
                    else{
                        new_segments.push_back({l, r});
                    }
                }
            }
            else if(l<mni && r>mxi){
                operations.insert({1, n});
            }
        }

        if(operations.size()>5){
            cout<<-1<<endl;
            continue;
        }

        cout<<operations.size()<<endl;
        for(auto op: operations){
            cout<<op.first<<" "<<op.second<<endl;
        }
    }
    return 0;
}