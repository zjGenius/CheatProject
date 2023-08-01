/**
 * @file AbstractFactory.h
 * @author zhangjun (1905212905@qq.com)
 * @brief 抽象工厂模式
 * @version 0.1
 * @date 2023-08-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include <string>
#include <list>

class Student
{
private:
    int id;
    std::string name;

public:
    void setId(int id)
    {
        this->id = id;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    int getId()
    {
        return this->id;
    }
    std::string getName()
    {
        return this->name;
    }
};

class Teacher
{
private:
    int id;
    std::string name;

public:
    void setId(int id)
    {
        this->id = id;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    int getId()
    {
        return this->id;
    }
    std::string getName()
    {
        return this->name;
    }
};

class Student_SQL
{
public:
    virtual void Insert(Student *student) = 0;
    virtual Student *getStudent(int id) = 0;
};

class Teacher_SQL
{
public:
    virtual void Insert(Teacher *teacher) = 0;
    virtual Teacher *getTeacher(int id) = 0;
};

class SQLServer_Student : public Student_SQL
{
private:
    std::list<Student *> students;

public:
    void Insert(Student *student)
    {
        students.push_back(student);
    }

    Student *getStudent(int id)
    {
        std::list<Student *>::iterator iter;
        for (iter = students.begin(); iter != students.end(); ++iter)
        {
            if ((*iter)->getId() == id)
                return *iter;
        }
        return nullptr;
    }
};

class Access_Student : public Student_SQL
{
private:
    std::list<Student *> students;

public:
    void Insert(Student *student)
    {
        students.push_back(student);
    }

    Student *getStudent(int id)
    {
        std::list<Student *>::iterator iter;
        for (iter = students.begin(); iter != students.end(); iter++)
        {
            if ((*iter)->getId() == id)
                return *iter;
        }
        return nullptr;
    }
};

class SQLServer_Teacher : public Teacher_SQL
{
private:
    std::list<Teacher *> teachers;

public:
    void Insert(Teacher *teacher)
    {
        teachers.push_back(teacher);
    }

    Teacher *getTeacher(int id)
    {
        std::list<Teacher *>::iterator iter;
        for (iter = teachers.begin(); iter != teachers.end(); iter++)
        {
            if ((*iter)->getId() == id)
                return *iter;
        }
        return nullptr;
    }
};

class Access_Teacher : public Teacher_SQL
{
private:
    std::list<Teacher *> teachers;

public:
    void Insert(Teacher *teacher)
    {
        teachers.push_back(teacher);
    }

    Teacher *getTeacher(int id)
    {
        std::list<Teacher *>::iterator iter;
        for (iter = teachers.begin(); iter != teachers.end(); iter++)
        {
            if ((*iter)->getId() == id)
                return *iter;
        }
        return nullptr;
    }
};

class SQL_Factory
{
public:
    virtual Student_SQL *createStudent_SQL() = 0;
    virtual Teacher_SQL *createTeacher_SQL() = 0;
};

class SQLServerFactory : public SQL_Factory
{
public:
    Student_SQL *createStudent_SQL()
    {
        return new SQLServer_Student();
    }
    Teacher_SQL *createTeacher_SQL()
    {
        return new SQLServer_Teacher();
    }
};

class AccessFactory : public SQL_Factory
{
public:
    Student_SQL *createStudent_SQL()
    {
        return new Access_Student();
    }
    Teacher_SQL *createTeacher_SQL()
    {
        return new Access_Teacher();
    }
};

#endif // !_ABSTRACT_FACTORY_H_