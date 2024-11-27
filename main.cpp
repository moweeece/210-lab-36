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
    
    while(true)
    {
        int userChoice;

        cout << "BST Menu:\n";
        cout << "=========\n";
        cout << "[1] Add a record\n";
        cout << "[2] Delete a record\n";
        cout << "[3] Search for a record\n";
        cout << "[4] Modify a record\n";
        cout << "[5] Exit\n";
        cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                // add
                break;
            case 2:
                // delete
            case 3:
                // search
            case 4:
                // modify
            case 5:
                cout << "Exiting the program.\n";
                return 0;
                // exit
            default:
                // default - invalid choice
                cout << "Invalid choice. Enter a number between 1 and 5.\n";
        }
    }


    return 0;
}