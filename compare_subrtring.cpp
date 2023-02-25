/* Dynamic Programming solution to
find length of the
longest common substring */
#include <iostream>
#include <string.h>
using namespace std;

/* Returns length of longest
common substring of X[0..m-1]
and Y[0..n-1] */
int LCSubStr(char* X, char* Y, int m, int n)
{
	// Create a table to store
	// lengths of longest
	// common suffixes of substrings.
	// Note that LCSuff[i][j] contains
	// length of longest common suffix
	// of X[0..i-1] and Y[0..j-1].

	int LCSuff[m + 1][n + 1];
	int result = 0; // To store length of the
					// longest common substring

	/* Following steps build LCSuff[m+1][n+1] in
		bottom up fashion. */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// The first row and first column
			// entries have no logical meaning,
			// they are used only for simplicity
			// of program
			if (i == 0 || j == 0)
				LCSuff[i][j] = 0;

			else if (X[i - 1] == Y[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else
				LCSuff[i][j] = 0;
		}
	}
	return result;
}

int main() {
  string first_string;
  string second_string;
  int max_size = 100000;
  char first_array[max_size];
  char second_array[max_size];
  int biggest_substring_size;

  while (getline(cin, first_string)){

      for (int j = 0; j < first_string.length(); j++){
        first_array[j] = first_string[j];
      }

      getline(cin, second_string);

      for (int j = 0; j < second_string.length(); j++)
        second_array[j] = second_string[j];

      biggest_substring_size = LCSubStr(first_array, second_array, first_string.length(), second_string.length());

      cout << biggest_substring_size << endl;
    
  }
  
  return 0;
}