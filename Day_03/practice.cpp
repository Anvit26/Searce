#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

#pragma region Seprate chaining

//Seprate chaining start
class Hash {
		int bucket;
		list<int>* table;

	public:
		Hash(int v);
		void insertItem(int x);
		void deleteItem(int key);
		int hashFunc(int x) {
			return (x % bucket);
		}
		void displayHash();
};

Hash::Hash(int b) {
	this->bucket = b;
	table = new list <int>[bucket];
}

void Hash::insertItem(int key) {
	int index = hashFunc(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key) {
	int index = hashFunc(key);
	list <int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key) {
			break;
		}
	}
	if (i != table[index].end()) {
		table[index].erase(i);
	}
}

void Hash::displayHash() {
	for (int i = 0; i < bucket; i++) {
		cout << i;
		for (auto x : table[i]) {
			cout << "--> " << x;
		}
		cout << endl;
	}
}
//Seprate chaining end

int seprateChaining() {
	int a[] = { 10,5, 12, 67, 9, 16,22,23,26,36 };
	int n = 10;
	Hash h(7);
	for (int i = 0; i < n; i++) {
		h.insertItem(a[i]);
	}
	h.deleteItem(12);
	h.displayHash();
	return 0;
}

#pragma endregion

#pragma region Linear probing

const int hashTab = 11;
int hashFunc(int key) {
	return (key % hashTab);
}

void insertKey(int arr[], int key) {
	int n = 0;
	int index = hashFunc(key);
	while (arr[index] != INT_MIN) {
		if (arr[index] == INT_MAX) {
			break;
		}
		index = hashFunc(index + 1);
		n++;
		if (n == hashTab) {
			break;
		}
	}
	if (n == hashTab) {
		cout << "Hash table was full of elements\nNo Place to insert this element\n\n";
	}
	else {
		arr[index] = key;
	}
}

void deleteKey(int arr[], int key) {
	int n = 0;

	int index = hashFunc(key);

	while (n++ != hashTab) {
		if (arr[index] == INT_MIN) {
			cout << "Element not found in hash table\n";
			break;
		}
		else if (arr[index] == key) {
			arr[index] = INT_MAX;
			cout << "Element deleted\n\n";
			break;
		}
		else {
			index = hashFunc(index+1);
		}
	}
	if (--n == hashTab) {
		cout << "Element not found in hash table\n";
	}
}

void searchKey() {
}

void display(int arr[], int hashTab) {
	int i;

	cout << "Index\tValue\n";

	for (i = 0; i < hashTab; i++)
		cout << i << "\t" << arr[i] << "\n";
}

void linearProbing() {
	int hashArrTab[hashTab]{};
	for (int i = 0; i < hashTab; i++) {
		hashArrTab[i]=INT_MIN;
	}
	int myArr[10]{21,42,31,12,54,20,1,1,1,1};

	for (int i = 0; i < 10; i++) {
		insertKey(hashArrTab, myArr[i]);
	}

	display(hashArrTab,hashTab);

	return;
}
int main(){

    seprateChaining();
    linearProbing();
    return 0;
}
#pragma endregion