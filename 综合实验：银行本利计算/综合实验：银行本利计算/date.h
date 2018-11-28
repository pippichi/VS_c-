#ifndef __DATE_H_
#define __DATE_H_

class Date {
	int year;
	int month;
	int day;
	int totalDays;

public:
	Date(int year, int month, int day);
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMonthMaxDay() const;
	bool isLeapYear()const {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show()const;
	//计算两个日期间隔多少天
	int distance(Date &date) {
		return totalDays - date.totalDays;
	}
};

#endif//__DATE_H_