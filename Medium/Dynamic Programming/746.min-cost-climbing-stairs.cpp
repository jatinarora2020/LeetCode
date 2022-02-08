class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

    	vector<int> lDpCost;
    	int lSize = cost.size();
    	//Base Case
    	lDpCost.push_back(cost[lSize - 1]);
    	lDpCost.push_back(cost[lSize - 2]);
    	for(int i = lSize - 3; i >=0 ; i--)
    	{
    		cost[i] += (cost[i+1] > cost[i+2] ? cost[i+2] : cost[i+1]);
    		lDpCost.push_back(cost[i]);
    	}
    	return (lDpCost[lDpCost.size() -1] > lDpCost[lDpCost.size() - 2 ] ? lDpCost[lDpCost.size() - 2 ] : lDpCost[lDpCost.size() - 1]);
    }
};


int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Solution s;
	vector<int> cost = {10,15,20};
	cout << s.minCostClimbingStairs(cost);
	return 0;
}
