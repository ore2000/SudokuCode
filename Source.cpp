#include <iostream>
#include<vector>
#include<stack>
using namespace std;

const int baseSize = 9;

int num = 0;
int mat[baseSize][baseSize];
vector<int> sudokuNumbers;
int result = 0;
int blank = 0;
int arrayIndex = 0;


void checkFunc(vector<int>& vec, int val, bool& cond)
{
	if (cond)
	{
		if (val == 0)
		{

		}
		else if (val < 0 || val > 9)
		{
			cond = false;
			vec.clear();
			exit;
		}
		else
		{
			if (vec.empty())
			{
				vec.push_back(val);
			}
			else {
				for (int iter : vec)
				{
					if (iter == val)
					{
						cond = false;
						vec.clear();
						break;
					}
				}
				if (cond)
				{
					vec.push_back(val);
				}
			}
		}
	}
	
}

void checkBox(bool& condition)
{
	int start1 = 0;
	int stop1 = 3;
	int start2 = 0;
	int stop2 = 3;
	int value;
	vector<int>check;
	for (int g = 0; g < 9; g++)
	{
		for (int s = start1; s < stop1; s++)
		{
			for (int t = start2; t < stop2; t++)
			{
				value = mat[s][t];
				checkFunc(check, value, condition);
				if (!condition) break;
			}
			if (!condition) break;
		}
		if (!condition) break;
		check.clear();
		if (stop1 == 9)
		{
			start2 = stop2;
			stop2 = stop2 + 3;
			start1 = 0;
			stop1 = 3;
		}
		start1 = stop1;
		stop1 = stop1 + 3;
	}
}

void checkRow(bool& condition)
{
	vector<int>check;
	int value;

	for (int x = 0; x < baseSize; x++)
	{
		for (int y = 0; y < baseSize; y++)
		{
			value = mat[x][y];
			checkFunc(check, value, condition);
			if (!condition) break;
		}
		check.clear();
		if (!condition) break;
	}
}

void checkCol(bool& condition)
{
	vector<int>check;
	int value;
	for (int y = 0; y < baseSize; y++)
	{
		for (int x = 0; x < baseSize; x++)
		{
			value = mat[x][y];
			checkFunc(check, value, condition);
			if (!condition) break;
		}
		check.clear();
		if (!condition) break;
	}
}

void fillSudoku()
{
	for (int x = 0; x < baseSize; x++)
	{
		for (int y = 0; y < baseSize; y++)
		{
			mat[x][y] = sudokuNumbers[arrayIndex];
			arrayIndex++;
		}
	}
}

int main() {
	bool condition = true;
	int val;

	cin >> num;
	//determine the number of variables that will be entered.
	const int arraySize = num * baseSize * baseSize;

	//enter the sudoku values into the vector
	for (int i = 0; i < arraySize; i++)
	{
		cin >> val;
		sudokuNumbers.push_back(val);
	}

	//iterate through with the number of sudoku sets
	for (int i = 0; i < num; i++)
	{
		condition = true;
		//Fills up the matrix with the first set of values for the Sudoku
		fillSudoku();

		//Check rows to see if sudoku puzzle is valid
		checkRow(condition);

		//check the columns for repetision
		if(condition) checkCol(condition);

		//check boxes for repetision
		if(condition) checkBox(condition);

		cout << condition << "\n";
	}
	return 0;
}