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
	for(int row = 0; row < board.size(); row++){
		for(int col = 0; col < board[row].size(); col++){
	//North
			if(row > 2){
				if(board[row][col] == 'X' && board[row-1][col] == 'M' && board[row-2][col] == 'A' && board[row-3][col] == 'S') count++;
			}
	//South
			if(row < board.size() - 3){
				if(board[row][col] == 'X' && board[row+1][col] == 'M' && board[row+2][col] == 'A' && board[row+3][col] == 'S') count++;
			}
	//East
			if(col < board[row].size() - 3){
				if(board[row][col] == 'X' && board[row][col+1] == 'M' && board[row][col+2] == 'A' && board[row][col+3] == 'S') count++;
			}
	//West
			if(col > 2){
				if(board[row][col] == 'X' && board[row][col-1] == 'M' && board[row][col-2] == 'A' && board[row][col-3] == 'S') count++;
			}
	//Ne
			if(row > 2 && col < board[row].size() - 3){
				if(board[row][col] == 'X' && board[row-1][col+1] == 'M' && board[row-2][col+2] == 'A' && board[row-3][col+3] == 'S') count++;
			}
	//Nw
			if(row > 2 && col > 2){
				if(board[row][col] == 'X' && board[row-1][col-1] == 'M' && board[row-2][col-2] == 'A' && board[row-3][col-3] == 'S') count++;
			}
	//Se
			if(row < board.size() - 3 && col < board[row].size() - 3){
				if(board[row][col] == 'X' && board[row+1][col+1] == 'M' && board[row+2][col+2] == 'A' && board[row+3][col+3] == 'S') count++;
			}
	//Sw
			if(row < board.size() - 3 && col > 2){
				if(board[row][col] == 'X' && board[row+1][col-1] == 'M' && board[row+2][col-2] == 'A' && board[row+3][col-3] == 'S') count++;
			}
		}
	}
	cout << count << endl;
}
