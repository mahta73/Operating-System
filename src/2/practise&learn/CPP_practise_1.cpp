  // vector in c++

  #include <iostream>
  #include <algorithm>
  #include <vector>

  using namespace std;

  // show elements of the vector
  void show_vector_elements(vector<int> v) {
    cout << "Vector elements: " << endl;
    for (unsigned int i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
    }
  };

  int main() {
    // vector<type> vector_name(number of elements);
    vector<int> vector_1;

    // fill the vector from 0 to 19
    for (unsigned int i = 0; i < 20; i++) {
      // push_back() adds an element to the end of the vector also resize it
      vector_1.push_back(i);
    }

    cout << "The size of the vector is: " << vector_1.size() << endl;

    show_vector_elements(vector_1);

    // at(index) returns element at a specific index number
    cout << "Vector at a specific index " << vector_1.at(5) << endl;

    // .begin() reads vector from first element
    // .end()  reads vector from last element
    // .insert(vector_1.begin() + integer, value) adds element before specifed number
    vector_1.insert( vector_1.begin() , -1);

    show_vector_elements(vector_1);

    // .erase() removes and element at the specifed index
    vector_1.erase( vector_1.begin() );

    show_vector_elements(vector_1);

    // clear() removes all elements from the vector

    vector_1.clear();

    cout << vector_1.empty() << endl; // 1 -> wich means true in c++
    return 0;
  }
