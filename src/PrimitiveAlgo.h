//
// Created by roei_ on 05/12/2018.
//

#ifndef PROJECT_PRIMITIVEALGO_H
#define PROJECT_PRIMITIVEALGO_H


#include <vector>
#include "GeneralClasses.h"


class ComplexityRes{
public:
    int Complexity;
    float OverallCounter;
    float DebroienCounter;
    float TuviCounter;
    vector<vector<bool>> DebroienSequencesVector;
    vector<vector<bool>> TuviSequencesVector;
};

set<Series> UpgradeSequencesComplexity(set<Series> series);

class SearchResult {
public:
    int n; //series parameter
    vector<ComplexityRes> ComplexitiesVector;
    SearchResult(int n):n(n),ComplexitiesVector(vector<ComplexityRes>(Get2Power(n)+1)){
        ComplexitiesVector[0].DebroienCounter=0;
        ComplexitiesVector[0].TuviCounter=0;
        ComplexitiesVector[0].OverallCounter=1;
        for(int i =0; i< n+1 ;++i){
            ComplexitiesVector[i].Complexity=i;
        }
    };
};

ostream& operator<<(ostream& os, SearchResult& result);

ostream& operator<<(ostream& os, vector<bool>& var);

SearchResult ClacPrimitive(int n);

#endif //PROJECT_PRIMITIVEALGO_H
