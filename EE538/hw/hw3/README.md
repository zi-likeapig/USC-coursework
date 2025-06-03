[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/YiBV7igX)
# HW3 EE538

## University of Southern California

## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

## Important:

- Use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:

| Question | Points |
| -------- | ------ |
| 1        | 16     |
| 2        | 20     |
| 3        | 20     |
| 4        | 20     |
| 5        | 24     |

- 100 points is considered full credit.

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
## file 1
### Q1
 - `Non-parameterized constructor` --> calls non-parameterized constructor for MyClass o1
 - `o1.v_.size(): 0` --> cout in block, because non-parameterized constructor does not push values, so the size_ be initialized as 0
 - `Destructor` --> when the block ends, destruct o1
### Q2
 - `Non-parameterized constructor` --> MyClass o1
 - `Parameterized constructor` --> MyClass o2(1, 3)
 - `Copy constructor` --> MyClass o3 = o1
 - `Destructor` --> for o3 
 - `Destructor` --> for o2
 - `Destructor` --> for o1
When the block ends, destruct all local objects in the reverse order their construction
### Q3
 - `Non-parameterized constructor` --> MyClass o
 - `Copy constructor` --> passing value, call copy constructor for o in function
 - `Something 1.` --> cout in function DoSomething1 
 - `Destructor` --> when the function return, destruct o in fuction
 - `Destructor` --> destruct o in {}
### Q4
 - `Non-parameterized constructor` --> MyClass o
 - `Something 2.` --> passing reference, cout in function DoSomething2
 - `Destructor` --> destruct o in {}
### Q5
 - `Non-parameterized constructor` --> MyClass o
 - `Something 3.` --> passing reference, cout in function DoSomething3
 - `Destructor` --> destruct o in {}
### Q6
 - `Non-parameterized constructor` --> MyClass o
 - `Copy constructor` --> passing reference, MyClass o2 = o in function
 - `Something 4.` --> cout in function DoSomething4
 - `Destructor` --> destruct o2 in funtion
 - `Destructor` --> destruct o in {}
### Q7
 - `Parameterized constructor` --> MyClass(1, 2)
 - `Copy constructor` --> when `std::pair<MyClass, int> p1 = {MyClass(1, 2), 0};`, p1.first will call copy constructor to copy MyClass(1, 2), and initialized p1.second=0
 - `Destructor` --> when the end of copy for p1, MyClass(1, 2) will be destructed
 - `p1.first.v_.size(): 0` --> because only initialize a and b of p1.first, the v is empty, so p1.first.v_.size() = 0
 - `p1.second: 0`
 - `Copy constructor` --> when `std::pair<MyClass, int> p2 = p1;` p2.first will call copy constructor to copy p1.first
 - `p2.first.v_.size(): 0` --> p2.first.v_.size()=p1.first.v_.size()=0
 - `p2.second: 0` --> p2.second=p1.second=0
 - `Destructor` --> for p2
 - `Destructor` --> for p1
### Q8
 - `Parameterized constructor` --> MyClass(1, 2)
 - `Copy constructor` --> when `std::pair<MyClass, int> p1 = {MyClass(1, 2), 0};` p1.first will call copy constructor to copy MyClass(1, 2), and initialized p1.second=0
 - `Destructor` --> when the end of copy for p1, MyClass(1, 2) will be destructed
 - `Something 4.` --> p.second=0, passing reference, cout in function DoSomething4
 - `Something 4.` --> p.second=1, passing reference, cout in function DoSomething4
 - `Something 4.` --> p.second=2, passing reference, cout in function DoSomething4
 - `Destructor` --> p.second=3, for loop stop, destruct p in for loop
### Q9
 - `Parameterized constructor` --> o = new MyClass(1, 2)
This is an dynamically allocated object, because we don't `delete o`, so the destructor is not called
But it will lead memory leak!
### Q10
 - `Parameterized constructor` --> o = new MyClass(1, 2);
 - `Destructor` --> delete o;
