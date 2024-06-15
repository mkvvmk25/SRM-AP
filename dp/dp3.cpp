#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

/* int knapsack(int n, int w, int profit[], int weight[])
{
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for (int items = 1; items < n + 1; items++)
    {

        int wi = weight[items - 1];
        int pi = profit[items - 1]; 
        for(int sacks = 0; sacks < w+1; sacks++) // j = 4
        {    
            if( wi  <= sacks )
            {
                int rw = sacks - wi; 
                int cp =  pi + dp[items - 1][rw];  
                dp[items][sacks] = max(cp , dp[items - 1][sacks]);
            }
            else 
            {
                dp[items][sacks] = dp[items-1][sacks]; 
            }
        }
    }

    return dp[n][w]; 
}

int maxsubsq(vector<vector<int>> &mat, int n , int m)
{
    // vector<vector<int>> dp(num of rows )
    vector<vector<int>> dp(n + 1,vector<int>(m+1, 0)); 
    int maxsize = 0; 
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            if( mat[x][y] == 0)
            {
                dp[x+1][y+1] = 0; 
            }
            else 
            {
                int dpx = x + 1;
                int dpy = y + 1; 
                int left = dp[dpx][dpy - 1]; 
                int dia = dp[dpx-1][dpy - 1]; 
                int top = dp[dpx - 1][dpy]; 

                dp[dpx][dpy] = min(left, top, dia) + 1 ;
                maxsize = max(maxsize, dp[dpx][dpy]);
            }
        }

        return maxsize; 
    }

} */

int minEdits(string s1, string s2)
{
    int s1len = s1.size(); // 5  for columns 
    int s2len = s2.size(); // 6  for rows

    vector<vector<int>> dp(s2len + 1, vector<int>(s1len + 1, 0));

    for(int i = 0; i < s1len + 1; i++)
    {
        dp[0][i] = i; 
    }

    for(int i = 0; i < s2len + 1; i++)
    {
        dp[i][0] = i; 
    }

    for(int i = 1; i < s2len + 1; i++) // s2
    {
        for(int j = 1; j < s1len + 1; j++) // s1 
        {
            if( s2[i-1] == s1[j-1])
            {
                dp[i][j] = dp[i-1][j-1]; 
            }
            else 
            {
                int top = dp[i-1][j];
                int left = dp[i][j-1];
                int dia = dp[i-1][j-1];
                dp[i][j] = min(top, dia, left) + 1 ; 
            }
        }
    }
    return dp[s2len][s1len]; 
}
class pop
{
};
int main()
{
    
    pop k;
    cout << sizeof(k); 
    return 0;
}
