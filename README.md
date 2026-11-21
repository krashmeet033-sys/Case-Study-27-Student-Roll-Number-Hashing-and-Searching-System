# Student Roll Number Hashing and Searching System

### DSA Case Study 27 | C++ Implementation

A menu-free, console-based C++ application that demonstrates the implementation of a Hash Table for storing and searching student roll numbers using the Modulo Hash Function and Linear Probing for collision resolution.

---

## 1. Problem Statement

A college maintains a large number of student records identified by unique roll numbers. Searching for a particular student record using conventional searching techniques can become inefficient as the number of records increases.

The objective of this case study is to develop a Student Roll Number Hashing and Searching System using a Hash Table that enables efficient insertion and searching of student roll numbers.

The system uses a modulo-based hash function to calculate the index for each roll number and Linear Probing to resolve collisions when multiple roll numbers generate the same index.

## 2. Objectives

- Implement a Hash Table of fixed size 10.
- Accept at least eight unique student roll numbers.
- Generate hash indexes using the Modulo Operator.
- Insert student records into the Hash Table.
- Detect and handle collisions using Linear Probing.
- Search for a particular student roll number.
- Display the complete Hash Table after insertion.
- Demonstrate multiple collisions and their resolution.

## 3. Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Programming language |
| iostream | Input and output operations |
| iomanip | Formatted Hash Table display |
| Arrays | Hash Table implementation |
| Modulo Operator | Hash index calculation |

## 4. Data Structures and Concepts Used

**Hashing**

A technique used to store and retrieve records efficiently by converting a key into an index using a hash function.

**Hash Function**

The function that calculates the appropriate index for a student roll number.

**Hash Table**

An array-based data structure used to store student roll numbers at their calculated indexes.

**Collision**

A collision occurs when two or more different roll numbers generate the same hash index.

**Linear Probing**

A collision resolution technique that checks the next consecutive position until an empty location is found.

**Searching**

The process of locating a particular student roll number by calculating its hash index and following the Linear Probing sequence when necessary.

## 5. Hash Function

The project uses the Modulo Hash Function:

```cpp
int hashFunction(int rollNumber) {
    return rollNumber % TABLE_SIZE;
}
```

Mathematical representation:

**h(k) = k % 10**

Where:

- `h(k)` = Calculated hash index
- `k` = Student roll number
- `10` = Hash Table size

### Example

For roll number 101:

`101 % 10 = 1`

Therefore, the calculated hash index is 1.

For roll number 111:

`111 % 10 = 1`

Both roll numbers generate the same index, resulting in a collision.

## 6. Collision Resolution – Linear Probing

The project uses Linear Probing to handle collisions.

Whenever the calculated hash index is already occupied, the system checks the next position using:

```cpp
index = (index + 1) % TABLE_SIZE;
```

This process continues until an available position is found.

The modulo operation also ensures that the search wraps around to index 0 when the end of the Hash Table is reached.

## 7. Sample Input

The following eight unique student roll numbers were used to test the implementation:

| Student | Roll Number |
|---|---:|
| Student 1 | 101 |
| Student 2 | 111 |
| Student 3 | 121 |
| Student 4 | 132 |
| Student 5 | 142 |
| Student 6 | 152 |
| Student 7 | 163 |
| Student 8 | 173 |

Search operation: `111`

## 8. Collision Demonstration

The following examples demonstrate how multiple roll numbers generate the same hash index.

| Roll Number | Hash Calculation | Original Index | Final Index |
|---|---|---:|---:|
| 101 | 101 % 10 | 1 | 1 |
| 111 | 111 % 10 | 1 | 2 |
| 121 | 121 % 10 | 1 | 3 |
| 132 | 132 % 10 | 2 | 4 |
| 142 | 142 % 10 | 2 | 5 |
| 152 | 152 % 10 | 2 | 6 |
| 163 | 163 % 10 | 3 | 7 |
| 173 | 173 % 10 | 3 | 8 |

The final index changes when the calculated position is occupied. Linear Probing checks subsequent positions to find an available location.

## 9. Final Hash Table

After inserting all eight student roll numbers, the Hash Table is:

| Hash Index | Roll Number | Status |
|---:|---:|---|
| 0 | EMPTY | Available |
| 1 | 101 | Occupied |
| 2 | 111 | Occupied |
| 3 | 121 | Occupied |
| 4 | 132 | Occupied |
| 5 | 142 | Occupied |
| 6 | 152 | Occupied |
| 7 | 163 | Occupied |
| 8 | 173 | Occupied |
| 9 | EMPTY | Available |

## 10. Searching Demonstration

The program searches for student roll number `111`.

1. Calculate the hash index: `111 % 10 = 1`.
2. Check index 1. It contains roll number 101.
3. Since the required roll number is not found, check the next index.
4. Check index 2. It contains roll number 111.
5. The student record is successfully found at index 2.

**Search Result:** Student Record FOUND!

**Roll Number:** 111

**Hash Table Index:** 2

## 11. Program Features

- Fixed-size Hash Table with 10 positions.
- Acceptance of 8 to 10 student records.
- Positive integer validation for roll numbers.
- Duplicate roll number prevention.
- Collision detection with informative console messages.
- Linear Probing with circular index calculation.
- Successful and unsuccessful search handling.
- Full Hash Table detection.
- Formatted Hash Table display.

## 12. Time and Space Complexity

Let `n` represent the number of positions in the Hash Table.

| Operation | Average Case | Worst Case |
|---|---|---|
| Hash Function | O(1) | O(1) |
| Insertion | O(1) | O(n) |
| Searching | O(1) | O(n) |
| Display | O(n) | O(n) |

**Space Complexity:** O(n), where `n` is the Hash Table size.

Hashing provides efficient average-case insertion and searching. However, in the worst case, multiple collisions can increase the number of positions that must be checked.

## 13. How to Compile and Execute

### Prerequisites

- C++ compiler (G++ recommended).
- Terminal or command-line environment.

### Step 1: Compile the program

```bash
g++ CaseStudy27_Hashing.cpp -o hashing
```

### Step 2: Execute the program

On macOS or Linux:

```bash
./hashing
```

On Windows:

```bash
hashing.exe
```

### Step 3: Enter student records

- Enter the number of student records (between 8 and 10).
- Enter unique positive student roll numbers.
- Observe collision detection and Linear Probing.
- View the final Hash Table.
- Enter a roll number to search for.

## 14. Expected Output

The program displays:

- Calculated hash indexes.
- Collision detection messages.
- Next available index checks.
- Successful student record insertion.
- Complete Hash Table.
- Search result and corresponding Hash Table index.
- Final Hash Table after searching.

## 15. Conclusion

The Student Roll Number Hashing and Searching System successfully demonstrates the practical implementation of Hashing using C++.

The project uses a modulo-based hash function to calculate indexes and Linear Probing to resolve collisions. It also demonstrates student record insertion, duplicate prevention, searching, and Hash Table display.

Through this implementation, the fundamental concepts of Hash Tables, Hash Functions, Collisions, Linear Probing, and Searching are demonstrated practically.

---

## Author

**Rashmeet Kaur Nanade**

B.Tech – Computer Science and Engineering

ITM Skills University

**Subject:** Data Structures and Algorithms

**Case Study:** 27 – Student Roll Number Hashing and Searching System