The destructor is called because we delete the `new` memory
### Q11
 - `Non-parameterized constructor` --> MyClass()
 - `Copy constructor` --> copy MyClass() to a temporary pair1
 - `Parameterized constructor` --> MyClass(1, 2)
 - `Copy constructor` --> copy MyClass() to a temporary pair2
 - `Parameterized constructor` --> MyClass(3, 4)
 - `Copy constructor` --> copy MyClass() to a temporary pair3
 - `Copy constructor` --> copy pair1 to the map
 - `Copy constructor` --> copy pair2 to the map
 - `Copy constructor` --> copy pair3 to the map
 - `Destructor` --> for pair3
 - `Destructor` --> for pair3
 - `Destructor` --> for pair3
 - `Destructor` --> for MyClass(3, 4)
 - `Destructor` --> for MyClass(1, 2)
 - `Destructor` --> for MyClass()
 - `Copy constructor` --> pass value in for loop, call copy constructor for e to copy {0, MyClass()}
 - `Destructor` --> in the end of this loop, destruct temporary copy
 - `Copy constructor` --> pass value in for loop, call copy constructor for e to copy {3, MyClass(1, 2)}
 - `Destructor` --> in the end of this loop, destruct temporary copy
 - `Copy constructor` --> pass value in for loop, call copy constructor for e to copy {5, MyClass(3, 4)}
 - `Destructor` --> in the end of this loop, destruct temporary copy
 - `Destructor` --> destruct {5, MyClass(3, 4)} in map
 - `Destructor` --> destruct {3, MyClass(1, 2)} in map
 - `Destructor` --> destruct {0, MyClass()} in map
### Q12
 - `Non-parameterized constructor` --> MyClass()
 - `Copy constructor` --> copy MyClass() to a temporary pair1
 - `Parameterized constructor` --> MyClass(1, 2)
 - `Copy constructor` --> copy MyClass() to a temporary pair2
 - `Parameterized constructor` --> MyClass(3, 4)
 - `Copy constructor` --> copy MyClass() to a temporary pair3
 - `Copy constructor` --> copy pair1 to the map
 - `Copy constructor` --> copy pair2 to the map
 - `Copy constructor` --> copy pair3 to the map
 - `Destructor` --> for pair3
 - `Destructor` --> for pair3
 - `Destructor` --> for pair3
 - `Destructor` --> for MyClass(3, 4)
 - `Destructor` --> for MyClass(1, 2)
 - `Destructor` --> for MyClass()
 - `Destructor` --> destruct {5, MyClass(3, 4)} in map
 - `Destructor` --> destruct {3, MyClass(1, 2)} in map
 - `Destructor` --> destruct {0, MyClass()} in map
### Q13
 - `Parameterized constructor` --> o = new MyClass(1, 2);
 - `Destructor` --> delete o
### Q14
 - `Parameterized constructor` --> MyClass o(100000000);
 - `Operation took: 1234 milliseconds` --> cout in function PrintAndGetDuration
 - `Copy constructor` --> i=0, MyClass o2 = o;
 - `Copy constructor` --> passing value, call copy constructor for o in fuction DoSomething1
 - `Something 1.` --> cout in function DoSomething1
 - `Destructor` --> when fuction return, destruct o in fuction
 - `o2.v_.size(): 100000000` --> i=0, cout in for loop. o2.v_.size()=o.v_.size()=100000000
 - `Destructor` --> when the end of this loop(i=0), destruct o2
 - `Copy constructor` --> i=1, MyClass o2 = o;
 - `Copy constructor` --> passing value, call copy constructor for o in fuction DoSomething1
 - `Something 1.` --> cout in function DoSomething1
 - `Destructor` --> when fuction return, destruct o in fuction
 - `o2.v_.size(): 100000000` --> i=1, cout in for loop. o2.v_.size()=o.v_.size()=100000000
 - `Destructor` --> when the end of this loop(i=1), destruct o2
 - `Operation took: 1152 milliseconds` --> cout in function PrintAndGetDuration
 - `Destructor` --> for o(100000000)
