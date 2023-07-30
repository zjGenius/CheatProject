/**
 * @file Interpreter.h
 * @author zhangjun (strivejun@gmail.com)
 * @brief 设计模式之解释器模式
 * @version 0.1
 * @date 2023-07-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <string>
#include <iostream>
#include <cstring>

class PlayContext
{
private:
    std::string context;

public:
    void setContext(std::string c)
    {
        this->context = c;
    }

    std::string getContext()
    {
        return this->context;
    }
};

class Expression
{
public:
    void Interpreter(PlayContext *playcontext)
    {
        if (playcontext->getContext().size() == 0)
        {
            printf("无内容\n");
            return;
        }
        else
        {
            std::string compareChar = "OEGADC";
            // printf("\nplaycontext1:%s;\n", playcontext->getContext().c_str());
            std::string playKey = playcontext->getContext().substr(0, 1); // 找到字母

            std::string playValue = playcontext->getContext().substr(0, playcontext->getContext().find_first_of(" ")); // 找到数字

            // printf("playKey:%s,playValue:%s;\n", playKey.c_str(), playValue.c_str());

            playcontext->setContext(playcontext->getContext().substr(playcontext->getContext().find_first_of(" ") + 1));
            // printf("playcontext2:%s;\n", playcontext->getContext().c_str());

            double playValue_d = 0.0;

            if (strstr(compareChar.c_str(), playValue.c_str()) == NULL)
            {
                // printf("come stod.\n");
                playValue_d = std::stod(playValue);
            }

            Excute(playKey, playValue_d);
            if (playcontext->getContext().size() == 0)
                printf("\n演奏完毕\n");
        }
    }

    virtual void Excute(std::string key, double value) = 0;
};

// 音符类
class Note : public Expression
{
public:
    void Excute(std::string key, double value)
    {
        std::string note = "";
        const char *s_key = key.c_str();
        switch (s_key[0])
        {
        case 'C':
            note = "1";
            break;
        case 'D':
            note = "2";
            break;
        case 'E':
            note = "3";
            break;
        case 'F':
            note = "4";
            break;
        case 'G':
            note = "5";
            break;
        case 'A':
            note = "6";
            break;
        case 'B':
            note = "7";
            break;

        default:
            break;
        }
        printf("%s ", note.c_str());
    }
};

// 音符类
class Scale : public Expression
{
public:
    void Excute(std::string key, double value)
    {
        std::string note = "";
        int s = value;
        switch (s)
        {
        case 1:
            note = "低音";
            break;
        case 2:
            note = "中音";
            break;
        case 3:
            note = "高音";
            break;
        default:
            break;
        }
        printf("%s ", note.c_str());
    }
};

#endif //!_INTERPRETER_H_