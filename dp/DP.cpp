#include <iostream>
#include <algorithm>
using namespace std;

int fib(int n, vector<int> &memo)
{
    if(n == 1 || n == 2 )
    {
        return memo[n];  
    }
    else if( memo[n] != -1)
    {
        return memo[n]; 
    }
    memo[n] = fib(n - 2, memo) + fib(n - 1, memo);
    return memo[n]; 
}

void fun(int s, int n, vector<int> &coins, vector<int> &store, vector<int> &dp)
{
    if( dp[s] != INT_MAX)
    {
        // print(store)
        return; 
    }
    for(int i = 0; i < n; i++)
    {
        int rem = s -coins[i]; 
        if( rem >= 0)  // rem = 0
        {
            // store.push_back(coins[i]); 
            fun(rem, n, coins, store, dp); // ened
            // store.pop_back(); 
            if(dp[rem] != INT_MAX)
            {
                dp[s] = min( dp[rem] + 1,  dp[s]); 
            }
        }
    }
}


// void fun(int s, int n, vector<int> &coins, vector<int> &store, vector<int> &dp)
// {
//     if( dp[s] != INT_MAX)
//     {
//         // print(store); 
//         return; 
//     }
//     for(int i = 0; i < n; i++)
//     {
//         int rem = s -coins[i]; 
//         if( rem >= 0)
//         {
//             store.push_back(coins[i]); 
//             fun(rem, n, coins, store, dp); 
//             store.pop_back(); 
//             if( dp[rem] != INT_MAX)
//             {
//                 dp[s] = min(dp[s], dp[rem] + 1); 
//             }
//         }
//     }
// }
int main()
{
    int n = 4; 
    vector<int> coins = {5,1,4,3}; 
    int s = 7; 
    vector<int> store;  
    vector<int> dp(s+1, INT_MAX); 
    dp[0] = 0;
    fun(s, n, coins, store, dp); 
    cout << dp[s]; 

}