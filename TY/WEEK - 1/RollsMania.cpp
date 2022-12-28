#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f(vector<int> &z,int pos,int k,int prev,int end,vector<vector<vector<int>>> &dp){
    if(k==0){
        return end-prev-1;
    }
    if(pos>=z.size()){
        return 1e9;
    }
    if(dp[pos][k][prev]!=1e9){
        return dp[pos][k][prev];
    }
    int t=max(z[pos]-prev-1,f(z,pos+1,k-1,z[pos],end,dp));
    int nt=f(z,pos+1,k,prev,end,dp);
    // cout<<pos<<","<<k<<","<<prev<<","<<t<<","<<nt<<endl;
    return dp[pos][k][prev]=min(t,nt);
}

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    k=k-2;
    vector<int> z;
    for(int i=1;i<n-1;i++){
        if(s[i]=='0'){
            z.push_back(i);
        }
    }
    int ans=n-2;
    vector<vector<vector<int>>> dp(z.size()+1,vector<vector<int>>(k+1,vector<int>(n,1e9)));
    cout<<min(ans,f(z,0,k,0,n-1,dp));
    return 0;
}