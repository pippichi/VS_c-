#include"stdafx.h"
#include<iostream>
#include<cstdlib>
#include"date.h"
using namespace std;

namespace {//namespace使得以下定义只在当前文件中有效
	const int DATE_BEFORE_MONTH[] = { 0,31,59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}

Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMonthMaxDay()) {
		cout << "Invalid day" ;
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = 365 * years + years / 4 - years / 100 + years / 400+
		DATE_BEFORE_MONTH[month-1]+day;
	if (isLeapYear()&&month > 2) totalDays++;
}

int Date::getMonthMaxDay() const{
	if (isLeapYear() && month == 2) {
		return 29;
	}
	else {
		return DATE_BEFORE_MONTH[month] - DATE_BEFORE_MONTH[month - 1];
	}
}

void Date::show() const{
	cout << getYear() << "-" << getMonth() << "-" << getDay() << endl;
}