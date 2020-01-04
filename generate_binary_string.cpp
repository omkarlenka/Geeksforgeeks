//
//  generate_binary_string.cpp
//
//  Created by omlenka on 02/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

//Problem URL : https://practice.geeksforgeeks.org/problems/generate-binary-string/0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getBinStrings(string s1)
{
    vector<string> v1;
    
    size_t found = s1.find_last_of('?');
    
    if(found == string::npos)
    {
        v1.push_back(s1);
        return v1;
    }
    
    string pre = s1.substr(0, found);
    string post = s1.substr(found + 1);
    
    v1 = getBinStrings(pre);
    
    vector<string>::iterator itr;
    vector<string> v2;
    
    for(itr=v1.begin();itr!=v1.end();itr++)
    {
        v2.push_back(*itr + '0' + post);
        v2.push_back(*itr + '1' + post);
    }
    
    return v2;
}

int main() {
    int T;
    cin >> T;
    
    while(T--)
    {
        string s;
        cin >> s;
        
        vector<string> v = getBinStrings(s);
        vector<string>::iterator itr;
        for(itr = v.begin();itr!=v.end();itr++)
            cout << *itr << " ";
        
        cout << endl;
    }
    
    return 0;
}
