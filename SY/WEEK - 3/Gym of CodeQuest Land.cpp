/*
CONTRIBUTED BY - Aditya Choudhary
SY COMP
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int curr=0; // here the work of our curr variable is to store number of 1's starting from the 0th index till the ith index where we need it for the comparisison.
        int flag=0; // this flag will tell us at end whether our condition has been satisfied or not.
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                curr++; // incrementing curr at every occurence of 1.
            }
            if(2*curr>=i+1) // if at any position my condition is satisfied then I will set flag to 1 and break the loop to print YES.
            {
                flag=1;
                break;
            }
            // if condition is not satisfied then also i will explore the next possiblities.
        }
        if(flag==1)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
        t--;
    }
    return 0;
}