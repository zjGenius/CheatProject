#include "ScoringSystem.h"

ScoringSystem::ScoringSystem()
{
}

ScoringSystem::~ScoringSystem()
{
}

void ScoringSystem::PAUSE()
{
    system("read -p '按任意键继续...' var");
}

void MyPrintPlayer_Heima(const Player_Heima &p)
{
    cout << p;
}

void ScoringSystem::fileEmpty(char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        LOG_RED("文件打开失败");
        return;
    }

    LOG_GREEN("文件已清空");

    fclose(fp);
}

string ScoringSystem::saveData(const vector<Player_Heima> &p)
{
    char d[50];
    string ss;

    for (int i = 0; i < p.size(); i++)
    {
        sprintf(d, "选手[%s], 得分%d\n", p[i].name.c_str(), p[i].score);
        ss += d;
    }
    return ss;
}

void ScoringSystem::ViewPreviousGrades(char *filename)
{
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        LOG_RED("文件打开失败");
        return;
    }
    char ch = fgetc(fp);
    if (ch == EOF)
    {
        LOG_RED("文件为空");
        return;
    }

    LOG_GREEN("========往届比赛成绩=======");
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL)
    {
        cout << buffer;
    }

    fclose(fp);
}

void ScoringSystem::showMenu()
{
    cout << "---------------------------------------" << endl;
    cout << "-------------欢迎来到打分系统----------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "            1.查看往届比赛     " << endl;
    cout << "            2.开始演讲比赛    " << endl;
    cout << "            3.清空比赛记录    " << endl;
    cout << "            4.退出打分系统   " << endl;
    cout << "--------------------------------------- " << endl;
}

void ScoringSystem::initPlayer(vector<Player_Heima> &p, int num)
{
    vector<Player_Heima>().swap(p);
    for (int i = 0; i < num; i++)
    {
        Player_Heima player;
        memset(&player, 0, sizeof(Player_Heima));
        player.name = Player_name[i];
        p.push_back(player);
    }

    srand(time(NULL));
    random_shuffle(p.begin(), p.end());
    LOG_GREEN("选手初始化成功!");

    showPlayer(p);
}

void ScoringSystem::showPlayer(vector<Player_Heima> &p)
{
    cout << "姓名     分数" << endl;
    for_each(p.begin(), p.end(), MyPrintPlayer_Heima);
}

int getAverage(list<int> score)
{
    int sum = 0;
    for (list<int>::iterator it = score.begin(); it != score.end(); it++)
    {
        sum += *it;
    }
    return sum / score.size();
}

void ScoringSystem::Competition(vector<Player_Heima> &p, int Session, FILE *fp)
{
    srand(time(NULL));
    list<int> score_list;
    char data[50];

    LOG_YELLOW("========第%d轮比赛=======", Session);
    fprintf(fp, "========第%d轮比赛=======\n", Session);

    for (vector<Player_Heima>::iterator it = p.begin(); it != p.end(); it++)
    {
        fprintf(fp, "选手[%s]的评委打分 ", it->name.c_str());
        for (int j = 0; j < 10; j++)
        {
            int num = rand() % 50 + 50;
            score_list.push_back(num);
            fprintf(fp, "%d ", num);
        }
        fprintf(fp, "\n");
        score_list.sort();
        score_list.pop_back();
        score_list.pop_front();
        it->score = getAverage(score_list);
    }
    LOG_GREEN("选手得分情况");
    fprintf(fp, "选手得分情况\n");
    sort(p.begin(), p.end(), Player_Heima());
    showPlayer(p);
    fprintf(fp, "%s", saveData(p).c_str());
    if (p.size() > 2)
        p.resize(p.size() / 2 + 1);
    else
        p.resize(p.size() / 2);
    LOG_GREEN("晋级选手名单");
    fprintf(fp, "晋级选手名单\n");
    showPlayer(p);
    fprintf(fp, "%s\n", saveData(p).c_str());
}

void ScoringSystem::StartCompetition(vector<Player_Heima> &p)
{
    int num = 1;
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        LOG_RED("文件打开失败");
        return;
    }

    while (p.size() != 1)
    {
        Competition(p, num, fp);
        PAUSE();
        num++;
    }

    fclose(fp);
    LOG_YELLOW("比赛结束");
    PAUSE();
}

void ScoringSystem::startSystem()
{
    // signal(SIGINT, SIG_IGN);
    system("mkdir ./heima");
    filename = "./heima/data.csv";

    int select;
    vector<Player_Heima> player_vec;

    while (1)
    {
        system("clear");
        showMenu();
        cout << "请输入您的选项： " << endl;
        cin >> select;

        switch (select)
        {
        case 1:
            ViewPreviousGrades(filename);
            PAUSE();
            break;
        case 2:
            long long num;
            cout << "请输入选手的数量" << endl;
            while (1)
            {
                cin >> num;
                if (num > 0 && num <= 10)
                    break;
                LOG_RED("超过阈值,请重新输入");
            }
            initPlayer(player_vec, num);
            StartCompetition(player_vec);
            break;
        case 3:
            fileEmpty(filename);
            PAUSE();
            break;
        case 4:
            LOG_YELLOW("欢迎下次再来");
            return;

        default:
            LOG_RED("没有该选项");
            PAUSE();
            break;
        }
    }
}