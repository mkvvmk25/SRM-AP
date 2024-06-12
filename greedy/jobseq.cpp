#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int jId;
    int dline;
    int profit;
};

bool compare(struct item i1, struct item i2)
{
    return i1.profit > i2.profit; 
}

int main()
{
    struct item jobs[] = {{1, 4, 20},   // 2
                          {2, 1, 10},   // 3
                          {3, 1, 40},  // 0
                          {4, 1, 30} }; // 1

    
    int n = 4;


    int maxDead = jobs[0].dline;

    for(int i = 1; i < n; i++)
    {
        if( maxDead < jobs[i].dline) 
        {
            maxDead = jobs[i].dline; 
        }
    }

    int slots[maxDead + 1] = {0}; 

    sort(jobs, jobs + n, compare );
     
    int sumProfit = 0; 
    int occupied = 0; 
    for(int i = 0; i < n ;i++)
    {
        int j = jobs[i].dline; // 1 
        while( j!=0 && slots[j] != -1 )
        {
            j--;
        }

        if(j > 0)
        {
            slots[j] = jobs[i].jId; 
            occupied++; 
            sumProfit += jobs[i].profit; 
        }

    }

    cout << sumProfit <<"  " << occupied; 

     


 
}