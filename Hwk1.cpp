//C:\\Users\\jorda\\Documents\\Visual Studio 2015\\Projects\\DataStructures-Hw1\\prez.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef string prezname;
int n, where;
bool found;
prezname prez[80];
ifstream fin;
ofstream fout;
// The big three algorithms declarations
prezname keyname;
void binarySearch(prezname, bool&, int&);
void insertion(prezname);
void deletion(prezname);
string temp;
string question = "What is the name you wish to ";



// Main loop begins
void main(prezname keyname, bool&found, int&where)
{
	
	int i = 1;
	string name;
	fin.open("C:\\Users\\jorda\\Documents\\Visual Studio 2015\\Projects\\DataStructures-Hw1\\prez.txt");
	//fout.open("C:\\Users\\jorda\\Documents\\Visual Studio 2015\\Projects\\Data-Structrues-And-Algorithms\\Homework1\\Results.txt");
	fin >> name;

	// read in pres name and assign it to the array
	while (!fin.eof())
	{
		prez[i] = name;
		i++;
		n++;
		fin >> name;
	}
	// Sorting algorithm
	for (int bottom = n - 1;bottom > 0;bottom--)
	{
		int maxIndex = 0;
		for (int i = 1;i <= bottom;i++)
		{
			if (prez[i] > prez[maxIndex])
				maxIndex = i;
			temp = prez[maxIndex];
			prez[maxIndex] = prez[bottom];
			prez[bottom] = temp;
		}
	}
	// Interface
	int choice = 0;
	cout << "HomeWork-1, Inserting, Deleting, and Searching in a singular array " << endl << endl;
	cout << "This program consists of an alphalbetical list of our previous and current presidents " << endl;
	cout << "Below are options for you choose from, to manipulate the content in the array" << endl;
	cout << "1. Search" << endl << "2. Insert" << endl << "3. Delete" << endl << "4. Print Updated List" << endl << "5. Exit" << endl;
	cout << "please choose from one of the above" << endl;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
		{
			cout << question << " find" << endl;
			cin >> keyname;
			binarySearch(keyname, found, where);
			if (found)
			{
				cout << keyname << " can be found at slot: " << where << endl;
				system("pause");
			}
			else
				cout << keyname << "not found" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << question << "insert" << endl;
			cin >> keyname;
			insertion(keyname);
			system("pause");
			break;
		}
		case 3:
		{
			cout << question << "delete" << endl;
			cin >> keyname;
			deletion(keyname);
			system("pause");
			break;
		}
		case 4:
		{
			for (int i = 1; i < n; i++)
				cout << prez[i] << endl;
			system("pause");
			break;
		}

		}

	}
}
	/*for (int j = 0;j < n;j++)
	{
	cout << prez[j] << endl;
	}
	system("pause");*/


void binarySearch(prezname keyname, bool&found, int&where)
{

	int top = 1, bottom = n;
	found = false;
	while (!found&& top <= bottom)
	{
		int mid = (top + bottom) / 2;

		if (prez[mid] == keyname)
		{
			found = true;
			where = mid;
		}
		else
			if (prez[mid] < keyname)
				top = mid + 1;
			else
				bottom = mid - 1;
	}
}

void insertion(prezname keyname)
{
	bool found;
	int where;
	binarySearch(keyname, found, where);
	if (found)
	{
		cout << "found" << endl;
		cout << "cannot insert" << endl;
	}
	else
	{
		for (int i = n;i >= where;i--)
		{
			prez[i + 1] = prez[i];
			prez[where] = keyname;
			n++;
		}
	}
}
void deletion(prezname keyname)
{
	bool found;
	int where;
	binarySearch(keyname, found, where);
	if (!found)
	{
		cout << keyname << " " << "not found";
	}
	else
	{
		//prez[where] = " ";
		for (int i = where;i <= n;i++)
		{
			prez[i] = prez[i+1];
		}
	}

	for (int j = 0;j < n;j++)
	{
		cout << prez[j] << endl;
	}
	system("pause");
}