#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::getline;

int main()
{
	ifstream is("input.txt");

	if (is.is_open())
	{				
		cout << std::fixed << std::setprecision(3);
		double num;
		while (is >> num)
			cout << num << endl;			
	}
	else
	{
		cout << "A problem occured while reading file" << endl;
	}

	return 0;
}