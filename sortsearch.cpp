HW sort and searching
The insertion sort just jumps through all of the elements once. When the array is sorted, insertion sort does not have to move or look for the minimum element and does not need to go through the while loop.
Selection sort still has to look through all the element to check for the minimum.
O(n)
0XXXXXX0
X0XXXX0X
XX0XX0XX
XXX00XXX
Key: 0 - on | X - off
Stable sort
Selection sort is stable because when the sorting algorithm reaches a duplicate element, it skips over it since the original value is still the minimum value.
Insertion sort is stable because if the two values are the same, the next value being inserted keeps the order of being after the first duplicate.
4. Changed Code

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

bool binary_search(int a[], int from, int to, int value, int& pos)
{
   if (from > to)
   {
      pos = (from != sizeof(a)/sizeof(a[0]))?to:from;
      return false;
   }

   int mid = (from + to) / 2;
   if (a[mid] == value)
   {
	pos = mid;
      return true;
   }
   else if (a[mid] < value)
   {
      return binary_search(a, mid + 1, to, value, pos);
   }
   else
   {
      return binary_search(a, from, mid - 1, value, pos);
   }
}

int main()
{
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   values[0] = 0;
   for (int i = 1; i < SIZE; i++)
   {
      values[i] = values[i - 1] + rand() % 10;
      cout << values[i] << " ";
   }
   cout << endl;

   bool done = false;
   int pos;
   while (!done)
   {
      cout << "Enter number to search for, -1 when done: ";
      int target;
      cin >> target;
      if (target == -1)
         done = true;
      else
         if (binary_search(values, 0, SIZE - 1, target,pos) && pos != SIZE)
            cout << " Found in position " << pos << endl;
   }
   return 0;
}
