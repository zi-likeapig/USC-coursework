[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/lWdvaK1G)

# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

Important: Please use bazel with c++17:

```bash
bazel test --cxxopt="-std=c++17"  {test_target}
```

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 10     |
| 2        | 18     |
| 3        | 10     |
| 4        | 20     |
| 5        | 25     |
| 6        | 30     |

- 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Write non-coding answers below

### Question 1

#### CountCharacters Function
```cpp
std::map<char, int> CountCharacters(std::string& input) {
    std::map<char,int> chars;
    for(auto c : input) {   //n
        chars[c]++; //worse logn
    }
    return chars;
}
```
- Outer loop runs O(N)
- Since the keys in `std::map` are ordered like a `std::set`, `chars[c]++` has two possible cases:
    - Inserting a new key is equivalent to `set.insert()`, which takes O(log N).
    - Updating an existing key is equivalent to `set.find()`, which also takes O(log N).
- **Total:** O(N log N)






### Question 2

#### Question1 Function
##### **Errors**
1. The original code `elements[i] = 0;` attempts to access an index in the vector that has not been allocated, leading to out-of-bounds access, which may cause undefined behavior.  
2. The variable `element` is declared but never used.  

##### **Fix**
1. Replace `elements[i] = 0;` with `elements.push_back(0);`, which safely appends elements to the vector, preventing out-of-bounds errors.  
2. Remove the unused variable `element`.

#### Question2 Function
##### **Errors**
1. The original code `int* a;` declared a pointer but did not initialize it, making dereferencing `*a = 12;` leads to undefined behavior.  
2. The allocated memory was not released, which would cause a memory leak.

##### **Fix**
1. Change `int* a;` to `int* a = new int;` to allocate valid memory before dereferencing.  
2. Add `delete a;` to release the memory.


#### Question3 Function
##### **Errors**
1. The allocated memory was not released, which would cause a memory leak.

##### **Fix**
1. Add `delete a;` and `delete b;` to release the memory.

#### Question4 Function
##### **Errors**
1. The original code `a++` and `b++` incorrectly modify the pointer itself, causing it to point to an invalid memory location, leading to undefined behavior.  
2. The allocated memory was not released, which would cause a memory leak.
##### **Fix**
1. Remove `a++` and `b++`, ensuring the pointer remains valid.  
2. Add `delete a;` and `delete b;` to release the allocated memory.
   
#### Question5 Function
##### **Errors**
1. The original code contained `i = i - 1;`, which negated the effect of `i++`, causing an infinite loop.
##### **Fix**
1. Change `i = i - 1;` to `i = i + 1;` to prevent the infinite loop and ensure the intended output.
   
#### Question6 Function
##### **Errors**
1. The original code modified `std::set<int>` while iterating over it, causing iterator invalidation, which could lead to undefined behavior.  
2. `insert((*it) + 1);` inside the loop dynamically expanded the `set`, potentially leading to infinite loops.
##### **Fix**
1. Use `std::vector<int> new_elements` to temporarily store the new values.  
2. After the iteration completed, inserted the stored values into `set`, avoiding modification during traversal and infinite loops.
   






### Question 3

#### SwapByPointer Function
```cpp
void SwapByPointer(float *input1, float *input2) {
    if(input1==nullptr || input2==nullptr) return;  //1
    float a=(*input1);  //1
    (*input1)=(*input2);    //1
    (*input2)=a;    //1
}
```
- **Total:** O(1)
  
#### SwapByReference Function
```cpp
void SwapByReference(float &input1, float &input2) {
    float a=input1; //1
    input1=input2;  //1
    input2=a;   //1
}
```
- **Total:** O(1)





### Question 4

#### UniqueVectorNotBySet Function
```cpp
void UniqueVectorNotBySet(std::vector<int> &input) {
    for(int i=0;i<input.size();i++) {   //n
        for(int j=i-1;j>=0;j--) {   //worse n
            if(input[i]==input[j]) {
                input.erase(input.begin()+i);   //worse n
                i--;
                break;
            }
        }
    }
}
```
- Outer loop runs O(N).
- Inner loop in the worst case runs O(N).
- `erase(input.begin() + i)` takes O(N), as every vector elements behind i must shift left.
- **Total** : O(N) * O(N) * O(N) = O(N³)
  
#### UniqueVectorBySet Function
```cpp
void UniqueVectorBySet(std::vector<int> &input) {
    std::set<int> s;
    for(int i=0;i<input.size();i++) {   //n
        if(s.count(input[i])) { //logn
            input.erase(input.begin()+i);   //n
            i--;
        }
        else s.insert(input[i]); //logn
    }
}
```
- Outer loop runs O(N).
- `s.count(input[i])` runs in O(log N), since std::set is implemented as a balanced BST.
- `erase(input.begin() + i)` runs in O(N), as every vector elements behind i must shift left.
- **Total** : O(N) * (k * (O(log N) + O(N)) + (1-k) * O(log N)) = O(N²)

