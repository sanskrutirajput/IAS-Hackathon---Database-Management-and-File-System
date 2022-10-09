// #include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;

class student
{

public:
    int index;
    int prn;
    string name;
    float cpi;
    string dept;
    int rollNo;

    // Default Consructor
    student()
    {
        cout << "Default constructor called" << endl;
    }

    // Parameterized Constructor
    student(int index, int prn, string name, float cpi, string dept, int rollNo)
    {
        this->index = index;
        this->prn = prn;
        this->name = name;
        this->cpi = cpi;
        this->dept = dept;
        this->rollNo = rollNo;
    }

    // Copy constructor
    // student(student &s){
    //     this->index=s.index;
    //     this->prn=s.prn;
    //     this->name=s.name;
    //     this->cpi=s.cpi;
    //     this->dept=s.dept;
    //     this->rollNo=s.rollNo;
    // }

    // Member functions
    void menu(vector<student> &db);
    void add(vector<student> &db);
    void admin(vector<student> &db);
    void textToVector(vector<student> &d);
    void vectorToText(vector<student> &d);
    void rem();
    void mean(vector<student> &d);
    void update(vector<student> &d);
    void display(vector<student> &d);
};

void student ::menu(vector<student> &db)
{
    cout << "\n\t\t\t____________________________\t\t\t";
    cout << "\n\t\t\t____________________________\t\t\t";
    cout << "\n\t\t\t  Student Visualization Menu\t\t\t";
    cout << "\n\t\t\t____________________________\t\t\t";
    cout << "                                   ";
    int choice;
    string email;
    string passwd;

    cout << "\n\t\t\t|   1) Admin         \n";
    cout << "\n\t\t\t|   2) Exit          \n";
    cout << "\n\t\t\t                     \n";
    cout << "Enter the choice from above";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email  \n";
        cin >> email;
        cout << "\t\t\t   Password   \n";
        cin >> passwd;

        if (email == "1" and passwd == "1")
        {
            admin(db);
        }
        else
        {
            cout << "Invalid email or password";
        }
        break;
    case 2:
        exit(0);
        // break;
    default:
        cout << "Please select from the given options";
    }
}

void student ::admin(vector<student> &db)
{
m:
    int choice;

    cout << "\t\t\t\t___________________________________________________\n";
    cout << "\n\n\t\t\t\t\t\t\tAdministrator Menu             \n";
    cout << "\t\t\t\t___________________________________________________\n";
    cout << "\n\n\t\t\t\t\t\t\t1) Add Student\n";
    cout << "\n\n\t\t\t\t                                       ";
    cout << "\n\n\t\t\t\t\t\t\t2) Update Student Profile\n";
    cout << "\n\n\t\t\t\t                                       ";
    cout << "\n\n\t\t\t\t\t\t\t3) Delete the Student Profile\n";
    cout << "\n\n\t\t\t\t                                       ";
    cout << "\n\n\t\t\t\t\t\t\t4) Display all the students\n";
    cout << "\n\n\t\t\t\t                                       ";
    cout << "\n\n\t\t\t\t\t\t\t5) Get the average CPI\n";
    cout << "\n\n\t\t\t\t                                       ";
    cout << "\n\n\t\t\t\t\t\t\t6) Save and Back to main menu\n";

    cout << "Please enter your choice\n";
    cin >> choice;
    textToVector(db);

    switch (choice)
    {
    case 1:
        add(db);
        break;
    case 2:
        update(db);
        break;
    case 3:
        rem();
        // break;
    case 4:
        display(db);
        break;
    // case 5:
    //     textToVector(db);
    // case 6:
    //     vectorToText(db);
    case 5:
        mean(db);
    case 6:
        vectorToText(db);
        menu(db);

    default:
        cout << "Invalid Choice";
    }
    goto m;
}

void student ::add(vector<student> &db)
{

    // Write in the file=> <<
    // Read from the file=> >>

    int startPRN = 12000000;

    cout << "________Add a student_____\n"
         << endl;
    cout << "Enter PRN:" << endl;
    cin >> prn;
    cout << "Enter Name:" << endl;
    cin >> name;
    cout << "Enter CPI:" << endl;
    cin >> cpi;
    cout << "Enter Department:" << endl;
    cin >> dept;
    cout << "Enter RollNo:" << endl;
    cin >> rollNo;

    index = prn - startPRN;

    student s(index, prn, name, cpi, dept, rollNo);

    // Search=>Read from the file if the prn aleady exists
    if (db[index].index != index)
    {
        // If PRN does not exists, then record is inserted
        db[index] = s;
    }
    else
    {
        // Student already exists, then record is not inserted
    }

    cout << "Student Record Inserted successfully" << endl;
    admin(db);
}

