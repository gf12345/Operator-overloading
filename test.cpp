#include"test.h"
class Time{
public:
	Time(int hour=16, int minute=51, int second=30)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
	}
	//<运算符重载
	bool operator<(const Time& d){
		return (_hour < d._hour) || (_hour == d._hour&&_minute < d._minute) || (_hour == d._hour&&_minute == d._minute&&_second < d._second);
	}
	//==运算符重载
	bool operator==(const Time& d){
		return _hour == d._hour&&_minute == d._minute&&_second == d._second;
	}
	//>运算符重载
	bool operator>(const Time& d){
		return !(*this < d || *this == d);
	}
	//<=运算符重载
	bool operator<=(const Time& d){
		return (*this < d || *this == d);
	}
	//>=运算符重载
	bool operator>=(const Time& d){
		return (*this>d || *this == d);
	}
	//!=运算符重载
	bool operator!=(const Time& d){
		return !(*this == d);
	}
	//两个时间之间的运算
	Time operator+(Time& d){
		Time tmp(*this);
		tmp._hour = _hour + d._hour;
		tmp._minute = _minute + d._minute;
		tmp._second = _second + d._second;
		if (tmp._second > 60){
			tmp._second = tmp._second - 60;
			tmp._minute = tmp._minute + 1;
			if (tmp._minute > 60){
				tmp._minute = tmp._minute - 60;
				tmp._hour = tmp._hour + 1;
				if (tmp._hour > 24){
					cout << "hour不能大于24" << endl;
				}
			}
		}
		return tmp;
	}
	Time operator-(Time& d){
		Time tmp(*this);
		tmp._hour = _hour - d._hour;
		tmp._minute = _minute - d._minute;
		tmp._second = _second - d._second;
		if (tmp._minute < 0){
			tmp._hour = tmp._hour - 1;
			tmp._minute = tmp._minute + 60;
		}
		if (tmp._second < 0){
			tmp._minute = tmp._minute - 1;
			tmp._second = tmp._second + 60;
		}
		return tmp;
	}
	//时间+-=秒
	Time& operator+=(int second){
		_second = _second + second;
		return *this;
	}
	Time& operator-=(int second){
		_second = _second - second;
		return *this;
	}
	Time operator+(int second){
		Time tmp(*this);
		tmp._second += second;
		if (tmp._second > 60){
			tmp._second = tmp._second - 60;
			tmp._minute = tmp._minute + 1;
			if (tmp._minute > 60){
				tmp._minute = tmp._minute - 60;
				tmp._hour = tmp._hour + 1;
				if (tmp._hour > 24){
					cout << "hour不能大于24" << endl;
				}
			}
		}
		return tmp;
	}
	Time operator-(int second){
		Time tmp(*this);
		tmp._second -= second;
		if (tmp._minute < 0){
			tmp._hour = tmp._hour - 1;
			tmp._minute = tmp._minute + 60;
		}
		if (tmp._second < 0){
			tmp._minute = tmp._minute - 1;
			tmp._second = tmp._second + 60;
		}
		return tmp;
	}
	//前置++
	Time& operator++(){
		*this = *this + 1;
		return *this;
	}
	//后置++
	Time operator++(int){
		Time tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	//前置--
	Time& operator--(){
		*this = *this - 1;
		return *this;
	}
	//后置--
	Time operator--(int){
		Time tmp(*this);
		*this = *this - 1;
		return tmp;
	}
	//时间-时间=秒数
	int operator-(const Time& d){
		int i = 0;
		Time a(*this);
		Time b(d);
		if (*this > d){
			while (a != b){
				i++;
				b++;
			}
		}
		else{
			while (a != b){
				i++;
				a++;
			}
		}
		return i;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
void test(){
	Time a1(16, 52, 30);
	Time a2;
	Time a3(0,0,30);
	a3 = a1 - a2;
	a3=a1++;
	a3 = ++a1;
	const Time a4(17,43,30);
	int n;
	n = a2 - a4;
	if (a1 < a2){
		cout << "a1<a2" << endl;
	}
	else if(a1==a2){
		cout << "a1=a2" << endl;
	}
	else{
		cout << "a1>a2" << endl;
	}
}

int main(){
	test();
	system("pause");
	return 0;
}