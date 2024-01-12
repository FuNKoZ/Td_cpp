//
// Created by Thibaut Hérault on 10/01/2024.
//

#ifndef TIMESERIES_KNN_H
#define TIMESERIES_KNN_H

#include <string>
#include "TimeSeriesDataset.h"

using namespace std;

class KNN {
private:
    int k;
    string similarity_measure;
    std::vector<int> findKNearestNeighbors(const std::vector<double>& testInstance, const TimeSeriesDataset& trainData) const;

public:
    KNN(int, string);
    int predict(const vector<double> &testSeries, const TimeSeriesDataset &trainData) const;
    double evaluate(const TimeSeriesDataset &, const TimeSeriesDataset &, const std::vector<int> &) const;
};


#endif //TIMESERIES_KNN_H
