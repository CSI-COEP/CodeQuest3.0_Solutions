/*
CONTRIBUTED BY - 
CSI COEP Tech Core Team
*/

#include<bits/stdc++.h>
#define MOD 1000000009
#define MOD2 1000000006
#define TEMPMOD2 998244352
#define INF 1000000000000000007
#define NEGINF -1000000000000000007
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define plll pair<ll,pll>
#define vpll vector<pll>
using namespace std;
typedef long long int ll;

ll dp[510][510];
ll arr1[510];

ll solve(ll idx,ll left)
{
    if(left>idx)
    {
        return INF;
    }
    if(left==0 || idx==0 )
    {
        return 0;
    }
    if(dp[idx][left]!=-1)
    {
        return dp[idx][left];
    }
    ll ans=INF,store;
    for(int i=1;i<=idx;i++)
    {
        store=(idx+1-i)*arr1[i];
        store+=solve(i-1,left-1);
        ans=min(ans,store);
    }
    dp[idx][left]=ans;
    return ans;
}

int main()
{
// 
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    ll n,k;
    for(int i=0;i<510;i++)
    {
        for(ll j=0;j<510;j++)
        {
            dp[i][j]=-1;
        }
    }
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr1[i];
    }
    sort(arr1+1,arr1+n+1);
    ll ans=solve(n,k);
    cout<<ans<<endl;
    return 0;
}