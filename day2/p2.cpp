#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int checkDesc(vector<vector<int>> arr, int report, int &result){
	for(int i = 0; i < arr[report].size()-1; i++){
		// Check for Descending and large differences
		if(arr[report][i] <= arr[report][i+1] || arr[report][i] - arr[report][i+1] > 3){
			return i;
		}
	}
	cout << "Report " << report << " is safe." <<  endl;
	result++;
	return -1;
}

int checkAsc(vector<vector<int>> arr, int report, int &result){
	for(int i = 0; i < arr[report].size()-1; i++){
		// Check for Ascending and large difference
		if(arr[report][i] >= arr[report][i+1] || arr[report][i+1] - arr[report][i] > 3){
			return i;
		}
	}
	cout << "Report " << report << " is safe." << endl;
	result++;
	return -1;
}


bool check(vector<vector<int>> arr, int report, int &result, bool first){
	int flag = checkAsc(arr, report, result);
	if(flag == -1){
		return true;
	} else if(first){
		// Check bounds
		if (flag < arr[report].size()) {
			// Remove flag
			int temp = arr[report][flag];
			arr[report].erase(arr[report].begin() + flag);
			if(checkAsc(arr, report, result) == -1) return true;
			arr[report].insert(arr[report].begin() + flag, temp);

			// Remove flag + 1
			if (flag + 1 < arr[report].size()) {
				temp = arr[report][flag + 1];
				arr[report].erase(arr[report].begin() + (flag + 1));
				if(checkAsc(arr, report, result) == -1) return true;
				arr[report].insert(arr[report].begin() + (flag + 1), temp);
			}
		}
	}

	flag = checkDesc(arr, report, result);
	if(flag == -1){
		return true;
	} else if(first){
		// Check Bounds
		if (flag < arr[report].size()) {
			// Remove flag
			int temp = arr[report][flag];
			arr[report].erase(arr[report].begin() + flag);
			if(checkDesc(arr, report, result) == -1) return true;
			arr[report].insert(arr[report].begin() + flag, temp);

			// Remove flag
			if (flag + 1 < arr[report].size()) {
				temp = arr[report][flag + 1];
				arr[report].erase(arr[report].begin() + (flag + 1));
				if(checkDesc(arr, report, result) == -1) return true;
				arr[report].insert(arr[report].begin() + (flag + 1), temp);
			}
		}
	}

    cout << "Report " << report << " is not safe." << endl;
    return false;
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
		check(data, i, result, true);
	}

	cout << result << endl;
}
