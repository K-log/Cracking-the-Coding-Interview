/**
 *
 * 2d Array maze solvers.
 *
 * Noah
 *
 */

                 
#include <iostream>  // printf
#include <vector>    // vector
#include <stack>     // stack
#include <set>       // set
#include <utility>   // pair<>
#include <memory>    // shared_ptr
#include <algorithm> //
#include <math.h>    // sqrt
#include <unistd.h>  // usleep
#include <stdlib.h>  // system
#include <float.h>   // FLT_MAX
using namespace std;


//typedef vector<vector<int>> Grid;


/**
 * BFS Shortest Path
 *
 */

void display(shared_ptr<vector<vector<int>>> a) {
    for(auto y = a->begin(); y != a->end(); y++) {
        for(auto x = y->begin(); x != y->end(); x++) {
            cout << *x << ' ';
        }
        cout << endl;
    }
}


int recurSearch(int maxRows, int maxCols,   
        vector<vector<int>> a, 
        shared_ptr<vector<pair<int, int>>> visited, 
        pair<int, int> curCell,
        shared_ptr<vector<vector<int>>> displayPath){
    
    int y = curCell.first;
    int x = curCell.second;

    if(x < 0 || x > maxCols-1 || y < 0 || y > maxRows-1) {
        return maxRows*maxCols; 
    }

    if(a[y][x] == 0){
        return maxRows*maxCols;
    }

    if(visited->at(y+x*maxCols) == curCell) {
        return maxRows*maxCols;
    }

    visited->at(y+x*maxCols) = curCell;

    if(a[y][x] == 3) {
        displayPath->at(y).at(x) = 3;
        return 1;
    }
        
    displayPath->at(y).at(x) = 1;

    usleep(700000);
    system("clear");
    
    display(displayPath);

    int top = recurSearch(maxRows, maxCols, a, visited, pair<int, int>(curCell.first-1, curCell.second), displayPath);
    int bot = recurSearch(maxRows, maxCols, a, visited, pair<int, int>(curCell.first+1, curCell.second), displayPath);
    int left = recurSearch(maxRows, maxCols, a, visited, pair<int, int>(curCell.first, curCell.second-1), displayPath);
    int right = recurSearch(maxRows, maxCols, a, visited, pair<int, int>(curCell.first, curCell.second+1), displayPath);

    int minPath = min(top, min(bot, min(left, right))); 

    return 1+minPath;
}

int shortestPath(vector<vector<int>> a, pair<int, int> startCell) {
    int maxRows = a.size();
    int maxCols = a[0].size();
    
    shared_ptr<vector<pair<int, int>>> visited(new vector<pair<int, int>>(maxRows*maxCols, pair<int, int>(-1, -1)));
    shared_ptr<vector<vector<int>>> displayPath(new vector<vector<int>>(maxRows, vector<int>(maxCols, 0)));
    
    pair<int, int> dest(-1, -1);

    int minPath = recurSearch(maxRows, maxCols, a, visited, startCell, displayPath);

    //display(displayPath);

    return minPath;
}


/**
 * A* Algorithm
 *
 */

struct Cell {
    // Coords of the cell
    int y, x;

    // Coords of the parent cell on the path
    int parentX, parentY;

    double g; // Distance from start
    double h; // Euclidian distance from dest
    double f; // g + h
    
    Cell(int newY, int newX) : y(newY), x(newX) {}
};

bool inBounds(Cell maxBounds,  int y, int x) {
    // Check if a point falls within the maximum bounds of the 2d array.
    return ((0 < y && y < maxBounds.y) && (0 < x && x < maxBounds.x)); 
}

bool isDestination(Cell dest, int y, int x) {
    // Check if the curCell is dest
    if(dest.y == y && dest.x == x) {
        return true;
    }

    return false;
}

double calcHValue(Cell dest, int y, int x) {
    // Euclidean distance from curCell to dest
    return (double)sqrt(((dest.y - y)*2) + ((dest.x - x)*2));
}

