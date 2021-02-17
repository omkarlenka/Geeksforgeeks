//
//  spirally_traversing_matrix.cpps
//
//  Created by omlenka on 17/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        int start_r = 0, start_c = 0;
        vector<int> res;
        int no_of_elements = r*c;
        while(res.size() < no_of_elements){
            //left to right
            for(int j = start_c;j<start_c+c;j++){
                if(res.size() == no_of_elements)
                    break;
                res.push_back(matrix[start_r][j]);
            }
            //top tp bottom
            for(int i = start_r+1;i<start_r+r;i++){
                if(res.size() == no_of_elements)
                    break;
                res.push_back(matrix[i][c+start_c-1]);
            }
            //right to left
            for(int j = c+start_c-2;j>=start_c;j--){
                if(res.size() == no_of_elements)
                    break;
                res.push_back(matrix[r+start_r-1][j]);
            }
            //bottom to top
            for(int i = r+start_r-2;i>start_r;i--){
                if(res.size() == no_of_elements)
                    break;
                res.push_back(matrix[i][start_c]);
            }
            r -= 2;
            c -= 2;
            start_r++;
            start_c++;
        }
        return res;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r);
        
        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
