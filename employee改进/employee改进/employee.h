#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<iostream>
using namespace std;

class Employee {
	const char* name;
	const char* address;
	const char* city;
	const char* code;
public:
	Employee(const char*name = "",const char*address = "",const char* city = "", const char*code = "") :name(name), address(address),
		city(city), code(code) {}
	Employee(Employee *e) {
		name = e->name;
		address = e->address;
		city = e->city;
		code = e->code;
	}
	void display() {
		cout << "name: " << name << endl;
		cout << "address: " << address << endl;
		cout << "city: " << city << endl;
		cout << "code: " << code << endl;
	}
	void change_name(char* nm) {
		name = nm;
	}

};

#endif