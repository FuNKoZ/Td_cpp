//
// Created by Thibaut Hérault on 24/12/2023.
//

#ifndef TIMESERIES_TIMESERIESDATASET_H
#define TIMESERIES_TIMESERIESDATASET_H

#include <vector>
#include "TimeSeriesGenerator.h"

class TimeSeriesDataset {
private:
    bool znormalize;
    int maxLength = 0;
    int numberOfSamples = 0;
    std::vector<int> labels;
    std::vector<std::vector<double>> data;
public:
    TimeSeriesDataset(bool);
    void addTimeSeries(const std::vector<double>&, int);
    void addTimeSeries(const std::vector<double>&);
    int getNumberOfSamples() const;
    const std::vector<int> &getLabels() const;
    const std::vector<std::vector<double>> &getData() const;
};


#endif //TIMESERIES_TIMESERIESDATASET_H
