/*
* Make a list of integers
* By Krzysztof Nowakowski
*/

#include <IntegerList.h>

IntegerList list;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  

  if(list.isEmpty()){
    Serial.println("List is empty. Has list some in firt position?");
    if(list.hasDigit(1)){
      Serial.println("Yes.");
    }
    else{
      Serial.println("No. I will add somethitg.");
      list.addDigit(-20);
    }
  }

  if(list.hasDigit(1)){
      Serial.println("Yes, at now list has something at first position.");
  }

  Serial.print("Digit on firt position: ");
  Serial.println(list.getDigit(1));

  Serial.print("Lets add some digits.");
  list.addDigit(-10);
  list.addDigit(0);
  list.addDigit(10);
  list.addDigit(20);
  list.addDigit(30);

  Serial.println("All list: ");
  for(int i = 1; i <= list.listLength(); i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(list.getDigit(i));
  }

  Serial.println("Add digit on third position.");
  list.addDigitAfter(2, 9);
  Serial.println("Add arry at the end.");
  int arr[] = { 11, 12, 13 };
  list.addArrayAtTheEnd(arr, 3);
  Serial.println("Add arry after four.");
  int arr2[] = { 1, 2, 3 };
  list.addArrayAfter(4, arr2, 3);

  Serial.println("All list: ");
  for (int i = 1; i <= list.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list.getDigit(i));
  }

  Serial.println("Change the first value.");
  list.changeValue(1, 222);
  Serial.println(list.getDigit(1));

  Serial.print("Max: ");
  Serial.println(list.maxDigit());
  Serial.print("Min: ");
  Serial.println(list.minDigit());

  Serial.print("Length of list: ");
  Serial.println(list.listLength());

  Serial.print("Sum: ");
  Serial.println(list.sum());

  Serial.print("Average: ");
  Serial.println(list.average());

  Serial.println("All list: ");
  for (int i = 1; i <= list.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list.getDigit(i));
  }
  list.sortFromMinToMax();
  Serial.println("After sorting: ");
  for(int i = 1; i <= list.listLength(); i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(list.getDigit(i));
  }

  list.invertList();
  Serial.println("After inverting: ");
  for (int i = 1; i <= list.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list.getDigit(i));
  }

  Serial.println("Delete second digit.");
  list.deleteDigit(2);
  Serial.println("Delete between four and seven.");
  list.deleteDigit(4,7);
  Serial.println("After deleting: ");
  for (int i = 1; i <= list.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list.getDigit(i));
  }


  IntegerList list2(3,6);
  Serial.println("Second list with six threes: ");
  for(int i = 1; i <= list2.listLength(); i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(list2.getDigit(i));
  }
  
  int arr3[] = { 5, 2, 3, 4, 1 };
  IntegerList list3(arr3, 5);
  Serial.println("Third list was make from array: ");
  for(int i = 1; i <= list3.listLength(); i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(list3.getDigit(i));
  }

  Serial.println("Several assignments.");
  IntegerList list4 = list2;
  list = list3;

  Serial.println("List 4 is like list 2: ");
  for (int i = 1; i <= list4.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list4.getDigit(i));
  }

  Serial.println("List 1 is like list 3: ");
  for (int i = 1; i <= list.listLength(); i++) {
	  Serial.print(i);
	  Serial.print(" : ");
	  Serial.println(list.getDigit(i));
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
