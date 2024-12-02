#include <iostream>
using namespace std;

const int REPORTS = 6;
const int LEVELS = 5;

void checkDesc(int arr[REPORTS][LEVELS], int report){
	for(int i = 1; i < LEVELS-1; i++){
		// Check for Descending and large differences
		if(arr[report][i] <= arr[report][i+1] || arr[report][i] - arr[report][i+1] > 3){
			cout << "Report " << report << " is not safe." << endl;
			return;
		}
	}
	cout << "Report " << report << " is safe." <<  endl;
	return;
}

void checkAsc(int arr[REPORTS][LEVELS], int report){
	for(int i = 1; i < LEVELS-1; i++){
		// Check for Ascending and large difference
		if(arr[report][i] >= arr[report][i+1] || arr[report][i+1] - arr[report][i] > 3){
			cout << "Report " << report << " is not safe." << endl;
			return;
		}
	}
	cout << "Report " << report << " is safe." << endl;
	return;
}

int main(){

	//Init data
	int data[REPORTS][LEVELS];
	data[0][0] = 7; data[0][1] = 6; data[0][2] = 4; data[0][3] = 2; data[0][4] = 1;
	data[1][0] = 1; data[1][1] = 2; data[1][2] = 7; data[1][3] = 8; data[1][4] = 9;
	data[2][0] = 9; data[2][1] = 7; data[2][2] = 6; data[2][3] = 2; data[2][4] = 1;
	data[3][0] = 1; data[3][1] = 3; data[3][2] = 2; data[3][3] = 4; data[3][4] = 5;
	data[4][0] = 8; data[4][1] = 6; data[4][2] = 4; data[4][3] = 4; data[4][4] = 1;
	data[5][0] = 1; data[5][1] = 3; data[5][2] = 6; data[5][3] = 7; data[5][4] = 9;
	int result;

	for(int i = 0; i < REPORTS; i++){
		if(data[i][0] == data[i][1]){ cout << "Report " << i << " is unsafe." << endl;}
		if(data[i][0] > data[i][1]){ checkDesc(data, i);}
		if(data[i][0] < data[i][1]){ checkAsc(data, i);}
	}
}

