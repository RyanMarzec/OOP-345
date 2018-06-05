#pragma once

/*!--- List (of key-value pairs) Managment template --!*/

template <typename K, typename V, int N>
class KVList {
	K keys[N];
	V values[N];
	int dimensions;

public:
	/*!--- default constructor - safe empty state ---!*/
	KVList()
	   :dimensions(0)
		//keys(nullptr),
		//values(nullptr)
	{}

	/*!--- query - return number of entries (dimensions of arrays) ---!*/
	size_t size() const
	{
		return dimensions;
	}

	/*!--- query - return unmodifiable reference to K, ---!*
	 *!--- if out of bounds reference first element    ---!*/
	const K& key(int i) const
	{
		if (i > dimensions)
		{
			return keys[0];
		}
		else
		{
			return keys[i];
		}
	}

	/*!--- query - return unmodifiable reference to V ---!*
	*!---  if out of bounds reference first element   ---!*/
	const V& value(int i) const
	{
		if (i > dimensions)
		{
			return values[0];
		}
		else
		{
			return values[i];
		}
	}

	/*!--- add new element to list if room exists, ---!*
	 *!--- return reference to current objet       ---!*/ 
	KVList& add(const K& k, const V& v)
	{
		if (dimensions < N)
		{
			keys[dimensions] = k;
			values[dimensions] = v;
			dimensions++;
		}
		return *this;
	}

	/*!--- return the index of the first element ---!*
	 *!--- with key(k). defaults to 0            ---!*/ 
	int find(const K& k)
	{
		for (int i = 0; i < dimensions; i++)
		{
			if (k == keys[i])
			{
				return i;
			}
		}
		return 0;
	}

	/*!--- replaces element in the list with key & value ---!*
	 *!--- recived, return reference to current object   ---!*/ 
	KVList& replace(int i, const K& k, const V& v)
	{
		keys[i] = k;
		values[i] = v;
		return *this;
	}
};