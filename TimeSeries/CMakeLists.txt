cmake_minimum_required(VERSION 3.27)
project(timeSeries)

set(CMAKE_CXX_STANDARD 23)

add_executable(timeSeries main.cpp
        series/TimeSeriesGenerator.cpp
        series/TimeSeriesGenerator.h
        series/GaussianGenerator.cpp
        series/GaussianGenerator.h
        series/StepGenerator.cpp
        series/StepGenerator.h
        series/SinWaveGenerator.cpp
        series/SinWaveGenerator.h
        series/TimeSeriesDataset.cpp
        series/TimeSeriesDataset.h
        series/KNN.h
        series/KNN.cpp)
