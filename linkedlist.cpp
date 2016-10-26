#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef string presName;
typedef struct cell *lref;// pointer to the structure named lref
typedef struct cell { presName prez;lref next; } lnode;//structurre box with two fields
// the name cell is used to link the pointer to the stucture box


void listSearch(presName keyname, lref head, bool&found,lref &where,lref whereprev)
{
	lref p = head, pprev = NULL; // creating two pointers to keep up with the current and previous boxes
	while (p != NULL&&p->prez < keyname)
	{
		pprev = p;
		p = p->next;
	}
	found = p != NULL&&p->prez == keyname;
	whereprev = pprev;
	where = p;
}

void insertion(presName keyname, lref & head)
{
	bool found;
	lref where, whereprev, p;
	listSearch(keyname, head, found, where, whereprev);
	if (found)
		cout << keyname << " already in list at " << where << endl;
	else
	{
		p = new lnode;// alocates space on the heap and returns a pointer to the space
		p->prez = keyname;
		p->next = where;
		if (whereprev == NULL)//if where=head
			head = p;
		else
			whereprev->next = p;

	}
}
void deletion(presName keyname, lref &head)
{
	bool found;
	lref where, whereprev;
	listSearch(keyname, head, found, where, whereprev);
	if (!found)
		cout << keyname << " not found." << endl;
	else
		if (whereprev = NULL)
			head = where->next;// or head=head->next
}

//outputting a linked list

void output(lref head)
{
	lref p = head;
	while (head != NULL)
	{
		cout << p->prez << endl;
		p = p->next;
	}
}

//right rotating the list
// ex. head->a->b->c->d->Null
// result  head->d->a->b->c->NULL

void rrotate(lref & head)
{
	lref tailprev = head;
	if (head != NULL&&head->next != NULL)
	{
		while (tailprev->next->next != NULL)
			tailprev = tailprev->next;
		tailprev->next->next = head;
		head = tailprev->next;
		tailprev->next = NULL;
	}
}

void lrotate(lref &head)
{
	if (head != NULL)
	{
		lref tail = head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = head;
		head = head->next;
		tail->next->next = NULL;
	}
}
void reverse(lref& head)
{
	lref pbefore = NULL, p = head, pafter;
	while (p != NULL)
	{
		pafter = p->next;
		p->next = pbefore;
		pbefore = p;
		p = pafter;
	}
	head = pbefore;
}

void ncopy(lref head, int n)
{
	lref p = head, pahead;
	int i;
	while (p != NULL)
	{
		pahead = p->next;
		for (i = 1;i <= n;i++)
		{
			p->next = new lnode;
			p->next->prez = p->prez;
			p = p->next;
		}
		p->next = pahead;
		p = pahead;
	}
}
void altmerge(lref head1, lref head2)
{
	lref p = head1, q = head2, r;
	while (q != NULL)
	{
		r = p->next;
		p->next = q;
		p = q;
		q = r;
	}
}