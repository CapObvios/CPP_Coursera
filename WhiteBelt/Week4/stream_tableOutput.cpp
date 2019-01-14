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
		int N, M, num; is >> N >> M;

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M-1; j++)
			{
				is >> num; is.ignore(1);
				cout << std::setw(10) << num << ' ';
			}
			is >> num;
			cout << std::setw(10) << num << endl;

		}
	}
	else
	{
		cout << "A problem occured while reading file" << endl;
	}

	return 0;
}