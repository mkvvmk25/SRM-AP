#include <iostream>
#include <algorithm>
using namespace std;

int fib(int n, vector<int> &memo)
{
    if (n == 1 || n == 2)
    {
        return memo[n];
    }
    else if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fib(n - 2, memo) + fib(n - 1, memo);
    return memo[n];
}

void fun(int s, int n, vector<int> &coins, vector<int> &store, vector<int> &dp)
{
    if (dp[s] != INT_MAX)
    {
        // print(store)
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int rem = s - coins[i];
        if (rem >= 0) // rem = 0
        {
            // store.push_back(coins[i]);
            fun(rem, n, coins, store, dp); // ened
            // store.pop_back();
            if (dp[rem] != INT_MAX)
            {
                dp[s] = min(dp[rem] + 1, dp[s]);
            }
        }
    }
}

int dpfun(int s, int n, vector<int> &coins)
{
    vector<int> dp(s + 1, INT_MAX);
    for (int probs = 1; probs <= s; probs++)
    {
        for (int ops = 0; ops < n; ops++)
        {
            int rem = probs - coins[ops];
            if (rem >= 0)
            {
                dp[probs] = min(dp[rem] + 1, dp[probs]);
            }
        }
    }
    return dp[s];
}

int insub(int cur, int prev, int n,
          vector<int> &sub, vector<int> &store,
          int dp[][5])
{
    if (cur == n)
    {
        // print(store)
        return 0;
    }
    else if (dp[cur][prev + 1] != -1)
    {
        return dp[cur][prev + 1];
    }

    // take
    int take = 0;
    if (prev == -1 || sub[cur] > sub[prev])
    {
        store.push_back(sub[cur]);
        take = 1 + insub(cur + 1, cur, n, sub, store, dp);
        store.pop_back();
    }
    // dont take
    int donttake = 1 + insub(cur + 1, prev, n, sub, store, dp);
    return max(take, donttake);
}
void subse(int n, vector<int> sub)
{

    int dp[n] = {1}; 
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if( sub[i] > sub[j] && 
                dp[i] <= dp[j])
                {
                    dp[i]  = 1 + dp[j]; 
                }
        }
    }

    // traverse the arr of max 
    
}

int main()
{
    int n = 4;
    vector<int> sub = {0, 1, 1, 1, 4, 3};
    vector<int> store;
    int dp[n][n + 1];
    int maxsub = 0;
    insub(0, -1, n, sub, store, dp);
}