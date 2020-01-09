//
//  subarray_with_given_sum
//
//  Created by omlenka on 09/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int,int> findSubArray(vector<int> v, int sum)
{
    int start = 0;
    int curr_sum = v[0];
    
    for(int i = 1;i<=v.size();i++)
    {
        while(curr_sum > sum && start < i-1)
        {
            curr_sum -= v[start];
            start++;
        }
        
        if(curr_sum == sum)
            return make_tuple(start+1, i);
        
        if(i!=v.size())
            curr_sum += v[i];
    }
    
    return make_tuple(-1,-1);
    
}

int main() {
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int n, sum;
        cin >> n >> sum;
        vector<int> v(n);
        
        for(int i =0;i<n;i++)
            cin >> v[i];
        
        tuple<int, int> res = findSubArray(v, sum);
        int start = get<0>(res);
        int end = get<1>(res);
        
        if(start!=-1 && end!=-1)
            cout << start << " "  << end;
        else
            cout << start;
        cout << endl;
        
    }
    return 0;
}
