
#include "CoinSimulation.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

using namespace std;

void runCoinSimulation(vector<int> flipCounts, vector<double> probabilities, int m) {
    random_device rd;
    mt19937 gen(rd());
    //limit to 2 decimal places for output
    cout << fixed << setprecision(2);

    cout << "\n ----Biased Coin Simulation---- \n\n";

    cout << left
         << setw(25) << "Number of Flips (n)"
         << setw(20) << "Trial Number (m)"
         << setw(25) << "Probability of Heads (p)"
         << setw(20) << "Number of Heads"
         << "\n";

    cout << string(90, '-') << "\n";

    for (double p : probabilities) {
        //found online, used to set the probability of heads for the coin flip
        bernoulli_distribution coin(p);
        for (int n : flipCounts) {
            int totalHeads = 0;
            for (int trial = 1; trial <= m; trial++) {
                int heads = 0;
                for (int flip = 0; flip < n; flip++) {
                    if (coin(gen)) {
                        heads++;
                    }
                }
                totalHeads += heads;

                // Print Trial Results
                cout << left
                     << setw(25) << n
                     << setw(20) << trial
                     << setw(25) << p
                     << setw(20) << heads
                     << "\n";
            }

            // Print experimental average
            double averageHeads =
                static_cast<double>(totalHeads) / m;

            cout << "\nAverage Heads: " << averageHeads
                 << " | Expected Heads: " << n * p
                 << "\n\n";
        }
    }
}
