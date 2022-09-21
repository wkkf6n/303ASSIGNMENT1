



#include "functions.h"

#include<iostream>

#include<fstream>

using namespace std;



/*
* This function will read the content of file that are integers
and store them in an array and return it
*/




int** readFile()
{
	int** data = new int*[10];
	for (int i = 0; i < 10; i++)
		data[i] = new int[10];
	ifstream ifile("data.txt");
	int i = 0, j = 0;
	while (!ifile.eof())
	{
		ifile >> data[i][j];
		if (j == 9)
		{
			i++;
			j = 0;
		}
		else
			j++;


	}
;
	return data;
}

/*
This function will recieve the pointer array as parameter then it will ask
user for a value to search, if found it will return it's index or return -1 instead
*/
int* findNumber(int **data)
{
	int num;
	cout << "Please enter number to search: ";
	cin >> num;

	int index1 = -1, index2 = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (data[i][j] == num)
			{
				index1 = i;
				index2 = j;
			}
	}

	static int index[]{ index1,index2 };
	return index;
}

/*
This function will recieve the pointer array as parameter and the index to change
then it will ask user for a new value, after changing it will return a pointer array of size 2
that will contain old value as well as the new one
*/
int* changeNumber(int **data, int rindex, int cindex)
{
	int newNum;
	cout << "Please enter the new number: ";
	cin >> newNum;

	int oldNum = data[rindex][cindex];
	data[rindex][cindex] = newNum;

	static int nums[]{ oldNum,newNum };
	return nums;
}

/*
A simple function that will recieve pointer to array, it will ask for a new value to add
then create a new array with size + 1 and copy the content of array in new array and store the
new value at the end of new array, after it will assign old array to the new one and return it
*/
int** addNumber(int **data)
{
	int newNum;
	cout << "Please enter the number to add: ";
	cin >> newNum;

	int *newData = new int[11];
	for (int i = 0; i < 10; i++)
	{
		newData[i] = data[9][i];
	}
	newData[10] = newNum;

	data[9] = newData;
	return data;
}

/*
A simple function that will recieve pointer to array and an index,
then create a new array with size - 1 and copy the content of array in new array except for the index to delete
then it will return the old array back
*/
int** deleteNumber(int** data, int rind, int cind)
{
	data[rind][cind] = 0;
	return data;
}

/*Main Function*/
int main()
{
	//Reading the content of file in data array
	int **data = readFile();
	//Printing the contents of initial array
	cout << "Content of Array:\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << data[i][j] << " ";

		cout << endl;
	}
	cout << endl;
	//Checking if the number user tried to find existed or not
	int* ind = findNumber(data);
	if (ind[1] == -1 || ind[0] == -1)
		cout << "Sorry Number is not in data\n";
	else
		cout << "Number found at index: " << ind[0] << " " << ind[1] << endl;

	//Asking user for the index at which value wanted to be changed and printing old and new value
	int rind,cind;
	cout << "Please enter row index to change (1-10): ";
	cin >> rind;
	cout << "Please enter column index to change (1-10): ";
	cin >> cind;
	int* nums = changeNumber(data, rind, cind);
	cout << "Old Value: " << nums[0] << "\t" << "New Value: " << nums[1] << endl;

	data = addNumber(data);

	cout << "Please enter row index to delete (1-10): ";
	cin >> rind;
	cout << "Please enter column index to delete (1-10): ";
	cin >> cind;
	data = deleteNumber(data, rind, cind);


	//Printing content of final array
	cout << "\nContent of Array:\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << data[i][j] << " ";

		if (i == 9)
			cout << data[i][10];
		cout << endl;
	}
}

