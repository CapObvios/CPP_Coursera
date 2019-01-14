#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::map;
using std::vector;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		_Names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		_Surnames[year] = last_name;
	}
	string GetFullName(int year) {
		auto surname_it = _Surnames.lower_bound(year);
		auto name_it = _Names.lower_bound(year);

		if (surname_it != _Surnames.end() && name_it != _Names.end())
			return (name_it->second + " " + surname_it->second);
		else if (surname_it != _Surnames.end())
			return (surname_it->second + " with unknown first name");
		else if (name_it != _Names.end())
			return (name_it->second + " with unknown last name");
		else
			return "Incognito";
	}

	string GetFullNameWithHistory(int year) {
		string name = getHistoryString(_Names, year), 
			surname = getHistoryString(_Surnames, year);
		
		if (name != "" && surname != "")
			return (name + " " + surname);
		else if (surname != "")
			return (surname + " with unknown first name");
		else if (name != "")
			return (name + " with unknown last name");
		else
			return "Incognito";
	}
private:
	map<int, string, std::greater<int>> _Surnames;
	
	map<int, string, std::greater<int>> _Names;

	vector<string> getHistoryList(map<int, string, std::greater<int>> yearDict, int year)
	{
		vector<string> res;

		for (auto it = yearDict.lower_bound(year); it != yearDict.end(); ++it)
		{
			if (res.size() == 0 || res[res.size() - 1] != it->second) res.push_back(it->second);
		}
		return res;
	}

	string getHistoryString(map<int, string, std::greater<int>> yearDict, int year)
	{
		auto history = getHistoryList(yearDict, year);

		string res = "";

		if (history.size() > 0)
			res += history[0];

		for (int i = 1; i < history.size(); i++)
		{
			if (i == 1) res += " ("; // start of parethesised part
			res += history[i]; // add name
			if (i == (history.size() - 1)) res += ")"; // end of parenthesised part
			else res += ", "; // not end
		}

		return res;
	}
};


//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	return 0;
//}

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova-Sergeeva");
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1961, "Ivanova");
//	cout << person.GetFullNameWithHistory(1967) << endl;
//
//	return 0;
//}