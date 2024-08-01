#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to implement the BRUSS (Secretary) Algorithm
int brussAlgorithm(const vector<int>& candidates) {
    int n = candidates.size();
    int threshold = n / exp(1); // Calculate the threshold (n / e)
    int bestSoFar = -1; // Initialize the best candidate seen so far
    int bestIndex = -1; // Initialize the index of the best candidate

    // Phase 1: Reject the first n/e candidates and find the best among them
    for (int i = 0; i < threshold; ++i) {
        if (candidates[i] > bestSoFar) {
            bestSoFar = candidates[i];
        }
    }

    // Phase 2: Select the first candidate better than the best of the first n/e candidates
    for (int i = threshold; i < n; ++i) {
        if (candidates[i] > bestSoFar) {
            bestIndex = i;
            break;
        }
    }

    // If no better candidate is found in Phase 2, choose the last candidate
    if (bestIndex == -1) {
        bestIndex = n - 1;
    }

    return bestIndex;
}

// Helper function to generate random candidates
vector<int> generateCandidates(int n) {
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = rand() % 100 + 1; // Random values between 1 and 100
    }
    return candidates;
}

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int n = 10; // Number of candidates
    vector<int> candidates = generateCandidates(n);

    cout << "Candidates: ";
    for (int i = 0; i < n; ++i) {
        cout << candidates[i] << " ";
    }
    cout << endl;

    int bestCandidateIndex = brussAlgorithm(candidates);
    cout << "Best candidate selected is at index: " << bestCandidateIndex << " with value: " << candidates[bestCandidateIndex] << endl;

    return 0;
}
