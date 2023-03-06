#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
  int number_of_test_cases; 
  long long int number_of_warriors;
 
  cin >> number_of_test_cases;
  for (int i = 0; i < number_of_test_cases; i++) {
    cin >> number_of_warriors;
    int lines = (sqrt(8 * number_of_warriors + 1) - 1) / 2;
    cout << lines << endl;
  }
}