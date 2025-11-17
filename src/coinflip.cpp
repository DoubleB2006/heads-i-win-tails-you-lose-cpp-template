#include "coinflip.hpp"
#include <iostream>
#include <random>
#include <iomanip>

void runCoinFlipSimulation() {
    std::vector<int> nValues = {10, 50, 100, 200, 500};
    std::vector<double> pValues = {0.25, 0.5, 0.75};
    int m = 10; // trials per (n, p)

    // Random setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // Header
    std::cout << std::left
              << std::setw(15) << "n (flips)"
              << std::setw(15) << "trial #"
              << std::setw(20) << "p (prob of heads)"
              << std::setw(15) << "# of heads"
              << '\n';

    std::cout << std::string(65, '-') << '\n';

    // Simulation
    for (double p : pValues) {
        for (int n : nValues) {
            for (int trial = 1; trial <= m; ++trial) {
                int heads = 0;

                for (int flip = 0; flip < n; ++flip) {
                    double r = dist(gen);
                    if (r < p) {
                        heads++;
                    }
                }

                std::cout << std::left
                          << std::setw(15) << n
                          << std::setw(15) << trial
                          << std::setw(20) << std::fixed << std::setprecision(2) << p
                          << std::setw(15) << heads
                          << '\n';
            }
        }
    }
}
