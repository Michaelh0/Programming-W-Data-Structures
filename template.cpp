#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
    Gets the position of the smallest element in an array range.
    @param a the array
    @param from the beginning of the range
    @param to the end of the range
    @return the position of the smallest element in
    the range a[from]...a[to]
*/
int min_position(int a[], int from, int to)
{
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
      if (a[i] < a[min_pos]) { min_pos = i; }
   }
   return min_pos;
}

/**
   Swaps two integers.
   @param x the first integer to swap
   @param y the second integer to swap
*/
void swap(int& x, int& y)
{
   int temp = x;
   x = y;
   y = temp;
}

/**
   Sorts a array using the selection sort algorithm
   @param a the array to sort
   @param size the number of elements in a
*/
void selection_sort(int a[], int size)
{
   int next; // The next position to be set to the minimum

   for (next = 0; next < size - 1; next++)
   {
      // Find the position of the minimum starting at next
      int min_pos = min_position(a, next, size - 1);
      // Swap the next element and the minimum
      swap(a[next], a[min_pos]);
   }
}

/**
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
void print(int a[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

int main()
{
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   for (int i = 0; i < SIZE; i++)
   {
      values[i] = rand() % 100;
   }
   print(values, SIZE);
   selection_sort(values, SIZE);
   print(values, SIZE);
   return 0;
}
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
