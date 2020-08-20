#ifndef COMPUTATIONALMODEL_H
#define COMPUTATIONALMODEL_H

#include <windows.h>


class ComputationalModel
{
    public:
        //ComputationalModel();
        //virtual ~ComputationalModel();
        static void updateResults(LARGE_INTEGER start,LARGE_INTEGER stop,LARGE_INTEGER freq, int processor);
        void execute();

    protected:

    private:
        int processor = 0;
        virtual void CPUImplementation() = 0;
        virtual void GPUImplementation() = 0;
};

#endif // COMPUTATIONALMODEL_H
