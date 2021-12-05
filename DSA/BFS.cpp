#include <iostream>
#include <list>
#include<queue>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s);
};

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        //*(visited + i) = false;
    }

    queue<int> queue;

    visited[s] = true;
    queue.push(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop();

        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
               //*(visited + *i) = true;
                queue.push(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.BFS(2);
    cout<<endl;


    return 0;
}