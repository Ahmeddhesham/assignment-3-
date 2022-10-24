#include <iostream>
#include "linkedlist.h"
#include <vector>

using namespace std;

linkedlist::linkedlist() {
	head = NULL;
}

void linkedlist::addnode(node *&add) {
	if (head == NULL) {
		head = add;
		add->next = NULL;
	}
	else {
		node* q;
		node* p=head;
		q = p;
		while (p->next != NULL) {
			q = p;
			p = p->next;
		}
		p->next = add;
		add->next = NULL;
	}

}

void linkedlist::removenode(int wantednodenum) {
	if (head->num == wantednodenum) {
		head = head -> next;
	}
	else {
		node* p = head;
		node* q = p;
		while (p->num!=wantednodenum){
			q = p;
			p = p->next;
		}
		q->next = p->next;
		p->next = NULL;
	}
}

void linkedlist::printnodes() {
	node* p = head;
	while (p != NULL) {
		cout << "The number is: " << p->num << endl;
		cout << "And its occurances are: " << p->occ << endl;
		p = p ->next;
	}
}

void linkedlist::makelinkedlist(vector <int> &v) {

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[i]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	int counter = 1;
	int n = v.size();
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = v[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1]) {
			counter++;
		}
		else {
			node *newnode= new node;
			newnode->num = arr[i];
			newnode->occ = counter;
			newnode->next = NULL;
			addnode(newnode);
			counter = 1;
		}
	}

}

int linkedlist::sumofnodes() {
	int sum = 0;
	node* p = head;
	while (p != NULL) {
		sum = sum + (p->num * p->occ);
		p = p->next;
	}
	return sum;
}
