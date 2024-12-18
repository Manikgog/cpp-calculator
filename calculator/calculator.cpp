#include <iostream>
#include <string>
#include <cmath>
#include <vector>

void RunCalculatorCycle() {
    std::string str_input;
    std::vector<std::string> strings;
    int j = 0;
    bool is_saved = false;
    while (std::cin >> str_input) {

        if (str_input == "q") {
            break;
        }

        if (str_input == "=" || str_input == "s" || str_input == "l") {
            if (str_input == "s") {
                is_saved = true;
            }
            strings.push_back(str_input);
            if (str_input == "l" && !is_saved) {
                break;
            }
            continue;
        }
        else if (str_input == "c") {
            strings.push_back(str_input);
            continue;
        }
        if (j % 2 == 0) {
            std::string s = str_input;
            try {
                std::stod(s);
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return;
            }
            strings.push_back(str_input);
            j++;
            continue;
        }
        else {
            if (str_input != "+" && str_input != "-" && str_input != "*" && str_input != "**" &&
                str_input != "/" && str_input != ":" && str_input != "s" && str_input != "l") {
                std::cerr << "Error: Unknown token " << str_input << std::endl;
                return;
            }
            else {
                strings.push_back(str_input);
                j++;
            }
            continue;
        }

    }

    std::vector<double> results;
    double memory_cell = 0;
    bool is_memory_cell_empty = true;
    double result = std::stod(strings[0]);
    for (int i = 1; i < strings.size(); i++) {
        std::string s = strings[i];
        if (s == "=") {
            results.push_back(result);
            continue;
        }
        else if (s == "s") {
            memory_cell = results.at(results.size() - 1);
            is_memory_cell_empty = false;
            continue;
        }
        else if (s == "l") {
            if (is_memory_cell_empty) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return;
            }
            result = memory_cell;
            continue;
        }
        if (s == "+" || s == "-" || s == "*" || s == "/" || s == "**" || s == ":" || s == "c") {
            continue;
        }
        double number = std::stod(strings[i]);
        std::string operation = strings[i - 1];
        if (operation == "+") {
            result += number;
        }
        else if (operation == "-") {
            result -= number;
        }
        else if (operation == "*") {
            result *= number;
        }
        else if (operation == "/") {
            result /= number;
        }
        else if (operation == "**") {
            result = std::pow(result, number);
        }
        else if (operation == ":") {
            result = number;
        }
        else if (operation == "c") {
            result = 0;
        }
    }

    for (double item : results) {
        int n = (int)item;
        double d = (item - n) * 10;
        if (d < 0) {
            d *= -1;
            if (d - (int)d > 0.5) {
                d = std::round(d) / 10;
            }
            else {
                d /= 10;
            }
            d *= -1;
        }
        else {
            if (d - (int)d > 0.5) {
                d = std::round(d) / 10;
            }
            else {
                d /= 10;
            }
        }
        double res = (double)n + d;
        std::cout << res << std::endl;
    }

}

