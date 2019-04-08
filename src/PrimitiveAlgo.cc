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


    //Creating base series os 2^n 1's vector
    Series BaseSeries(Get2Power(n));

    //Creating Series Set (contains all the possible vectors of the same complexity)
    set<Series> SeriesSet;
    SeriesSet.insert(BaseSeries);
    int Complexity = 1;
    while (Complexity <= Get2Power(n)){
        cout <<"calcing complexcity " << Complexity << endl;
        //iterating through all series of this complexity
        set<Series>::iterator it = SeriesSet.begin();
        while (it!= SeriesSet.end()){
            result.ComplexitiesVector[Complexity].OverallCounter++;
            if((*it).CheckNSubSeiresUniquness(n+1)){
                result.ComplexitiesVector[Complexity].TuviCounter++;
                result.ComplexitiesVector[Complexity].TuviSequencesVector.push_back((*it).series);
                if((*it).CheckNSubSeiresUniquness(n)){
                    result.ComplexitiesVector[Complexity].DebroienCounter++;
                    result.ComplexitiesVector[Complexity].DebroienSequencesVector.push_back((*it).series);
                }
            }
            it++;
        }
        if(Complexity < Get2Power(n))
            SeriesSet = UpgradeSequencesComplexity(SeriesSet);
        Complexity++;
    }
    return result;
}

ostream& operator<<(ostream& os, vector<bool>& var){
    for (unsigned int i = 0; i < var.size() ; ++i) {
        os << var[i];
    }
    return os;
}

ostream& operator<<(ostream& os, SearchResult& result){
    os << "Search Result fon n parameter = " << result.n<<std::endl;
    for (unsigned int i = 0; i < result.ComplexitiesVector.size(); ++i) {
        os << "Complexity = " << i << "; Number of Series: " << result.ComplexitiesVector[i].OverallCounter <<
           ";   Number of De-Broien Series:" << result.ComplexitiesVector[i].DebroienCounter << ";   Number of semi De-Broien Series:" <<
           result.ComplexitiesVector[i].TuviCounter << std::endl << std::endl;
//        cout<< " Debroin series: " << endl;
//        for (unsigned int j = 0; j < result.ComplexitiesVector[i].DebroienSequencesVector.size() ; ++j) {
//            cout<< result.ComplexitiesVector[i].DebroienSequencesVector[j] << endl;
//        }
//
//        cout<< " Tuvi series: " << endl;
//        for (unsigned int j = 0; j < result.ComplexitiesVector[i].TuviSequencesVector.size() ; ++j) {
//            cout<< result.ComplexitiesVector[i].TuviSequencesVector[j] << endl;
//        }
    }

    os<< endl << endl;
    return os;
}
