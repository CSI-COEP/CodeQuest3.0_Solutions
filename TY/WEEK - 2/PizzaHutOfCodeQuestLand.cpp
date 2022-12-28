#include<iostream>
#include<cstdio> 
#include<cmath>
#include<queue>
#include<vector>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<climits>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int un;
const int desll[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const ll mod=1e9+7;
const int maxn=4e2+7;
const int maxm=1e6+7;
const double eps=1e-4;
int m,n,p;
int ar[maxn];
char c[maxn];


//se stores all the X+1 possible solutions (<string,number of complaints for this pizza type>)
set<pair<int,string> > se;

//seMid stores all the forbidden strings.
set<string> seMid;


// function for flippings the bits
char cha(char c)
{
    return c=='1'?'0':'1';
}
int main()
{
    
    int t,fir=0;
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        memset(ar,0,sizeof(ar));
        seMid.clear();
        se.clear();
        
        for(int i=0;i<n;i++){
            cin>>c;
            
            //storing number of zeros in the pizza types of her friends.
            
            for(int j=0;j<p;j++){
                if(c[j]=='0')ar[j]++;
            }
        }
        
        //storing the forbidden pizza types.
        for(int i=0;i<m;i++){
            cin>>c;
            seMid.insert(string(c));
        }
        string str(p,'1');
        int mid=0;
        
        //formulation of the new string representing pizza type with minimum complaints(we dont yet know whether this type is forbidden or not.Will compute that in the coming section)
        for(int i=0;i<p;i++){
            if(ar[i]>n/2){
                str[i]='0';
                ar[i]=n-ar[i];
            }
            //mid represents the minimum number of complaints.
            mid+=ar[i];
        }
        
        //inserting the obtained newly formulated string and the complaint number in an array(se). 
        se.insert(make_pair(mid,string(str)));
        int ans=0;
        while((int)se.size()<=m){
            int mn=p*n;
            string ss;
            for(set<pair<int,string>>::iterator au = se.begin();au!=se.end();au++){
                mid = au->first;
                string sMid = au->second;
                if(mid>mn)break;
                for(int i=0;i<p;i++){
                    if(sMid[i]==str[i] && mn>mid+n-2*ar[i]){
                        sMid[i] = cha(sMid[i]);
                        if(se.count(make_pair(mid+n-2*ar[i],sMid))==0){
                            mn=mid+n-2*ar[i];
                            ss=sMid;
                        }
                        sMid[i] = cha(sMid[i]);
                    }
                }
            }
            se.insert(make_pair(mn,ss));
            if(seMid.count(ss)==0)break;
        }
        set<pair<int,string>>::iterator au=se.begin();
        for(;au!=se.end();au++){
            string sMid = au->second;
            if(seMid.count(sMid)==0){
                ans=au->first;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}