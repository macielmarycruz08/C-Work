#include <iostream>
using namespace std;

// Function for factorial of a number
int factorial(int n) {
    int answer = 1;
    for (int i = 1; i <= n; ++i) {
        answer *= i;
    }
    return answer;
}
        
// Function
void generatePermutations(int n) {
    // array containing numbers from 1 to n
    int numbers[20];
    for (int i = 1; i <= n; ++i) {
        numbers[i - 1] = i;
    }

    // total number of permutations
    int totalPermutations = factorial(n);

    // Output the number of permutations
    cout << "There are " << totalPermutations << " permutations of the set {1, 2, ..., " << n << "}:" << endl;

    // Generate and output all permutations
    do {
        for (int i = 0; i < n; ++i) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        ;
    } while (next_permutation(numbers, numbers + n));
}

int main() {
    int n;
    cout << "Enter a value for n between 1 to 20: ";
    cin >> n;
    // Input the value of n

    // Check if the n is between 1-20
    if (n < 1 || n > 20) {
        // Display for invalid input
        cout << "Invalid input. Please enter a value between 1 to 20.\n";
        return 1; // Exit
    }// Generate and output permutations
    generatePermutations(n);

    return 0; // Exit
}



