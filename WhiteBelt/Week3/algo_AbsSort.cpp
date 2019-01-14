#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin; using std::cout; using std::endl;
using std::sort;

int main()
{
	vector<int> numbers;
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int num; cin >> num;
		numbers.push_back(num);
	}

	sort(begin(numbers), end(numbers), [](int x1, int x2) {return abs(x1) < abs(x2); });

	for (const auto& num : numbers)
		cout << num << ' ';

	return 0;
}