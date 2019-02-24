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
//    vector<bool*> DebroienSequenceVector;
//    vector<bool*> TuviSequenceVector;
};

class SearchResult {
public:
    int n; //series parameter
    vector<ComplexityRes> ComplexitiesVector;
    SearchResult(int n):n(n),ComplexitiesVector(vector<ComplexityRes>(n)){};
};

ostream& operator<<(ostream& os, SearchResult& result){
    os << "Search Result fon n parameter = " << result.n<<std::endl;
    for (int i = 0; i < result.ComplexitiesVector.size(); ++i) {
        os << "Complexity = " << i << "Number of Series: " << result.ComplexitiesVector[i].OverallCounter <<
           " Number of De-Broien Series:" << result.ComplexitiesVector[i].DebroienCounter << " Number of semi De-Broien Series:" <<
           result.ComplexitiesVector[i].TuviCounter << std::endl << std::endl;
    }
}

#endif //PROJECT_PRIMITIVEALGO_H
