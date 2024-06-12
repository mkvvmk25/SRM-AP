#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int aId;
    int starta;
    int enda;
};

bool compare(struct item i1, struct item i2)
{
    return i1.enda < i2.enda; 
}

int main()
{
    struct item activities[] = {{1, 3, 4},   // 2
                          {2, 1, 10},   // 3
                          {3, 1, 40},  // 0
                          {4, 1, 30} }; // 1

    
    int n = 10;
    
    sort(activities, activities + n, compare); 

    int lae = activities[0].enda;
    vector<int> acts; 
    acts.push_back(  activities[0].aId    ); 
    for(int i = 1; i < n; i++)
    {
        if( lae <= activities[i].starta )
        {
            acts.push_back( activities[i].aId); 
            lae = activities[i].enda; 
        }
    }

    // print(acts) 
 
}
