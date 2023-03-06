#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;

int main() {
    string binary_number;
 
    while (getline(cin, binary_number)){
        string whole_binary_number = "";

        while(binary_number[binary_number.size() - 1] != '#'){
            whole_binary_number = whole_binary_number + binary_number;
            getline(cin, binary_number);
        }   

        if (binary_number[binary_number.size() - 1] == '#'){
            binary_number.pop_back();
            whole_binary_number = whole_binary_number + binary_number;
        }

        unsigned long long binary_to_decimal = 0;
        for (int i = 0; i < whole_binary_number.length(); i++){
            if (whole_binary_number[i] == '0') {
                binary_to_decimal = (binary_to_decimal * 2) % 131071;
            }
            else if (whole_binary_number[i] == '1') {
                binary_to_decimal = (binary_to_decimal * 2 + 1) % 131071;
            }
        }

        if(binary_to_decimal == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
  }
}