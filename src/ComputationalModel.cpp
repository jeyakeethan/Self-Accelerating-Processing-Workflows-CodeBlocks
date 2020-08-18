#include "computationalmodel.h"

ComputationalModel::ComputationalModel()
{
    //ctor
}

ComputationalModel::~ComputationalModel()
{
    //dtor
}

void ComputationalModel::execute(int *input, int *output)
{
    bool bounded = true;
    //Algorithm here
    if(bounded){
        CPUImplementation(input, output);
    }
    else {
        GPUImplementation(input, output);
    }
}
