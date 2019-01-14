#include <iostream>
#include <string>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;
using std::cin; using std::cout; using std::endl;


set<string> BuildMapValuesSet(const map<int, string>& m) 
{	
	set<string> uniqueValues;

	for (const auto& val : m)
		uniqueValues.insert(val.second);

	return uniqueValues;
}