
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;
// Email Vaildation Pattern
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

class student
{
protected:
    string name, roll_no, course, address, email_id;
    long long int contact_no;

public:
    // Parameterized Constructor
    student(string name, string roll_no, string course, string address, string email_id, long long int contact_no)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->course = course;
        this->address = address;
        this->email_id = email_id;
        this->contact_no = contact_no;
    }
    // Default Constructor
    student()
    {
        name = "megha";
        roll_no = "81";
        course = "cse";
        address = "pune";
        email_id = "meghadalsaniya@gmail.com";
        contact_no = 1234567890;
    }
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
// Inheritance
class marks : public student
{
private:
    int marks1, marks2, marks3, total;

public:
    void insert_marks();
    void display_marks();
};

void marks::insert_marks()
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Enter Student Marks ----------------------------------------------" << endl;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Marks for Subject 1: ";
    cin >> marks1;
    cout << "\t\t\tEnter Marks for Subject 2: ";
    cin >> marks2;
    cout << "\t\t\tEnter Marks for Subject 3: ";
    cin >> marks3;

    file.open("StudentRecord.txt", ios::app | ios::out);
    if (!file)
    {
        throw runtime_error("Error opening file.");
    }
    file << roll_no << " " << marks1 << " " << marks2 << " " << marks3 << "\n";
    file.close();

    cout << "\n\t\t\tMarks Successfully Added!" << endl;
}

void marks::display_marks()
{
    try
    {
        system("cls");
        fstream file;
        int total = 1;
        int Marks;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Marks Table ---------------------------------------------" << endl;
        file.open("studentRecord.txt", ios::in);
        if (!file)
        {
            throw runtime_error("Error opening file.");
        }
        cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
        cout << "\t\t\tRoll No.: " << roll_no << "\n";
        cout << "\t\t\tMarks 1: " << marks1 << "\n";
        cout << "\t\t\tMarks 2: " << marks2 << "\n";
        cout << "\t\t\tMarks 3: " << marks3 << "\n";

        // Calculate total marks
        Marks = (marks1 + marks2 + marks3) / 3;

        // Assign grades based on marks
        char grade;
        if (Marks >= 90)
            grade = 'A';
        else if (Marks >= 80)
            grade = 'B';
        else if (Marks >= 70)
            grade = 'C';
        else if (Marks >= 60)
            grade = 'D';
        else
            grade = 'F';

        cout << "\t\t\tTotal Marks: " << Marks << "\n";
        cout << "\t\t\tGrade: " << grade << "\n";
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }

        file.close();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
}

// Project Menu
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Enter Student Marks" << endl;
    cout << "\t\t\t 7. Display Student Marks" << endl;
    cout << "\t\t\t 8. Exit\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7/8]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Option: ";
    cin >> choice;
    char a;
    marks marksObj;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        marksObj.insert_marks();
        break;
    case 7:
        marksObj.display_marks();
        break;
    case 8:
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    getch();
    goto menustart;
}

void student::insert() // Add student details
{
    system("cls"); // command line interface to clear the display screen
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
email: // act as a marker
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is InValid" << endl;
        goto email;
    }
contact: // act as a marker
    cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "\t\t\tEnter Address: ";
    cin >> address;

    // Create an instance of the student class using the parameterized constructor
    student newStudent(name, roll_no, course, address, email_id, contact_no);

    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
void student::display() // Display data of student
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tCourse: " << course << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tContact No.: " << contact_no << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {

            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }

    file.close();
}
void student::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
            email:
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;
                if (Emailcheck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is InValid" << endl;
                    goto email;
                }
            contact:
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....";
            }
        }
        file.close();
    }
}
void student::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

int main()
{
    student project; // object
    project.menu();  // object calling
    return 0;
}