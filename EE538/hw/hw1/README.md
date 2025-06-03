[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/9yWLqeIe)

# HW1 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc.
  We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 18     |
| 2        | 18     |
| 3        | 18     |
| 4        | 18     |
| 5        | 18     |
| 6        | 18     |
| 7        | 18     |

- Total: 126 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
### Question 1

#### Reverse Function
```cpp
std::vector<int> Reverse(std::vector<int> input) {
    int len = input.size();     // 1
    std::vector<int> output(len);
    for(int i=0;i<len;i++) 
        output[i]=input[len-i-1];   // n
    return output;
}
```
- The `for` loop iterates over the input vector, performing \(n\) operations, where \(n\) is the size of the input vector.
- **Total:** \(O(n)\)


#### PlusOne Function
```cpp
std::vector<int> PlusOne(std::vector<int> input) {
    if (input.empty())    // 1
        return {};

    int number = 0;
    for (int i = 0; i < (int)input.size(); i++) {   // n
        if (input[i] > 9 || input[i] < 0) 
            return {-1};
        number = number * 10 + input[i];
    }
    number += 1;

    std::vector<int> output;
    while (number != 0) {   // n or n+1
        output.push_back(number % 10);
        number /= 10;
    }
    output = Reverse(output); //n
    return output;
}
```
- **Step 1:** The `for` loop iterates over the input vector to validate the input and calculate the number, which takes \(O(n)\), where \(n\) is the size of the input vector.
- **Step 2:** The `while` loop extracts digits of the number and pushes them to the output vector. This loop takes \(O(\log_{10}(number))\). For most practical cases, the number of digits is proportional to the size of the input, so this step is effectively \(O(n)\).
- **Step 3:** The `Reverse` function is called, which has a time complexity of \(O(n)\).
- **Total:** \(O(n)\).


### Question 2

#### PrimeCheck Function
```cpp
bool IsPrime(int number) {
    if(number<=1)
        return false;

    for(int i=2;i<=sqrt(number);i++) {  // sqrt{n}
        if(number%i==0)
            return false;
    }
    return true;
}
```
- Iterate from 2 to \(\sqrt{n}\) and check divisibility for each number. The loop runs approximately \(\sqrt{n}\) times.
- **Total:** \(O(\sqrt{n})\)

### Question 3

#### CountNumberOfSpaces Function
```cpp
int CountNumberOfSpaces(std::string input) {
    int count=0;
    for(int i=0;i<input.size();i++) {   // n 
        if(input[i]==' ')
            count++;
    }
    return count;
}
```
- The `for` loop iterates through all characters in the string, performing \(n\) comparisons and increments, where \(n\) is the length of the string.
- **Total:** \(O(n)\)


### Question 4

#### Flatten3DVector Function
```cpp
std::vector<int> Flatten3DVector(std::vector<std::vector<std::vector<int>>> input) {
    std::vector<int> output;
    for(int i=0;i<input.size();i++) {   // d1
        for(int j=0;j<input[i].size();j++) {    // d1*d2
            for(int t=0;t<input[i][j].size();t++) {   //d1*d2*d3
                output.push_back(input[i][j][t]);
            }
        }
    }
    return output;
}
```
- **Step 1:** The outermost loop iterates over the 3D vector's first dimension, taking \(O(d_1)\), where \(d_1\) is the size of the outermost vector.
- **Step 2:** The second loop iterates over the second dimension for each element in the first dimension, taking \(O(d_2)\) for each outer element. This results in a total of \(O(d_1 \cdot d_2)\).
- **Step 3:** The innermost loop iterates over the third dimension for each element in the second dimension, taking \(O(d_3)\) for each pair of outer elements. This results in a total of \(O(d_1 \cdot d_2 \cdot d_3)\).
- **Total:** \(O(d_1 \cdot d_2 \cdot d_3)\)


### Question 5

#### ClimbStairs Function
```cpp
int ClimbStairs(int n) {
    int step=0;

    if(n==0) 
        return 0;
    else if(n<0)
        return -1;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    
    step=step+ClimbStairs(n-1)+ClimbStairs(n-2)+ClimbStairs(n-3);
    
    return step;
}
```
- **Step 1:** For each input \(n\), the function makes recursive calls to \(ClimbStairs(n-1)\), \(ClimbStairs(n-2)\), and \(ClimbStairs(n-3)\).
- **Step 2:** This creates a tree of recursive calls with branching factor 3 and depth \(n\), leading to \(O(3^n)\) recursive calls in total.
- **Total:** \(O(3^n)\)


### Question 6

#### Calculator Function
```cpp
ErrorCode Calculator(float a, float b, float &sum, float &diff, float &product, float &ratio) {
    sum=a+b;    // 1
    diff=a-b;   // 1
    product=a*b;    // 1
    if(b==0)    // 1
        return ErrorCode::kDivideByZero;
    else ratio=a/b;

    return ErrorCode::kNoError;
}
```
- **Step 1:** Addition, subtraction, and multiplication operations are performed, each taking \(O(1)\).
- **Step 2:** A conditional check is performed to determine if the divisor is zero. This takes \(O(1)\).
- **Step 3:** If the divisor is not zero, a division operation is performed, taking \(O(1)\).
- **Total:** \(O(1)\)


### Question 7

#### CanBecome Function
```cpp
bool CanBecome(const std::string &s, const std::string &goal) {
    if(s.size()!=goal.size())
        return false;
    if(s.size()==0)
        return true;
    int len=s.size();
    for(int i=0;i<len;i++) {  // n
        if(goal[i]==s[0]) {
            bool same=true;
            for(int j=0;j<len;j++) {  // n*n
                if(goal[(i+j)%len]!=s[j])
                    same=false;
            }
            if(same==true) return true;
        }
    }
    return false;
}
```
- **Step 1:** The `for` loop iterates over the length of the string \(s\) (denoted as \(n\)), and for each character, checks if it matches the first character of `goal`, which takes \(O(n)\).
- **Step 2:** Inside the outer loop, a nested `for` loop iterates to compare the rotated version of \(s\) with `goal`, taking \(O(n)\) for each rotation.
- **Total:** \(O(n^2)\)

