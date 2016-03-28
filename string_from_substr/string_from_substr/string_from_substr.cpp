// string_from_substr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<string>

using namespace std;

class LPSMaker
{
	string str;
	int *arr;
	void createLPS();
public:
	LPSMaker()
	{
		arr = NULL;
	}
	LPSMaker(string str)
	{
		this->str = str;
		createLPS();
	}

	~LPSMaker()
	{
		delete[] arr;
	}

	int* getLPS()
	{
		return arr;
	}
};

void LPSMaker::createLPS()
{
	arr = new int[str.length()];
	int j = 0, i = 1;

	arr[0] = 0;

	while(i<str.length())
	{
		if(str[i] == str[j])
		{
			j++;
			arr[i++] = j;
		}
		else
		{
			if(j == 0)
			{
				arr[i++] = 0;
			}
			else
			{
				j = arr[j-1];
			}
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
		LPSMaker lps(s);
		int *arr = lps.getLPS();
		int len = arr[s.length()-1];

		if((len != 0) && (s.length() % (s.length()-len) == 0))
			cout << "True";
		else
			cout << "False";

		cout << endl;
	}

	return 0;
}

