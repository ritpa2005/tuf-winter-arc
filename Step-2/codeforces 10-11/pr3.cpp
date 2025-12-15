#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a1(n+1), a2(n+1);
        for(int i=1;i<=n;i++) cin>>a1[i];
        for(int i=1;i<=n;i++) cin>>a2[i];
        int m = 2*n;

        vector<int> pref_min1(n+1), pref_max1(n+1);
        pref_min1[1]=a1[1]; pref_max1[1]=a1[1];
        for(int i=2;i<=n;i++){
            pref_min1[i]=min(pref_min1[i-1], a1[i]);
            pref_max1[i]=max(pref_max1[i-1], a1[i]);
        }
        
        vector<int> suf_min2(n+2), suf_max2(n+2);
        suf_min2[n]=a2[n]; suf_max2[n]=a2[n];
        for(int i=n-1;i>=1;i--){
            suf_min2[i]=min(suf_min2[i+1], a2[i]);
            suf_max2[i]=max(suf_max2[i+1], a2[i]);
        }
        
        vector<vector<int>> bucket(m+2);
        for(int k=1;k<=n;k++){
            int mn = min(pref_min1[k], suf_min2[k]);
            int mx = max(pref_max1[k], suf_max2[k]);
            bucket[mn].push_back(mx);
        }
        
        long long ans = 0;
        int cur = m+5;
        for(int l=m;l>=1;--l){
            for(int mx : bucket[l]){
                if(mx < cur) cur = mx;
            }
            if(cur <= m){
                int need = max(l, cur);
                if(need <= m) ans += (m - need + 1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
