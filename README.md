# Description
> This is easy way to have a list of integer types. It's designed to have intuitive API. It uses an allocation on the heap. It makes a pointer array, which is like normal integer array, but it can be extensible. It has been written with Arduino in mind, but it isn't linked to Arduino libraries so you can use this library in any other C++ project.

## Quick start
```c++
#include <IntegerList.h>

IntegerList list;

int x = 10;
list.addDigit(x);

int y = list.getDigit(1);

//y == x;
```

> Take a look at `IntegerList.h`. There is a lot information about results of function. In `examples` folder there is an example of using the library

# Arduino installation
>To download click the `DOWNLOADS` button in the top right corner, rename the uncompressed folder `IntegerList`. Check that the `IntegerList` folder contains `IntegerList.cpp` and `IntegerList.h`

>Place the `IntegerList` library folder your *arduinosketchfolder*/libraries/ folder. 
You may need to create the libraries subfolder if its your first library. Restart the Arduino IDE.

# Author
> **Krzysztof Nowakowski**