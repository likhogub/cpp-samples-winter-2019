#include <iostream>
using namespace std;

struct list {
	int value;
	list* next = NULL;
};

list* L, * L1, * L2, * tmp;


//Checks existence of 'value' in list
int isValueInList(list* listToCheckTo, int targetValue) {
	if (listToCheckTo == NULL) return 0;
	if (listToCheckTo->value == targetValue) return 1;
	return isValueInList(listToCheckTo->next, targetValue);
}


//Creates and returns list
list* createList(int value) {
	list* tmp = new list;
	tmp->value = value;
	return tmp;
}


//Checks existence of 'value' in 'listToCheckTo' and if there aren't similar items , function adds it to 'listToAddTo' 
int addUniqItemToList(list* listToAddTo, list* listToCheckTo, int itemValue) {
	if (!isValueInList(listToCheckTo, itemValue)) {
		while (listToAddTo->next != NULL) listToAddTo = listToAddTo->next;
		list* tmp = new list;
		tmp->value = itemValue;
		listToAddTo->next = tmp;
		return 1;
	}
	return 0;
}


//Prints items of 'listToBrowse'
int browseList(list* listToBrowse) {
	if (listToBrowse == NULL) return 0;
	cout << listToBrowse->value << " ";
	return browseList(listToBrowse->next);
}


//Finds item to be first in 'L' list
int findFirstItemValue() {
	tmp = L1;
	while (tmp != NULL) {
		if (!isValueInList(L2, tmp->value)) return tmp->value;
		tmp = tmp->next;
	}
	tmp = L2;
	while (tmp != NULL) {
		if (!isValueInList(L1, tmp->value)) return tmp->value;
		tmp = tmp->next;
	}
	return 0;
}


//XOR rule
//Adds elements from 'listSource' to 'listTarget' excluding 'listException' items
int addElemToFromExcept(list* listTarget, list* listSource, list* listException) {
	while (listSource != NULL) {
		if (!isValueInList(listException, listSource->value)) addUniqItemToList(listTarget, listTarget, listSource->value);
		listSource = listSource->next;
	}
	return 0;
}


//Compares first and last digits in number
int areFirstAndLastDigitEqual(int valueToProcess) {
	int valueCopy = valueToProcess;
	while (valueToProcess / 10 > 0) valueToProcess /= 10;
	return valueToProcess == (valueCopy % 10);
}


//Counts numbers according to the 'good' numbers rule
//first_digit == last_digit
int getGoodNumbersCount(list* listToBrowse) {
	if (listToBrowse == NULL) return 0;
	if (areFirstAndLastDigitEqual(listToBrowse->value)) return 1 + getGoodNumbersCount(listToBrowse->next);
	return getGoodNumbersCount(listToBrowse->next);
}


//Generates 
list* getTestSample(int testSampleLength) {
	tmp = createList(rand() % 999 + 1);
	for (int i = 0; i < testSampleLength; i++) addUniqItemToList(tmp, tmp, rand() % 999 + 1);
	return tmp;
}


int coreOne() {

	//Toggles automatic test samples generation method
	int mode = -1;
	while (!(mode == 0 || mode == 1)) {
		cout << "Enter program mode - 0 or 1 (manual or auto):" << endl;
		cin >> mode;
	}
	if (mode == 0) {
		int x;

		//Input of initial lists
		cout << "Enter L1 list: " << endl;
		cin >> x;
		L1 = createList(x);
		while (true) {
			cin >> x;
			if (!x) break;
			addUniqItemToList(L1, L1, x);
		}

		cout << "Enter L2 list:" << endl;
		cin >> x;
		L2 = createList(x);
		while (true) {
			cin >> x;
			if (!x) break;
			addUniqItemToList(L2, L2, x);
		}
	}
	else {
		int L1Length = rand() % 19 + 1;
		L1 = getTestSample(L1Length);
		cout << "L1 is ";
		browseList(L1);
		cout << endl;

		int L2Length = rand() % 19 + 1;
		L2 = getTestSample(L2Length);
		cout << "L2 is ";
		browseList(L2);
		cout << endl;
	}

	//Trying to find first acceptable item and creating new list 'L'
	int firstItemValue = findFirstItemValue();
	if (!firstItemValue) {
		cout << "Lists are equal!" << endl;
		return 0;
	}

	L = createList(firstItemValue);

	//Appending items to the 'L' list using XOR rule
	addElemToFromExcept(L, L1, L2);
	addElemToFromExcept(L, L2, L1);

	//Printing results
	cout << "Result list is:" << endl;
	browseList(L);
	cout << endl;
	cout << "There are 'good': " << getGoodNumbersCount(L) << " number(s)" << endl;

	return 0;
}

int IndividualTaskOne() {
	cout << "Individual Task #20.1" << endl;
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	coreOne();
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	system("pause");
	system("cls");
	return 0;
}


