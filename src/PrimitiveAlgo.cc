//
// Created by roei_ on 05/12/2018.
//

#include "PrimitiveAlgo.h"
#include <vector>
#include "GeneralClasses.h"
using  namespace std;

class SearchResult {
    int n; //serie parameter
    vector<ComplexityRes> ComplexitiesVector;
};

class ComplexityRes{
    int Complexity;
    float OverallCounter;
    float DebroienCounter;
    float ToviCounter;
    vector<bool*> DebroienSequenceVector;
    vector<bool*> TuviSequenceVector;
};



void UpgradeSequencesComplexity(vector<Series> seires){

};

SearchResult ClacPrimitive(int n){


}