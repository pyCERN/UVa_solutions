// UVa 11935 - Through the Desert
// Binary search
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#define EPS 1e-7
using namespace std;

// fuel consume liter per 1km

enum {FUEL=0, LEAK, GAS, MECHANIC, GOAL};
vector<int> events, dists;
vector<double> fuelConsume;

vector<string> split(string str, char delimiter){
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while(getline(iss, buffer, delimiter))
        result.push_back(buffer);

    return result;
}

bool simulate(double capacity){ // if reachable with capacity
    /*
    consumption: fuel consumed by Fuel consumption
    leak: fuel consumed by Leak
    */
    double consumption = 0.0, leak = 0.0, iniCapacity = capacity;

    for(int i = 0; i < events.size()-1; i++){
        if(events[i] == FUEL) consumption = fuelConsume[i];
        else if(events[i] == LEAK) leak += fuelConsume[i];
        else if(events[i] == GAS) capacity = iniCapacity;
        else if(events[i] == MECHANIC) leak = 0.0;
        capacity -= (dists[i+1]-dists[i]) * (consumption+leak);
        if(capacity < 0) return false;
    }

    return true;
}

void binarySearch(void){
    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;

    while(fabs(hi-lo) > EPS){
        mid = (lo + hi) / 2;
        if(simulate(mid)){
            ans = mid;
            hi = mid;
        }
        else lo = mid;
    }
   printf("%.3lf\n", mid);
}

int main(void){
    string line;

    while(true){
        events.clear(); dists.clear(); fuelConsume.clear();
        getline(cin, line);
        vector<string> command = split(line, ' ');
        if(command[3] == "0") break;
        dists.push_back(0.0);
        events.push_back(FUEL); fuelConsume.push_back(stoi(command[3])/100.0);
        
        while(true){
            getline(cin, line);
            vector<string> command = split(line, ' ');

            dists.push_back(stoi(command[0]));
            if(command[1] == "Fuel"){
                events.push_back(FUEL); fuelConsume.push_back(stoi(command[3])/100.0);
            }
            else if(command[1] == "Leak"){
                events.push_back(LEAK); fuelConsume.push_back(1.0);
            }
            else if(command[1] == "Gas"){
                events.push_back(GAS); fuelConsume.push_back(0.0);
            }
            else if(command[1] == "Mechanic"){
                events.push_back(MECHANIC); fuelConsume.push_back(0.0);
            }
            else{
                events.push_back(GOAL);
                break;
            }
        }
        binarySearch();
    }

    return 0;
}