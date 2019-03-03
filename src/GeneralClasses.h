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
    int length;
    int power2;
    unsigned int complexity;
    Series(int length):series(vector<bool>(length, true)), length(length), power2(log2(length)), complexity(1){};
    Series(int length, vector<bool> series):series(series),length(length), power2(log2(length)){
        complexity=GetComplexity();
    };
    Series(int length, vector<bool> series, unsigned int complex):series(series),length(length), power2(log2(length)), complexity(complex){};
    bool CheckNSubSeiresUniquness(int n) const;
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
void shift_vector(vector<bool> &shifted_vec);

#endif //DEBROINPROJECT_GENERALCLASSES_H
