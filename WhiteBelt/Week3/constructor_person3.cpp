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
	Person(const string& name, const string& surname, int birthYear) 
		: _BirthYear(birthYear), _Names({ { birthYear, name } }), _Surnames({ {birthYear, surname} }) { }

	void ChangeFirstName(int year, const string& first_name) { if (validYear(year)) _Names[year] = first_name; }
	void ChangeLastName(int year, const string& last_name) { if (validYear(year)) _Surnames[year] = last_name; }

	string GetFullName(int year) const
	{
		if (!validYear(year)) return "No person";
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

	string GetFullNameWithHistory(int year) const
	{
		if (!validYear(year)) return "No person";
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

	int _BirthYear;

	vector<string> getHistoryList(map<int, string, std::greater<int>> yearDict, int year) const
	{
		vector<string> res;

		for (auto it = yearDict.lower_bound(year); it != yearDict.end(); ++it)
		{
			if (res.size() == 0 || res[res.size() - 1] != it->second) res.push_back(it->second);
		}
		return res;
	}

	string getHistoryString(map<int, string, std::greater<int>> yearDict, int year) const
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

	inline bool validYear(int year) const
	{
		return year >= _BirthYear;
	}
};


//int main() {
//	Person person("Polina", "Sergeeva", 1960);
//	for (int year : {1959, 1960}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1965, "Appolinaria");
//	person.ChangeLastName(1967, "Ivanova");
//	for (int year : {1965, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	return 0;
//}
