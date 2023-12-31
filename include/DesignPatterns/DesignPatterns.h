/**
 * @file DesignPatterns.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 大话设计模式相关代码
 * @version 0.1
 * @date 2023-08-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
#include "Composite.h"
#include "Bridge.h"
#include "Command.h"
#include "Responsibility.h"
#include "Colleague.h"
#include "FlyWeight.h"
#include "Interpreter.h"

#include "Visitor.h"

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
    void compsite_display();
    void bridge_display();
    void command_display();
    void responsibility_display();
    void mediator_display();
    void flyWeight_display();
    void interpreter_display();
    void visitor_display();
};

#endif // !_DESIGN_PATTERNS_H_