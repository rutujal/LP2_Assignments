#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Seegraph(vector<vector<int>> &graph, int v)
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " --> ";
        }
        cout << endl;
    }
}

bool dfsexist(vector<vector<int>> &graph, vector<int> check, int node, int tosearch)
{ // recursively
    if (check[node] == 0)
    {
        if (node == tosearch)
        {
            return true;
        }
        check[node] = 1;
        for (int k = 0; k < graph[node].size(); k++)
        {
            bool find = dfsexist(graph, check, graph[node][k], tosearch);
            if (find)
            {
                return true;
            }
        }
    }
    return false;
}

void dfs(vector<vector<int>> &graph, vector<int> &check, int node)
{ // recursively
    if (check[node] == 0)
    {
        cout << node << " ";
        check[node] = 1;
        for (int k = 0; k < graph[node].size(); k++)
        {
            dfs(graph, check, graph[node][k]);
        }
    }
}

bool bfsexist(vector<int> check, vector<vector<int>> &graph, int node, int tosearch)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        if (node == tosearch)
        {
            return true;
        }
        q.pop();
        if (check[node] == 0)
        {
            check[node] = 1;
        }
        for (int k = 0; k < graph[node].size(); k++)
        {
            if (check[graph[node][k]] == 0)
            {
                check[graph[node][k]] = 1;
                q.push(graph[node][k]);
            }
        }
    }

    return false;
}

void bfs(vector<int> check, vector<vector<int>> &graph, int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (check[node] == 0)
        {
            cout << node << " ";
            check[node] = 1;
        }
        for (int k = 0; k < graph[node].size(); k++)
        {
            if (check[graph[node][k]] == 0)
            {
                check[graph[node][k]] = 1;
                cout << graph[node][k] << " ";
                q.push(graph[node][k]);
            }
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter no. of vertices :";
    cin >> v;
    cout << "Enter no. of Edges :";

    cin >> e;
    vector<vector<int>> graph;
    vector<int> nodes;
    vector<int> check;
    for (int i = 0; i <= v; i++)
    { // initialising  the graph
        graph.push_back(nodes);
        check.push_back(0);
    }

    cout << "Enter the edges\n";
    for (int i = 0; i < e; i++)
    {
        int e1, e2;
        cout << "Enter first node ";
        cin >> e1;
        cout << "Enter second node ";
        cin >> e2;
        cout << "---------------------------------------------\n";
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }

    int count = 0, size = v, node = 1, j = 0;
    Seegraph(graph, v);
    // dfs(graph,check,node);
    //  for(int i=1;i<=v;i++){   //initialising check array again to 0
    //      check[i]=0;
    //  }

    //    bfs(check,graph,node);
    int tosearch, opt;
    int conti;
    conti = 1;
    while (conti)
    {

        cout << "Enter 1  to search by dfs\nEnter 2 to search by bfs\nEnter 3 to traverse using dfs\nEnter 4 to traverse using bfs\n ";
        cin >> opt;

        if (opt == 1)
        {
            cout << "Enter the vertex you want to find: ";
            cin >> tosearch;
            if (dfsexist(graph, check, node, tosearch))
            {
                cout << "Entered vertex is present in graph:))))\n";
            }
            else
            {
                cout << "Entered vertex is not present in graph:(((\n";
            }
        }
        if (opt == 2)
        {
            cout << "Enter the vertex you want to find: ";
            cin >> tosearch;
            if (bfsexist(check, graph, node, tosearch))
            {
                cout << "Entered vertex is present in graph:))))\n";
            }
            else
            {
                cout << "Entered vertex is not present in graph:(((\n";
            }
        }

        if (opt == 3)
        {
            cout << "DFS traversal " << endl;
            dfs(graph, check, 2);
            for (int i = 1; i <= v; i++)
            { // initialising check array again to 0
                check[i] = 0;
            }
            cout << endl;
        }

        if (opt == 4)
        {
            cout << "BFS traversal " << endl;
            bfs(check, graph, 2);

            cout << endl;
        }

        cout << "----------------------------------------------------------------------\n";
        cout << "Do you want to continue??? (1-Yes/ 0-No) ";
        cin >> conti;
    }
}
//                1
//              /   \
//             2     3
//             |  \  |
//             4-----5
//              \   /
//                6
/*

Enter no. of vertices :4
Enter no. of Edges :3
Enter the edges  
Enter first node 1
Enter second node 2
---------------------------------------------
Enter first node 1
Enter second node 3
---------------------------------------------
Enter first node 2
Enter second node 4
---------------------------------------------
1 : 2 --> 3 -->
2 : 1 --> 4 -->
3 : 1 -->
4 : 2 -->
Enter 1  to search by dfs
Enter 2 to search by bfs
Enter 3 to traverse using dfs
Enter 4 to traverse using bfs
 1
Enter the vertex you want to find: 1
Entered vertex is present in graph:))))
----------------------------------------------------------------------
Do you want to continue??? (1-Yes/ 0-No) 1
Enter 1  to search by dfs
Enter 2 to search by bfs
Enter 3 to traverse using dfs
Enter 4 to traverse using bfs
 3
DFS traversal 
2 1 3 4
----------------------------------------------------------------------
Do you want to continue??? (1-Yes/ 0-No) 1
Enter 1  to search by dfs
Enter 2 to search by bfs
Enter 3 to traverse using dfs
Enter 4 to traverse using bfs
 4
BFS traversal 
2 1 4 3
----------------------------------------------------------------------
Do you want to continue??? (1-Yes/ 0-No) 2
Enter 1  to search by dfs
Enter 2 to search by bfs
Enter 3 to traverse using dfs
Enter 4 to traverse using bfs
 1
Enter the vertex you want to find: 1
Entered vertex is present in graph:))))
----------------------------------------------------------------------
Do you want to continue??? (1-Yes/ 0-No) 1
Enter 1  to search by dfs
Enter 2 to search by bfs
Enter 3 to traverse using dfs
Enter 4 to traverse using bfs
 2
Enter the vertex you want to find: 1
Entered vertex is present in graph:))))
----------------------------------------------------------------------
Do you want to continue??? (1-Yes/ 0-No) 0
*/