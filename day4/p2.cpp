#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	ifstream file("input");
	string line;
	vector<char> vecLine;
	vector<vector<char>> board;

	//Get file to 2d vector
	while(getline(file, line)){
		for(char el: line)
			vecLine.push_back(el);
		board.push_back(vecLine);
		vecLine.erase(vecLine.begin(), vecLine.end());
	} file.close();
	
	//Find XMAS strings
	int count = 0;
	for(int row = 1; row < board.size()-1; row++){
		for(int col = 1; col < board[row].size()-1; col++){
			//Check A only
			if(board[row][col] == 'A'){
				if(board[row-1][col-1] == 'M' && board[row-1][col+1] == 'S' && board[row+1][col-1] == 'M' && board[row+1][col+1] == 'S') count ++;
			}
			if(board[row][col] == 'A'){
				if(board[row-1][col-1] == 'M' && board[row-1][col+1] == 'M' && board[row+1][col-1] == 'S' && board[row+1][col+1] == 'S') count ++;
			}
			if(board[row][col] == 'A'){
				if(board[row-1][col-1] == 'S' && board[row-1][col+1] == 'S' && board[row+1][col-1] == 'M' && board[row+1][col+1] == 'M') count ++;
			}
			if(board[row][col] == 'A'){
				if(board[row-1][col-1] == 'S' && board[row-1][col+1] == 'M' && board[row+1][col-1] == 'S' && board[row+1][col+1] == 'M') count ++;
			}
		}
	}
	cout << count << endl;
}
