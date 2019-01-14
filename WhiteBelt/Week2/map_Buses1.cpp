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

inline void processLine()
{
	string cmd; cin >> cmd;

	if (cmd == "NEW_BUS")
	{
		string bus;	cin >> bus;

		int stopCount; cin >> stopCount;

		busesToRoutes[bus] = vector<string>();

		for (int i = 0; i < stopCount; i++)
		{
			string route; cin >> route;

			if (routesToBuses.count(route) == 0)
				routesToBuses[route] = vector<string>();

			routesToBuses[route].push_back(bus);

			busesToRoutes[bus].push_back(route);
			
		}
	}
	else if (cmd == "BUSES_FOR_STOP")
	{
		string stop; cin >> stop;
		if (routesToBuses.count(stop) == 0)
		{
			cout << "No stop" << endl;
			return;
		}

		for (const string& bus : routesToBuses[stop])
			cout << bus << " ";
		cout << endl;
	}
	else if (cmd == "STOPS_FOR_BUS")
	{
		string bus; cin >> bus;
		if (busesToRoutes.count(bus) == 0)
		{
			cout << "No bus" << endl;
			return;
		}

		for (const string& route : busesToRoutes[bus])
		{
			cout << "Stop " << route << ":";
			if (routesToBuses[route].size() == 1)
				cout << " no interchange" <<endl;
			else
			{
				for (const string& curBus : routesToBuses[route])
					cout << (curBus == bus ? "" : " " + curBus);
				cout << endl;
			}			
		}
		cout << endl;
	}
	else if (cmd == "ALL_BUSES")
	{
		if (busesToRoutes.size() == 0)
		{
			cout << "No buses" << endl;
			return;
		}

		for (auto pair : busesToRoutes)
		{
			cout << "Bus " << pair.first << ":";
			for (const string& route : pair.second)
				cout << " " << route;
			cout << endl;
		}
	}
}

int main()
{
	int n;	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		processLine();
	}

	return 0;
}