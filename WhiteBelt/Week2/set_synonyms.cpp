#include <iostream>
#include <string>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;
using std::cin; using std::cout; using std::endl;


int main()
{
	map<string, set<string>> synonyms;
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		string command; cin >> command;

		if (command == "ADD")
		{
			string word1, word2; cin >> word1 >> word2;

			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		}
		else if (command == "COUNT")
		{
			string word; cin >> word;
			cout << synonyms[word].size() << endl;
		}
		else if (command == "CHECK")
		{
			string word1, word2; cin >> word1 >> word2;
			
			cout << (synonyms[word1].count(word2) == 0 ? "NO" : "YES") << endl;
		}
	}

	return 0;
}