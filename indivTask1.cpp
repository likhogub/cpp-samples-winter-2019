/*
Описать процедуру, которая формирует список L, включив в него по одному разу элементы, которые входят в один
из списков L1 и L2, но в тоже время не входят в другой из них.
*/

#include <iostream>
#include <string>
using namespace std;

struct list {
	int value;
	list* next = NULL;
};

list* L, * L1, * L2, * tmp;


int isValueInList(list* listToCheckTo, int targetValue) {
	if (listToCheckTo == NULL) return 0;
	if (listToCheckTo->value == targetValue) return 1;
	return isValueInList(listToCheckTo->next, targetValue);
}


list* createList(int value) {
	list* tmp = new list;
	tmp->value = value;
	return tmp;
}


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


int browseList(list* listToBrowse) {
	if (listToBrowse == NULL) return 0;
	cout << listToBrowse->value << " ";
	return browseList(listToBrowse->next);;
}

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


int addElemToFromExcept(list* listTarget, list* listSource, list* listException) {
	while (listSource != NULL) {
		if (!isValueInList(listException, listSource->value)) addUniqItemToList(listTarget, listTarget, listSource->value);
		listSource = listSource->next;
	}
	return 0;
}


int println(string text) {
	cout << text << endl;
	return 0;
}

int main() {
	int x;

	println("Enter L1 list:");
	cin >> x;
	L1 = createList(x);
	while (true) {
		cin >> x;
		if (!x) break;
		addUniqItemToList(L1, L1, x);
	}

	println("Enter L2 list:");
	cin >> x;
	L2 = createList(x);
	while (true) {
		cin >> x;
		if (!x) break;
		addUniqItemToList(L2, L2, x);
	}
	
	int firstItemValue = findFirstItemValue();
	if (!firstItemValue) {
		println("Lists are equal!");
		return 0;
	}

	L = createList(firstItemValue);

	addElemToFromExcept(L, L1, L2);
	addElemToFromExcept(L, L2, L1);
	
	println("Result is:");
	browseList(L);

	return 0;
}
