#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "date.h"
#include<string>
using namespace std;

class savingsAccount {//�����˻���
private:
	string id;//�˻�id
	double balance;//���
	double rate;//������
	Date lastDate; //�ϴα���������
	double accumulation;//�����ۼ�֮��
	static double total;

	//��һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date& date, double amount,const string &desc);
	//���������Ϣ
	void error(const string &msg) const;

	//��õ�ָ������Ϊֹ�Ĵ������ۼ�ֵ
	double accumulate(const Date &date) const {
		return accumulation + balance * date.distance(lastDate);
	}

public:
	//���캯��
	savingsAccount(const Date &date, const string id, double rate);
	const string &getId() const{ return id; }
	double getBalance()const { return balance; }
	double getRate() const { return rate; }

	//�����ֽ�
	void deposit(const Date &date, double amount,const string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount,const string &desc);
	//������Ϣ��ÿ��1��1�յ��øú���
	void settle(const Date &date) ;
	//��ʾ�˻���Ϣ
	void show() const;
	static double getTotal();
};
#endif 