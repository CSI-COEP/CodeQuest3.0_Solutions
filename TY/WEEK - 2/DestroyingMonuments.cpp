#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<pair<int,int>> adj[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"####";
        for(auto it:adj[i])
        {
            cout<<it.first<<"("<<it.second<<")-->";
        }
        cout<<"NULL\n";
    }
}

void printVector(vector<int> &v)
{
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

void printVectorofVector(vector<vector<int>> vv)
{
    for(int i=0;i<vv.size();i++)
    {
        for(auto it:vv[i])
            cout<<it<<" ";
        cout<<endl;
    }
}


class mm{
    public:
    int mx_dist;
    vector<vector<int>> path;
    vector<int> common;
    mm()
    {
        mx_dist=0;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> monuments;
    vector<bool> ismonuments(n+1,false);
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        monuments.push_back(x);
        ismonuments[x]=true;
    }
    
    vector<pair<int,int>> adj [n+1];
    for(int i=0;i<n-1;i++)
    {
        int u,v,dist;
        cin>>u>>v>>dist;
        adj[u].push_back(make_pair(v,dist));
        adj[v].push_back(make_pair(u,dist));
    }

    mm element[m];

    // printGraph(adj,n);
    
    for(int i=0;i<monuments.size();i++)
    {
        mm obj1;

        queue<pair<pair<int,vector<int>>,int>>q;
        vector<bool>visited(n+1,false);

        int curr_monument=monuments[i];
        // cout<<"\ncurr_monument"<<curr_monument<<"\n";
        vector<int> v;

        q.push(make_pair(make_pair(curr_monument,v),0));
        visited[curr_monument]=true;
        while(!q.empty())
        {
            int node=q.front().first.first;
            vector<int> curr_path=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int adj_node=it.first;
                // cout<<adj_node<<" ";
                int adj_dist=it.second+dist;
                if(!visited[adj_node])
                {
                    if(ismonuments[adj_node])
                    {
                        if(obj1.mx_dist<adj_dist)
                        {
                            obj1.path.clear();
                            obj1.mx_dist=adj_dist;
                            obj1.path.push_back(curr_path);
                        }
                        else if(obj1.mx_dist==adj_dist)
                        {
                            obj1.path.push_back(curr_path);
                        }
                        // cout<<"Distance: "<<curr_path<<"+++";
                        // printVector(curr_path);
                    }

                    curr_path.push_back(adj_node);
                    q.push(make_pair(make_pair(adj_node,curr_path),adj_dist));
                    visited[adj_node]=true;

                    curr_path.pop_back();
                }
            }
        }

        unordered_map<int,int> mp;
        for(auto it:obj1.path)
        {
            for(int k=0;k<it.size();k++)
                mp[it[k]]++;
        }

        for(auto it:mp)
        {
            if(it.second==obj1.path.size() && ismonuments[it.first]==false)
                obj1.common.push_back(it.first);
        }

        // printVector(obj1.common);

        element[i]=obj1;
        // cout<<obj1.mx_dist<<"KK";
        // printVectorofVector(obj1.path);
    }

    // vector<int> res=
    // for(int i=0;i<m;i++)
    // {
    //     cout<<element[i].mx_dist<<"\n";
    // }

    unordered_map<int,int> mp;
    for(int i=0;i<m;i++)
    {
        for(auto it:element[i].common)
        {
            mp[it]++;
        }
    }
    
    int mx=0;
    for(auto ik:mp)
    {
        mx=max(mx,ik.second);
    }
    int count=0;
    for(auto ik:mp)
    {
        if(ik.second==mx)
            count++;
    }
    if(mx!=0)
       cout<<mx<<" "<<count;
    else
    {
        cout<<mx<<" "<<count+1;   
    }
    
        
    return 0;
}