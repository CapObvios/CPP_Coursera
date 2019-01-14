#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::getline;

//#define OUTPUT_TO_FILE

void output(istream& is, ostream& os)
{
	string line;
	while (getline(is, line))
	{		
		os << line << endl;
	}
}

int main()
{
	ifstream is("input.txt");

	if (is.is_open())
	{
#ifdef OUTPUT_TO_FILE
		ofstream os("output.txt");
#else
		ostream& os = cout;
#endif // OUTPUT_TO_FILE

		output(is, os);
	}
	else
	{
		cout << "A problem occured while reading file" << endl;
	}

	return 0;
}