#ifndef _DESIGN_PATTERNS_H_
#define _DESIGN_PATTERNS_H_

#include "SampleFactory.h"
#include "Strategy.h"
#include "Decorator.h"
#include "myDecorator.h"
#include "Proxy.h"
#include "FactoryMethod.h"
#include "Prototype.h"
#include "Template.h"
#include "Appearance.h"

class DesignPatterns
{
private:
    /* data */
public:
    DesignPatterns(/* args */);
    ~DesignPatterns();
    void sampleFactory_display();
    void strategy_display();
    void decorator_display();
    void proxy_display();
    void factoryMethod_display();
    void prototype_display();
    void template_display();
    void appearance_display();
};

#endif // !_DESIGN_PATTERNS_H_