#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Display(vector<int> &v){
    for (int a: v){
        cout << a << " ";
    }
    cout << endl;
}

bool comp(const vector<int> &a, const vector<int> &b){
    return a[0]<b[0];
}

bool isCyclic(int from, int to, vector<int> &parent){
    if (parent[from]==parent[to]){
        return true;
    } else{
        return false;
    }
}

void unionize(int from, int to, vector<int> &parent, int N){
    int change = max(parent[from],parent[to]);
    int keep = min(parent[from],parent[to]);
    for (int i=0; i<N; i++){
        if (parent[i]==change){
            parent[i] = keep;
        }
    }
}

long long int getMeMin(vector<long long int> &B, vector<long long int> &W, int i, int j){
    long long int bw = B[i]^W[j];
    long long int wb = W[i]^B[j];
    if (bw<wb){
        return bw;
    } else{
        return wb;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<long long int> B(N,0);
        vector<long long int> W(N,0);
        for (int i=0; i<N; i++){
            cin >> B[i];
        }
        for (int i=0; i<N; i++){
            cin >> W[i];
        }
        vector<vector<long long int>> cost;
        for (int i=0; i<N; i++){
            for (int j=i+1; j<N; j++){
                if (i!=j){
                    cost.push_back({getMeMin(B,W,i,j),i,j});
                }
            }
        }
        sort(cost.begin(), cost.end());
        vector<int> parent;
        for (int i=0; i<N; i++){
            parent.push_back(i);
        }
        // Iterate over the edges
        int count = 0;
        int pos = 0;
        long long int minCost = 0;
        // Until there are N-1 edges
        while (count<N-1){
            vector<long long int> row = cost[pos];
            // Does it form a cycle?
            if (isCyclic(row[1],row[2],parent)){
                // Skip
            } else{
                // Unionize
                unionize(row[1],row[2],parent,N);
                // Add to the cost
                minCost += row[0];
                count++;
            }
            pos++;
        }
        cout << minCost << endl;
    }
    return 0;
}