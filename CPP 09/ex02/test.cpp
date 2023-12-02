static bool paircomp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return std::max(a.first, a.second) < std::max(b.first, b.second);
}
// Recursive function to sort the sequence by the largest pair value

static void recursort(std::vector<std::pair<int, int> > &vecpair, size_t start, size_t end)
{
	if (start < end)
	{
		size_t max = start;
		for (size_t i = start + 1; i < end; ++i)
		{
			if (paircomp(vecpair[i], vecpair[max]))
				max = i;
		}
		std::swap(vecpair[max], vecpair[end - 1]);
		recursort(vecpair, start, end - 1);
	}
}

// Function to calculate the nth Jacobsthal-Lucas number which works in O(Log n) time

static int jcbnb(int nb)
{
	if (nb == 0)
		return 0;
	if (nb == 1)
		return 1;
	return jcbnb(nb - 1) + 2 * jcbnb(nb - 2);
}

// Binary search function to find the insertion point 

static size_t binsearch(const std::vector<int>& vec, int nb)
{
	size_t start = 0;
	size_t end = vec.size();
	while (start < end)
	{
		size_t mid = start + (end - start) / 2;
		if (vec[mid] < nb)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

void FJMI::sort_vector()
{
	// make pairs, if odd, store it
	std::vector<std::pair<int, int> > vecpair;

	size_t i = 0;
	for (; i < _size - 1; i+=2)
		vecpair.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	if (i < _size)
		_odd = _vec[i];

	// sort index of each pair
	for (size_t i = 0; i < vecpair.size(); ++i)
	{
		if (vecpair[i].first > vecpair[i].second)
			std::swap(vecpair[i].first, vecpair[i].second);
	}
		
	// sort by largest pair value
	recursort(vecpair, 0, vecpair.size());

	// push highest value of each pair to the initial vector by cleaning it first
	_vec.clear();
	for (size_t i = 0; i < vecpair.size(); ++i)
		_vec.push_back(vecpair[i].second);

	// optimal = remaining numbers + odd if exist

	std::vector<int> optimal;

	for (size_t i = 0; i < vecpair.size(); ++i)
		optimal.push_back(vecpair[i].first);
	if (_odd)
		optimal.push_back(_odd);

	// calculate jcbnb for each optimal number
		
	std::vector<int> jcbvec;
	for (size_t i = 0; i < optimal.size(); ++i)
		jcbvec.push_back(jcbnb(optimal[i]));

	// binary search to insert

	for (size_t i = 0; i < optimal.size(); ++i)
	{
		size_t insertionIndex = binsearch(_vec, jcbvec[i]);
		_vec.insert(_vec.begin() + insertionIndex, optimal[i]);
	}
}