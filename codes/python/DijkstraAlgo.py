class Solution:
    def dijkstra(self, V, adj, S):
        stack=[]
        dist=[float("inf") for i in range(V)]
        stack.append([S,0])
        visited=[False for i in range(V)]
        # dist[S]=0
        while len(stack)!=0:
            node,w=stack.pop(0)
            visited[node]=True
            if dist[node]>w:
                dist[node]=w
            for i in adj[node]:
                if w+i[1]<dist[i[0]]:
                    stack.append([i[0],w+i[1]])
        return dist


import atexit
import io
import sys


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V,E = map(int,input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u,v,w = map(int,input().strip().split())
            adj[u].append([v,w])
            adj[v].append([u,w])
        S=int(input())
        ob = Solution()
        
        res = ob.dijkstra(V,adj,S)
        for i in res:
            print(i,end=" ")
        print()
