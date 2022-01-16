// UVa 118 - Mutant Flatworld Explorers
// Graph traversal
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// E, N, W, S
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
vector<pair<int, int> > scent;

int convertToDir(char orientation){
    switch(orientation){
    case 'E':
        return 0;
    case 'N':
        return 1;
    case 'W':
        return 2;
    case 'S':
        return 3;
    }
}

char convertToOrientation(int dir){
    switch(dir){
    case 0:
        return 'E';
    case 1:
        return 'N';
    case 2:
        return 'W';
    case 3:
        return 'S';
    }
}

void move(int recX, int recY, int x, int y, int dir, string command){
    bool isLost = false;
    int prevX, prevY;

    for(int i = 0; i < command.size(); i++){
        prevX = x; prevY = y;
        switch(command[i]){
        case 'L':
            dir = (dir+1) % 4;
            break;
        case 'R':
            dir = (dir+3) % 4;
            break;
        case 'F':
            x += dx[dir]; y += dy[dir];
            break;
        }

        if(x > recX || y > recY || x < 0 || y < 0){
            x = prevX;
            y = prevY;
            if(find(scent.begin(), scent.end(), make_pair(x, y)) == scent.end()){ // if failed first time at (x, y)
                scent.push_back(make_pair(x, y));
                isLost = true;
                break;
            }
        }
    }
    if(isLost) printf("%d %d %c LOST\n", prevX, prevY, convertToOrientation(dir));
    else printf("%d %d %c\n", x, y, convertToOrientation(dir));
}

int main(void){
    int recX, recY, x, y, dir;
    char orientation;
    string command;

    scanf("%d %d", &recX, &recY);
    while(scanf("%d %d %c", &x, &y, &orientation) == 3){
        cin >> command;
        dir = convertToDir(orientation);    
        move(recX, recY, x, y, dir, command);
    }
    return 0;
}