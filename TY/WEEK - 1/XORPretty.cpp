#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int BitsSetTable256[256];

void initialize()
{

    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}

int countSetBits(int n)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}
int main()
{
    initialize();
    ll t;
    cin>>t;
    
    while(t--){
        ll  n,q;
    cin>>n>>q;
        
        ll arr[n];
        ll p[n];
        priority_queue<ll> q1;
        priority_queue<ll, vector<ll>, greater<ll>> q2;
        
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }
        
        ll count=0;
        
        for(ll i=0; i<n; i++){
            ll b=arr[i];
            ll c=countSetBits(b);
        if((c%2)==1){
                count++;
                q1.push(i);
                q2.push(i);
                p[i]=1;
            }else{
                p[i]=0;
            }
        }
        
        
        for(ll j=0;j<q;j++){
            ll i,val;
        cin>>i>>val;
            arr[i]=val;
            int c=countSetBits(val);
            if((c%2)==0 && p[i]==1){
                p[i]=0;
                count--;
            }else if((c%2)==1 && p[i]==0){
                p[i]=1;
                q1.push(i);
                q2.push(i);
                count++;
            }
            
            while(q1.empty()==false){
               if(p[q1.top()]==0){
                   q1.pop();
               }else{
                   break;
               }
               
            }
            while(q2.empty()==false){
               if(p[q2.top()]==0){
                   q2.pop();
               }else{
                   break;
               }
            }
            
            if(count%2==0){
                cout<<n<<' ';
            }else{
                cout<<max(q1.top(), n-1-q2.top())<<' ';
            }
        }
        cout<<endl;
        
    }
}