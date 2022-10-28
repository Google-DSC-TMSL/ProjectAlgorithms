Question Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Youtube Link - https://youtu.be/SQ-pXKsBBz8

//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution

{

    public:

    //Function to find the shortest distance of all the vertices

    //from the source vertex S.

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)

    {

        // Code here

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;



        vector<int> dist(V);

        for (int i=0; i<V; i++){

            dist[i]=1e9;

        }



        dist[S]=0;

        pq.push({0,S});



        while (pq.empty()==false){

            int dis=pq.top().first;

            int node=pq.top().second;

            pq.pop();



            for (auto it : adj[node]){

                int edgeweight=it[1];

                int adjnode=it[0];



                if (dis + edgeweight < dist[adjnode]){

                    dist[adjnode] = dis+ edgeweight;

                    pq.push({dist[adjnode], adjnode});

                }

            }

        }

        return dist;

    }

};
