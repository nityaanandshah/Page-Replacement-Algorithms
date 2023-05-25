# Page Replacement Algorithms

## Description

In an operating system that uses paging for memory management, a page replacement algorithm is needed to decide which page needs to be replaced when a new page comes in. This program implements the following page replacement algorithms:
1. FIFO (First In First Out)
2. LRU (Least Recently Used)
3. Optimal

## User Input

a) Number of frames allocated to the process
b) Reference string

## Output

The program provides the following output:
- Number of page faults for each replacement algorithm

The simulation runs multiple times in a loop, using different values for the reference string in each iteration. The program also checks for Belady's Anomaly by increasing the number of frames and indicating the number of frames for which Belady’s Anomaly is visible.

## Implementation Details

1. First In First Out (FIFO): This algorithm keeps track of all pages in the memory in a queue. The oldest page in the queue (front of the queue) is selected for replacement when a new page needs to be added.

2. Least Recently Used (LRU): This algorithm selects the page that has been least recently used for replacement.

3. Optimal Page Replacement: This algorithm replaces pages that are not expected to be used for the longest duration of time in the future.

## Running the Program

1. Download the provided zip folder and extract all the files.
2. Open the "Lab06" folder and open the terminal in that folder.
3. Run the following commands:

For FIFO:
	$ g++ fifo.cpp -o fifo
	$ ./fifo

For LRU:
	$ g++ lru.cpp -o lru
	$ ./lru

For Optimal:
	$ g++ optimal.cpp -o optimal
	$ ./optimal

## Input

Provide the following inputs:
- Size of reference string
- Number of frames allocated to the process
- Reference string

## Output

The program will display the number of page faults for each replacement algorithm.

Belady's Anomaly occurs when increasing the number of page frames can lead to more page faults in the FIFO page replacement algorithm. For example, if we consider a reference string with slots 3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4, and 3, we get a total of 9 page faults. However, if we increase the number of slots to 4, we get 10 page faults.

