#include <iostream>
#include <computationalmodel.h>

//for time measure
#include <windows.h>
#include <iomanip>
#include <set>
#include <time.h>
#include <stdlib.h>

//for async function
#include <thread>
#include <future>

using namespace std;

// ComputationalModel::ComputationalModel(){}

// ComputationalModel::~ComputationalModel(){}


static long tCPU = 0;
static long tGPU = 0;

void ComputationalModel::execute()
{
/*    if(tCPU+tGPU==0){
        GPUImplementation();
    } else  */

    LARGE_INTEGER start, stop, freq;
	QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    if(processor == 0){
        CPUImplementation();
    }
    else {
        GPUImplementation();
    }

    QueryPerformanceCounter(&stop);
    async(std::launch::async, [&]() { ComputationalModel::updateResults(start, stop, freq, processor); });
    //ComputationalModel::updateResults(start, stop, freq, tCPU, tGPU);
}

void ComputationalModel::updateResults(LARGE_INTEGER start, LARGE_INTEGER stop, LARGE_INTEGER freq, int processor){
    // To a async function
    double delay = (double)(stop.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    int time = int(delay * 100000 + 0.5);
    if(processor){
        cout << "CPU Time: " << time << " ms" << endl;
    } else {
        cout << "GPU Time: " << time << " ms" << endl;
    }

    // cout << tCPU <<","<<tGPU << endl << endl;
}
