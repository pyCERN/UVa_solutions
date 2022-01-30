// UVa 222 - Budget Travel
// Backtracking
#include <cstdio>
#include <cmath>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX 1e9

double distToDst;
double capacity, mpg, initialCost; // gallon capacity, mile per gallon, cost in dollars of filling
int nStations; // number of stations
double dist_price[2][55]; // (dist from orig to stn, price per gallon in cents)
double gallonToDst, minCost;

void backtrack(double remGallon, int station, double cost){ // currently at station, going to station+1, whether to stop or pass
    if(station == nStations+1){
        minCost = MIN(minCost, cost);
        return;
    }

    double dist = dist_price[0][station+1] - dist_price[0][station], fillCost;
    if(dist > remGallon*mpg){ // if not reachable
        fillCost = round((capacity - remGallon) * dist_price[1][station] + 200.0)/100; // refill at station
        backtrack(capacity, station, cost+fillCost);
    }
    else{
        remGallon -= dist/mpg;
        if(remGallon < capacity/2){ // if remaining gasoline is less than half of capacity
            fillCost = round((capacity - remGallon) * dist_price[1][station+1] + 200.0)/100; // refill at station+1
            backtrack(capacity, station+1, cost+fillCost); // stop and refill
        }
        backtrack(remGallon, station+1, cost); // pass
    }
}

int main(void){
    int TC = 1;

    while(scanf("%lf", &distToDst), distToDst != -1){
        scanf("%lf %lf %lf %d", &capacity, &mpg, &initialCost, &nStations);
        /*
        dist_price
        0 : origination city
        1..nStations : gasoline station
        nStations+1  : destination
        */
        dist_price[0][0] = 0; dist_price[1][0] = 0;
        dist_price[0][nStations+1] = distToDst;
        for(int i = 1; i <= nStations; i++) scanf("%lf %lf", &dist_price[0][i], &dist_price[1][i]);

        minCost = MAX;
        backtrack(capacity, 0, initialCost);
        printf("Data Set #%d\n", TC++);
        printf("minimum cost = $%.2lf\n", minCost);
    }

    return 0;
}