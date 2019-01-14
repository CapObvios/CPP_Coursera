#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::sort; using std::lexicographical_compare;
using std::vector;
using std::string;

class SortedStrings {
public:
	void AddString(const string& s) {
		auto it = std::lower_bound(begin(sorted), end(sorted), s);
		sorted.insert(it, s);
	}
	vector<string> GetSortedStrings() {
		return sorted;
	}
private:
	vector<string> sorted;
};