#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::map;
using std::cin; using std::cout; using std::endl;

std::map<string, vector<string>> busesToRoutes;
std::map<string, vector<string>> routesToBuses;

int main()
{
	int n;	
	cin >> n;

	map<vector<string>, int> routes;
	

	for (int i = 0; i < n; i++)
	{
		int stopCount; cin >> stopCount;

		string stop;
		vector<string> route;		

		for (size_t sn = 0; sn < stopCount; sn++)
		{
			cin >> stop;
			route.push_back(stop);			
		}
		if (routes.count(route) != 0)
			cout << "Already exists for " << routes[route] <<endl;
		else
		{
			int busNum = routes.size() + 1; // enumeration starting from 1
			routes[route] = busNum; 
			cout << "New bus " << busNum << endl;
		}
	}

	return 0;
}