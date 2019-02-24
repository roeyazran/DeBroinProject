//
// Created by roei_ on 05/12/2018.
//saar huberman
#include <iostream>
#include <vector>
#include "GeneralClasses.h"
#include "PrimitiveAlgo.h"
using namespace std;


int main(int argc, char** argv){
    vector<bool> testVec(8, false);
    testVec[2]=1;
    testVec[1]=1;
    Series testSeries(4,2,testVec);
    cout<<testSeries;
    cout<< "Debroin test: " << testSeries.CheckNSubSeiresUniqeness(2);
    return 0;
}