#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//  block that checks un and password or registers a new user
bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read("D:/C++_Exercises/Recistration_exercise_c++\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    int choice;

    cout << "1: Registration\n2: Login\nYour choice: "; cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout  << "select a username: "; cin >> username;
        cout  << "select a password: "; cin >> password;

        ofstream file;
        file.open("D:/C++_Exercises/Recistration_exercise_c++\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }

    else if (choice == 2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout << "False log in!" << endl;
            system("PAUSE");
            return 0;
        }

        else
        {
            cout << "Succesfuly logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}
