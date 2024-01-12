//
// Created by Thibaut Hérault on 23/12/2023.
//

#include "GaussianGenerator.h"
#include <cmath>

GaussianGenerator::GaussianGenerator(double _mean, double _standard_deviation): mean(_mean), standard_deviation(_standard_deviation) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int number) {
    double u1;
    double u2;

    double z0;
    srand(seed);
    std::vector<double> vector;
    vector.reserve(number);
    for (int i=0; i<number; i++){
        u1 = rand() / (RAND_MAX + 1.0);
        u2 = rand() / (RAND_MAX + 1.0);

        z0 = mean + standard_deviation * sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        // double z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);

        vector.push_back(z0);
    }
    return vector;
}