void student ::rem()
{
    fstream data, data1;
    int prnNo;
    int token = 0;
    cout << "Delete Student" << endl;
    cout << "Enter the prn no. of the student : ";
    cin >> prnNo;
    data.open("student.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist" << endl;
    }
    // int prn;
    // string name;
    // float cpi;
    // string dept;
    // int rollNo;
    else
    {
        data1.open("student1.txt", ios::app | ios::out);
        data >> prn >> name >> cpi >> dept >> rollNo;
        while (!data.eof())
        {
            if (prnNo == prn)
            {
                cout << "Student deleted successfully"
                     << "\n";
                token++;
            }
            else
            {
                data1 << " " << prn << " " << name << " " << cpi << " " << dept << " " << rollNo << "\n";
            }
            data >> prn >> name >> cpi >> dept >> rollNo;
        }
        data.close();
        data1.close();
        remove("student.txt");
        rename("student1.txt", "student.txt");
        if (token == 0)
        {
            cout << "Record not found" << endl;
        }
    }
}

void student ::update(vector<student> &db)
{
    fstream data, data1;
    int regNo;
    int roll;
    int token = 0;
    string n;
    string dep;
    int startPRN = 12000000;
    int PRN;
    int index = 0;

    float grade;

    cout << "\n\t\t\t Modify The Record";
    cout << "\n\t\t\t Enter The Registration Number";
    cin >> regNo;

    index = regNo - startPRN;
    if (db[index].index != -1)
    {

        cout << "\n\t\t\t Enter the PRN Number: ";
        cin >> regNo;
        cout << "\n\t\t\t                       ";
        cout << "\n\t\t\t Enter the Name: ";
        cin >> n;
        cout << "\n\t\t\t                       ";
        cout << "\n\t\t\t Enter the Updated CGPI: ";
        cin >> grade;
        cout << "\n\t\t\t                       ";
        cout << "\n\t\t\t Enter the Department: ";
        cin >> dep;
        cout << "\n\t\t\t                       ";
        cout << "\n\t\t\t Enter the Roll Number: ";
        cin >> roll;
        index = PRN - startPRN;
        // data1<<" "<<index<<" "<<regNo<<" "<<n<<" "<<grade<<" "<<dep<<" "<<roll;
        // cout<<"\n\t\t\t Record Updated";
        db[index].index = index;
        db[index].prn = regNo;
        db[index].name = n;
        db[index].cpi = grade;
        db[index].dept = dep;
        db[index].rollNo = roll;
    }
    else
    {
        cout << "Record Does Not Exist!";
    }

    //  data.close();
    //  data1.close();
    //  remove("student.txt");
    //  rename("student1.txt","student.txt");

    if (token == 0)
    {
        cout << "Record Not Found";
    }
}

void student ::display(vector<student> &db)
{
    cout << "  PRN       Name        CPI         Department      RollNo  " << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < db.size(); i++)
    {
        if (db[i].index != -1)
        {
            cout << db[i].index << " " << db[i].prn << " " << db[i].name << " " << db[i].cpi << " " << db[i].dept << " " << db[i].rollNo << "\n";
        }
    }
}

void student ::textToVector(vector<student> &db)
{
    fstream data;
    string dt;
    // student obj;

    data.open("student.txt", ios::in);

    if (!data)
    {
        cout << "File Does Not Exist";
        data.open("student.txt", ios::app | ios::out);
    }
    else
    {
        while (!data.eof())
        {
            data >> index >> prn >> name >> cpi >> dept >> rollNo;
            student obj(index, prn, name, cpi, dept, rollNo);
            db[index] = obj;
        }
    }
}

void student ::vectorToText(vector<student> &db)
{
    // int prn2;
    // string name2;
    // float cpi2;
    // string dept2;
    // int rollNo2;
    // int index2;
    fstream file;
    file.open("student2.txt", ios::app | ios::out);
    for (int i = 0; i < db.size(); i++)
    {
        if (db[i].index != -1)
        {
            file << " " << db[i].index << " " << db[i].prn << " " << db[i].name << " " << db[i].cpi << " " << db[i].dept << " " << db[i].rollNo << "\n";
        }
    }
    // remove("student.txt");
    // rename("student2.txt","student.txt");
}

void student::mean(vector<student> &db)
{
    double total = 0;
    double totalVal = 0;

    for (int i = 0; i < db.size(); i++)
    {
        if (db[i].index != -1)
        {
            totalVal += db[i].cpi;
            total++;
        }
    }
    cout << "The average CPI is : " << totalVal / total;
    fstream data;
    data.open("data.txt", ios::in);
    data << "The average CPI is : " << totalVal / total;
    data.close();
}

int main()
{

    student std1;
    student std2(-1, -1, "", -1, "", -1);
    vector<student> db(100, std2);
    std1.menu(db);

    return 0;
}