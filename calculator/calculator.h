#pragma once

#include <string>
#include <vector>

using Number = double;

Number Action(Number number_1, Number number_2, std::string operation);

Number Round(Number number);

bool ReadNumber(Number& result);

std::string ReadOperator();

bool RunCalculatorCycle();

void Print(const std::vector<Number>& results);