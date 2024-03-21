#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cmath>

void toNoramlForm(std::string& sourceString);
std::string RPN(std::string str);
bool Full();
bool Empty();
void Push(double value);

double Pop();

double Peek();

void _free_stack();

bool IsOp(char c);

double _max(double a, double b);

double _min(double a, double b);

double _cube(double n);

bool _isNumber(char c);

void set_var(char index, double value);

double get_var(char index);

void _free_vars();

bool RpnCalc(std::string expression);


