  #include <iostream>
  #include <cstring>

  #define LOG(x) std::cout << x << std::endl;

  // a pointer for all types is just that integer that holds
  // memory address
  int main() {

    // a type doesn't chage what pointer is, pointer is just a memory address, just an integer
    // if we give a pointer type we are just saying the data at that address is presumed to be
    // the type that we give it, but still a pointer is just an integer

    // void means it is completely typeless
    // void pointer means we don't care about the type of the data at this address

    void* ptr = 0; // we have given this pointer a memory address of zero,
    // zero is not a valid memory address, therefore our pointer in this case is not valid

    void* ptr2 = NULL; // #define NULL 0

    // void* ptr3 = nullptr -> c++11 syntax

    // every variable we create has a memory address

    int var = 8; // we are creating it in stack portion of our memory
    void* ptr4 = &var;
    int* ptr5 = &var;
    double* ptr6 = (double*) &var;

    // with *pointer we can actually access the data and read or write
    *ptr5 = 100;

    LOG(var); // 100

    // hey computer I want you to allocate some memory for me and I want it to be a certain size

    // we know char is one byte
    char* buffer = new char[8]; // I am really asking for 8 bytes of memory (heap)
    // so
    // new char[8] -> has allocated 8 bytes of memory for us and is returning a pointer
    // to the beginning of that block of memory

    // memset basically
    memset(buffer, 'a', 8);

    char** ptr6 = &buffer;

    delete[] buffer; // delete heap
    std::cin.get();
  }
