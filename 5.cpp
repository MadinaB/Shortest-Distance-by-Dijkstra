#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dijkstra(vector<vector<int> > matrix, vector<vector<int> > matrixCosts, int n, int s, int f){
    s--;
    f--;
    int distances[n];
    for(int i=0;i<n;i++){
        distances[i]=-1;
    }
    distances[s] = 0;
    int w[n];
    for(int i=0;i<n;i++){
        w[i]=0;
    }
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int key=q.top().second;
        q.pop();        
        if(w[key]){
            continue;
        }
        w[key]=1;
        for(int i=0; i<matrix[key].size();i++){
            int to=matrix[key][i];
            int distance= matrixCosts[key][i];
            if(distances[to]==-1||distances[to]>distances[key]+distance){
                distances[to]=distances[key]+distance;
                q.push(make_pair(-distances[to],to));
            }
        } 
    }
    return distances[f];
}
int main(){
    int n, s,f, in;
    cin>>n>>s>>f;
    
    vector<vector<int> > matrix;
    vector<vector<int> > matrixCosts;
    matrix.resize(n);
    matrixCosts.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>in;
           if(in !=-1){
                matrix[i].push_back(j);
                matrixCosts[i].push_back(in);
           }
        }
    }
    
    cout<<dijkstra(matrix, matrixCosts,n, s, f);

    for(int i=0;i<n;i++){
        for(int j=0;j<matrix[i].size();j++){
          //  cout<<matrixCosts[i][j]<<" ";
        }
       // cout<<endl;
    }

    return 0;
}
