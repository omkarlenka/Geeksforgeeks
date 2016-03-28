// number_from_patter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Pattern
{
	string ptr;
	int max;

	int getConsD(int i);//return consecutive D's from index i
public:
	Pattern(){}
	Pattern(string ptr)
	{
		this->ptr = ptr;
		max = 0;
	}
	void printNum();
};

int Pattern::getConsD(int j)
{
	int i;
	for(i = j;i<ptr.length();i++)
	{
		if(ptr[i] != 'D')
			break;
	}
	return (i-j);
}

void Pattern::printNum()
{
	if(ptr.length() == 0)
		return;
	for(int i = 0;i<ptr.length();i++)
	{
		if(ptr[i] == 'I')
		{
			if(i == 0)
			{
				max = 1;
				cout << max;
			}
			if(i+1 < ptr.length() && ptr[i+1] == 'I')
			{
				max = max + 1;
				cout << max;
			}
			else if(i+1 < ptr.length() && ptr[i+1] == 'D')
			{
				//int d = getConsD(i+1);
				//max = max+d+1;
				//cout << max;
			}
			else
			{
				cout << max+1;
			}
		}
		else
		{
			int d = getConsD(i);
			int temp_max = max;
			max += d+1;
			while(max > temp_max)
			{
				cout << max;
				max--;
			}
			max = temp_max+d+1;
			i += d-1;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		Pattern P(s);
		P.printNum();
		cout << endl;
	}
	return 0;
}

