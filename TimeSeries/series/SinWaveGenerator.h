//
// Created by Thibaut Hérault on 24/12/2023.
//

#ifndef TIMESERIES_SINWAVEGENERATOR_H
#define TIMESERIES_SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

class SinWaveGenerator: public TimeSeriesGenerator {
private:
    double a = 1;
    double omega = 1;
    double phi = 0;
public:
    SinWaveGenerator() = default;
    SinWaveGenerator(double, double, double);
    std::vector<double> generateTimeSeries(int) override;
};


#endif //TIMESERIES_SINWAVEGENERATOR_H
