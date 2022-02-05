// UVa 11935 - Through the Desert
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#define EPS 1e-9
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
    double fuel = 0.0, iniCapacity = capacity;
    int nLeaks = 0;

    for(int i = 0; i < events.size()-1; i++){
        capacity -= (dists[i+1]-dists[i]) * (fuelConsume[i]+fuel);
        fuel += fuelConsume[i];
        if(events[i] == LEAK) nLeaks++;
        else if(events[i] == GAS) capacity = iniCapacity;
        else if(events[i] == MECHANIC) fuel -= nLeaks;
        if(capacity <= 0) return false;
    }

    return true;
}

void binarySearch(void){
    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;

    while(fabs(hi-lo) > EPS){
        mid = (lo + hi) / 2;
        if(simulate(mid)){
            printf("%lf %lf %lf\n", lo, mid, hi);
            ans = mid;
            hi = mid;
        }
        else lo = mid;
    }
}

int main(void){
    string line;
    while(true){
        getline(cin, line);
        vector<string> command = split(line, ' ');

        dists.push_back(stoi(command[0])); 
        if(command[1] == "Fuel"){
            events.push_back(FUEL); fuelConsume.push_back(stoi(command[3])/100);
        }
        else if(command[1] == "Leak"){
            events.push_back(LEAK); fuelConsume.push_back(0.01);
        }
        else if(command[1] == "Gas"){
            events.push_back(GAS); fuelConsume.push_back(0.0);
        }
        else if(command[2] == "Mechanic"){
            events.push_back(MECHANIC); fuelConsume.push_back(0.0);
        }
        else{
            events.push_back(GOAL);
        }
    }
    binarySearch();

    return 0;
}