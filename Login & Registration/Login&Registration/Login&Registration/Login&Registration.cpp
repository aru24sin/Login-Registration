// Login & Registration System
// 
// Author: Aryan Singh
// Date: 5/5/2023
// 
// Purpose:
// Utilize file management in C++ to create user registration and remember login info
// This can also be done with the usage of a dictionary or class (leave for future practice)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Create User login info
void createLogin() {
    string username, password;

    cout << "\nSelect a username: "; cin >> username;
    cout << "Select a password: "; cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl << password;
    file.close();
}

// Determine whether User Input is valid for login
bool IsLoggedIn() {
    string username, password, u1, p1;

    cout << "\nInput Username: ";
    cin >> username;
    cout << "Input Password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, u1);
    getline(read, p1);

    if (u1 == username && p1 == password) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int choice;

    cout << "Select an option: \n\n1. Register\n2. Login\n3. Quit\n\nYour Choice: ";
    cin >> choice;

    // Loop through login system until either option 3 or correct login is executed
    while (choice != 3) {

        if (choice == 1) {
            createLogin();
        }

        else if (choice == 2) {
            bool loggedIn = IsLoggedIn();

            if (loggedIn == false) {
                cout << "\nIncorrect Information, Try Again!" << endl;
                system("PAUSE");
                return 0;
            }

            else {
                cout << "\nYou are logged in!" << endl;
                cout << "Welcome to the System :]" << endl;
                system("PAUSE");
                return 1;
            }
        }
        cout << "\nSelect an option:\n1. Register\n2. Login\n3. Quit\nYour Choice: ";
        cin >> choice;
    }
}