The parameter 100000000 is the size of vector<int> v_ in class. When we passing value and call copy constructor, it should copy this huge vector which might be very slow.
### Q15
 - `Parameterized constructor` --> MyClass o(100000000);
 - `Operation took: 1234 milliseconds` --> cout in function PrintAndGetDuration
 - `Copy constructor` --> i=0, MyClass o2 = o
 - `Something 2.` --> passing reference, cout in function DoSomething2
 - `o2.v_.size(): 100000000` --> i=0, cout in for loop. o2.v_.size()=o.v_.size()=100000000
 - `Destructor` --> when the end of this loop(i=0), destruct o2
 - `Copy constructor` --> i=1, MyClass o2 = o
 - `Something 2.` --> passing reference, cout in function DoSomething2
 - `o2.v_.size(): 100000000` --> i=1, cout in for loop. o2.v_.size()=o.v_.size()=100000000
 - `Destructor` --> when the end of this loop(i=1), destruct o2
 - `Operation took: 574 milliseconds` --> cout in function PrintAndGetDuration
 - `Destructor` --> for o(100000000)
In this case we use function DoSomething2 which is passing reference. It will avoid coping huge vector, so the time it cost is less than Q14.
### Q16
 - `Parameterized constructor` --> MyClass(10000000)
 - `Parameterized constructor` --> MyClass(20000000)
 - `Parameterized constructor` --> MyClass(30000000)
 - `Parameterized constructor` --> MyClass(40000000)
 - `Parameterized constructor` --> MyClass(50000000)
 - `Parameterized constructor` --> MyClass(60000000)
 - `Parameterized constructor` --> MyClass(70000000)
 - `Copy constructor` --> copy MyClass(10000000) to my_vector[0]
 - `Copy constructor` --> copy MyClass(20000000) to my_vector[1]
 - `Copy constructor` --> copy MyClass(30000000) to my_vector[2]
 - `Copy constructor` --> copy MyClass(40000000) to my_vector[3]
 - `Copy constructor` --> copy MyClass(50000000) to my_vector[4]
 - `Copy constructor` --> copy MyClass(60000000) to my_vector[5]
 - `Copy constructor` --> copy MyClass(70000000) to my_vector[6]
 - `Destructor` --> for MyClass(10000000)
 - `Destructor` --> for MyClass(20000000)
 - `Destructor` --> for MyClass(30000000)
 - `Destructor` --> for MyClass(40000000)
 - `Destructor` --> for MyClass(50000000)
 - `Destructor` --> for MyClass(60000000)
 - `Destructor` --> for MyClass(70000000)
 - `Operation took: 4608 milliseconds` --> cout in function PrintAndGetDuration
 - `Copy constructor` --> passing value, call copy constructor for e to copy my_vector[0]
 - `e.v_.size(): 10000000` --> e.v_.size()=my_vector[0].v_.size()=10000000
 - `Destructor` --> when the end of this loop, destruct e
 - `Copy constructor` --> passing value, call copy constructor for e to copy my_vector[1]
 - `e.v_.size(): 20000000` --> e.v_.size()=my_vector[1].v_.size()=20000000
 - `Destructor` --> when the end of this loop, destruct e
 - `Copy constructor` --> passing value, call copy constructor for e to copy my_vector[2]
 - `e.v_.size(): 30000000` --> e.v_.size()=my_vector[2].v_.size()=30000000
 - `Destructor` --> when the end of this loop, destruct e
 - `Copy constructor` --> same as above loops
 - `e.v_.size(): 40000000`
 - `Destructor`
 - `Copy constructor`
 - `e.v_.size(): 50000000` 
 - `Destructor` 
 - `Copy constructor`
 - `e.v_.size(): 60000000`
 - `Destructor` 
 - `Copy constructor` 
 - `e.v_.size(): 70000000`
 - `Destructor` --> 
 - `Operation took: 740 milliseconds` --> cout in function PrintAndGetDuration
 - `e.v_.size(): 10000000` --> passing reference, don't need to call copy constructor, e.v_.size()=my_vector[0].v_.size()=10000000
 - `e.v_.size(): 20000000` --> passing reference, don't need to call copy constructor, e.v_.size()=my_vector[1].v_.size()=20000000
 - `e.v_.size(): 30000000` --> passing reference, don't need to call copy constructor, e.v_.size()=my_vector[2].v_.size()=30000000
 - `e.v_.size(): 40000000` --> same as above loops
 - `e.v_.size(): 50000000` --> 
 - `e.v_.size(): 60000000` --> 
 - `e.v_.size(): 70000000` --> 
 - `Operation took: 0 milliseconds` --> cout in function PrintAndGetDuration
 - `Destructor` --> destruct my_vector[6]
 - `Destructor` --> destruct my_vector[5]
 - `Destructor` --> destruct my_vector[4]
 - `Destructor` --> destruct my_vector[3]
 - `Destructor` --> destruct my_vector[2]
 - `Destructor` --> destruct my_vector[1]
 - `Destructor` --> destruct my_vector[0]

