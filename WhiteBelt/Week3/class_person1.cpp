#include <iostream>
#include <string>
#include <map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::map;


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
private:
	map<int, string, std::greater<int>> _Surnames;
	
	map<int, string, std::greater<int>> _Names;
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
