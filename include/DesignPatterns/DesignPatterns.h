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
#include "Builder.h"

#include "Subject.h"
#include "Observer.h"
#include "AbstractFactory.h"
#include "Work.h"
#include "adapter.h"
#include "Memento.h"

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
    void builder_display();
    void observer_display();
    void abstractFactory_display();
    void state_display();
    void adapter_display();
    void memento_display();
};

#endif // !_DESIGN_PATTERNS_H_