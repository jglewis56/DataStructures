#include<iostream>
#include<string>
#include<fstream>
using namespace std;

typedef string prezname;
typedef struct cell *tref;
typedef struct cell { prezname pname; tref left, right; } tnode;
ifstream fin;
ofstream fout;

// function declarations
void tsearch(prezname, tref, bool&, tref&, tref &);
void insert(prezname, tref &);

//main function
void main()
{
	ifstream fin;
	ofstream fout;
	string name;
	tref root = NULL;
	fin.open("C:\\Users\\jorda\\Documents\\Visual Studio 2015\\Projects\\DataStructures and Algorithms\\prez.txt");
	while (!fin.eof())
	{
		prezname keyname;
		fin >> keyname;
		insert(keyname, root);
	}

	tref queue[30]; 
	int head = 0;  
	int tail = 1; 
	int counter = 0; 
	queue[head] = root; 
	counter++; 
	while (counter != 0)
	{
		cout << "President" << " " << queue[head]->pname << " ";
		
		if (queue[head]->left == NULL)
			cout << "Left kid" << " " << "NULL" << " ";
		else
		{
			cout << "Left kid" << " " << queue[head]->left->pname << " ";
			queue[tail] = queue[head]->left;
			counter++;
			if (tail == 29)
				tail = 0;
			else
				tail++;

		}
		if (queue[head]->right == NULL)
			cout << "Right kid" << " " << "NULL" << " ";
		else
		{
			cout << "Right kid" << " " << queue[head]->right->pname << " ";
			queue[tail] = queue[head]->right;
			counter++;
			if (tail == 29)
				tail = 0;
			else
				tail++;
		}
		cout << endl;
		if (head == 29)
			head = 0;
		else
		{
			head++;
		}
		counter--;

	}
	system("pause");

}

//helper functions
void tsearch(prezname keyname, tref root, bool &found, tref & where, tref & whereprev)
{
	tref p = root, pprev = NULL;
	while (p != NULL&&p->pname != keyname)
	{
		pprev = p;
		if (p->pname < keyname)
			p = p->right;
		else
			p = p->left;
	}
	found = p != NULL;
	where = p;
	whereprev = pprev;
}
void insert(prezname keyname, tref & root)
{
	if (root == NULL)
	{
		root = new tnode;
		root->pname = keyname;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		bool found;
		tref where, whereprev, p = 0;
		tsearch(keyname, root, found, where, whereprev);
		if (found)
		{
			cout << keyname << "found " << where << endl;
		}
		else
		{
			if (keyname > whereprev->pname)
			{
				p = new tnode;
				p->left = NULL;
				p->right = NULL;
				p->pname = keyname;
				whereprev->right = p;
			}
			else
				if (keyname < whereprev->pname)
				{
					p = new tnode;
					p->left = NULL;
					p->right = NULL;
					p->pname = keyname;
					whereprev->left = p;
				}		}

	}
}




