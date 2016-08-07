

/*
  Write code to remove duplicates from an unsorted linked list
 */


#include<stdio.h>
#include<iostream>
#include<list>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define d_type int

void print_list(list<d_type> &nums);
void rem_dup(list<d_type> &nums);

// Main creates unsorted linked list, then calls rem_dup()
int main(int argc, char* argv[])
{

  // Check for list length arg
  if (argc != 2)
    {
      cout << "List Length must be specified" << endl;
      return -1;
    }
  
  // establish List length
  int listLen = strtol(argv[1], NULL, 10);

  printf("Num Elements: %d\n", listLen);



  // Create unordered list of random integers 0:4 to ensure duplicates
  list<d_type> elems;
  srand(2048);

  for(int i = 0; i < listLen; i++)
      elems.push_back(rand() % 5);

  // Print list before rem_dup()
  cout << "BEFORE: ";
  print_list(elems);

  rem_dup(elems);

  cout << "AFTER: ";
  print_list(elems);

  return 0;
}


void print_list(list<d_type> &nums)
{
  list<d_type>::const_iterator it;
  for(it = nums.begin(); it != nums.end(); ++it)
    {
      cout << *it << " ";
    }
  cout << endl;
}


// O(1) space, O(N^2) time
void rem_dup(list<d_type> &nums)
{
  list<d_type>::iterator it1 = nums.begin(), it2;

  // iterate through with it1 (slow)
  for(; it1 != nums.end(); ++it1)
    {
      // Set it2 to element following 
      it2 = it1;
      it2++;

      // iterate rest of list with it2 (fast)
      for(; it2 != nums.end(); ++it2)
	{
	  //printf("it1: %d, it2: %d\n", *it1, *it2);

	  if( *it1 == *it2)
	    {
	      //cout << "Deleting " << *it2 << endl;
	      it2 = nums.erase(it2);
	      it2--;

	    }
	}
      //print_list(nums);
    }
}
