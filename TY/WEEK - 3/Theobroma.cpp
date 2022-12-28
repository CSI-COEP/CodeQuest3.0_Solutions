#include <iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,c,k;
        cin>>n>>c>>k;
        priority_queue<int> delight[n +1] ;

        for(int i=0;i<c;i++){
            int d,b,e;
            cin>>d>>b>>e;
            for(int i =b ;i<=e;i++){
                delight[i].push(d);
            }
        }
        int best = INT_MIN;
        for(int i=1;i<=n;i++){
            int count = k;
            int sum=0;
            while(count-- && !delight[i].empty()){
                sum+=delight[i].top();
                delight[i].pop();
            }
            best = max(best,sum);
        }
        cout<<best<<endl;
        
    }
    return 0;
}