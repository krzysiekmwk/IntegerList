/*
	Author: Krzysztof Nowakowski

	Dynamic list of integers. 
*/
#ifndef IntegerList_h
#define IntegerList_h

class IntegerList
{
public:

	/*
		Add a new number at the end of the list.
		Return the value of its own.
		Returns -1 when there is no more space or 0 when value is -1 and there is no more space.
	*/
	int addDigit(int value);

	/*
		Add a new number after some element in a list. It can be 0, for first position.
		Return the value of its own.
		Returns -1 when there is no more space or 0 when value is -1 and there is no more space.
	*/
	int addDigitAfter(int position, int value);

	/*
		Add an arry at the end of the list.
		Returns 1 when is success, -1 when was some error, eg. there is no more space.
	*/
	int addArrayAtTheEnd(int arr[], int size);

	/*
		Add an arry after some element in a list. It can be 0, for first position.
		Returns 1 when is success, -1 when was some error, eg. no more space.
	*/
	int addArrayAfter(int position, int arr[], int size);

	/*
		Get number from selected position.
		Returns an integer value or return -1 when value doesn't exist on selected position.
	*/
	int getDigit(int position);

	/*
		Returns the length of the list.
	*/
	int listLength();

	/*
		Returns true if list is empty or false if list has some digits.
	*/
	bool isEmpty();

	/*
		Returns true if is any digit in selected position or it returns false if is empty.
	*/
	bool hasDigit(int position);

	/*
		Change value on selected position.
		Returns -1 if position is wrong or 0 if position is wrong and value was -1.
	*/
	int changeValue(int position, int value);

	/*
		Returns the minimum digit in the list.
	*/
	int minDigit();

	/*
		Returns the maximum digit in the list.
	*/
	int maxDigit();

	/*
		Returns the sum from the whole list.
	*/
	long sum();

	/*
		Returns the average from the whole list.
	*/
	float average();

	/*
		Sort the list from min to max.
	*/
	void sortFromMinToMax();

	/*
		Invert the whole list.
	*/
	void invertList();

	/*
		Delete digit from selected position.
		Returns 1 if the result was good, or it returns -1 if there was no digit on selected positon.
	*/
	int deleteDigit(int position);

	/*
		Delete digit from selected start to end.
		Returns 1 if the result was good, or it returns -1 if there was no digit on selected positon or 
		start was higher than.
	*/
	int deleteDigit(int start, int end);


	/*
		Constructor empty list.
	*/
	IntegerList();

	/*
		Constructor list from array.
	*/
	IntegerList(int arr[], int size);

	/*
		Constructor list from selected value.
	*/
	IntegerList(int value, int size);

	/*
		The copy constructor.
	*/
	IntegerList(const IntegerList & pattern);

	/*
		The copy from another list.
	*/
	IntegerList & operator=(const IntegerList & pattern);

	/*
		Deconstructor. It delete the pointer and frees memory rervation.
	*/
	~IntegerList();

private:
	int lengthList;
	int * integerList;

};

#endif //IntegerList_h