#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xadd[] = {0,1,0,-1}; 
int yadd[] = {1,0,-1,0}; 



class trie
{
    public: 
        vector<trie*> nodes; 
        bool wordFinish; 
        trie()
        {
            this->nodes.resize(26,nullptr);
            wordFinish = false; 
        }

        void insert(string s, trie *obj)
        {
            trie *currObj = obj; // 5001 , 1001, 2001, 3001
            for(int i = 0; i < s.size(); i++)
            {
                char ch = s[i]; // 'd'
                int ind = ch - 'a'; // 0

                if(currObj->nodes[ind] == nullptr)
                {
                    trie *newnode = new trie(); // 6001
            
                    currObj->nodes[ind] = newnode; 
                    currObj = newnode; 
                }
                else {
                    currObj = currObj->nodes[ind]; 
                }
            }
            currObj->wordFinish = true;

        }
    
    bool search(string s, trie *obj) // ad
    {
            trie *currobj = obj; // 5001
            for (int i = 0; i < s.size(); i++)
            {
                char ch = s[i];     // a'd'  d
                int ind = ch - 'a'; // 0
                if( currobj->nodes[ind] != nullptr)
                {
                    currobj = currobj->nodes[ind]; // 1001 2001
                }
                else 
                {
                    return false; 
                }
            return currobj->wordFinish; 
            }
    }
};

int main()
{
    vector<string> p = {"add","aim","addidas", "bad", }; 
    trie obj = trie(); // 5001
    obj.insert(p[0], &obj);  
    cout << obj.search(p[0], &obj);  
    return 0;
}