#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
using namespace std;

// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity)
{
	// An Unordered Set to check if a page is present in set or not
	unordered_set<int> s;

	// To store the pages in FIFO
	queue<int> inds;
	int page_faults = 0;
	for (int i = 0; i < n; i++)
	{
		// Check if the set can hold more pages
		if (s.size() < capacity)
		{
			// Insert it into set if not present already which represents page fault
			if (s.find(pages[i]) == s.end())
			{
				s.insert(pages[i]);
            	page_faults++;
            	inds.push(pages[i]);
			}

			// If the page already present do nothing 
		}

		// If the set is full then remove the first page of the queue from set and queue both and insert the current page
		else
		{
			// Check if current page is not already present in the set
			if (s.find(pages[i]) == s.end())
			{
				int val = inds.front();
				inds.pop();
            	s.erase(val);
				s.insert(pages[i]);
				inds.push(pages[i]);
				page_faults++;
			}

			// If the page already present do nothing 
		}
	}
	return page_faults;
}

// Driver code
int main()
{
	// int pages[] = { 3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4};
	// int n = sizeof(pages)/sizeof(pages[0]);
	// int capacity = 4;
	int capacity, n, i = 0;
    cout << "Enter size of reference string : ";
	cin >> n;
    int pages[n];
	cout << "Enter reference string : ";
	while(i < n)
	{
		cin >> pages[i];
		i++;
	}
	cout << "Number of frames allocated to the process : ";
	cin >> capacity;
	cout << "Number of page faults : ";
	cout << pageFaults(pages, n, capacity);
	return 0;
}