#### IntersectVectors Function
```cpp
std::vector<int> IntersectVectors(const std::vector<int> &input1, const std::vector<int> &input2) {
    std::set<int> s1,s2;
    std::vector<int> intersect;
    for(auto n:input1)  //n1
        s1.insert(n);   //log n1
    for(auto n:input2)  //n2
        s2.insert(n);   //log n2
    for(auto n:s1) {    //n1
        if(s2.count(n)) // log n2
            intersect.push_back(n); //1
    }
    return intersect;
}
```
- Inserting input1 into s1 takes O(N1 log N1).
- Inserting input2 into s2 takes O(N2 log N2).
- Checking for intersection:
    - Outer loop runs O(N1).
    - `s2.count(n)` runs in O(log N2).
    - `intersect.push_back(n)` runs in O(1) amortized, as `std::vector` appends in constant time, except for occasional reallocations.
- **Total** : O(N1 log N1) + O(N2 log N2) + O(N1 log N2) =  O((N1 + N2) log max(N1, N2))

#### DiffVectors Function
```cpp
std::set<int> DiffVectors(const std::vector<int> &input1, const std::vector<int> &input2) {
    std::vector<int> intersect=IntersectVectors(input1,input2);
    std::set<int> s1;
    for(auto n:input1) // n1
        s1.insert(n);   //log n1
    for(auto n:intersect) { //min(n1,n2)
        if(s1.count(n)) //log n1
            s1.erase(n);    // log n1
    }
    return s1;
}
```
- Calling IntersectVectors takes O((N1 + N2) log max(N1, N2))
- Inserting input1 into s1 takes O(N1 log N1).
- Checking for intersection:
    - Outer loop runs (O(min(N1, N2))).
    - `s1.count(n)` runs in O(log N1).
    - `s1.erase(n)` runs in O(log N1).
- **Total** : O((N1 + N2) log max(N1, N2)) + O(N1 log N1) + O(2 * min(N1, N2) log N1) =  O((N1 + N2) log max(N1, N2))





### Question 5

#### push_back Function
```cpp
void push_back(int *&array, int &size, int element) {
    int *new_array=new int[++size]; //n
    int i=0;
    for(;i<size-1;i++) //n
        new_array[i]=array[i];  //1
    new_array[i]=element;   //1
    delete[] array;     //1
    array=new_array;    //1
}
```
- Allocating a new array takes O(N).
- Copying all elements takes O(N).
- **Total:** O(N)
  
#### pop_back Function
```cpp
void pop_back(int *&array, int &size) {
    if(size==0) return; //1
    int *new_array=new int[--size]; //n
    for(int i=0;i<size;i++)     //n
        new_array[i]=array[i];  //1
    delete[] array; //1
    array=new_array;    //1
}
```
- Allocating a new array takes O(N).
- Copying N-1 elements takes O(N).
- **Total:** O(N)

#### insert Function
```cpp
void insert(int *&array, int &size, int element, int index) {
    if(index<0 || index>size) return;   //1
    int *new_array=new int[++size]; //n
    for(int i=0;i<size-1;i++) { //n
        if(i==index){
            new_array[i]=element;
            new_array[i+1]=array[i];
        }
        else if (i>index)
            new_array[i+1]=array[i];
        else new_array[i]=array[i];
    }
    if(index==size-1) //1
        new_array[index]=element;
    delete[] array; //1
    array=new_array;    //1
}
```
- Allocating a new array takes O(N).
- Copying and shifting all elements takes O(N).
- **Total:** O(N)

#### erase Function
```cpp
int erase(int *&array, int &size, int index) {
    if(size==0 || index>=size || index<0) return -1;    //1
    int *new_array=new int[--size]; //n
    for(int i=0;i<size+1;i++)  {    //n
        if(i==index)
            continue;
        else if (i>index)
            new_array[i-1]=array[i];
        else new_array[i]=array[i];
    }
    delete[] array; //1
    array=new_array;    //1
    return 0;
}
```
- Allocating a new array takes O(N).
- Copying and shifting elements takes O(N).
- **Total:** O(N)

#### find Function
```cpp
int find(const int *array, int size, int element) {
    for(int i=0;i<size;i++) {   //n
        if (array[i]==element)
            return i;
    }
    return -1;
}

```
- In the worst case, the loop iterates O(N) times.
- **Total:** O(N)







### Question 6

#### setDifference Function
```cpp
std::set<int> setDifference(const std::set<int> &set1, const std::set<int> &set2) {
    std::set<int> diff;
    for(auto n:set1) {  //n1
        if(!set2.count(n))  //log n2
            diff.insert(n); //worse log n1
    }
    return diff;
}
```
- Looping through set1: O(N1).
- Checking set2.count(n): O(log N2)
- Inserting into diff: O(log N1)
- **Total:** O(N1 (logN1 + logN2)) = O(N1 log max(N1, N2))

#### areDisjoint Function
```cpp
bool areDisjoint(const std::set<int> &set1, const std::set<int> &set2) {
    for(auto n:set1) {  // worse n1
        if(set2.count(n)) return false; //log n2
    }
    return true;
}
```
- Looping through set1: O(N1).
- Checking set2.count(n): O(log N2).
- **Total:** O(N1 log N2)
