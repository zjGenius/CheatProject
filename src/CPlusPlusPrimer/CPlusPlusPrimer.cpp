#include "CPlusPlusPrimer.h"

CPlusPlusPrimer::CPlusPlusPrimer(/* args */)
{
}

CPlusPlusPrimer::~CPlusPlusPrimer()
{
}

void CPlusPlusPrimer::chapter1_display()
{
    Grammar *g = new Grammar();

    // g->test_while();
    g->test_count();
    // g->test_count1();
    // g->test_sacle_item();
}

void CPlusPlusPrimer::chapter12_display()
{
    ifstream infile("./text.txt");
    TextQuery tq(infile);
    while (1)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

void CPlusPlusPrimer::chapter10_display()
{
    // test_lambda();
    // test_inserter();
    test_bind();
    // test_iostream();
    // test_10_30();
    // test_10_31();

    // test_rbegin_rend();
    // test_10_34();
}