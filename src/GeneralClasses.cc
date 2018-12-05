//
// Created by roei_ on 05/12/2018.
//
#include "GeneralClasses.h"

bool Series::CheckNSubSeiresUniqeness(int n){
    //vector<vector<bool> > PossibleSeiries (n, vector<bool>(pow(n)));
    vector<bool> PossibleSeiries(Get2Power(n),false);
    for (int i=0; i<=length;++i){
        int DecRepresentation = ParseBoolArrToInt(series,n,i);

        if(PossibleSeiries[DecRepresentation]){
            return false;
        }
        PossibleSeiries[DecRepresentation] = true;
    }
    return false;

}

int Get2Power(int n){
    return 1<<n;
}

int ParseBoolArrToInt(vector<bool> arr, unsigned int size, unsigned int offset){
    int res=0;
    for (unsigned int i = offset; i < size; ++i) {
        if( i < arr.size()){
            res+=Get2Power(i)*arr[i];
        } else{
            res+=Get2Power(i-arr.size())*arr[i-arr.size()];
        }
    }
    return res;
}

ostream& Series::PrintSeriesInfo(ostream& os){
    os<<"Printing Series info:"<<endl;
    PrintVector(os,series);
    os<<"Mark Flag: "<<marking_flag<<endl;
    os<<"length: "<< length<<endl;
    os<<"power of 2 length:"<<power2<<endl;
    return os;
}



void PrintVector(ostream& os , vector<bool> vec){
    os<<"the vector is:"<<endl;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        os<<int(vec[i]);
    }
    os<<endl;
}

ostream& operator<<(ostream& os, Series& series){
    return series.PrintSeriesInfo(os);
}