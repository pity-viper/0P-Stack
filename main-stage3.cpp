/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include <chrono>
#include <iostream>

#include "stack-stage3.h"

using namespace std;

double time_n_pushes(unsigned n) {
    stack<unsigned> s;

    // get the starting clock value
    auto start_time = chrono::system_clock::now();

    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }

    // get the ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}

int main() {
    // You can use this main() to run your own analysis or initial testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;
    unsigned int num_pushes = 1000000;
    double elapsed_time = time_n_pushes(num_pushes);
    cout << "Number of Pushes: " << num_pushes << endl;
    cout << "Elapsed Time: " << elapsed_time << endl;
    cout << "Average Time: " << elapsed_time/num_pushes << endl; 
    return 0;
}
