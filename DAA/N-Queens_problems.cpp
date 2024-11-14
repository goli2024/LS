#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Check row, column, and diagonal constraints
bool constraint(const vector<int>& cb) {
    int n = cb.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cb[i] == cb[j] || abs(cb[i] - cb[j]) == abs(i - j))
                return false;
        }
    }
    return true;
}

// Print output cb
void print(vector<int> &cb) {
    int n = cb.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cb[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the no. of row: ";
    cin >> n;
    int counter = 0;

    vector<int> cb(n);
    for (int i = 0; i < n; i++) {
        cb[i] = i;
    }

   
    // bruteforce all permutations
    do {
        if (constraint(cb)) {
            cout << "Solution " << counter++ << ":" << endl;
            print(cb);
        }
    } 
    while (next_permutation(cb.begin(), cb.end()));
    

    if (counter == 0) {
        cout << "No solutions found: "<< endl;
    }
    else
        cout << "Possible solutions: " << counter << endl;

    return 0;
}