struct indexedList {
	float value;
	int index;
	indexedList* next = NULL;
};

indexedList* iL, * itmp;

indexedList* createIndexedList(float value) {
	itmp = new indexedList;
	itmp->value = value;
	itmp->index = 1;
	return itmp;
}

int addIndexedListItem(indexedList* listToAdd, float value) {
	while (listToAdd->next != NULL) listToAdd = listToAdd->next;
	itmp = new indexedList;
	itmp->value = value;
	itmp->index = listToAdd->index + 1;
	listToAdd->next = itmp;
	return 0;
}

float getValueByIndex(indexedList* listSource, int index) {
	if (listSource->index == index) return listSource->value;
	return getValueByIndex(listSource->next, index);
}


int browseListTwo(indexedList* L) {
	if (L == NULL) return 0;
	cout << L->value << " ";
	browseListTwo(L->next);
	return 0;
}

int coreTwo() {
	int N; float x;

	cout << "Enter N:" << endl;
	cin >> N;

	cout << "Enter list:" << endl;
	cin >> x;

	//Creating new list
	iL = createIndexedList(x);
	for (int i = 1; i < N; i++) {
		cin >> x;
		addIndexedListItem(iL, x);
	}


	//Getting min value of Ai*An/2+i
	float min = getValueByIndex(iL, 1) * getValueByIndex(iL, (N / 2 + 1));
	for (int i = 2; i <= (N / 2); i++) {
		x = getValueByIndex(iL, i) * getValueByIndex(iL, (N / 2 + i));
		if (x < min) min = x;
	}

	//Printing result
	cout << "Result is " << min << endl;
	return 0;
}

int IndividualTaskTwo() {
	cout << "Individual Task #20.2" << endl;
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	coreTwo();
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	system("pause");
	system("cls");
	return 0;
}



struct tree {
	int value;
	tree* left = NULL;
	tree* right = NULL;
};

tree* tmpTreeItem, * root;

int addToTree(tree* treeItem, int value) {
	if ((value < treeItem->value) && (treeItem->left == NULL)) {
		tmpTreeItem = new tree;
		tmpTreeItem->value = value;
		treeItem->left = tmpTreeItem;
		return 0;
	}
	if ((value > treeItem->value) && (treeItem->right == NULL)) {
		tmpTreeItem = new tree;
		tmpTreeItem->value = value;
		treeItem->right = tmpTreeItem;
		return 0;
	}
	if ((value < treeItem->value) && (treeItem->left != NULL)) {
		addToTree(treeItem->left, value);
		return 0;
	}
	if ((value > treeItem->value) && (treeItem->right != NULL)) { 
		addToTree(treeItem->right, value);
		return 0;
	}
	return 0;
}

int browseTree(tree* treeItem) {
	if (treeItem == NULL) return 0;
	cout << treeItem->value << " ";
	browseTree(treeItem->left);
	browseTree(treeItem->right);
	return 0;
}

int treeSum(tree* treeItem) {
	if (treeItem == NULL) return 0;
	return treeItem->value + (treeSum(treeItem->left)) + (treeSum(treeItem->right));
}

int treeCount(tree* treeItem) {
	if (treeItem == NULL) return 0;
	return 1 + (treeCount(treeItem->left)) + (treeCount(treeItem->right));
}

int treeLeavesProduction(tree* treeItem, float avg) {
	if (treeItem == NULL) return 1;
	if (treeItem->left == NULL && treeItem->right == NULL && treeItem->value < avg) return (treeItem->value);
	return treeLeavesProduction(treeItem->left, avg) * treeLeavesProduction(treeItem->right, avg);
}

int coreThree() {
	root = new tree;
	cout << "Enter tree:" << endl;
	cin >> root->value;
	while (true) {
		int x;
		cin >> x;
		if (!x) break;
		addToTree(root, x);
	}

	float avg = treeSum(root);
	avg /= treeCount(root);
	cout << "Production of leaves which are less average is " << treeLeavesProduction(root, avg) << endl;

	return 0;
}


int IndividualTaskThree() {
	cout << "Individual Task #20.3" << endl;
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	coreThree();
	for (int i = 0; i < 80; i++) cout << '-';
	cout << endl;
	system("pause");
	system("cls");
	return 0;
}

int main() {
	while (true) {
		cout << "Individual Task #20" << endl;
		for (int i = 0; i < 80; i++) cout << '-';
		cout << endl;

		cout << "Enter task number: ";
		int task;
		cin >> task;
		switch (task) {
		case 1: {
			system("cls");
			IndividualTaskOne();
			break;
		}
		case 2: {
			system("cls");
			IndividualTaskTwo();
			break;
		}
		case 3: {
			system("cls");
			IndividualTaskThree();
			break;
		}
		default: {
			system("cls");
			continue;
		}
		}
	}
	return 0;
}
