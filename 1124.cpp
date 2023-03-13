// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <iomanip> 
using namespace std;


// Driver program to test above functions
int main() {

    float  width, length, r1, r2;

    float  a, b, c;

    float  first_circle_dist, second_circle_dist, rectangle_hip;

    cin >> width >> length >> r1 >> r2;

    while(width != 0 && length != 0 && r1 != 0 && r2 != 0) {

        float  bigger_rad = max(r1, r2);

        float width_r2 = width - r2;
        float length_r2 = length - r2;

        float distance_circles = sqrt((r1 - width_r2) * (r1 - width_r2) + (r1 - length_r2) * (r1 - length_r2));

        if(length < bigger_rad*2 || width < bigger_rad*2) {
            cout << "N" << endl;
        } else if (length >= r1*2 + r2*2 && width >= bigger_rad) {
            cout << "S" << endl; 
        } else if (width >= r1*2 + r2*2 && length >= bigger_rad) {
            cout << "S" << endl; 
        } else if (distance_circles <= r1 - r2||distance_circles <= r2 - r1||distance_circles < r1 + r2) {
            cout << "N" << endl; 
        } else {
            cout << "S" << endl;
        }

        cin >> width >> length >> r1 >> r2;
    }

    return 0;
}