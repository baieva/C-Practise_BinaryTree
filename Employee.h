#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;


class Employee {
private:
	string name;
	int id;

public:
	Employee(int nid, string nname) {
		name = nname;
		id = nid;
	}

	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	bool operator < (const Employee& other) const{
		return id < other.id;
	}

	bool operator == (const Employee& otherid) const{
		return id == otherid.id;
	}

	bool operator <= (const Employee& otherid) const{
		return id <= otherid.id;
	}

	friend ostream& operator << (ostream& os, Employee& one){
		cout << "\t\tID Number: " << one.getId() << "\tName: " << one.getName() << endl << endl;
		return os;
	}
};

#endif