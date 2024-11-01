#include <iostream>
#include <string>

using namespace std;

// Base class for all university members
class UniversityMember {
protected:
    string name; // Name of the university member
    int id; // Unique ID for the member

public:
    // Constructor with initializer list to initialize member variables
    UniversityMember(const string& name, int id) : name(name), id(id) {
        cout << "UniversityMember created: " << name << endl;
    }

    // Virtual destructor to allow derived classes to clean up correctly
    virtual ~UniversityMember() {
        cout << "UniversityMember destroyed: " << name << endl;
    }

    // Pure virtual function to display information, forces derived classes to implement it
    virtual void displayInfo() const = 0;
};

// Class representing a course
class Course {
    string courseName; // Name of the course
    int courseId; // ID of the course

public:
    // Constructor using initializer list to initialize courseName and courseId
    Course(const string& name, int id) : courseName(name), courseId(id) {
        cout << "Course created: " << courseName << endl;
    }

    // Destructor to clean up resources
    ~Course() {
        cout << "Course destroyed: " << courseName << endl;
    }

    // Function to display course details
    void displayCourse() const {
        cout << "Course: " << courseName << ", ID: " << courseId << endl;
    }
};

// Derived class for Student inheriting from UniversityMember
class Student : public UniversityMember {
private:
    double gpa; // GPA of the student
    const Course* enrolledCourse; // Pointer to the enrolled course, const to prevent modification

public:
    // Constructor initializing base class and setting GPA and enrolledCourse to null initially
    Student(const string& name, int id, double gpa) 
        : UniversityMember(name, id), gpa(gpa), enrolledCourse(nullptr) {
        cout << "Student created: " << name << endl;
    }

    // Destructor to clean up, no need to delete enrolledCourse since it's not owned by Student
    ~Student() {
        cout << "Student destroyed: " << name << endl;
    }

    // Function to enroll student in a course
    void enrollInCourse(const Course* course) {
        enrolledCourse = course; // Assigns the course to enrolledCourse pointer
    }

    // Overridden displayInfo function to show student-specific details
    void displayInfo() const override {
        cout << "Student Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
        if (enrolledCourse) { // Checks if the student is enrolled in a course
            enrolledCourse->displayCourse(); // Displays course details
        } else {
            cout << "No course enrolled." << endl;
        }
    }
};

// Derived class for Faculty inheriting from UniversityMember
class Faculty : public UniversityMember {
private:
    string department; // Department of the faculty

public:
    // Constructor initializing base class and setting department
    Faculty(const string& name, int id, const string& department) 
        : UniversityMember(name, id), department(department) {
        cout << "Faculty created: " << name << " in " << department << endl;
    }

    // Destructor to clean up
    ~Faculty() {
        cout << "Faculty destroyed: " << name << endl;
    }

    // Overridden displayInfo function to show faculty-specific details
    void displayInfo() const override {
        cout << "Faculty Name: " << name << ", ID: " << id << ", Department: " << department << endl;
    }
};

// Example of a virtual base class for specialization in the university system
class Specialization {
public:
    // Pure virtual function making Specialization an abstract class
    virtual void showSpecialization() const = 0;
};

// Derived class inheriting multiple base classes (hierarchical inheritance and virtual inheritance)
class GraduateStudent : public Student, public Specialization {
private:
    string thesisTopic; // Thesis topic for the graduate student

public:
    // Constructor initializing Student base and setting thesis topic
    GraduateStudent(const string& name, int id, double gpa, const string& thesis)
        : Student(name, id, gpa), thesisTopic(thesis) {
        cout << "GraduateStudent created with thesis topic: " << thesisTopic << endl;
    }

    // Destructor for cleanup
    ~GraduateStudent() {
        cout << "GraduateStudent destroyed: " << name << endl;
    }

    // Function to display thesis topic for specialization
    void showSpecialization() const override {
        cout << "Thesis Topic: " << thesisTopic << endl;
    }

    // Overridden displayInfo to include specialization details
    void displayInfo() const override {
        Student::displayInfo(); // Calls the base class displayInfo
        showSpecialization(); // Shows specialization specific to GraduateStudent
    }
};

// Main function to demonstrate the system
int main() {
    // Example message to verify the program runs
    cout << "Program started successfully!" << endl;

    // Example of creating a Student and displaying information
    Course* course1 = new Course("Data Structures", 101);
    Student student1("Alice", 201, 3.8);
    student1.enrollInCourse(course1);
    student1.displayInfo();

    Faculty faculty1("Dr. Smith", 301, "Computer Science");
    faculty1.displayInfo();

    GraduateStudent gradStudent("Bob", 401, 3.9, "Machine Learning in Computer Vision");
    gradStudent.displayInfo();

    delete course1; // Free dynamically allocated memory

    // Pause to allow you to see the output before closing
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}


