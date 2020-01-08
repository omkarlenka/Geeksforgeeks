//
//  find_largest_word_in_dictionary_recursive.cpp
//
//  Created by omlenka on 08/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findSubsequence(string s1, string s2,  size_t l1, size_t l2)
{
    if(l1 > l2)
        return false;
    
    if(s1[l1-1] == s2[l2-1])
    {
        if(l1 == l2)
            return true;
        else
            return findSubsequence(s1, s2, l1-1, l2-1);
    }
    return findSubsequence(s1, s2, l1, l2-1);
}

string findLargestWord(vector<string> v, string str)
{
    string largestWord;
    size_t largestLen = 0;
    size_t str_len = str.length();
    
    vector<string>::iterator itr;
    for(itr = v.begin();itr<v.end();itr++)
    {
        size_t wordLength = (*itr).length();
        if(findSubsequence(*itr, str, wordLength, str_len))
        {
            if(wordLength > largestLen)
            {
                largestWord = *itr;
                largestLen = wordLength;
            }
        }
    }
    
    return largestWord;
}

int main() {
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int x;
        cin >> x;
        vector<string> v;
        for(int i = 0;i<x;i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        string str;
        cin >> str;
        
        cout << findLargestWord(v, str) << endl;
    }
    
    return 0;
}
