#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <iostream>
#include <stdio.h>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <functional>
#include <algorithm>
#include <numeric>

#include "paramRead.h"
#include "log.h"

using namespace std;

void deque_test();
void list_test();
void map_test(int Mode);
void set_test(int Mode);
void STL_test();
void predicateOne_test();
void predicateTwo_test();
void functional_test1();
void functional_test2();
void functional_test3();

void algorithm_for();
void algorithm_find_example();
void algorithm_sort_example();
void algorithm_copy_replace_example();
void numeric_example();
void setContainer_example();

#endif