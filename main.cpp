#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Structure to represent a student
struct Student {
    string name;    // Student's name
    int rollN;      // Student's roll number
    bool present;   // Attendance status (true for present, false for absent)
};

// Global vector to store student records
vector<Student> students;

// Function to save student records to a file
void save(const vector<Student>& students, const string& filename) {
    ofstream out(filename); // Open file for writing
    if (!out) {
        cerr << "Error: Unable to open file " << filename << endl; // Error message if file cannot be opened
        return;
    }
    // Write each student's record to the file
    for (const auto& student : students) {
        out << "Name: " << student.name << endl;
        out << "RollNo: " << student.rollN << endl;
        out << "Status: " << (student.present ? "Present" : "Absent") << endl << endl;
    }
    out.close(); // Close the file
    cout << "Records successfully saved to file: " << filename << endl;
}

// Main function to drive the program
int main() {
    cout << "-----------------------------------------------------" << endl;
    cout << " |        STUDENT ATTENDANCE MANAGEMENT SYSTEM     |" << endl;
    cout << "-----------------------------------------------------" << endl;

    int choice;
    while (true) {
        // Display menu options
        cout << "1 | Add Student" << endl;
        cout << "2 | Mark Attendance" << endl;
        cout << "3 | Show Details" << endl;
        cout << "4 | Save to File" << endl;
        cout << "0 | Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Option to add a new student
        if (choice == 1) {
            system("cls"); // Clear the screen
            char continueChoice;
            do {
                Student student; // Create a new student object
                cout << "Enter Name: "; cin >> student.name;
                cout << "Enter Roll No: "; cin >> student.rollN;
                student.present = false; // Default status is absent
                students.push_back(student); // Add student to the vector
                cout << "Student information added successfully." << endl;
                cout << "Enter 'x' to exit or 'c' to continue: "; cin >> continueChoice;
            } while (continueChoice != 'x' && continueChoice == 'c');
        }
        // Option to mark attendance
        else if (choice == 2) {
            system("cls"); // Clear the screen
            char attendanceChoice;
            for (auto& student : students) {
                cout << "Name: " << student.name << endl;
                cout << "RollNo: " << student.rollN << endl;
                cout << "'P' for present or 'A' for absent: "; cin >> attendanceChoice;
                student.present = (attendanceChoice == 'P'); // Set attendance status based on input
            }
        }
        // Option to show student details
        else if (choice == 3) {
            system("cls"); // Clear the screen
            for (const auto& student : students) {
                cout << "Name: " << student.name << endl;
                cout << "Roll No: " << student.rollN << endl;
                cout << "Status: " << (student.present ? "Present" : "Absent") << endl << endl;
            }
        }
        // Option to save records to a file
        else if (choice == 4) {
            save(students, "C:/text files/attendance_record.txt");
        }
        // Option to exit the program
        else if (choice == 0) {
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        }
        // Handle invalid input
        else {
            system("cls"); // Clear the screen
            cout << "Invalid Input. Please try again." << endl;
        }
    }
}
