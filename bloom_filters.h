#include <vector>
#include <cstddef>

template <typename T>
class bloom_filter
{
private:
	std::size_t				m_size;
	std::vector<std::size_t>		m_filter_array;
public:
	bloom_filter(std::size_t size)
		: m_size(size),
		  m_filter_array(size, 0)
	{
	}

	~bloom_filter() {}
	
	void add_item(const T& key);

	void delete_item(const T& key);

	bool query_item(const T& key);

	void print_filter(void);
};
