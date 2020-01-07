//
//  strings_with_constraint_iterative.cpp
//
//  Created by omlenka on 05/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

int countStrings(int n, int bCount, int cCount)
{
    int row = bCount + 1,  col = cCount+1;
    int dp[n+1][row][col];
    
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j<row;j++)
        {
            for(int k = 0;k<col;k++)
            {
                if(j == 0 && k == 0)
                    dp[i][j][k] = 1;
                else
                    dp[i][j][k] = 0;
            }
        }
    }
    
    for(int i= 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(i != 0 && j != 0)
                dp[1][i][j] = 3;
            else if(i == 0 && j == 0)
                dp[1][i][j] = 1;
            else if(i == 0 || j == 0)
                dp[1][i][j] = 2;
            else
                dp[1][i][j] = 0;
            
        }
    }
    
    for(int i = 2;i<n+1;i++)
    {
        for(int j = 0;j<row;j++)
        {
            for(int k = 0;k<col;k++)
            {
                int res = 0;
                if(j >= 1)
                    res += dp [i-1][j-1][k];
                if(k>=1)
                    res += dp[i-1][j][k-1];
                
                res += dp[i-1][j][k];
                
                dp[i][j][k] = res;
            }
        }
    }
    
//    for(int i = 1;i<n+1;i++)
//    {
//        for(int j = 0;j<row;j++)
//        {
//            for(int k = 0;k<col;k++)
//            {
//                cout << dp[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        
//        cout << "----------" << endl << endl;
//    }
    
    return dp[n][row-1][col-1];
}

int main() {
    int T;
    cin >> T;
    
    while(T--)
    {
        int n;
        cin >> n;
        
        cout << countStrings(n, 1, 2) << endl;
    }
    return 0;
}
