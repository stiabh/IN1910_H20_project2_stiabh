# IN1910 – Project 2
*Stian Berg Hansen*  

Completed every exercise. Using Ubuntu 20.04 through WSL. Compiled and run with following command:  
`g++ <script_name>.cpp -o <script_name>.out -std=c++11 && ./<script_name>.out`  

https://github.uio.no/IN1910/H20_project2_stiabh  

## Part 3: Big-O analysis
### array_list.cpp

| Operation | Cost | Explanation |
|-|-|-|
| Get element i by index | O(1) | Every element is stored   contiguously in memory, therefore not dependent on array size. |
| Insert at front | O(n)* | No specific method, but would   work the same way as insert(). Entire array is shifted. Sometimes resizing   will be necessary, which is why the cost is amortized. |
| Insert at back (aka append) | O(1)* | Constant cost, assigns value to   memory block after "size". Resizing sometimes necessary. |
| Insert into middle of list | O(n)* | Shifts array, cost can also be   written as O(n-i). Resizing sometimes necessary. |
| Remove element from front | O(n)* | Shifts entire array. Amortized   cost as array will be resized if size/capacity < .25. |
| Remove element from back | O(1)* | Assuming pop() is used.   Amortized cost as array will be resized if size/capacity < .25. |
| Remove element from middle | O(n)* | See explanation for removing   from front. |
| Print | O(n) | Iterates over array until entry   number "size" is reached. |

### linked_list.cpp

| Operation | Cost | Explanation |
|-|-|-|
| Get element i by index | O(n) | Uses get_node(), which starts at   head and iterates over every element until index i is reached. Can also be   written as O(n-i). |
| Insert at front | O(1) | Replaces head, every operation has a constant cost. |
| Insert at back (aka append) | O(1) | Replaces tail, every operation has a constant cost. |
| Insert into middle of list | O(n) | Same explanation as get element i by index. |
| Remove element from front | O(1) | Replaces head, every operation has a constant cost. |
| Remove element from back | O(1) | Replaces tail, every operation has a constant cost. |
| Remove element from middle | O(n) | Same explanation as get element i by index. |
| Print | O(n) | Iterates over every element in chain. |

## Part 4: Circularly Linked List
### Exercise 4g)

If *n* = 68 and *k* = 7, then the last man standing will be number 68. Found by running `last_man_standing(68, 7)`.
