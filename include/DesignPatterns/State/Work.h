#ifndef _DESIGN_WORK_H_
#define _DESIGN_WORK_H_

#include "State.h"

class Work
{
private:
    State *state;
    double hour;
    bool finish;

public:
    Work();
    ~Work();
    double getHour();
    void setHour(double value);
    bool getFinish();
    void setFinish(bool value);
    void setState(State *s);
    void writeProgram();
};

#endif // !_DESIGN_WORK_H_