/*
	Author: Krzysztof Nowakowski

	Dynamic list of integers.
*/
#include "IntegerList.h"


int IntegerList::addDigit(int value) {
	int nextDigit = lengthList + 1;
	int * listCopy = new int[nextDigit]; // (std::nothrow) is not working in Arduino IDE
	if (listCopy) {
		for (int i = 0; i < lengthList; i++) {
			listCopy[i] = integerList[i];
		}

		delete[] integerList;
		listCopy[lengthList] = value;
		integerList = new int[nextDigit];

		for (int i = 0; i < nextDigit; i++) {
			integerList[i] = listCopy[i];
		}

		delete[] listCopy;
		lengthList++;

		return value;
	}
	if(value == -1)
		return 0;
	else
		return -1;

}

int IntegerList::addDigitAfter(int position, int value) {
	if (position <= lengthList && position >= 0) {
		int addResult = addDigit(value);
		if (addResult == 0 && value == -1)
			return 0;
		if (addResult == -1 && value != -1)
			return -1;

		for (int i = lengthList - 1; i > position; i--) {
			integerList[i] = integerList[i - 1];
		}
		return integerList[position] = value;
	}

	return -1;
}

int IntegerList::addArrayAtTheEnd(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int addResult = addDigit(arr[i]);
		if (addResult == 0 && arr[i] == -1)
			return -1;
		if (addResult == -1 && arr[i] != -1)
			return -1;
	}
	return 1;
}

int IntegerList::addArrayAfter(int position, int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int addResult = addDigitAfter(position, arr[i]);
		if (addResult == 0 && arr[i] == -1)
			return -1;
		if (addResult == -1 && arr[i] != -1)
			return -1;
		position++;
	}
	return 1;
}

int IntegerList::getDigit(int position) {
	if (position <= lengthList && position > 0) {
		return integerList[position - 1];
	}
	return -1;
}

int IntegerList::listLength() {
	return lengthList;
}

bool IntegerList::isEmpty() {
	if (lengthList == 0) {
		return true;
	}
	return false;
}

bool IntegerList::hasDigit(int position) {
	if (position <= lengthList && position > 0) {
		return true;
	}
	return false;
}

int IntegerList::changeValue(int position, int value) {
	if (position <= lengthList && position > 0) {
		integerList[position - 1] = value;
		return integerList[position - 1];
	}
	if (value == -1)
		return 0;
	else
		return -1;
}

int IntegerList::minDigit() {
	int min = integerList[0];
	for (int i = 0; i < lengthList; i++) {
		if (integerList[i] < min) {
			min = integerList[i];
		}
	}
	return min;
}

int IntegerList::maxDigit() {
	int max = integerList[0];
	for (int i = 0; i < lengthList; i++) {
		if (integerList[i] > max) {
			max = integerList[i];
		}
	}
	return max;
}

long IntegerList::sum() {
	int suma = 0;
	for (int i = 0; i < lengthList; i++) {
		suma += integerList[i];
	}
	return suma;
}

float IntegerList::average() {
	int suma = 0;
	for (int i = 0; i < lengthList; i++) {
		suma += integerList[i];
	}
	return ((float)suma / lengthList);

}

void IntegerList::sortFromMinToMax(){

	// Bubble sorting.
	for (int i = 0; i < lengthList; i++) {
		for (int j = 0; j < lengthList - 1; j++) {
			if (integerList[j] > integerList[j + 1]) {
				int actual = integerList[j];
				integerList[j] = integerList[j + 1];
				integerList[j + 1] = actual;
			}
		}
	}
}

void IntegerList::invertList() {
	for (int i = 0; i < lengthList/2; i++) {
		int beginning = integerList[i];
		int end = lengthList - 1 - i;
		integerList[i] = integerList[end];
		integerList[end] = beginning;
	}
}

int IntegerList::deleteDigit(int position) {
	if (position <= lengthList && position > 0) {
		for (int i = position - 1; i < lengthList; i++) {
			integerList[i] = integerList[i + 1];
		}
		lengthList--;
		return 1;
	}
	return -1;
}

int IntegerList::deleteDigit(int start, int end) {
	if(start > end)
		return -1;
	if (end <= lengthList && start > 0) {
		for (int i = start; i <= end; i++) {
			deleteDigit(start);
		}
		start++;
		return 1;
	}
	return -1;
}


IntegerList::IntegerList() {
	lengthList = 0;
	integerList = new int[1];
}

IntegerList::IntegerList(int arr[], int size) {
	lengthList = 0;
	integerList = new int[1];
	for (int i = 0; i < size; i++) {
		addDigit(arr[i]);
	}
}

IntegerList::IntegerList(int value, int size){
	lengthList = 0;
	integerList = new int[1];
	for (int i = 0; i < size; i++) {
		addDigit(value);
	}
}

IntegerList::IntegerList(const IntegerList & pattern) {
	lengthList = pattern.lengthList;
	integerList = new int[lengthList];

	for (int i = 0; i < lengthList; i++) {
		integerList[i] = pattern.integerList[i];
	}
}

IntegerList & IntegerList::operator=(const IntegerList & pattern) {
	if (&pattern != this) {

		delete[] integerList;

		lengthList = pattern.lengthList;
		integerList = new int[lengthList];

		for (int i = 0; i < lengthList; i++) {
			integerList[i] = pattern.integerList[i];
		}
	}
	return *this;
}

IntegerList::~IntegerList(){
	delete[] integerList;
}