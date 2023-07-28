#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include <string>

class Player
{
protected:
    std::string name_;

public:
    Player(std::string name) 
    {
        this->name_ = name;
    }

    virtual void Attack() = 0;
    virtual void Defence() = 0;
};

class Forwark : public Player
{
public:
    Forwark(std::string name) : Player(name) {}
    void Attack()
    {
        printf("前锋 %s 冲锋\n", name_.c_str());
    }
    void Defence()
    {
        printf("前锋 %s 防守\n", name_.c_str());
    }
};

class Center : public Player
{
public:
    Center(std::string name) : Player(name) {}
    void Attack()
    {
        printf("中锋 %s 冲锋\n", name_.c_str());
    }
    void Defence()
    {
        printf("中锋 %s 防守\n", name_.c_str());
    }
};

class Guards : public Player
{
public:
    Guards(std::string name) : Player(name) {}
    void Attack()
    {
        printf("后卫 %s 冲锋\n", name_.c_str());
    }
    void Defence()
    {
        printf("后卫 %s 防守\n", name_.c_str());
    }
};

class ForeignCenter
{
private:
    std::string name;

public:
    void setName(std::string name)
    {
        this->name = name;
    }
    std::string getName()
    {
        return this->name;
    }
    void Attck_CN()
    {
        printf("外籍中锋 %s 冲锋\n", this->name.c_str());
    }
    void Defence_CN()
    {
        printf("外籍中锋 %s 防守\n", this->name.c_str());
    }
};

class Transmit : public Player
{
private:
    ForeignCenter *cen;

public:
    Transmit(std::string name) : Player(name)
    {
        cen = new ForeignCenter();
        cen->setName(name);
    };
    void Attack()
    {
        cen->Attck_CN();
    }
    void Defence()
    {
        cen->Defence_CN();
    }
};

#endif // !_ADAPTER_H_