#include <iostream>
#include "series/GaussianGenerator.h"
#include "series/StepGenerator.h"
#include "series/TimeSeriesDataset.h"
#include "series/SinWaveGenerator.h"
#include "series/KNN.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    TimeSeriesDataset trainData(false), testData(false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;
    std::vector<double> gaussian1 = gsg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(gaussian1);
    trainData.addTimeSeries(gaussian1 , 0);
    std::vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2 , 0);

    std::vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);
    std::vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);

    std::vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);
    std::vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);

    std::vector<int> ground_truth;
    std::vector<double> gaus = gsg.generateTimeSeries(11);
    testData.addTimeSeries(gaus);
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");
    std::cout << knn_1.evaluate(trainData , testData, ground_truth) << std::endl;

    KNN knn_2(2, "euclidean_distance");
    std::cout << knn_2.evaluate(trainData , testData, ground_truth) << std::endl;

    KNN knn_3(3, "levenshtein_distance");
    std::cout << knn_3.evaluate(trainData , testData, ground_truth) << std::endl;

    return 0;

}
