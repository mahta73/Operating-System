  #include <iostream>

  int main() {

    // here we have 32 bits, and 1 bit for sign so , 2 in power 31
    int variable_1 = 8; // -2b -> 2b  4 bytes of data

    // here all 32 bits are for numbers and we don't have 1 bit for sign
    // always positive so 2 in power 32
    unsigned int variable_2 = 10;

    // char -> 1 bytes
    // short -> 2 bytes
    // int -> 4 bytes
    // long -> 4 bytes
    // long long -> 8 bytes
    // float -> 4 bytes
    // double -> 8 bytes

    char a = 65;

    std::cout << "a: " << a << std::endl; //2

    float variable_3 = 2.3f;
    float variable_4 = 2.5F;

    std::cout << variable_3 << " " << variable_4 << std::endl;

    bool bool_1 = true;
    std::cout << bool_1 << std::endl; // 1

    bool bool_2 = false;
    std::cout << bool_2 << std::endl; // 0

    // bool takes 1 byte of memory, but why?
    // when we are dealling with addressing memory to retrieve our bool from memory
    // there is no way for us to address individual bit we can only address bytes.
    // actually we can not create a variable wich is 1 bit, because we won't be able
    // to access it later and we cant because we can access only bytes.

    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(bool) << std::endl;

    // pointer (* after type) and reference (& after type)
  }
