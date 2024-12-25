#include "bloom_filters.h"
#include <iostream>

using namespace std;

template <typename T>
void bloom_filter<T>::add_item(const T& key)
{
	size_t	k_hash = (hash<T>{}(key)) % m_size;

	m_filter_array[k_hash]++;
}

template <typename T>
void bloom_filter<T>::delete_item(const T& key)
{
	size_t	k_hash = (hash<T>{}(key)) % m_size;

	m_filter_array[k_hash] ? m_filter_array[k_hash]-- : 0;
}

template<typename T>
bool bloom_filter<T>::query_item(const T& key)
{
	size_t	k_hash = (hash<T>{}(key)) % m_size;
	
	return (m_filter_array[k_hash]);
}

template <typename T>
void bloom_filter<T>::print_filter()
{
	for (int ii = 0; ii < m_size; ii++)
	{
		cout << ii << ":"<< m_filter_array[ii] << " ";
	}
	cout << endl;
}

template class bloom_filter<int>;
template class bloom_filter<string>;
