/*
  Return Kth to last element in a list
*/

#include <stdio.h>
#include<iostream>
#include <list>
#include<time.h>


using namespace std;

#define d_type int

void print_list(list<d_type> &nums);
list<d_type>::iterator kLast(list<d_type> & nums, int k_back);


// Main creates unsorted linked list, then calls rem_dup()
int main(int argc, char* argv[])
{

  // Check for list length arg
  if (argc != 3)
    {
      cout << "Must Specify list length and k_Back" << endl;
      return -1;
    }
  
  // establish List length
  int listLen = strtol(argv[1], NULL, 10);
  int kBack = strtol(argv[2], NULL, 10);

  // Create unordered list of random integers 0:4 to ensure duplicates
  list<d_type> elems;
  srand(2048);

  for(int i = 0; i < listLen; i++)
      elems.push_back(rand() % 5);

  // Print list before rem_dup()
  cout << "LIST: ";
  print_list(elems);

  list<d_type>::iterator kk = kLast(elems, kBack);

  if(kk == elems.end())
    {
      cout << "ERROR: too few elements in list\n";
      return -1;
    }
  else
    printf("%d-To-Last = %d\n", kBack, (int)*kk);
  
  return 0;
}

void print_list(list<d_type> &nums)
{
  list<d_type>::const_iterator it;
  for(it = nums.begin(); it != nums.end(); ++it)
      cout << *it << " ";
  cout << endl;
}


list<d_type>::iterator kLast(list<d_type> & nums, int k_back)
{

  // Check if nums has at least k_back elements
  if (nums.size() < k_back)
      return nums.end();
      
  list<d_type>::iterator it1 = nums.begin(), it2, it3;
  it2 = it1;

  
  // Increment second iterator until k_back gap between
  for (int i = 0; i < k_back; i++)
      it2++;

  // it3 tests if it2 is last element
  it3 = it2;
  it3++;

  for (; it2 != nums.end(); ++it2)
    {

      // If it2 is AT last element
      if (it3 == nums.end())
	return it1;
      // Otherwise, increment iterators
      else
	{
	  it1++;
	  it3++;
	}   
    }
  // SHould never reach here.
  return nums.end();
}
