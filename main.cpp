#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include "src/CoinSimulation.hpp"

int main() {
    vector<int> flipCounts = {100, 200, 300, 400, 500};
    vector<double> probabilities = {0.25, 0.50, 0.75};
    int m = 20;

    runCoinSimulation(flipCounts, probabilities, m);

    return 0;
}
