#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <string>

using namespace std;

const set<char> Numbers = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-' };
set<char> DateDivisors = { '-' };

void ensureNextSymbol(istream& is, const set<char>& symbols)
{
	char c = char(is.peek());

	for (char sym : symbols)
	{
		if (c == sym)
			return;
	}

	throw runtime_error("Wrong symbol.");
}

void ensureEndOfStream(istream& is)
{
	char c = char(is.peek());

	if (is.eof()) 
		return;

	throw runtime_error("Not the end of stream.");
}

struct Date {
	int year;
	int month;
	int day;

	Date(int y = 1, int m = 1, int d = 1) : year(y), month(m), day(d)
	{
		ensureCorrectness();
	}

	bool operator<(const Date& rval) const
	{
		if (year != rval.year) return year < rval.year;
		else if (month != rval.month) return month < rval.month;
		else if (day != rval.day) return day < rval.day;
		return false;
	}

	bool operator>(const Date& rval) const
	{
		if (year != rval.year) return year > rval.year;
		else if (month != rval.month) return month > rval.month;
		else if (day != rval.day) return day > rval.day;
		return false;
	}

	bool operator==(const Date& rval) const
	{
		year == rval.year && month == rval.month && day == rval.day;		
	}

	void ensureCorrectness()
	{
		if (month < 1 || month > 12)
			throw runtime_error("Month value is invalid: " + to_string(month));
		else if (day < 1 || day > 31)
			throw runtime_error("Day value is invalid: " + to_string(day));
	}
};

ostream& operator<<(ostream& os, const Date& date)
{
	os	<< setw(4) << setfill('0') << date.year  << '-'
		<< setw(2) << setfill('0') << date.month << '-'
		<< setw(2) << setfill('0') << date.day;

	return os;
}								

istream& operator>>(istream& is, Date& date)
{
	string sdate;
	is >> sdate;

	stringstream dateStream(sdate);
	
	try {
		ensureNextSymbol(dateStream, Numbers);
		dateStream >> date.year;

		ensureNextSymbol(dateStream, DateDivisors);
		dateStream.ignore(1);

		ensureNextSymbol(dateStream, Numbers);
		dateStream >> date.month;

		ensureNextSymbol(dateStream, DateDivisors);
		dateStream.ignore(1);

		ensureNextSymbol(dateStream, Numbers);
		dateStream >> date.day;

		ensureEndOfStream(dateStream);
	}
	catch (const exception& e)
	{
		throw runtime_error("Wrong date format: " + sdate);
	}

	date.ensureCorrectness();

	return is;
}



//
//int main()
//{
//	try {
//		Date date;
//		cin >> date;
//		cout << date;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what();
//	}	
//
//	system("pause");
//
//	return 0;
//}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}
	void DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0 && data[date].count(event) > 0)
		{
			data[date].erase(event);
			cout << "Deleted successfully" << endl;
		}
		else
			cout << "Event not found" << endl;			
	}
	void  DeleteDate(const Date& date) {
		if (data.count(date) > 0)
		{
			cout << "Deleted " << to_string(data[date].size()) << " events" << endl;
			data.erase(date);
		}
		else
			cout << "Deleted 0 events" << endl;
	}
	void Find(const Date& date) const {
		if (data.count(date) > 0)
			for (const string& s : data.at(date))
				cout << s << endl;
	}
	void Print() const {
		for (auto kpv : data)
			for (string s : kpv.second)
				cout << kpv.first << ' ' << s << endl;
	}

private:
	map<Date, set<string>> data;
};

Database db;

void executeCommand(const string& line)
{
	stringstream commandStream(line);

	string command; commandStream >> command;

	if (command == "Add")
	{
		Date date; commandStream >> date;
		string entry; commandStream >> entry;		
		db.AddEvent(date, entry);
	}
	else if (command == "Del")
	{
		Date date; commandStream >> date;
		commandStream.peek();
		if (commandStream.eof()) { db.DeleteDate(date); }
		else {
			string entry; commandStream >> entry;
			db.DeleteEvent(date, entry);
		}
	}
	else if (command == "Find")
	{
		Date date; commandStream >> date;
		db.Find(date);
	}
	else if (command == "Print")
	{
		db.Print();
	}
	else
	{
		cout << "Unknown command: " + command << endl;
	}
}

int main() {
	Database db;

	string line;
	while (getline(cin, line)) {
		if (line == "") continue;
		else
		{
			try { executeCommand(line); }
			catch (const exception& e) { cout << e.what() << endl; }
		}
	}

	return 0;
}