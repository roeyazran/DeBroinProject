//
// Created by roei_ on 05/12/2018.
//
#include "GeneralClasses.h"

bool Series::CheckNSubSeiresUniqeness(int n){
    //vector<vector<bool> > PossibleSeiries (n, vector<bool>(pow(n)));
    vector<bool> PossibleSeiries(Get2Power(n),false);
    for (int i=0; i<length;++i){
        int DecRepresentation = ParseBoolArrToInt(series,n,i);

        if(PossibleSeiries[DecRepresentation]){
            return false;
        }
        PossibleSeiries[DecRepresentation] = true;
    }
    return true;

}
//set<Series>
set<Series> Series::CalcUpperComplexity() const{
    vector<bool> series_0(this->length, false);
    vector<bool> series_1(this->length, true);
    for(int i=1; i < this->length; i++){
        series_0[i] = this->series[i-1] ^ series_0[i-1];
        series_1[i] = this->series[i-1] ^ series_1[i-1];
    }
    Series Series_obj_0(this->length, this->power2, series_0);
    Series Series_obj_1(this->length, this->power2, series_1);


//    set<Series> UpperComplexity;
//    UpperComplexity.insert(Series_obj_0);
//    UpperComplexity.insert(Series_obj_1);
//    set<Series>::iterator it = UpperComplexity.begin();
//    while(it != UpperComplexity.end()){
//        cout << *it;
//        it++;
//    }
    set<Series> UpperComplexity;
    UpperComplexity.insert(Series_obj_0);
    UpperComplexity.insert(Series_obj_1);
    set<Series>::iterator it = UpperComplexity.begin();
//    while(it != UpperComplexity.end()){
//        cout << *it;
//        it++;
//    }
    return UpperComplexity;
}

int Series::GetComplexity() const{
    vector<bool> series_vec = this->series;
    vector<bool> all_1_vec = vector<bool>(this->length, true);
    int complexiy = 1;
    while(series_vec != all_1_vec){
        vector<bool> shifted_vec = series_vec;
        vector<bool>::iterator it = shifted_vec.begin();
        bool shifted_val = *it;
        shifted_vec.erase(it);
        shifted_vec.push_back(shifted_val);
        vector<bool>::iterator it1 = series_vec.begin();
        vector<bool>::iterator it2 = shifted_vec.begin();
        while(it1 != series_vec.end()){
            *it1 = (*it1) ^ (*it2);
            it1++;
            it2++;
        }
        complexiy++;
    }

    return complexiy;
}


int Get2Power(int n){
    return 1<<n;
}
//
int ParseBoolArrToInt(vector<bool> arr, unsigned int size, unsigned int offset){
    int res=0;
    for (unsigned int j=0, i = offset; j < size; ++j,++i) {
        if( i < arr.size()){
            res+=Get2Power(j)*arr[i];
        } else{
            res+=Get2Power(j)*arr[i-arr.size()];
        }
    }
    return res;
}
//
ostream& Series::PrintSeriesInfo(ostream& os) const{
    os<<"Printing Series info:"<<endl;
    PrintVector(os,series);
    os<<"Mark Flag: "<<marking_flag<<endl;
    os<<"length: "<< length<<endl;
    os<<"power of 2 length:"<<power2<<endl;
    return os;
}



void PrintVector(ostream& os , const vector<bool> vec){
    os<<"the vector is:"<<endl;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        os<<int(vec[i]);
    }
    os<<endl;
}




ostream& operator<<(ostream& os, const Series& series){
    return series.PrintSeriesInfo(os);
}


bool Series::operator==(Series const &series2_obj){
    return this->series == series2_obj.series;
}
bool Series::operator>(Series const &series2_obj) const{
    return this->series > series2_obj.series;
}
bool Series::operator<(Series const &series2_obj) const{
    return this->series < series2_obj.series;
}




