#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    static int nextId;
    int id = 0;
    string _name = "";
    string _surname = "";
    float _average = 0;

    Student() {
        id = nextId++;
    }

    Student(string name, string surname, float average) {
        id = nextId++;
        _name = name;
        _surname = surname;
        _average = average;
    }

    friend ostream& operator <<(ostream& output, const Student& student);
    friend istream& operator >>(istream& input, Student& student);
    friend void showallStudents();
    friend void addStudent(Student* student);
};

int Student::nextId = 1; 

ostream& operator <<(ostream& output, const Student& student) {
    output << "Id: " << student.id << endl;
    output << "Name: " << student._name << endl;
    output << "Surname: " << student._surname << endl;
    output << "Average score: " << student._average << endl;
    return output;
}

istream& operator >>(istream& input, Student& student) {
    cout << "Name:";
    getline(input, student._name);

    cout << "Surname:";
    getline(input, student._surname);

    cout << "Average:";
    input >> student._average;

    cin.ignore();
    return input;
}

class Group {
public:
    string _groupName;
    Student** students;
    int studentCount = 0;

    Group() {
        students = new Student* [20];
    }

    Group(string name, Student** students, int sCount = 0) {
        _groupName = name;
        this->students = students;
        studentCount = sCount;
    }

    void addStudent() {
        Student* student = new Student();
        cin >> *student;
        students[studentCount] = student;
        studentCount++;
    }

    void showallStudents() {
        cout << "Group " << _groupName << ":\n";
        for (int i = 0; i < studentCount; i++) {
            cout << *(students[i]);
        }
    }

    Student* getById(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->id == id)
                return students[i];
        }
        return nullptr;
    }
};

void main() {
    Group g1;
    g1._groupName = "FSDE_Oct_24_9_az";

    g1.addStudent(); 
    g1.showallStudents();

    int searchId;
    cout << "Search by ID: ";
    cin >> searchId;
    Student* result = g1.getById(searchId);
    if (result != nullptr)
        cout << "Found:\n" << *result;
    else
        cout << "Student not found.\n";
}
