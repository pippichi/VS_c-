#include"stdafx.h"
#include<iostream>
#include"account.h"
using namespace std;

double savingsAccount::total = 0;
savingsAccount::savingsAccount(const Date &date, const string id, double rate) :
	balance(0), id(id), lastDate(date), rate(rate), accumulation(0) {
	date.show();
	cout  << "\t#" << id << " is created." << endl;
}
void savingsAccount::record(const Date &date, double amount,const string &desc) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;//保留两位小数
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << desc<< endl;
}

void savingsAccount::error(const string &desc)const {
	cout << "Error (#" << id <<"):"<< desc << endl;
}

void savingsAccount::deposit(const Date &date, double amount,const string &desc) {
	record(date, amount,desc);
}

void savingsAccount::withdraw(const Date &date, double amount,const string &desc) {
	if (amount > getBalance()) {
		error("Error:not enough money." );
	}
	else {
		record(date, -amount,desc);
	}

}
void savingsAccount::settle(const Date &date){
	double interest = accumulate(date)*rate / 
		date.distance(Date(date.getYear()-1,1,1));//计算年息
	if (interest != 0) {
		record(date, interest,"interest");
	}
	accumulation = 0;
}

void savingsAccount::show() const{
	cout << "#" << id << "\tBalance: " << balance << endl;
}
double savingsAccount::getTotal() {
	return total;
}
