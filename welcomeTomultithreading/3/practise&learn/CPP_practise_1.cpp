  // Pointers in c++

  /*
    Some C++ tasks are performed more easily with pointers, and other C++ tasks,
    such as dynamic memory allocation, cannot be performed without them.

    As you know every variable is a memory location and every memory location has
    its address defined which can be accessed using ampersand (&) operator which
    denotes an address in memory.

    A pointer is a variable whose value is the address of another variable.
    type *variable_name;
    Here, type is the pointer's base type; it must be a valid C++ type and var-name
    is the name of the pointer variable.
  */
  #include <iostream>

  using namespace std;

  int main() {

    // value of x set to 5 (actual variable declaration)
    int x = 5;

    // integer pointer variable
    int *p;

    // store address of var in pointer variable
    p = &x;

    // address of x variable
    cout << "Location (address) of x in memory " << &x << endl;
    // value of pointer p
    cout << "Value of pointer p (which is the address of variable x) " << p << endl;
    // access the value at the address available in pointer
    cout<< "value of x (using pointer) " << *p << endl;
    // address of pointer variable
    cout << "Location (address) of p in memory " << &p << endl;

    // lets define an integer array
    int size = 20;
    int array_1[size];

    // fill the array from 0 to 19
    for (int i = 0; i < size; i++) {
      array_1[i] = i;
    }

    // print array's elements
    for (int i = 0; i < size; i++) {
      cout << array_1[i] << " ";
    }
    cout << endl;

    // address of array's elements
    for (int i = 0; i < size; i++) {
      cout << &array_1[i] << endl;
    }


    return 0;
  } 
