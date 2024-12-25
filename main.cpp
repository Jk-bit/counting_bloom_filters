#include "bloom_filters.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <unordered_map>

using namespace std;

void test_bloom_filter();

int main(void)
{
	test_bloom_filter();
	return 0;
}

void test_bloom_filter()
{
	const char alphanum[] = "ABXYM";
	bloom_filter<string>		filter(6000);
	unordered_map<string, int>	test_map;
	int				true_positive = 0, false_positive = 0;

	srand((unsigned)time(NULL) * getpid());
	for (int ii = 0; ii < 2000; ii++)
	{
		string			tmp_key;
		pair<string, int>	tmp_pair;
		for (int jj = 0; jj < 4; jj++)
		{
			tmp_key += alphanum[rand() % sizeof(alphanum)];
		}

		tmp_pair = make_pair(tmp_key, ii);
		test_map.insert(tmp_pair);
		filter.add_item(tmp_key);
	}

	for (int ii = 0; ii < 3125; ii++)
	{
		string			tmp_key;
		pair<string, int>	tmp_pair;
		for (int jj = 0; jj < 4; jj++)
		{
			tmp_key += alphanum[rand() % sizeof(alphanum)];
		}
		tmp_pair = make_pair(tmp_key, ii);
		if (filter.query_item(tmp_key)) {
			if (test_map.find(tmp_key) == test_map.end())
			{
				false_positive++;
			} else {
				true_positive++;
			}
		}
	}

	cout << "True positives : " << true_positive << endl;
	cout << "False positives : " << false_positive << endl;
}
