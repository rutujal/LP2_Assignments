#include <iostream>
#include <vector>
using namespace std;

void djktra(vector<int> &visited, vector<int> &dist, vector<vector<pair<int, int>>> &g,vector<vector<int>> &path)
{
    int t = 0;
    int count = 1;
    dist[t] = 0;
    int n = dist.size();
    while (count != n)
    {
        visited[t]=1;
        for (int i = 0; i < g[t].size(); i++)
        {
            if (visited[g[t][i].first] == 0)
            {
                if(dist[g[t][i].first]>dist[t] + g[t][i].second){
                    path[g[t][i].first].clear();
                    for(int k=0;k<path[t].size();k++){
                         path[g[t][i].first].push_back(path[t][k]);
                    }
                     path[g[t][i].first].push_back(t);
                }
                dist[g[t][i].first] = min(dist[g[t][i].first], dist[t] + g[t][i].second);

            }
        }
        int mini = 100000;
    int minind = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (dist[i] < mini)
            {
                mini = dist[i];
                minind = i;
            }
        }
    }
    count++;
    t = minind;
    }
    
}

int main()
{
    int v, e;
    cout << "Enter no. of vertices :";
    cin >> v;
    cout << "Enter no. of Edges :";

    cin >> e;
    vector<vector<pair<int, int>>> graph(v);
    vector<vector<int>> path(v);
    vector<int> visited(v, 0); 
    vector<int> dist(v, 1000000);
    for (int i = 0; i < e; i++)
    { // initialising  the graph
        int v1, v2, w;
        cout << "v1 v2 and w ";
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }

    djktra(visited, dist, graph,path);
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> " << dist[i] << "    :   ";
        
        for(int j=0;j<path[i].size();j++){
            cout<<path[i][j]<<"->";
        }
        cout<<i<<endl;
    }
}


/*
Enter no. of vertices :4
Enter no. of Edges :3
v1 v2 and w 0 1 1
v1 v2 and w 0 2 2
v1 v2 and w 1 3 3
0 -> 0    :   0
1 -> 1    :   0->1
2 -> 2    :   0->2
3 -> 4    :   0->1->3
*/