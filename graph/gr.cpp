#include<iostream>
#include<vector>
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
            adjlist->push_back( vector<int>() )
        
        }

        void addEdge(int src, int des)
        {
            adjlist->at(src).push_back(des);
            adjlist->at(des).push_back(src); 
            edges += 2; 
        }

        void print( )
        {
            for(int i = 0; i < this->vertex; i++)
            {
                cout << i <<": "; 
                for(int j = 0; j < adjlist->at(i).size(); j++ )
                {
                    cout << adjlist->at(i).at(j); 
                }

                cout << endl;
            }
        }
};


int main()
{
    GraphUD g = GraphUD(5); 
    g.addEdge(0,1); 
    g.addEdge(0,1); 
    g.addEdge(0,2); 
    g.addEdge(3,4); 
    g.addEdge(2,1); 
    g.addEdge(2,3); 
    g.addEdge(2,4); 


    vector<int> p; 
    vector<int> *p1 = new vector<int>(5,0);  
    p1->push_back(5); 

    return 0; 
}