#include <iostream>
using namespace std;
#include <cstdio>
#include <string>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    string current_list_of_friends;
    string new_list_of_friends;
    string current_friend;
    string list_of_friends_with_indication = "";
    string name;
    bool has_indication = false;
    
    getline(cin, current_list_of_friends);
    
    getline(cin, new_list_of_friends);
    
    getline(cin, current_friend);
    
    if (current_friend.compare("no") == 0){
        current_list_of_friends += " " + new_list_of_friends;
        cout << current_list_of_friends << '\n';
    } else {
        istringstream ss(current_list_of_friends);
    
        while(getline(ss, name, ' ')) {
            if (current_friend.compare(name) == 0){
                list_of_friends_with_indication += new_list_of_friends + " ";
                has_indication = true;
            }
            
            list_of_friends_with_indication += name + " ";
        }
        
        if(!has_indication){
            list_of_friends_with_indication += new_list_of_friends;
        } else {
            list_of_friends_with_indication.pop_back();
        }
        
        cout << list_of_friends_with_indication << '\n';
    }

    return 0;
}