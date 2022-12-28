#include<bits/stdc++.h>
using namespace std;
vector<int> creatures[1001];
int dp[1001][1001][2];
int solve(int i,int x,bool last_taken){
    if(x<=0){
        return 0;
    }
    if(i==1001) return 1e9;
    if(dp[i][x][last_taken]!=-1){
        return dp[i][x][last_taken];
    }
    int ans=solve(i+1,x,last_taken);
    for(int j=0;j<creatures[i].size();j++){
        if(!last_taken){
            ans=min(ans,creatures[i][j]+solve(i+1,x-(j+1),1));
        }
        ans=min(ans,2*creatures[i][j]+solve(i+1,x-(j+1),last_taken));
    }
    return dp[i][x][last_taken]=ans;
}
int main(){
    int T,n,k;
    cin>>T;
    for(int t=0;t<T;t++) {
        cin>>n>>k;
        vector<int> pos(n),colors(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<1001;i++){
            creatures[i].clear();
        }
        for(int i=0;i<n;i++){
            cin>>pos[i];
        }
        for(int i=0;i<n;i++){
            cin>>colors[i];
        }
        for(int i=0;i<n;i++){
            creatures[colors[i]].push_back(pos[i]);
        }
        for(int i=0;i<1001;i++){
            sort(creatures[i].begin(),creatures[i].end());
        }
        cout<<solve(1,k,0)<<endl;
    }
}