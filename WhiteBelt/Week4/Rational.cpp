#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

int maxCommonDenominator(int a, int b)
{
	if (a == 0 || b == 0)
		return a>b ? a : b;

	while (a > 0 && b > 0) {
		if (a > b) { a %= b; }
		else { b %= a; }
	}
	return a + b;
}

class Rational {
public:
	Rational() : num(0), den(1) { }

	Rational(int numerator, int denominator) : num(numerator), den(denominator) {
		bringToNormalForm();
	}

	friend istream& operator>>(istream& is, Rational& r);

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return den;
	}

	bool operator==(const Rational& rval) const
	{
		return Numerator() == rval.Numerator() && Denominator() == rval.Denominator();
	}

	Rational operator+(const Rational& rval) const
	{
		int lnum = Numerator(), rnum = rval.Numerator(), lden = Denominator(), rden = rval.Denominator();
		return Rational(lnum*rden + rnum * lden, lden*rden);
	}

	Rational operator-(const Rational& rval) const
	{
		int lnum = Numerator(), rnum = rval.Numerator(), lden = Denominator(), rden = rval.Denominator();
		return Rational(lnum * rden - rnum * lden, lden * rden);
	}

	Rational operator*(const Rational& rval) const
	{
		int lnum = Numerator(), rnum = rval.Numerator(), lden = Denominator(), rden = rval.Denominator();
		return Rational(lnum*rnum, lden*rden);
	}

	Rational operator/(const Rational& rval) const
	{
		if (rval.Numerator() == 0)
			throw domain_error("Can't divide by zero.");
		int lnum = Numerator(), rnum = rval.Numerator(), lden = Denominator(), rden = rval.Denominator();
		return Rational(lnum*rden, lden*rnum);
	}

	bool operator>(const Rational& rval) const
	{
		return (Numerator() / (float)Denominator()) > (rval.Numerator() / (float)rval.Denominator());
	}

	bool operator<(const Rational& rval) const
	{
		return (Numerator() / (float)Denominator()) < (rval.Numerator() / (float)rval.Denominator());
	}

private:
	int num, den;

	void bringToNormalForm()
	{
		if (den == 0)
			throw invalid_argument("Denominator can't be equal to zero.");

		if (signbit((float)num) ^ signbit((float)den)) // The numbers are of different signs 		
			num = -abs(num);
		else
			num = abs(num);

		den = abs(den);// make denominator positive anyway		 

		int commonDenom = maxCommonDenominator(abs(num), den);

		num /= commonDenom;
		den /= commonDenom;
	}
};

istream& operator>>(istream& is, Rational& r)
{
	is >> r.num;
	is.ignore(1);
	is >> r.den;
	r.bringToNormalForm();
	return is;
}

ostream& operator<<(ostream& os, const Rational& r)
{
	os << r.Numerator() << '/' << r.Denominator();
	return os;
}

//int main() {
//	
//	Rational r1, r2; char operation;
//	
//	try {
//		cin >> r1;
//		cin >> operation;
//		cin >> r2;
//	}
//	catch (exception)
//	{
//		cout << "Invalid argument";
//		return 0;
//	}
//
//	try {
//		Rational res;
//		if (operation == '/')
//			res = r1 / r2;
//		else if (operation == '*')
//			res = r1 * r2;
//		else if (operation == '-')
//			res = r1 - r2;
//		else if (operation == '+')
//			res = r1 + r2;
//
//			cout << res;
//	}
//	catch (exception)
//	{
//		cout << "Division by zero";
//		return 0;
//	}
//
//	return 0;
//}
