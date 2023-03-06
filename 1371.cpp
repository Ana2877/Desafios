#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
  int number_of_rooms;
 
 
  cin >> number_of_rooms;
  while (number_of_rooms !=0) {

    for (int i = 1; i*i <= number_of_rooms; i ++ ) {
      cout << i*i;

      if ((i+1)*(i+1) <= number_of_rooms){
        cout << ' ';
      }

    }
      
    cout << endl;
    cin >> number_of_rooms;
  }
}