  // reference is a really just an extension of pointers
  // reference is a way for us to reference an existing varibal
  // unlike a pointer where you could create a new pointer variable
  // and then set it to a null pointer you can't do that with
  // references.
  // references have to reference an already existing variable
  // once you declare a reference you cannot change at what it references

  #include <iostream>

  #define LOG(x) std::cout << x << std::endl;

  void Increament(int number) {
    number++;
  }
  /*
    since we are passing just by value

    void Increament(int number) {
      int number = 5;
      number++;
   }

   int a = 5;
   Increament(a);
  */

  void Increament2(int* number) {
    (*number)++;
  }

  void Increament3(int& number) {
    number++;
  }

  int main() {
    int a = 5;

    // & is the part of the declaration (& in a part of the type)
    int& a_ref = a; // alias
    // a_ref just exits in our source code
    // if you compile this code right now you're not going to get
    // two variables created, you are just going to have a

    a_ref = 2;

    LOG(a); // 2

    Increament(a);
    LOG(a); // 2

    // int* pointer = &variable;
    Increament2(&a);
    LOG(a); // 3

    // int& reference = variable;
    Increament3(a);
    LOG(a); // 4

    std::cin.get();
  }
