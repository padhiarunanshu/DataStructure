/*
 * brief: Problems on Graph, algorithms used in graph to solve different problems.
 */

// headers
#include <bits/stdc++.h>
using namespace std;

// consts
const unsigned int kSize = 10;

// members
vector<int> adjList[kSize];
int level[kSize];
bool visited[kSize];

// Problems...
// 1. the level of each node in the given Graph/Tree?

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    level[ s ] = 0;
    visited[ s ] = true;
	
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
		
        for(int i = 0;i < adjList[parent].size() ; i++)
        {
			int node = adjList[parent][i];
			
            if(visited[node] == false)
            {
                level[node] = level[parent] + 1;                 
                q.push(node);
                visited[node] = true;
			}
        }
    }
}

