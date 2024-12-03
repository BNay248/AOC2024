#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){

	// Init lists
	vector<int> leftList;
	vector<int> rightList;

	// Sort into lists
	bool flag = true;
	int nextInt;
	ifstream input("input");
	while(input >> nextInt){
		if(flag){leftList.push_back(nextInt);}
		else {rightList.push_back(nextInt);}
		flag = !flag;
	}
	
	// Calculate similarity score
	int simScore = 0;
	for(int i = 0; i < leftList.size(); i++){
		simScore += (leftList[i] * count(rightList.begin(), rightList.end(), leftList[i]));
	}

	cout << "Similarity Score: " << simScore << endl;
}
