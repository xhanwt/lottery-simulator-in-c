// This program stimulates a lottery
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

// Function Prototypes
void generateLotteryNumbers(int[], int);
void getUserNumbers(int[], int);
int findMatches(int[], int[], int);
void displayValues(int[], int[], int);

// Variables
const int ARRAY_SIZE = 5;

int main() {
      int lottery[ARRAY_SIZE]; // Lottery numbers
      int user[ARRAY_SIZE];    // User's numbers
      int numMatches;          // Number of matches
    
      // Generate the random lottery numbers.
      generateLotteryNumbers(lottery, ARRAY_SIZE);
    
      // Get the user's numbers.
      getUserNumbers(user, ARRAY_SIZE);
    
      // Get the number of matching numbers.
      numMatches = findMatches(lottery, user, ARRAY_SIZE);
    
      // Display the lottery and user numbers.
      displayValues(lottery, user, ARRAY_SIZE);
// Display the number of matching numbers.
if (numMatches > 1 || numMatches == 0)
cout << "You matched " << numMatches << " numbers.\n";
else
// Determine whether the user won the grand prize.
if (numMatches == 5)
cout << "🎉 Congratulations! You're the grand prize winner!!\n";
return 0; 
    }

// Generate random lottery number function
void generateLotteryNumbers(int lottery[], int size){
  
    // Generate random number
    random_device myEngine;
    uniform_int_distribution<int> randomInt(0, 9);
    
    // Assign in lottery array
    for (int i = 0; i < size; i++) {
        lottery[i] = randomInt(myEngine);
    }
  
    }

// Enter user guesses function
void getUserNumbers(int user[], int size){
    cout << "Welcome to the lottery. 💸\n";
    for (int x = 0; x < size; x++){
        cout << x + 1 << ":➡️ Enter a digit between 0 and 9: ";
        cin >> user[x];

        // Validation
        while (user[x] < 0 || user[x] > 9 || !cin.good()) {
            cout << "⚠️ Error: input invalid! Please try again." << endl;
            cout << x + 1 << ":➡️ Enter a digit between 0 and 9: ";
            cin >> user[x];
        }
    }
}

// Finding matches function
int findMatches(int lottery[], int user[], int size){
    unsigned int match = 0;

    // Compare each from both arrays
    for (int c = 0; c < size; c++){
        if (lottery[c] == user[c])
            match++;
    }
    return match;
}

// Display results
void displayValues(int lottery[], int user[], int size){

    // Show lottery numbers
    cout << "Lottery numbers:\n";
    int l = 0;
    while (l < size){
    cout << setw(3) << lottery[l];
        l++;
    }
    cout << endl;

    // Show user inputs
    cout << "Your numbers:\n";
    int u = 0;
    while (u < size){
    cout << setw(3) << user[u];
        u++;
    }
    cout << endl;
    
}
