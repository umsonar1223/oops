#include <iostream>
#include <map>
#include<string>
using namespace std;
int main()
{
    typedef map<string,int>mapType;
    mapType populationMap;
    populationMap.insert(pair<string,int>("Maharashtra",1237875787));
    populationMap.insert(pair<string,int>("MadhyaPradesh",9873653425));
    populationMap.insert(pair<string,int>("Rajasthan",748390022));
    populationMap.insert(pair<string,int>("Gujarat",34562877));
    populationMap.insert(pair<string,int>("Haryana",87309871));
    mapType::iterator iter;
    cout<<"====Population o states o India====\n";
    cout<<"\nSize of populationmap"<<populationMap.size()<<"\n";
    string state_name;
    cout<<"\nEnter name of the state:";
    cin>>state_name;
    iter=populationMap.find(state_name);
    if(iter!=populationMap.end())
        cout<<state_name<<"'s population is "
        <<iter->second;
    else
        cout<<"Key is not polpulationMap"<<"\n";
        populationMap.clear();
        return 0;
}
