/**
 * @file ScoringSystem.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 黑马教程 演讲比赛流程管理系统
 * @version 0.1
 * @date 2023-09-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <signal.h>
#include <algorithm>
#include <numeric>
#include <fstream>

#include "log.h"

using namespace std;

struct Player_Heima
{
public:
    friend ostream &operator<<(ostream &out, const Player_Heima &p)
    {
        out << p.name << "         " << p.score << endl;
        return out;
    }

    bool operator()(const Player_Heima &p1, const Player_Heima &p2)
    {
        return p1.score > p2.score;
    }
    string name;
    int score;
};

class ScoringSystem
{
private:
    void PAUSE();
    void showMenu();
    void initPlayer(vector<Player_Heima> &p, int num);
    void StartCompetition(vector<Player_Heima> &p);
    void Competition(vector<Player_Heima> &p, int Session, FILE *fp);
    void showPlayer(vector<Player_Heima> &p);
    void ViewPreviousGrades(char *filename);
    string saveData(const vector<Player_Heima> &p);
    void fileEmpty(char *filename);

public:
    ScoringSystem();
    ~ScoringSystem();
    void startSystem();

private:
    const char Player_name[10]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *filename;
};