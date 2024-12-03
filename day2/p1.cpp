#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void checkDesc(vector<vector<int>> arr, int report, int &result){
	for(int i = 0; i < arr[report].size()-1; i++){
		// Check for Descending and large differences
		if(arr[report][i] <= arr[report][i+1] || arr[report][i] - arr[report][i+1] > 3){
			cout << "Report " << report << " is not safe." << endl;
			return;
		}
	}
	cout << "Report " << report << " is safe." <<  endl;
	result++;
	return;
}

void checkAsc(vector<vector<int>> arr, int report, int &result){
	for(int i = 0; i < arr[report].size()-1; i++){
		// Check for Ascending and large difference
		if(arr[report][i] >= arr[report][i+1] || arr[report][i+1] - arr[report][i] > 3){
			cout << "Report " << report << " is not safe." << endl;
			return;
		}
	}
	cout << "Report " << report << " is safe." << endl;
	result++;
	return;
}

int main(){

	//Init data
	vector<vector<int>> data;
	vector<int> current;
	ifstream input("input");
	string line;
	int num;
	int repNum = 0;
	
	while(input.peek() != EOF){
		getline(input, line);
		stringstream stream(line);
		while(stream >> num){
			current.push_back(num);
		}
		data.push_back(current);
		current.erase(current.begin(), current.end());
		repNum++;
	}

	int result = 0;

	for(int i = 0; i < data.size(); i++){
		if(data[i][0] == data[i][1]){ cout << "Report " << i << " is unsafe." << endl;}
		if(data[i][0] > data[i][1]){ checkDesc(data, i, result);}
		if(data[i][0] < data[i][1]){ checkAsc(data, i, result);}
	}

	cout << result << endl;
}
