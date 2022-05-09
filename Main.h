#pragma once
#include <iostream>
#include <exception>
#include <Windows.h>
#include <random>
#include <string>

using namespace std;

#define LR 6
#define REPORT true

#define MIN_PUP_YEAR 1800
#define DEFAULT_STR "<blank>"
#define DEFAULT_NUMBER 0


#if LR == 6
#include "LR_6.h"
#endif

const auto RusCharset = 1251;
void ALL();
int main();