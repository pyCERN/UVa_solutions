// UVa 222 - Budget Travel
#include <cstdio>

double distToDst;
double capacity, mpg, fillCost; // gallon capacity, mile per gallon, cost in dollars of filling
int nStations; // number of stations
double dist_price[2][55]; // (dist from orig to stn, price per gallon in cents)
double gallonToDst;

/*
475.6
11.9 27.4 14.98 6
102.0 99.9
220.0 132.9
256.3 147.9
275.0 102.9
277.6 112.9
381.8 100.9

채워야하는 gallon = 475.6/27.4 = 17.4
처음에 갈 수 있는 거리 = 11.9 * 27.4 = 326.1
station에서 멈추는 경우 : 다음 station or 목적지까지 갈 기름이 부족 -> 전체 용량의 반 아래로 남아있을 경우
*/

void backtrack(double remGallon, int station, double cost){ // stnIdx : nearest stn w.r.t current travelDist, travelDist < dist_price[0][stnIdx]

    double dist = remGallon * mpg;
    if(2*remGallon >= capacity){
        
    }
}

int main(void){
    scanf("%lf", &distToDst);
    scanf("%lf %lf %lf %d", &capacity, &mpg, &fillCost, &nStations);
    for(int i = 0; i < nStations; i++) scanf("%lf %lf", &dist_price[0][i], &dist_price[1][i]);

    gallonToDst = distToDst / mpg;

}