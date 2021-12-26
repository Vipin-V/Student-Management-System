#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    int menu();
    void insert();
    void clear_screen();
    void display();
    void modify();
    void search();
    void deleted();
};

void student::clear_screen() // Universal Function for clearing screen
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

int student::menu(void)
{
menustart:
    int choice;
    char x;
    clear_screen();

    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|  STUDENT MANAGEMENT SYSTEM  |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t------------------------------" << endl;
    cout << "\t\t\tChoose Options: [1/2/3/4/5/6]" << endl;
    cout << "\t\t\t------------------------------" << endl;
    cout << "Enter Your Option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
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
    case 6:
        exit(0);

    default:
        cout << "\n\t\t\t Invalid Choice... Please Try Again..";
    }
    return 0;
    goto menustart;
}

void student::insert() // For adding Students
{
    clear_screen();
    fstream file;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n---------------------------------------------------------------------- Add Students Details -------------------------------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact NO.: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "
         << "\n\n";
    file.close();
}

void student::display()
{
    clear_screen();
    fstream file;
    int total = 0;
    cout << "\n---------------------------------------------------------------------- Students Records -------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present...\n\n";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\t\t\t Student No: " << total++ << endl;
            cout << "\n\t\t\t Student Name: " << name << endl;
            cout << "\n\t\t\t Student Roll No: " << roll_no << endl;
            cout << "\n\t\t\t Student Email id: " << email_id << endl;
            cout << "\n\t\t\t Student Address: " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present...";
        }
    }
    file.close();
}

void student::modify()
{
    clear_screen();
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n---------------------------------------------------------------------- Modify Student Details -------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present>>>";
        file.close();
    }
    else
    {
        cout << "\n Enter ROll No. of student which you want to modify: ";
        cin >> rollno;
        file.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "
                      << "\n";
            }
            else
            {
                cout << "\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact NO.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "
                      << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        if (found == 0){
            cout << "\n\t\t\t Student Roll No. Not Found...";
        }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

void student::search (){
    clear_screen();
    fstream file;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n---------------------------------------------------------------------- Search Student Details -------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Found!!!";
    }
    else{
        string rollno;
        int found;
        cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n---------------------------------------------------------------------- Search Student Details -------------------------------------------------------------------" << endl;
        cout << "\n Enter Roll no. of Student (which you want to Search): ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no){
                    cout << "\n\t\t\t Student No: " << endl;
            cout << "\n\t\t\t Student Name: " << name << endl;
            cout << "\n\t\t\t Student Roll No: " << roll_no << endl;
            cout << "\n\t\t\t Student Email id: " << email_id << endl;
            cout << "\n\t\t\t Student Address: " << address << endl;
            }

        }
        
    }
    
}

void student::deleted(){
    clear_screen();
    fstream file,file1;
    string rollno;
    int found = 0;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n---------------------------------------------------------------------- Delete Student Details -------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present>>>";
        file.close();
    }
    else{
        cout << "\n Enter Roll No. of Student you want to delete: ";
    cin >> rollno;
    file1.open("Record.txt", ios::app | ios::out);
    file >> name >> roll_no >> course >> email_id >> contact_no >> address;
    while (!file.eof())
    {
        if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << " "
                      << "\n";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
    }
    if (found == 0){
        cout << "\n\t\t\t Successfully Deleted Data...";
    }
    file1.close();
    file.close();
    remove("studentRecord.txt");
    rename("Record.txt", "studentRecord.txt");
    }
}

main()
{
    student project;
    project.menu();
    return 0;
}