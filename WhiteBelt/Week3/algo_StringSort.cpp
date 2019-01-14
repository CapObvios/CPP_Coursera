#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using std::cin; using std::cout; using std::endl;
using std::sort; using std::lexicographical_compare;
using std::vector;
using std::string;

int main()
{
	vector<string> lines;
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		string line; cin >> line;
		lines.push_back(line);
	}

	sort(begin(lines), end(lines), [](string s1, string s2) {
		return lexicographical_compare(
			begin(s1), end(s1), begin(s2), end(s2),
			[](const char& c1, const char& c2) {return tolower(c1) < tolower(c2); }
		);
	});

	for (const auto& line : lines)
		cout << line << ' ';

	return 0;
}