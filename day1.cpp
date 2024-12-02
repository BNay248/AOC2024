#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Comparison function for qsort
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
	const int LIST_SIZE = 10;
	const int MAXNUM = 100;

	// Seed time
	srand(time(0));

	// Init lists
	int leftList[LIST_SIZE];
	int rightList[LIST_SIZE];
	
	// Randomize lists
	for(int i = 0; i < LIST_SIZE; i++){
		leftList[i] = rand() % LIST_SIZE + 1;
	}
	for(int i = 0; i < LIST_SIZE; i++){
		rightList[i] = rand() % LIST_SIZE + 1;
	}

	// Sort lists
	qsort(leftList, LIST_SIZE, sizeof(int), compare);
	qsort(rightList, LIST_SIZE, sizeof(int), compare);
	
	// Calculate distance
	int totalDistance = 0;
	for(int i = 0; i < LIST_SIZE; i++){
		cout << leftList[i] << "    " << rightList[i] << endl;
		totalDistance += abs(leftList[i] - rightList[i]);
	}

	cout << "Total Distance: " << totalDistance << endl;
}
