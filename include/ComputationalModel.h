#ifndef COMPUTATIONALMODEL_H
#define COMPUTATIONALMODEL_H


class ComputationalModel
{
    public:
        ComputationalModel();
        virtual ~ComputationalModel();
        virtual void CPUImplementation(int *input, int *output) = 0;
        virtual void GPUImplementation(int *input, int *output) = 0;
        void execute(int *input, int *output);

    protected:

    private:

};

#endif // COMPUTATIONALMODEL_H
