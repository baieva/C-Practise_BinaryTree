#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Employee.h"

using namespace std;

int main() {
	BinaryTree<string> names;
	BinaryTree<Employee> employees;
	employees.insert(Employee(1021,"John Williams"));
	employees.insert(Employee(1057, "Bill Witherspoon"));
	employees.insert(Employee(2487, "Jennifer Twain"));
	employees.insert(Employee(3769, "Sophia Lancaster"));
	employees.insert(Employee(1017, "Debbie Reece"));
	employees.insert(Employee(1275, "George McMullen"));
	employees.insert(Employee(1899, "Ashley Smith"));
	employees.insert(Employee(4218, "Josh Plemmons"));
	int choice;
	int dischoice;
	int eid;
	string name;

	while (true) {
		cout << "******** BINARY TREE MENU ********" << endl << endl;
		cout << "1. Insert one or more items" << endl;
		cout << "2. Delete one or more elements" << endl;
		cout << "3. Display the nodes of the tree" << endl;
		cout << "4. Get the number of nodes in the tree" << endl;
		cout << "5. Get the height of the tree" << endl;
		cout << "6. Get the width of the tree" << endl;
		cout << "7. Get the number of leaves of the tree" << endl;
		cout << "8. Find an employee in the employee tree" << endl;
		cout << "9. Exit" << endl << endl;;
		cout << "Your Choice, please: (1-9) ";
		reenter:
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Insert any number or text to the tree or 00 to exit inetereing:" << endl;
			cin >> name;
			while (name != "00") {
				names.insert(name);
				cout << "Insert any number or text to the tree or 00 to exit inetereing:" << endl;
				cin >> name;
			}
			break;
		}
		case 2: {
			cout << "Delete any number or text in the tree or 00 to exit inetereing:" << endl;
			cin >> name;
			while (name != "00") {
				names.remove(name);
				cout << "Delete any number or text in the tree or 00 to exit inetereing:" << endl;
				cin >> name;
			}
			break;
		}
		case 3: {
			while (true) {
				cout << endl << "\t******** BINARY TREE DISPLAY MODES SUB MENU ********" << endl << endl;
				cout << "\t\t1. via inorder traversal" << endl;
				cout << "\t\t2. via preorder traversal" << endl;
				cout << "\t\t3. via postorder traversal" << endl << endl;
				cout << "Your choice, please: (1-4) ";
				retype:
				cin >> dischoice;
				switch (dischoice) {
				case 1: {
					cout << "Now, here are the nodes via inorder traversal:" << endl;
					names.inOrder();
					break;
				}
				case 2: {
					cout << "Now, here are the nodes via preorder traversal:" << endl;
					names.preOrder();
					break;
				}
				case 3: {
					cout << "Now, here are the nodes via postorder traversal:" << endl;
					names.postOrder();
					break;
				}
				case 4: {
					goto dend;
					break;
				}
				default: {
					cout << "Enter a number from 1 through 9 please";
					goto retype;
				}
				}
			}
			dend:
			break;
		}
		case 4: {
			cout << "Number of nodes: " << names.size() << endl << endl;
			break;
		}
		case 5: {
			cout << "Height: " << names.height() << endl << endl;
			break;
		}
		case 6: {
			cout << "Width: " << names.width() << endl << endl;
			break;
		}
		case 7: {
			cout << "Number of leaves: " << names.leafsize() << endl << endl;
			break;
		}
		case 8: {
			cout << "Here is the work force" << endl << endl;
			employees.inOrder();
			cout << "Enter an employee number to find or 0 to exit: ";
			cin >> eid;
			while (eid != 0) {
				if(employees.findif(Employee(eid,"a")) == 0) cout << "That emplyee was not found" << endl;
				cout << "Enter an employee number to find or 0 to exit: ";
				cin >> eid;
			}
			break;
		}
		case 9: {
			exit(0);
			break;
		}
		default: {
			cout << "Enter a number from 1 through 9 please";
			goto reenter;
		}
		}
	}
}