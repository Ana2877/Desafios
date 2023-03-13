// C++ program to check if two
// circles touch each other or not.
#include <bits/stdc++.h>
using namespace std;

int circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double d = sqrt((x1 - x2) * (x1 - x2)
                    + (y1 - y2) * (y1 - y2));
  
    if (d + r2 <= r1) {
        cout << "RICO" << endl;
    } else {
        cout << "MORTO" << endl;
    }
    return 0;
}

// Driver code
int main() {
    int x1, y1, x2, y2, r1, r2;

    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
        circle(x1, y1, x2, y2, r1, r2);
    }

	    return 0;
}