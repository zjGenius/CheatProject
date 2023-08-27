#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace polymorphicComputer
{
    class CPU
    {
    public:
        virtual void work() = 0;
    };
    class GPU
    {
    public:
        virtual void work() = 0;
    };
    class RAM
    {
    public:
        virtual void work() = 0;
    };

    class IntelCPU : public CPU
    {
    public:
        void work()
        {
            cout << "Intel CPU工作" << endl;
        }
    };
    class LenvolCPU : public CPU
    {
    public:
        void work()
        {
            cout << "Lenvol CPU工作" << endl;
        }
    };
    class IntelGPU : public GPU
    {
    public:
        void work()
        {
            cout << "Intel GPU工作" << endl;
        }
    };
    class LenvolGPU : public GPU
    {
    public:
        void work()
        {
            cout << "Lenvol GPU工作" << endl;
        }
    };
    class IntelRAM : public RAM
    {
    public:
        void work()
        {
            cout << "Intel RAM工作" << endl;
        }
    };
    class LenvolRAM : public RAM
    {
    public:
        void work()
        {
            cout << "Lenvol RAM工作" << endl;
        }
    };

    class Computer
    {
    private:
        CPU *cpu;
        GPU *gpu;
        RAM *ram;

    public:
        Computer(CPU *c, GPU *g, RAM *r)
        {
            cpu = c;
            gpu = g;
            ram = r;
        }
        ~Computer()
        {
            if (cpu != NULL)
            {
                delete cpu;
                cpu = NULL;
            }
            if (gpu != NULL)
            {
                delete gpu;
                gpu = NULL;
            }
            if (ram != NULL)
            {
                delete ram;
                ram = NULL;
            }
        }
        void work()
        {
            cpu->work();
            gpu->work();
            ram->work();
        }
    };
}