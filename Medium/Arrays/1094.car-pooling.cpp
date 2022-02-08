//============================================================================
// Name        : Leet_Car_Pooling.cpp
// Author      : jatin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

    	long long lResult[1001] = {0};
    	int i = 0;

    	vector<vector<int>>::iterator itr;

    	for(itr = trips.begin();itr != trips.end() ;itr++)
    	{
    		lResult[itr[0][1]] += itr[0][0];
    		lResult[itr[0][2]] -= itr[0][0];
    	}

    	for(int i = 1;i < 1001 ; i++)
    	{
    		lResult[i] += lResult[i-1];
    		if(lResult[i] > capacity)
    			return false;
    	}
    	return true;
    }
};

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Solution s;
	vector<vector<int>> trips = {{2,1,5},{3,3,7}};
	int capacity = 4;
	cout << s.carPooling(trips, capacity);
	return 0;
}
