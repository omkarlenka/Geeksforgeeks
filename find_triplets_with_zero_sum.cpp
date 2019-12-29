//
//  find_triplets_with_zero_sum.cpp
//
//  Created by omlenka on 30/12/19.
//  Copyright © 2019 omkar lenka. All rights reserved.
//

//Problem URL: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

#include <iostream>

using namespace std;

bool findTriplet(int arr[], int n)
{
    sort(arr, arr+n);
    for(int i = 0; i< n-2; i++)
    {
        int l = 0, r = n-1;
        
        while(l < r)
        {
            if(l == i)
                l++;
            else if(r == i)
                r--;
            else
            {
                int sum = arr[l] + arr[r];
                if(sum == (-arr[i]))
                    return true;
                else if (sum < (-arr[i]))
                    l++;
                else
                    r--;
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    
    while(T--)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        cout << findTriplet(arr, n) << endl;
    }
    return 0;
}
