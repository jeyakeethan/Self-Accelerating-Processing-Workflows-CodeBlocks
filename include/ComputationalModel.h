#ifndef COMPUTATIONALMODEL_H
#define COMPUTATIONALMODEL_H

class ComputationalModel
{
    public:
        //ComputationalModel();
        //virtual ~ComputationalModel();
        virtual void CPUImplementation() = 0;
        virtual void GPUImplementation() = 0;
        void execute();

    protected:

    private:
        volatile long tCPU = 0;
        volatile long tGPU = 0;
        bool isGPU = true;
};

#endif // COMPUTATIONALMODEL_H
