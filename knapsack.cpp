#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> argumentVector(int argc, char *argv[]){
std::vector<std::string> v(argc);
    for (unsigned int i=0; i<argc; i++){
        v.at(i) = argv[i]; 
    }
    return v;
}

int knapSackResult(int Index , std::vector <int> weightV, std::vector <int> valueV, int capacity,
                    std::vector <bool>& include){

    int taken=0;
    int notTaken=0;
    std::vector <bool> include_temp;

        if(capacity <= 0 || Index >=include.size()){   
            return 0;
        }
        else if(weightV.at(Index)>capacity){  
            return knapSackResult(Index+1, weightV,valueV, capacity, include);      
        }
        else{
            include_temp=include;
            include_temp.at(Index) = true;

            taken = knapSackResult(Index+1, weightV,valueV, capacity-weightV.at(Index),include_temp)+ valueV.at(Index);
            notTaken = knapSackResult(Index+1, weightV,valueV, capacity,include);

                if(taken>notTaken){
                    include=include_temp;
                    return taken;  
                }
                else{      
                    return notTaken;
                }
        }  
}

void printBool (std::vector <bool> include, std::vector <int> weightV, std::vector <int> valueV){
    int vectorSize= weightV.size();

    for(unsigned int i = 0; i < vectorSize ; i++){
        if(include.at(i) == true){
            std::cout << "[" <<weightV.at(i) << "," << valueV.at(i) << "] " ;
        }
    }
}

int totalWeightKnapsack (std::vector <bool> include, std::vector <int> weightV){
    int vectorSize,totalweightitems;
    vectorSize= weightV.size();
    totalweightitems = 0;
    
    for(unsigned int i = 0; i < vectorSize ; i++){
        if(include.at(i) == true)
            totalweightitems += weightV.at(i);
        }

    return totalweightitems;
}

void PrintResult(int Index , std::vector <int> weightV, std::vector <int> valueV, int capacity,
                    std::vector <bool>& include){

    std::cout << "With a capacity of " << capacity << " kg, the total value is " 
    <<knapSackResult(Index,  weightV,  valueV, capacity, include) 
    << " Eur, leading to a total weight of " << totalWeightKnapsack(include,weightV)
    << " kg" << std::endl; std::cout << "The following items are included: ";
    printBool(include,weightV,valueV);
}

int main(int argc, char *argv[]) {
    std::ifstream inFS;
    std::vector <int> weightV, valueV;
    int totalData, capacity, weightProd, valueProd, totalItems, Index;
    std::vector<std::string> args = argumentVector(argc, argv);
    Index = 0;

    inFS.open(argv[1]);
    if (argv[1] == 0){
      std::cout << "No input filename given " << std::endl;
      return 1;
    }
    if (!inFS.is_open()) {
        std::cout << "Could not open file " << args.at(1) << std::endl; 
        return 1;
    }
    while (!inFS.fail()) { 
        inFS >> valueProd; 
        weightV.push_back(weightProd);
        inFS >> weightProd;
        valueV.push_back(valueProd);
    }

    capacity = valueV.at(0);
    
    for (unsigned int i = 0 ; i < weightV.size(); i++ ){
        if(i ==0){
            weightV.erase(weightV.begin() + i) ;
            valueV.erase(valueV.begin() + i) ;
        }
    }
    inFS.close();

    std::vector <bool> include(valueV.size(),false);

    PrintResult(Index ,weightV, valueV,capacity,include);

    return 0;
}
