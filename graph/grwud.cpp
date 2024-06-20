#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
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
        // 
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

    void krushkals()
    {
        vector<vector<int>> edges;
        // see all the vertex connection
        for (int stand = 0; stand < vertex; stand++)
        {
            for (int i = 0; i < adjlist->at(stand).size(); i++)
            {
                vector<int> nei = adjlist->at(stand).at(i);
                int wght_n = nei[0];
                int stand_n = nei[1];
                edges.push_back({wght_n, stand_n, stand});
            }
        }

        sort(edges.begin(), edges.end());
        vector<vector<int>> store;
        setbysize obj(vertex);
        for (int ed = 0; ed < edges.size(); ed++)
        {
            int src = edges[ed][1];
            int des = edges[ed][2];
            int wgt = edges[ed][0];

            if (obj.unionbysize(src, des) == true)
            {
                store.push_back(edges[ed]); 
            }
        }

        // print store 
    }
};

class setbysize
{
public:
    int vertex;
    int *size;
    int *par;

    setbysize(int n)
    {
        vertex = n;
        size = new int[n];
        par = new int[n];
        for (int i = 0; i < n; i++)
        {
            size[i] = 1;
            par[i] = i;
        }
    }
    //                        3
    int findParent(int ver)
    {

        while (par[ver] != ver)
        {
            ver = par[ver];
            //     2 1 0
        }

        return ver;
    }

    bool unionbysize(int src, int des)
    {
        int end_src_par = findParent(src);
        int end_des_par = findParent(des);

        if (end_des_par != end_src_par)
        {
            // connection
            // check the size
            if (size[end_des_par] > size[end_src_par])
            {
                // src----->des
                size[end_des_par] = size[end_des_par] + size[end_src_par];
                par[end_src_par] = end_des_par;
            }
            else
            {
                size[end_src_par] = size[end_des_par] + size[end_src_par];
                par[end_des_par] = end_src_par;
            }

            return true;
        }

        return false;
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