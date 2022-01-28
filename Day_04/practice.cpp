#include <iostream>
#include <vector>		//vector
#include <algorithm>	//sort
#include <set>			//sets
#include <map>			//map

using namespace std;

bool f(int x,int y) {
	return x > y;
}

void vectorDemo() {

	vector<int> a = { 11,2,3,15 };
	cout << a[1] << endl;
	//{ 2,3,11,15 };
	sort(a.begin(), a.end());		//merge sort O(logN)

	bool present = binary_search(a.begin(), a.end(), 3);
	cout << present << endl;
	present = binary_search(a.begin(), a.end(), 118);
	cout << present << endl;
	//{ 2,3,11,15,100 };
	a.push_back(100);
	present = binary_search(a.begin(), a.end(), 100);
	cout << present << endl;

	a.push_back(100);
	a.push_back(100);
	a.push_back(100);
	a.push_back(100);
	//{ 2,3,11,15,100,100,100,100,100 };
	a.push_back(123);
	//{ 2,3,11,15,100,100,100,100,100,123 };
	auto it = lower_bound(a.begin(), a.end(), 100);	//100  ptr
	auto it2 = upper_bound(a.begin(), a.end(), 100);	//123	ptr

	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl;		//ptr diff

	sort(a.begin(), a.end(), f);
	vector<int>::iterator it3;

	for (it3 = a.begin(); it3 != a.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;

	for (int& x : a) {		//update by referance
		x++;
		cout << x << " ";
	}
	cout << endl;

}

void setDemo() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(-1);
	s.insert(-10);
	
	for (int x : s) {
		cout << x << " ";
	}
	cout << endl;

	auto it = s.find(-1);
	if (it == s.end()) {
		cout << "Element is not present" << *it<<endl;
	}
	else {
		cout << "present" << *it<<endl;
	}

	auto it2 = s.upper_bound(-1);
	auto it3 = s.upper_bound(0);

	cout << *it2 << " " << *it3 << endl;

	auto it4 = s.upper_bound(2);
	if (it4 == s.end()) {
		cout << "Element is not present"  << endl;
	}
	else {
		cout << "present" << endl;
	}

}

void mapDemo() {
	map<int,int> m;
	m[1] = 100;
	m[2] = -1;
	m[3] = 200;
	m[100012] = 1;

	map<char, int> cnt;
	string x = "anvit dave";
	for (char c : x) {
		cnt[c]++;
	}

	cout << cnt['a'] << " " << cnt['v'] << endl;
}

void powerofStl() {
	set<pair<int, int>> s;
	s.insert({ 401, 450 });
	s.insert({ 10, 20 });
	s.insert({ 2, 3});
	s.insert({ 30, 400 });

	int point = 50;
	auto it = s.upper_bound({ point,INT_MAX });
	if (it == s.begin()) {
		cout << "Not exist" << endl;
		return;
	}
	it--;
	pair<int, int> curr = *it;
	if(curr.first<=point && point<= curr.second){
		cout << "Present in set:[ " << curr.first << "," << curr.second << " ]" << endl;
	}
	else {
		cout << "Not exist" << endl;
	}
}

int mymain() {
	powerofStl();
	return 0;
}