## file 2
 - `MyVector::MyVector()`: O(1)
 - `MyVector::MyVector(int size)`: O(N) initializes an array of size elements, setting them all to zero
 - `MyVector::MyVector(const MyVector& rhs)`: O(N) allocates new memory and copies all elements
 - `MyVector::~MyVector()`: O(1) delete int* data_, because of contiguous memory
 - `push_back(int value)`: O(N), allocate a new array of size n+1, copies all elements, and adds the new element
 - `pop_back()`: O(n), creates a new array of size n−1, copies all elements except the last one, and deletes the old array
 - `push_front(int value)`: O(N), allocates a new array of size n+1, shifts all elements, and inserts the new value at the front
 - `pop_front()`: O(N),creates a new array of size n−1, shifts all elements left by one, and deletes the old array
 - `insert(int value, int index)`: O(N), creates a new array of size n+1, copies elements before and after the insertion point
 - `at(int index)`: O(1) indexing
 - `find(int item)`: O(N), linear search
 - `get_error()`: O(1)
 - `size()`: O(1)
 - `ConvertToStdVector()`: O(N), Copies elements into a std::vector

## file 3
 - `Queue::Queue(const Queue& rhs)`: O(n), v_ = rhs.v_: creates a copy of the vector
 - `Queue::operator=(const Queue& rhs)`: O(n), the assignment v_ = rhs.v_: replaces the existing vector contents with rhs.v_, which involves copying elements
 - `Queue::operator+(const Queue& rhs)`: O(n+m) (where n is this->size() and m is rhs.size()), `Queue new_q(rhs)` calls the copy constructor, which is O(m); `new_q.v_.insert(new_q.v_.end(), v_.begin(), v_.end())` inserts elements of v_ at the end, which takes O(n)
 - `Queue::Enqueue(int value)`: O(1) in average, calls vector.push_back()
 - `Queue::Dequeue()`: O(n), `v_.erase(v_.begin())` removes the first element. Since std::vector shifts all remaining elements left, the operation takes linear time
 - `Queue::IsEmpty()`: O(1), calls vector.empty()
 - `Queue::Front()`: O(1), calls vector.front()

## file 4
 - `DoubleStack::DoubleStack()`: O(1)
 - `push(int num)`: O(1) in average, calls vector.push_back()
 - `pop()`: O(1), vector::pop_back() removes the last element in constant time. It checks which vector to pop from, which involves a few empty() checks and comparisons, but those are all O(1)
 - `top()`: O(1), calls vector.empty(), vector.back(), std::max() they are all O(1)
 - `size()`: O(1), calls vector.size()
 - `empty()`: O(1), calls vector.front()

## file 5
### `CheckValidExpression(const std::string& input)`
 - Iterates over the input string once (for loop)
 - Each operation (pushing, popping, checking top, checking map) takes O(1)
 - Total time: O(n)
### `IsPalindrome(const std::string& input)`
 - The loop runs at most n/2 times, where n is the length of input
 - Each comparison takes O(1).
 - Total time: O(n)
### `OddChar(const std::string& input)`
 - The first loop iterates over the input string and updates the map O(n)
 - The second loop iterates over the map, which has at most O(1) (bounded by character set size, at most 256 in ASCII)
 - Total time: O(n)