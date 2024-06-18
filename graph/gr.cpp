#include<iostream>
#include<vector>
#include<queue>
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
            adjlist->push_back( vector<int>() );
        
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


int main()
{
    GraphUD g = GraphUD(5); 
    g.addEdge(0,1); 
    g.addEdge(0,2); 
    g.addEdge(3,4); 
    g.addEdge(2,1); 
    g.addEdge(2,3); 
    g.addEdge(2,4); 


    g.print();

    /* vector<int> **p; 
    p = new vector<int>*;
    *(p + 0) = new vector<int>(2,20); */

    int* p, a, c; 

    int h = 45;
    p = &h;
    a = h;
    c = h; 

    cout << *p << endl;
    cout << a << endl;
    cout << c << endl;

    return 0; 
}
