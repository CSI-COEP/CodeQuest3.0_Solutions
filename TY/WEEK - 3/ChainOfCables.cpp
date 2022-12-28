#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;

void Display(unordered_map<int,vector<pair<int,int>>> &p){
    for (auto it: p){
        cout << it.first << endl;
        for (pair<int,int> n: it.second){
            cout << n.first << " " << n.second << " | ";
        }
        cout << endl;
    }
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

int findMin(vector<int> &cost, vector<bool> &visited, int N){
    int pos = 0;
    int mini = 1e9;
    for (int i=0; i<N; i++){
        if (!visited[i]){
            if (cost[i]<mini){
                mini = cost[i];
                pos = i;
            }
        }
    }
    return pos;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Find all towers with given height
    // Each of their positions are your vertices
    // Find the cost between each adjacent pair of towers
    // Introduce a dead start node and a dead finish node
    int N,K;
    cin >> N;
    cin >> K;
    unordered_map<int,vector<pair<int,int>>> p;
    p[0] = {{-1,-1}};
    p[K] = {{K+1,K+1}};
    for (int i=1; i<=K; i++){
        p[i] = {};
    }
    unordered_map<int,pair<int,int>> m;
    unordered_map<pair<int,int>,int,hash_pair> rm;
    m[0] = {-1,-1};
    rm[{-1,-1}] = 0;
    int nodeNum = 1;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int num;
            cin >> num;
            p[num].push_back({i,j});
            m[nodeNum] = {i,j};
            rm[{i,j}] = nodeNum;
            nodeNum++;
        }
    }
    m[nodeNum] = {K+1,K+1};
    rm[{K+1,K+1}] = nodeNum;
    // Display(p);
    // Connect start to all towers with height of 1
    vector<vector<vector<int>>> adj;
    vector<int> cost;
    vector<bool> visited;
    for (int i=0; i<=nodeNum; i++){
        adj.push_back({});
        cost.push_back(1e9);
        visited.push_back(false);
    }
    for (auto it: p[1]){
        adj[0].push_back({0,it.first,it.second});
        adj[rm[{it.first,it.second}]].push_back({0,-1,-1});
    }
    // Connect all towers with height K to end
    for (auto it: p[K]){
        adj[rm[{K+1,K+1}]].push_back({0,it.first,it.second});
        adj[rm[{it.first,it.second}]].push_back({0,K+1,K+1});
    }
    // Connect towers with height i to towers with height (i+1)
    for (int i=1; i<K; i++){
        for (auto it: p[i]){
            for (auto jt: p[i+1]){
                adj[rm[{it.first,it.second}]].push_back({abs(it.first-jt.first)+abs(it.second-jt.second),jt.first,jt.second});
                adj[rm[{jt.first,jt.second}]].push_back({abs(it.first-jt.first)+abs(it.second-jt.second),it.first,it.second});
            }
        }
    }
    // Now do Dijkstra's
    cost[0] = 0;
    bool flag = false;
    while(!flag){
        // Find which node to take
        int pos = findMin(cost,visited,nodeNum+1);
        // cout << "Pos: " << pos << endl;
        pair<int,int> node = m[pos];
        // cout << node.first << " " << node.second << endl;
        visited[pos] = true;
        // Relax the adjacent edges
        // cout << "Relaxing " << rm[node] << endl;
        for (auto it: adj[rm[node]]){
            // cout << it[1] << " " << it[2] << endl;
            if (!visited[rm[{it[1],it[2]}]] && cost[pos]+it[0]<cost[rm[{it[1],it[2]}]]){
                cost[rm[{it[1],it[2]}]] = cost[pos]+it[0];
            }
            if (it[1]==K+1 && it[2]==K+1){
                flag=true;
                break;
            }
        }
    }
    cout << cost[rm[{K+1,K+1}]] << endl;
    return 0;
}
