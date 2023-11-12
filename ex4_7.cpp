// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Unit 4 Exercise 4-7
// Course: SDEV-230
// Creation Date: 11/04/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <limits>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants

int main() {
    // Delcare Local Variables
    double dblA = 0.0, dblB = 0.0, dblC = 0.0;
    double dblDiscriminant, dblRootPlus, dblRootMinus, dblRoot, dblImaginary;

    // Display instruction message to user
    cout << "----------------------------------------------------------------" << endl;
    cout << "You will be prompted to enter three values, (coefficient of x squared, " << endl;
    cout << "coefficient of x, and the constant term)." << endl;
    cout << "----------------------------------------------------------------" << endl;

    // Get the input from user
    cout << "Enter coefficient of x squared, coefficient of x, and the constant term: ";
    // If any of the inputs are false, then show error message
    if (!(cin >> dblA >> dblB >> dblC)) {
        cout << "Error: Invalid input." << endl;
        // Return non-zero value to indicate error
        return 1; 
    }

    // Set the decimal precision
    cout << fixed << setprecision(2);

    // If all is good, proceed to calculate the discriminant, root pluse and minus
    dblDiscriminant = pow(dblB, 2) - (4 * dblA * dblC);

    // Determine the discriminant value and equate the root value
    if (dblDiscriminant > 0) {
        // There are two real roots that are different
        dblRootPlus = (-dblB + sqrt(dblDiscriminant)) / (2 * dblA);
        dblRootMinus = (-dblB - sqrt(dblDiscriminant)) / (2 * dblA);
        // Display the results
        cout << "The roots are real and different.\n"
             << "Root 1: " << dblRootPlus << "\n"
             << "Root 2: " << dblRootMinus << endl;
    } else if (dblDiscriminant == 0) {
        // There are two real roots that are different
        dblRoot = -dblB / (2 * dblA);
        // Display the results
        cout << "The roots are real and repeated.\n"
             << "Root: " << dblRoot << endl;
    } else {
        // The roots are not real
        dblRoot = -dblB / (2 * dblA);
        dblImaginary = sqrt(-dblDiscriminant) /  (2 * dblA);
        // Display the results
        cout << "The roots are complex and different.\n"
             << "Root 1: " << dblRoot << " + " << dblImaginary << "i\n"
             << "Root 2: " << dblRoot << " - " << dblImaginary << "i" << endl;
    }
}