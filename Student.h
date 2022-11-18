#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>  
#include <chrono>
class Student {
    std::string name;
    std::string lastname;
    std::vector<std::string> gradesinstring;
    std::vector<int> grades;
    int a;
    int exam;
    double average;
    double median;
public:
    Student();
    ~Student();
    void get(std::string str);
    void input();
    void inputrand();
    void countAverage();
    void countMedian();
    void print(int x);
    void printfile(int x);
};