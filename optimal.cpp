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

// Function to check whether a page exists in a frame or not
bool exist(int key, vector<int>& frame)
{
	for (int i = 0; i < frame.size(); i++)
		if (frame[i] == key)
		{
			return true;
		}	
	return false;
}

// Function to find the frame that will not be used recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
	// Store the index of pages which are going to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future, return it.
		if (j == pn)
			return i;
	}

	// If all of the frames were not in future, return any of them, we return 0. Otherwise we return res.
	return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
	// An array for given number of frames
    vector<int> fr;
	// Traverse through page reference array to check for miss and hit.
	int hit = 0;
	for (int i = 0; i < pn; i++) {
		// Page found in a frame : HIT
		if (exist(pg[i], fr)) {
			hit++;
			continue;
		}
		
		// Page not found in a frame : MISS

		// If there is space available in frames
		if (fr.size() < fn)
			fr.push_back(pg[i]);

		// Find the page to be replaced
		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
	}
	cout << "Number of misses (page faults) = " << pn - hit << endl;
}

// Driver Function
int main()
{
	// int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	// int pn = sizeof(pg) / sizeof(pg[0]);
	// int fn = 4;
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
	optimalPage(pages, n, capacity);
	return 0;
}