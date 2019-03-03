//
// Created by roei_ on 05/12/2018.
//

#include "PrimitiveAlgo.h"
#include <vector>
#include "GeneralClasses.h"
#include <algorithm>
#include <set>

using  namespace std;




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
    SearchResult result(n);


    //Creating basic seires - complexity 0
    vector<bool> zeroVec(n, false);
    Series BaseSeries(Get2Power(n),n,zeroVec);

    //Creating Series Vector (contains all possible vectors of the same complexity)
    vector<Series> SeriesVector;
    SeriesVector.push_back(BaseSeries);
    int Complexity = 0;
    while (SeriesVector.size() != 0){

        //iterating through all series of this complexity
        vector<Series>::iterator it = SeriesVector.begin();
        while (it!= SeriesVector.end()){
            result.ComplexitiesVector[Complexity].OverallCounter++;
            if((*it).CheckNSubSeiresUniqeness(n+1)){
                result.ComplexitiesVector[Complexity].TuviCounter++;
                if((*it).CheckNSubSeiresUniqeness(n)){
                    result.ComplexitiesVector[Complexity].DebroienCounter++;                }
            }
            it++;
        }
        Complexity++;
        UpgradeSequencesComplexity(SeriesVector);
    }
    return result;
}