bool isWall(shared_ptr<vector<vector<int>>> a, int y, int x) {
    // Check if the current Cell is a wall
    return (a->at(y)[x] == 0);
}

void displayAStar(shared_ptr<vector<vector<int>>> a) {
    system("clear");
    for(int row = 0; row < a->size()-1; row++) {
        for(int col = 0; col < a->at(row).size(); col++) {
            cout << a->at(row)[col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    usleep(1000000);
}


void tracePath(vector<vector<int>> a, shared_ptr<vector<vector<Cell>>> cellDetails, Cell dest) {
    int row = dest.y;
    int col = dest.x;

    stack<pair<int, int>> Path;

    printf("Printing Path!\n\n Original Maze: \n");
    displayAStar(make_shared<vector<vector<int>>>(a));
    shared_ptr<vector<vector<int>>> displayArr(new vector<vector<int>>(a.size(), vector<int>(a[0].size(), 0)));

    while(!(cellDetails->at(row)[col].parentY == row 
                && cellDetails->at(row)[col].parentX == col)) {
    
        Path.push(make_pair(row, col));
        int tempRow = cellDetails->at(row)[col].parentY;
        int tempCol = cellDetails->at(row)[col].parentX;
        
        row = tempRow;
        col = tempCol;
    }

    displayArr->at(row)[col] = 2;
    displayAStar(displayArr);

    pair<int, int> p = Path.top();
    Path.pop();
    while(!Path.empty()) {
        displayArr->at(p.first)[p.second] = 1;
        displayAStar(displayArr); 
        p = Path.top();
        Path.pop();
    }
    displayArr->at(p.first)[p.second] = 3;
    displayAStar(displayArr); 
}


void checkCell(
        vector<vector<int>> a,
        shared_ptr<set<pair<int, pair<int, int>>>> openList,
        shared_ptr<vector<vector<bool>>> closedList, 
        shared_ptr<vector<vector<Cell>>> cellDetails, 
        shared_ptr<vector<vector<int>>> displayArr,
        int row, int col, int rowMod, int colMod,
        Cell maxBounds, Cell dest){


    double gNew, hNew, fNew;

    if(inBounds(maxBounds, row+rowMod, col+colMod)) {
        if(isDestination(dest, row+rowMod, col+colMod)) {
            cellDetails->at(row+rowMod)[col+colMod].parentY = row;
            cellDetails->at(row+rowMod)[col+colMod].parentX = col;
            printf("Dest found!\n");
            tracePath(a, cellDetails, dest);
            return;
        }
        
        if(!closedList->at(row+rowMod)[col+colMod] && !isWall(make_shared<vector<vector<int>>>(a), row+rowMod, col+colMod)) {
            gNew = cellDetails->at(row+rowMod)[col+colMod].g + 1.0;
            hNew = calcHValue(dest, row-1, col);
            fNew = gNew + hNew;
            // Insert the current cell if it is either not already in the cellDetails
            // or if this cell has a lower f cost.
            if(cellDetails->at(row+rowMod)[col+colMod].f == FLT_MAX ||
                    cellDetails->at(row+rowMod)[col+colMod].f > fNew) {
                openList->insert(make_pair(fNew, make_pair(row+rowMod, col+colMod)));
                cellDetails->at(row+rowMod)[col+colMod].f = fNew;
                cellDetails->at(row+rowMod)[col+colMod].g = gNew;
                cellDetails->at(row+rowMod)[col+colMod].h = hNew;
                cellDetails->at(row+rowMod)[col+colMod].parentY = row;
                cellDetails->at(row+rowMod)[col+colMod].parentX = col;
                displayArr->at(row+rowMod)[col+colMod] = 1;
            }
        }
    }
}



void aStarSearch(vector<vector<int>> a, Cell start, Cell dest) {

    printf("Starting A* . . .\n");

    Cell maxBounds(a.size(), a[0].size());

    // Check if we have a valid start cell
    if(!inBounds(maxBounds, start.y, start.x)) {
        printf("Start out of bounds!\n");
        return;
    }

    // Check if we have a valid destination cell
    if(!inBounds(maxBounds, dest.y, dest.x)){
        printf("Dest not found\n");
        return;
    }

    // Make sure start and dest are different cells
    if(isDestination(dest, start.y, start.x)) {
        printf("Start is the Destination!\n");
        return;
    }

    shared_ptr<vector<vector<bool>>> closedList(new vector<vector<bool>>(maxBounds.y, vector<bool>(maxBounds.x,false)));
    



    // This hold the cell information
    shared_ptr<vector<vector<Cell>>> cellDetails(new vector<vector<Cell>>(maxBounds.y, vector<Cell>(maxBounds.x, Cell(-1,-1))));
    
    // Initialize these once since there will be a lot of lists
    int row, col;

    cout << "!!!!" << endl;
    // Initialze default values
    for(row=0; row<maxBounds.y; row++) {
        for(col=0; col<maxBounds.x;col++) {
            // Initialize heuristic values to the maximum float value
            cellDetails->at(row)[col].f = FLT_MAX;
            cellDetails->at(row)[col].g = FLT_MAX;
            cellDetails->at(row)[col].h = FLT_MAX;
            // Initialize the parent values to out of bounds
            cellDetails->at(row)[col].parentY = -1;
            cellDetails->at(row)[col].parentX = -1;
        } 
    }
    cout << "!!!!" << endl;

    shared_ptr<vector<vector<int>>> displayArr(new vector<vector<int>>(a.size(), vector<int>(a[0].size(), 0)));

    // Initialize start node

    row = start.y;
    col = start.x;
    cellDetails->at(row)[col].f = 0.0;
    cellDetails->at(row)[col].g = 0.0;
    cellDetails->at(row)[col].h = 0.0;
    cellDetails->at(row)[col].parentY = row;
    cellDetails->at(row)[col].parentX = col;

    // Open list contains the euclidian distance from Start to Dest and cell coordinates in the form
    // <f, <row, col>>
    shared_ptr<set<pair<int, pair<int, int>>>> openList;
    cout << "!!!!" << endl;

    // Initialize with the Start value
    openList->insert(make_pair(0.0, make_pair(row, col)));
    
    cout << "!!!!" << endl;
    while(!openList->empty()) {
        pair<int, pair<int, int>> p = *openList->begin(); 
        openList->erase(openList->begin()); 
        // Get the x, y coords of the first node
        row = p.second.first;
        col = p.second.second;

        closedList->at(row)[col] = true;

        displayAStar(displayArr); 
        
        printf("Checking cells\n");

        // top
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, -1, 0, maxBounds, dest); 

        // top left
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, -1, -1, maxBounds, dest); 

        // top right
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, -1, 1, maxBounds, dest); 

        // left
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, 0, -1, maxBounds, dest); 

        // right
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, 0, 1, maxBounds, dest); 

        // bottom
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, 1, 0, maxBounds, dest); 

        // bottom left
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, 1, -1, maxBounds, dest); 

        // bottom right
        checkCell(a, openList, closedList, cellDetails, displayArr, row, col, 1, 1, maxBounds, dest);
    }


    printf("No path to destination found\n");

    return;

}

void AStar(vector<vector<int>> a, Cell startCell){

    Cell dest = {6, 3};

    // Find the destination value's location
    for(int y = 0; y < a.size(); y++) {
        for(int x = 0; x < a[0].size(); x++) {
            if(a[y][x] == 3) {
                //cout << y << ' ';
                //cout << x << endl;
                //dest.x = x;
                //dest.y = y;
            }
        }
        cout << endl;
    }

    //printf("%d\n", a[dest.y][dest.x]);

    aStarSearch(a, startCell, dest); 

    return;
}



int main() {
    vector<vector<int>> maze1 = {
        {1, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 1},
        {0, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 3, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };

    cout << shortestPath(maze1, pair<int, int>(0, 0)) << endl;

    
    AStar(maze1, Cell(1, 1));

    return 1;
}
