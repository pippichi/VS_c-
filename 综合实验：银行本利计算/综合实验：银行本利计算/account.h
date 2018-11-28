#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "date.h"
#include<string>
using namespace std;

class savingsAccount {//储蓄账户类
private:
	string id;//账户id
	double balance;//余额
	double rate;//年利率
	Date lastDate; //上次变更余额日期
	double accumulation;//余额按日累加之和
	static double total;

	//记一笔账，date为日期，amount为金额，desc为说明
	void record(const Date& date, double amount,const string &desc);
	//报告错误信息
	void error(const string &msg) const;

	//获得到指定日期为止的存款金额按日累计值
	double accumulate(const Date &date) const {
		return accumulation + balance * date.distance(lastDate);
	}

public:
	//构造函数
	savingsAccount(const Date &date, const string id, double rate);
	const string &getId() const{ return id; }
	double getBalance()const { return balance; }
	double getRate() const { return rate; }

	//存入现金
	void deposit(const Date &date, double amount,const string &desc);
	//取出现金
	void withdraw(const Date &date, double amount,const string &desc);
	//结算利息，每年1月1日调用该函数
	void settle(const Date &date) ;
	//显示账户信息
	void show() const;
	static double getTotal();
};
#endif 