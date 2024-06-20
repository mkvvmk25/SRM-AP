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

    bool checkcolorofnei(int stand,
                         int trycolor, int colorArr[])
    {
        for (int i = 0; i < adjlist->at(stand).size(); i++)
        {
            int nei = adjlist->at(stand).at(i);
            if (colorArr[nei] == trycolor)
            {
                return false;
            }
        }
        return true;
    }
    void solver(int stand, int m, int colorArr[])
    {
        if (stand == vertex)
        {
            // print the colorarr
            return;
        }
        for (int i = 1; i <= m; i++)
        {

            if (checkcolorofnei(stand, i, colorArr) == true)
            {
                colorArr[stand] = i;
                solver(stand + 1, m, colorArr);

                colorArr[stand] = 0;
            }
        }
        return;
    }
    void mcolor(int m)
    {
        int colorArr[vertex] = {0};

        int stand = 0;
        solver(stand, m, colorArr);
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

        while (que.empty() != true)
        {
            int stand = que.front();
            que.pop();
            cout << stand << " ";

            // look at nei
            for (int j = 0; j < adjlist->at(stand).size(); j++)
            {
                int next = adjlist->at(stand).at(j);
                if (vis[next] == -1)
                {
                    que.push(next);
                    vis[next] = 1;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < this->vertex; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adjlist->at(i).size(); j++)
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

bool safe(int x, int y, vector<vector<int>> &board, int n)
{
}
void queen(int col, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        // print board
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (safe(i, col, board, n) == true)
        {
            board[i][col] = 1;
            queen(col + 1, board, n);
            board[i][col] = 0;
        }
    }
}

void nqueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));

    queen(0, board, n);
}

int main()
{
    int n = 4;
    nqueens(n);
}