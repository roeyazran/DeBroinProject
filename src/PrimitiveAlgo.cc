//
// Created by roei_ on 05/12/2018.
//

#include "PrimitiveAlgo.h"
#include <vector>
#include "GeneralClasses.h"
#include <algorithm>
#include <set>

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



set<Series> UpgradeSequencesComplexity(set<Series> series) {
    set<Series> UpperComplexitySet;
    for (set<Series>::iterator it = series.begin(); it != series.end(); ++it) {
        set<Series> result_set = (*it).CalcUpperComplexity();
        for(set<Series>::iterator it_set = result_set.begin(); it_set != result_set.end(); ++it_set){
            UpperComplexitySet.insert(*it_set);
        }
    }
//    set<Series>::iterator it = UpperComplexitySet.begin();
//    while(it != UpperComplexitySet.end()){
//        cout << *it;
//        it++;
//    }
    return UpperComplexitySet;
}

SearchResult ClacPrimitive(int n){
    //Creating basic seires - complexity 0
    vector<bool> testVec(n, false);

    return SearchResult();
}