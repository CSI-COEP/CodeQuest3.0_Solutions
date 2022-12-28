/*
CODE CONTRIBUTED BY - Indrajeet Shelake
SY COMP
*/

#include<bits/stdc++.h>
using namespace std;
// Time Complexity →> 0(n*logn)
int main() {

       // taking inputs
       int n;
       cin>>n;
       int arr[n], brr[n];
       for(int i=0; i<n; i++) cin>>arr[i];
       for(int i=0; i<n; i++) cin>>brr[i];
       // set flag = 1, implies we are assuming all is okay till now
       int flag = 1;
       // sorting arr[] and brr [] in 0(n*logn)
       sort(arr, arr+n);
       sort(brr, brr+n);
       // comparing i-th element from arr[] with the t-th element of brr[]
       // Time complexity → 0(n)
       for(int i=n-1; i>=0; i--){
          if(arr[i]<brr[i]){
             flag = 0; // not okay, so set flag = 0
             break;
          }
          
       }
       // at any index iif we found arr[t] <brr[i] then print "NO"
       if(flag==0) cout<<"NO"<<endl;
       // else print "YES" means for all t, arr [t]>= brr[1]
       else cout<<"YES"<<endl;
       // NOTE ;)
       // total time complexity
       // 0(n*logn) + 0(n) = 0(n*logn)
       // our sorting time is 0(n*logn) due to sort function
       // this function uses merge sort internally which have TC-> 0(n*logn.)
       // we can write merge sort algorithm instead of using sort function
       // but we can't use bubble, insertion or selection sort if time limit is 1 sec
       // because bubble, insertion and selection have Time complexity 0(n^2) in worst case
       // and our constraint for n is 1 <= n <= 10^5
       // this implies 0(n^2) = 0(10^5*10^5) = 0(10^10) operations
       // in 1 sec we can do at max 10^8 operations implies TC < 0(10^8) for 1 sec
       // using bubble sort we have 0(10^10), this will take 100 sec to pass but we have 1 sec
       // choose the optimal sorting algorithm >
       return 0;
}