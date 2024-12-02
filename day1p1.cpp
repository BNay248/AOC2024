#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){

	// Init lists
	vector<int> leftList;
	vector<int> rightList;

	bool flag = true;
	int nextInt;
	ifstream input("input.txt");
	while(input >> nextInt){
		if(flag){leftList.push_back(nextInt);}
		else {rightList.push_back(nextInt);}
		flag = !flag;
	}


	// Sort lists
	sort(leftList.begin(), leftList.end());
	sort(rightList.begin(), rightList.end());
	
	// Calculate distance
	int totalDistance = 0;
	for(int i = 0; i < leftList.size(); i++){
		cout << leftList[i] << "    " << rightList[i] << endl;
		totalDistance += abs(leftList[i] - rightList[i]);
	}

	cout << "Total Distance: " << totalDistance << endl;
}
