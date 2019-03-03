//
// Created by roei_ on 05/12/2018.
//saar huberman
#include <iostream>
#include <vector>
#include "GeneralClasses.h"
#include "PrimitiveAlgo.h"
using namespace std;
//set<Series>::iterator it = set_of_upper.begin();
//while(it != set_of_upper.end()){
//cout << *it;
//it++;
//}


int main(int argc, char** argv){
    Series se(4,2);
    bool saar = true ^ true;
//nunber 2
    set<Series> se_new = se.CalcUpperComplexity();
    set<Series>::iterator it1 = se_new.begin();
    int complex = (*it1).GetComplexity();
    cout << complex << endl;

//    number 3
    set<Series> set_of_upper = UpgradeSequencesComplexity(se_new);
//    number 4
    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
//    //    number 5
//    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
//    //    number 6
//    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
//    //    number 7
//    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
//    //    number 8
//    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
//    //    number 9
//    set_of_upper = UpgradeSequencesComplexity(set_of_upper);
    set<Series>::iterator it = set_of_upper.begin();
    while(it != set_of_upper.end()){
        cout << *it;
        it++;
    }

    return 0;
}