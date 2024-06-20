#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphUD
{
    public:
        int vertex;
        int edges;
        vector<vector<int>> *adjlist;
        
        GraphUD(int n)
        {
            vertex = n;
            edges = 0;
            adjlist = new vector<vector<int>>(vertex);

        }


        void mcolor(int m)
        {
            int colorArr[vertex] = {0}; 
            int node = 0; 
            // solver(node, m, colorArr); 
        }
        


        void addEdge(int src, int des)
        {
            adjlist->at(src).push_back(des);
            adjlist->at(des).push_back(src);
            edges += 2;
        }
        void solver(int stand, vector<int> &vis)
        {
            vis[stand] = 1;
            cout << stand << " ";

            // look 
            for (int j = 0; j < adjlist->at(stand).size(); j++)
            {
                int next = adjlist->at(stand).at(j);
                if (vis[next] == -1)
                {
                    solver(next, vis);
                }
            }
        }
        void dfs(int start)
        {
            vector<int> vis(vertex, -1);
            solver(start, vis);
            //      3

        }
        void bfs(int start)
        {
            queue<int> que;
            // int *vis  = new int[vertex];
            vector<int> vis(vertex, -1);
            que.push(start);
            vis[start] = 1;

            while( que.empty() != true)
            {
                int stand = que.front();
                que.pop();
                cout << stand <<" ";

                // look at nei
                for(int j = 0; j < adjlist->at(stand).size(); j++)
                {
                    int next = adjlist->at(stand).at(j);
                    if( vis[next] == -1)
                    {
                        que.push(next);
                        vis[next] = 1;
                    }
                }


            }

        }

        void print( )
        {
            for(int i = 0; i < this->vertex; i++)
            {
                cout << i <<": ";
                for(int j = 0; j < adjlist->at(i).size(); j++ )
                {
                    cout << adjlist->at(i).at(j) << " ";
                }

                cout << endl;
            }
        }
};


class GraphUDW
{
public:
    int vertex;
    int edges;
    vector<vector<vector<int>>> *adjlist;
    GraphUDW(int n)
    {
        vertex = n;
        edges = 0;
        adjlist = new vector<vector<vector<int>>>(vertex);
    }
    void addEdge(int src, int des, int wgt)
    {
        vector<int> edge(2);
        edge[0] = wgt;
        edge[1] = des;
        adjlist->at(src).push_back(edge);
    }

    void prims()
    {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<int> vis(vertex, -1);
        //        w n p
        vector<int> edge = {0, 0, -1};
        pq.push(edge);

        int sum = 0;
        while (pq.empty() == false)
        {
            vector<int> p = pq.top();
            pq.pop();
            int wght = p[0];
            int stand = p[1];
            int par = p[2];

            if (vis[stand] == -1)
            {
                vis[stand] = 1;
                cout << wght << " " << stand << " " << par << endl;
                sum += wght;
                // look at nie
                for (int i = 0; i < adjlist->at(stand).size(); i++)
                {
                    vector<int> nei = adjlist->at(stand).at(i);
                    int wght_n = nei[0];
                    int stand_n = nei[1];

                    if (vis[stand_n] == -1)
                    {
                        pq.push({wght_n, stand_n, stand});
                    }
                }
            }
        }
    }
};

class Compare
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};

int main()
{
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    pq.push({5, 3, 4});
    pq.push({6, 3, 4});
    pq.push({2, 3, 4});

    return 0;
}