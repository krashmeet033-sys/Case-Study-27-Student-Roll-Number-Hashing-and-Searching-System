
#include <iostream>
#include <iomanip>
using namespace std;

// 1. Hash Table Configuration
const int TABLE_SIZE = 10;

// Student Record Structure
struct Student {
    int rollNumber;
    bool occupied;
};

// Hash Table
Student hashTable[TABLE_SIZE];

// Initialize Hash Table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].rollNumber = -1;
        hashTable[i].occupied = false;
    }
}

// 2. Hash Function using Modulo Operator
int hashFunction(int rollNumber) {
    return rollNumber % TABLE_SIZE;
}

// 3. Insert Student Record using Linear Probing
bool insertStudent(int rollNumber) {

    int index = hashFunction(rollNumber);
    int originalIndex = index;

    cout << "\nInserting Roll Number: " << rollNumber << endl;
    cout << "Calculated Hash Index: " << index << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {

        if (hashTable[index].occupied) {

            // Check for duplicate roll number
            if (hashTable[index].rollNumber == rollNumber) {
                cout << "Duplicate Roll Number! Please enter a unique roll number.\n";
                return false;
            }

            // Collision detected
            cout << "Collision at index " << index
                 << " (occupied by Roll Number "
                 << hashTable[index].rollNumber << ")" << endl;

            // Linear Probing
            index = (index + 1) % TABLE_SIZE;

            cout << "Checking next index: " << index << endl;
        }

        else {

            // Insert record at available position
            hashTable[index].rollNumber = rollNumber;
            hashTable[index].occupied = true;

            cout << "Roll Number " << rollNumber
                 << " inserted successfully at index "
                 << index << endl;

            if (index != originalIndex) {
                cout << "Position found using Linear Probing.\n";
            }

            return true;
        }
    }

    cout << "Hash Table is FULL! Cannot insert Roll Number "
         << rollNumber << endl;

    return false;
}

// 4. Search Student Record using Linear Probing
void searchStudent(int rollNumber) {

    int index = hashFunction(rollNumber);

    cout << "\nSearching for Roll Number: "
         << rollNumber << endl;

    cout << "Calculated Hash Index: " << index << endl;

    for (int i = 0; i < TABLE_SIZE; i++) {

        // Empty position means record is not present
        if (!hashTable[index].occupied) {
            cout << "Student Record NOT FOUND.\n";
            return;
        }

        // Record found
        if (hashTable[index].rollNumber == rollNumber) {

            cout << "Student Record FOUND!\n";
            cout << "Roll Number: "
                 << hashTable[index].rollNumber << endl;

            cout << "Hash Table Index: "
                 << index << endl;

            return;
        }

        cout << "Roll Number not found at index "
             << index << ". Checking next index...\n";

        // Continue Linear Probing
        index = (index + 1) % TABLE_SIZE;
    }

    cout << "Student Record NOT FOUND.\n";
}

// 5. Display Hash Table
void displayTable() {

    cout << "\n========== STUDENT HASH TABLE ==========\n";

    cout << left << setw(15) << "Hash Index"
         << setw(20) << "Roll Number"
         << "Status" << endl;

    cout << "----------------------------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {

        cout << left << setw(15) << i;

        if (hashTable[i].occupied) {

            cout << setw(20) << hashTable[i].rollNumber
                 << "Occupied" << endl;
        }
        else {

            cout << setw(20) << "EMPTY"
                 << "Available" << endl;
        }
    }

    cout << "========================================\n";
}

// 6. Main Function
int main() {

    initializeTable();

    int n, rollNumber;

    cout << "========================================\n";
    cout << " STUDENT ROLL NUMBER HASHING SYSTEM\n";
    cout << "========================================\n";

    cout << "\nEnter number of student records (Minimum 8): ";
    cin >> n;

    // Validate number of records
    if (cin.fail() || n < 8 || n > TABLE_SIZE) {

        cout << "Invalid input! Enter between 8 and 10 records.\n";
        return 0;
    }

    // Accept unique student roll numbers
    cout << "\nEnter " << n << " Unique Student Roll Numbers:\n";

    int count = 0;

    while (count < n) {

        cout << "Student " << count + 1 << ": ";
        cin >> rollNumber;

        if (cin.fail() || rollNumber <= 0) {

            cout << "Invalid Roll Number! Enter a positive integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Count only successfully inserted records
        if (insertStudent(rollNumber)) {
            count++;
        }
    }

    // Display Hash Table after insertion
    displayTable();

    // Search for a particular student
    int searchRollNumber;

    cout << "\nEnter Roll Number to Search: ";
    cin >> searchRollNumber;

    if (cin.fail() || searchRollNumber <= 0) {

        cout << "Invalid Roll Number!\n";
        return 0;
    }

    searchStudent(searchRollNumber);

    // Display final Hash Table
    displayTable();

    cout << "\nProgram executed successfully!\n";

    return 0;
}
