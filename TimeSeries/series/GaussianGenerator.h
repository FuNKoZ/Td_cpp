//
// Created by Thibaut Hérault on 23/12/2023.
//

#ifndef TIMESERIES_GAUSSIANGENERATOR_H
#define TIMESERIES_GAUSSIANGENERATOR_H


#include "TimeSeriesGenerator.h"


class GaussianGenerator: public TimeSeriesGenerator {
private:
    double mean = 0;
    double standard_deviation = 1;
public:
    GaussianGenerator() = default;
    GaussianGenerator(double, double);

    std::vector<double> generateTimeSeries(int) override;

};


#endif //TIMESERIES_GAUSSIANGENERATOR_H
