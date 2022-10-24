#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

void fillvector(vector <int> &vc, int n) {
	cout << "Enter number of integers: ";
	cin >> n;
	int input;
	for (int i = 0; i < n; i++) {
		cout << "Enter integer number " << i + 1 << ": ";
		cin >> input;
		vc.push_back(input);
	}
}

void insert(vector<int>& vc, int firstvalue, int secondvalue) {
	for (int i = 0; i < vc.size(); i++) {

		if (vc[i] == firstvalue) {
			vc.insert((vc.begin()+i+1), secondvalue);
		}

	}
}

int main() {
	vector <int> vc;
	int n=0;
	fillvector(vc, n);
	linkedlist ll;
	ll.makelinkedlist(vc);
	ll.printnodes();
	cout << endl << "And the sum is: " << ll.sumofnodes()<<endl;
	cout << endl;
	cout << "DELETE NODE (3)" << endl;
	ll.removenode(3);
	ll.printnodes();
	cout << endl << "And the sum is: " << ll.sumofnodes();
	return 0;
}