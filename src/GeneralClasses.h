//
// Created by roei_ on 05/12/2018.
//

#ifndef DEBROINPROJECT_GENERALCLASSES_H
#define DEBROINPROJECT_GENERALCLASSES_H


class Series{
public:
    vector<bool> seire;
    bool marking_flag;
    int length;
    int power2;
    Series(int length, int power2):seire(vector<bool>(length, false)),marking_flag(false), power2{power2}{};
    vector<Series> CalcUpperComplexity();
    bool CheckNSubSeiresUniqeness(int n=power2);
};
#endif //DEBROINPROJECT_GENERALCLASSES_H
