#include<bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   vector<int> dist(vertices,INT_MAX);
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
   vector<vector<pair<int,int>>> adj(vertices);
   for(int i=0;i<edges;i++){
       adj[vec[i][0]].push_back(make_pair(vec[i][1],vec[i][2]));
       adj[vec[i][1]].push_back(make_pair(vec[i][0],vec[i][2]));
   }
   pq.push(make_pair(0,source));
   dist[source]=0;
   while(pq.size()>0){
       int cur = pq.top().second;
       int distance= pq.top().first;
       pq.pop();
       for(auto node: adj[cur]){
           if(dist[cur]!=INT_MAX && dist[cur]+ node.second< dist[node.first]){
               dist[node.first]=dist[cur]+node.second;
               pq.push(make_pair(node.second,node.first));
            }
       }
   }
   return dist;
}
