#pragma once

#include<iostream>
#include<windows.h>
#include<string>
#include<assert.h>

class Date
{
public:
		Date(int year = 0, int month = 1, int day = 1);
		void Show( );
		bool operator==(Date& d);
		bool operator!=(Date& d);
		bool operator<(Date& d);
		bool operator>(Date& d);
		bool operator<=(Date& d);
		bool operator>=(Date& d);
		Date& operator=(const Date& d);
		Date operator+(int day);
		Date operator-(int day);
		Date& operator+=(int day);
		Date& operator-=(int day);
		Date& operator++();//前置
		Date operator++(int);//后置
		Date& operator--();//前置
		Date operator--(int);//后置
		int operator-(Date& d);
private:
	int _year;
	int _month;
	int _day;
};