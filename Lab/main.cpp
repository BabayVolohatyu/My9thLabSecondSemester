#include <iostream>
#include <array>
#include <vector>

template<typename T, size_t S1, size_t S2>
std::array<T,S1+S2> mergeArrays(const std::array<T,S1> &array1, const std::array<T,S2> &array2){
    auto it1 = array1.begin();
    auto it2 = array2.begin();
    std::array<T, S1+S2> newArray{};
    for(int i = 0; i <S1+S2; i++){
        if(*it1<*it2){
            if(it1 == array1.end()){
                newArray[i] = *it2;
                continue;
            }
            newArray[i] = *it1;
            it1++;
        }else
        {
            if(it2 == array2.end()){
                newArray[i] = *it1;
                continue;
            }
            newArray[i] = *it2;
            it2++;
        }
    }
    return newArray;
}
template<typename T>
std::pair<std::vector<T>, std::vector<T>> splitVector(const std::vector<T> &vector){
    auto itEven = vector.begin();
    auto itOdd = vector.begin()+1;
    std::pair<std::vector<T>, std::vector<T>> newPair;
    for(;itEven<vector.end();itEven+=2){
        newPair.first.emplace_back(*itEven);
    }
    for(;itOdd<vector.end();itOdd+=2){
        newPair.second.emplace_back(*itOdd);
    }
    return newPair;
}
int main() {
    std::array<int, 5> intar1{0,2,7,9,15};
    std::array<int, 4> intar2{-1,0,1,10};
    std::array newIntArray = mergeArrays(intar1,intar2);
    std::array<bool, 1> boolar1{true};
    std::array<bool,3> boolar2{false,false, true};
    std::array newBoolArray = mergeArrays(boolar1,boolar2);
    std::vector<int> intvec{0,3,8,9,0,6,2};
    std::pair intPair = splitVector(intvec);
    std::vector<bool> boolvec{true, false, true};
    std::pair boolPair = splitVector(boolvec);
    return 0;
}
