#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    public:
    float grades;
    string username, password, password1, name, course,snumber;
};

string name1;

void c_dashboard();
void details();
void dashboard();
void registration();
void login();

//Main menu
int main()
{
    int choice;
    system("cls");
    cout << "Welcome to the CSD Student Portal (Unofficial)\n";
    cout << "Please enjoy your stay!. Type in 1 to Register and Type in 2 to Login.\n";

    do
    {
        cout << "1. Register || 2. Login: ";
        cin >> choice;
    } while (choice < 1 || choice > 2);

    if (choice == 1)
    {
        system("cls");
        registration();
    }

    if (choice == 2)
    {
        system("cls");
        login();
    }

}

//Iniistore yung mga details na nilalagay into .txt file
void registration()
{
    Student raccount;
    cout << "Welcome to CSD Student Portal\n";

    cout << "Your name: ";
    cin >> raccount.username;

    cout << "Create your password: ";
    cin >> raccount.password;

    cout << "Confirm your password: ";
    cin >> raccount.password1;

    ofstream record(raccount.username + ".txt", ios::app);
    record << raccount.username << " " <<  raccount.password << endl;

    if (raccount.password != raccount.password1)
    {
        system("cls");
        cout << "Password does not match. Teleporting you back to the main screen.";
        main();
    }

    else
    {
        system("cls");
        cout << "Account created!\n";
        login();
    }        
}

//Login function, at chinecheck kung nag eexist yung account
void login()
{
    Student laccount;
    string username, pass;
    bool exist;
    int choice;

    cout << "Welcome to CSD Login portal, please input your username and password!\n";
    cout << "Name: ";
    cin >> laccount.username;

    cout << "Password: ";
    cin >> laccount.password;

    ifstream input(laccount.username + ".txt");

    while (input >> username >> pass)
    {
        if (username == laccount.username && pass == laccount.password)
        {
            exist = true;
        }
    }

        if (exist == true)
        {
            system("cls");
            cout << "Welcome! " << laccount.username << "\n";
            ifstream show;
            show.open(laccount.username + "details.txt");
            if (show)
            {
                system("cls");
                // Attaches the username to the name1 para matawag siya globally
                name1 = laccount.username;
                cout << "Directing you to your dashboard\n";
                dashboard();
            }

            else
            {
                system("cls");
                cout << "Create your own dashboard\n";
                c_dashboard();
            }
            input.close();
        }

        if (exist == false)
        {
            system("cls");
            cout << "Account not found.....Please try again\n";
            cout << "Type in 0 to retry: ";
            cin >> choice;
            if (choice == 0)
            {
                main();
            }
        }
    }

void dashboard()
{
    int choice;
    do
    {
        cout << "1. Details \n";
        cout << "2. Subjects \n";
        cout << "3. Logout \n";
        cout << "Enter: ";
        cin >> choice;
    } while (!choice == 1 || !choice == 2 || !choice == 3);

    switch(choice)
    {
        case 1:
        system("cls"); details(); break;
        case 3:
        system("cls"); login(); break;
    }
}

void c_dashboard()
{
    Student c_dashboard;
    cout << "Name: ";
    cin >> c_dashboard.name;
    cout << "Course: ";
    cin >> c_dashboard.course;
    cout << "Student number: ";
    cin >> c_dashboard.snumber;
    fstream create;
    create.open(c_dashboard.name + "details.txt", ios::out);
    if (create.is_open())
    {
        create << "Name: " << c_dashboard.name << "\n" << "Course: " << c_dashboard.course << "\n" << "Student number: " << c_dashboard.snumber << "\n";
        create.close();
    }
    system("cls");
    cout << "Dashboard created!, Please re login your account.\n";
    login();
}

void details()
{
    int choice;
    Student details;
    fstream show;

    do
    {
        cout << "1. Add new student details \n";
        cout << "2. Overwrite student details \n";
        cout << "3. View student details \n";
        cout << "Enter: ";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    if (choice == 1 || choice == 2)
    {
        show.open(details.name + "details.txt", ios::out);
        if (show.is_open())
        {
            cout << "Name: ";
            cin >> details.name;
            cout << "Course: ";
            cin >> details.course;
            cout << "Student number: ";
            cin >> details.snumber;
            show << "Name: " << details.name << "\n" << "Course: " << details.course << "\n" << "Student number: " << details.snumber << "\n"; 
            show.close();
        }
        system("cls");
        dashboard();
    }

    if (choice == 3)
    {
        system("cls");
        show.open(name1 + "details.txt", ios::in);
        if (show.is_open())
        {
            string line;
            while (getline(show, line))
            {
                cout << line << "\n";
            }
            show.close();
        }

        do
        {
            cout << "1. Back to Dashboard || 2. Logout: ";
            cin >> choice;
        } while (choice < 1 || choice > 2);

        switch(choice)
        {
            case 1:
            system("cls"); dashboard(); break;
            case 2:
            system("cls"); main(); break; 
        }
    }
}