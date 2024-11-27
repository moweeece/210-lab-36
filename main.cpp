#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main() {

    // BST
    StringBinaryTree tree;

    // read from file (strings)
    ifstream file("codes.txt");
    string code;

    // if the file exists is true
    if(file)
    {
        // loop to iterate through all lines of code
        while (getline(file, code))
        {
            // add the code to the tree
            tree.insertNode(code);
        }
        // close the file when BST population is completed
        file.close();
    }
    else  // error opening the file
    {
        cout << "Error opening the file.\n";
        return 1;
    }

    // user entry section
    while(true)
    {
        int userChoice;
        string userNewCode; // for case 4

        cout << "BST Menu:\n";
        cout << "=========\n";
        cout << "[1] Add a record\n";
        cout << "[2] Delete a record\n";
        cout << "[3] Search for a record\n";
        cout << "[4] Modify a record\n";
        cout << "[5] Exit\n";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice)
        {
            case 1:
                // add
                cout << "Enter a code to insert: ";
                getline(cin, code);
                tree.insertNode(code);
                cout << endl;
                cout << "Code Inserted.\n";
                break;

            case 2:
                // delete
                cout << "Enter a code to delete: ";
                getline(cin, code);

                // check if the string exists
                if(tree.searchNode(code))
                {
                    tree.remove(code);
                    cout << "Code Deleted Successfully.\n";
                }
                else 
                {
                    cout << "Code Not Found. Code not deleted.\n";
                }
                cout << endl;
                break;

            case 3:
                // search
                cout << "Enter a code to search for: ";
                getline(cin, code);

                // check if the string exists
                if(tree.searchNode(code))
                {
                    tree.remove(code);
                    cout << "Code Found!.\n";
                }
                else 
                {
                    cout << "Code Not Found.\n";
                }
                break;

            case 4:
                // modify
                cout << "Enter a code to modify: ";
                getline(cin, code);

                // check if the string exists, if it does ask user for what to change it to
                if(tree.searchNode(code))
                {
                    cout << "Enter the new code: ";
                    getline(cin, userNewCode);

                    // remove original code
                    tree.remove(code);

                    // insert users new code
                    tree.insertNode(userNewCode);

                    cout << "Code successfully replaced.\n";
                }
                else 
                {
                    cout << "Code Not Found. Replacement not completed.\n";
                }
                break;

            case 5:
                // exit the program
                cout << "Exiting the program.\n";
                return 0;

            default:
                // default - invalid choice
                cout << "Invalid choice. Enter a number between 1 and 5.\n";
        }
    }
}