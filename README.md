# Page-Replacement-Algorithms
To implement FIFO, LRU and Optimal Page Replacement Algorithms (Considering the degree of multiprogramming as 1).
User Input:
a) Number of frames allocated to the process
b) Reference string
Output:
No. of page faults for each replacement algorithm
Running the simulation n number times in a loop (use different values for input b in each loop) for a
given choice and checking if there is Belady's Anomaly by increasing the number of frames.
Indicating the no of frames for which Belady’s Anomaly is visible.

====================================================================================================================================================
Description:

In an operating system that uses paging for memory management, a page replacement algorithm is needed to decide which page needs to be replaced when a new page comes in. 

Page Fault: A page fault happens when a running program accesses a memory page that is mapped into the virtual address space but not loaded in physical memory. Since actual physical memory is much smaller than virtual memory, page faults happen. In case of a page fault, Operating System might have to replace one of the existing pages with the newly needed page. 

Different page replacement algorithms:
1.) FIFO
2.) LRU
3.) Optimal

====================================================================================================================================================
Implementation Details:

1. First In First Out (FIFO): This is the simplest page replacement algorithm. In this algorithm, the operating system keeps track of all pages in the memory in a queue, the oldest page is in the front of the queue. When a page needs to be replaced page in the front of the queue is selected for removal.  

2.  Least Recently Used (LRU): In this algorithm, the page will be replaced which is least recently used. 

3. Optimal Page replacement: In this algorithm, pages are replaced which would not be used for the longest duration of time in the future. 

====================================================================================================================================================
Running the program :

1. Download the zip folder provided.
2. Extract all the files along with the folder.
3. Open the folder named “Lab06” and open the terminal in that folder
4. Run the following commands:
	For FIFO:
        $ g++ fifo.cpp -o fifo
        $ ./fifo

	For LRU:
	  $ g++ lru.cpp -o lru
        $ ./lru

	For Optimal:
	  $ g++ optimal.cpp -o optimal
        $ ./optimal

Input :

a) Size of reference string
b) Number of frames allocated to the process
c) Reference string

Output :

Number of page faults for each replacement algorithm

Belady's Anamoly proves that it is possible to have more page faults when increasing the number of page frames while using the First in First Out (FIFO) page replacement algorithm.  
For example, if we consider reference strings 3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4, and 3 slots, we get 9 total page faults, but if we increase slots to 4, we get 10-page faults.
     
