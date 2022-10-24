#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int num;
	int occ;
	node* next;
};

class linkedlist {
private:
	node l;
	node* head;
public:
	linkedlist();
	void addnode(node *&add);
	void removenode(int wantednodenum);
	void printnodes();
	void makelinkedlist(vector <int> &x);
	int sumofnodes();
};