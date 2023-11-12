// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Unit 5 Exercise 5-2
// Course: SDEV-230
// Creation Date: 11/04/2023
// ----------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double pi = 0.0;
    long n;
    
    cout << "Enter the value of n: ";
    cin >> n;
    cout << endl;
    
    for (long i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            pi += 1.0 / (2 * i + 1);
        else
            pi -= 1.0 / (2 * i + 1);
    }
    // Multiply the sum by 4 to get pi 
    pi = 4 * pi;

    // Set the precision and display the result
    cout << fixed << setprecision(5);
    cout << "pi = " << pi << endl;
    return 0;
}
