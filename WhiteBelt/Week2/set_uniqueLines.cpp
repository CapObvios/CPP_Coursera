#include <iostream>
#include <string>
#include <set>

using std::string;
using std::set;
using std::cin; using std::cout; using std::endl;


int main()
{
	int n;	
	cin >> n;
	
	set<string> uniqueLines;

	for (int i = 0; i < n; i++)
	{
		string line; cin >> line;
		uniqueLines.insert(line);
	}

	cout << uniqueLines.size();

	return 0;
}