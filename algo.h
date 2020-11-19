#ifndef ALGO_H
#define ALGO_H


#include <stdlib.h>
#include <vector>


template <class T>
inline const T& __median(const T& a, const T& b, const T& c) {
    if (a < b)
	if (b < c)
	    return b;
	else if (a < c)
	    return c;
	else
	    return a;
    else if (a < c)
	return a;
    else if (b < c)
	return c;
    else
	return b;
}

template <class T, class Compare>
inline const T& __median(const T& a, const T& b, const T& c, Compare comp) {
    if (comp(a, b))
	if (comp(b, c))
	    return b;
	else if (comp(a, c))
	    return c;
	else
	    return a;
    else if (comp(a, c))
	return a;
    else if (comp(b, c))
	return c;
    else
	return b;
}


template <class RandomAccessIterator, class T>
void __nth_element(RandomAccessIterator first, RandomAccessIterator nth,
		   RandomAccessIterator last, T*) {
    while (last - first > 3) {
	RandomAccessIterator cut = __unguarded_partition
	    (first, last, T(__median(*first, *(first + (last - first)/2),
				     *(last - 1))));
	if (cut <= nth)
	    first = cut;
	else
	    last = cut;
    }
    __insertion_sort(first, last);
}

template <class RandomAccessIterator>
inline void nth_elements(RandomAccessIterator first, RandomAccessIterator nth,
			RandomAccessIterator last) {
    __nth_element(first, nth, last, value_type(first));
}

template <class RandomAccessIterator, class T, class Compare>
void __nth_element(RandomAccessIterator first, RandomAccessIterator nth,
		   RandomAccessIterator last, T*, Compare comp) {
    while (last - first > 3) {
	RandomAccessIterator cut = __unguarded_partition
	    (first, last, T(__median(*first, *(first + (last - first)/2),
				     *(last - 1), comp)), comp);
	if (cut <= nth)
	    first = cut;
	else
	    last = cut;
    }
    __insertion_sort(first, last, comp);
}

template <class RandomAccessIterator, class Compare>
inline void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
		 RandomAccessIterator last, Compare comp) {
    __nth_element(first, nth, last, value_type(first), comp);
}


int main()
{

   std::vector<int> myvector;

   for(int i = 0; i < 10; i++) myvector.push_back(i);

   nth_elements(myvector.begin(), myvector.begin()+5, myvector.end());


}




#endif
