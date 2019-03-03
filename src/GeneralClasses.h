//
// Created by roei_ on 05/12/2018.
//

#ifndef DEBROINPROJECT_GENERALCLASSES_H
#define DEBROINPROJECT_GENERALCLASSES_H
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Series{
public:
    vector<bool> series;
    bool marking_flag;
    int length;
    int power2;
    Series(int length, int power2):series(vector<bool>(length, true)),marking_flag(false),length(length), power2{power2}{};
    Series(int length, int power2, vector<bool> series):series(series),marking_flag(false),length(length), power2{power2}{};
    bool CheckNSubSeiresUniqeness(int n);
    set<Series> CalcUpperComplexity() const;
    ostream& PrintSeriesInfo(ostream& os) const;
    int GetComplexity() const;
    bool operator==(Series const &series2_obj);
    bool operator>(Series const &series2_obj) const;
    bool operator<(Series const &series2_obj) const;
};

int Get2Power(int n);
int ParseBoolArrToInt(vector<bool> arr, unsigned int size, unsigned int offset);
ostream& operator<<(ostream& os, const Series& series);

void PrintVector(ostream& os , vector<bool> vec);


#endif //DEBROINPROJECT_GENERALCLASSES_H
