#include <iostream>
#include <string>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;
using std::cin; using std::cout; using std::endl;

map<set<string>, int> Routes;

int main()
{
	
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int stopCount; cin >> stopCount;
		
		set<string> route;

		for (size_t sn = 0; sn < stopCount; sn++)
		{
			string stop; cin >> stop;
			route.insert(stop);
		}

		if (Routes.count(route) != 0)
			cout << "Already exists for " << Routes[route] << endl;
		else
		{
			int routeNum = Routes.size() + 1;
			Routes[route] = routeNum;
			cout << "New bus " << routeNum << endl;
		}
	}

	return 0;
}