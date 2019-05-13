/**
 *
 * CCI Ch7.10
 *
 * Make minesweeper.
 *
 */


#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
using namespace std;

/**
 * Planning
 *
 * 2d array for the board of size NxN.
 * Tile class for each of the different types.
 * Map the integers to different ASCII characters for the display.
 * 4 types of tiles: -1 bomb, 0 open, 1-3 bomb adjacent,  
 * Two pass board creator. 
 * First place bombs.
 * Second place numbered tiles around the bombs.
 * OR
 * Place a bomb then increment the bomb number on all adjacent tiles.
 * default_random_engine generator;
 * uniform_int_distribution<int> distribution(1,6);
 * int dice_roll = distribution(generator);  // generates number in the range 1..6
 * Recursively check if a node is next to a bomb. If not then mark as no hidden and call again on all adjacent nodes.
 */

class MineSweeper {
    private:
        struct tile {
            int bombs = 0;
            bool flagged = false; 
            bool hidden = true;
            bool isBomb = false;
        };

        vector<vector<tile>> board;
        int turnCount = 0;
        int boardSize = 0;
        int bombs = 0;
        int numHidden = 0;
        int boardSizeDigits = 1;
        bool gameover = false;

    public:
        MineSweeper(int n, int b) {
            printf("Creating board\n");
            boardSize = n;
            bombs = b;
            boardSizeDigits = to_string(boardSize).length();
            createBoard(n, b);
        }
        ~MineSweeper() {}

        void display() {
            // Display the board
            // Some of these symbols may display differently on different machines
            setlocale( LC_ALL, "en_US.UTF-8" );
            cout << string(boardSizeDigits+1, ' ');
            for(int x = 0; x < board.size(); x++) {
                printf("%d ", x);
            }
            printf("\n");
            cout << string(boardSizeDigits, ' ');
            printf("%lc", 9484);
            for(int x = 0; x < board.size(); x++) {
                printf("%lc%lc", 9472, 9472);
            }
            printf("\n");
            for(int y = 0; y < board.size(); y++) {
                int currDigits = to_string(y).length();
                string spaces = string((boardSizeDigits - currDigits), ' ');
                printf("%d", y);
                cout << spaces;
                printf("%lc", 9474);
                for(int x = 0; x < board[y].size(); x++) { 
                    if(gameover) {
                        board[y][x].hidden = false;
                        if(board[y][x].isBomb) {
                            board[y][x].flagged = true;
                        }
                    }
                    if(board[y][x].flagged) {
                        printf("%lc ", 9872);
                    } else if(board[y][x].hidden) {
                        printf("%lc ", 9632);          
                    } else if(board[y][x].bombs == 0) {
                        printf("%lc ", 9633);
                    } else {
                        printf("%d ", board[y][x].bombs);
                    }
                }
                printf("\n");
            }
        }

        void createBoard(int n, int bombs) {
            // Factory Method to create a new gameboard  
            
            // O(n^2) Linear for both the fill constructor and resize fill
            board = vector<vector<tile>>(n, vector<tile>(n, tile()));             
 
            // Random number/bomb placement generation
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            uniform_int_distribution<int> distribution(0,n*n);

            printf("Generating bombs\n");

            for(int i = 0; i < bombs; i++) {
                int bPlace = distribution(generator);  // generates number in the range 0..n*n
                int y = (int)bPlace/n;
                int x = bPlace%n;
                // If the bomb loc is a duplicate then ignore it
                // Fix this later if possible
                if(!board[y][x].isBomb){ 
                    board[y][x].isBomb = true;
                    board[y][x].bombs = 0;
                    
                    // Out of bounds checks
                    if(y-1 > -1){
                        if(x-1 > 0) {
                            // Top Left
                            board[y-1][x-1].bombs += 1;
                        }
                        // Top
                        board[y-1][x].bombs += 1;
                        if(x+1 < board.size()) {
                            // Top Right
                            board[y-1][x+1].bombs += 1;
                        } 
                    }
                    if(x-1 > -1) {
                        // Left
                        board[y][x-1].bombs += 1;
                    } 
                    if(x+1 < board[y].size()) {
                        // Right
                        board[y][x+1].bombs += 1;
                    } 
                    if(y+1 < board.size()) {
                        if(x-1 > -1) {
                            // Bottom Left
                            board[y+1][x-1].bombs += 1;
                        }
                        // Bottom 
                        board[y+1][x].bombs += 1; 
                        if(x+1 < board[x].size()) {
                            // Bottom Right
                            board[y+1][x+1].bombs += 1;
                        }     
                    }
                }
            }
        }

        void doClick(int x, int y) {
            // Out of bounds checks
            
            if(!board[y][x].hidden || board[y][x].flagged) {
                return;
            }
            if(board[y][x].isBomb) {
                printf("GAME OVER!\n");
                gameover = true;
                return;
            }

            board[y][x].hidden = false;
            numHidden -= 1;
            if(board[y][x].bombs > 0){
                return;
            }

            if(y-1 > -1){
                if(x-1 > -1) {
                    // Top Left
                    doClick(x-1, y-1);
                }
                // Top
                    doClick(x, y-1);
                if(x+1 < board.size()) {
                    // Top Right
                    doClick(x+1, y-1);
                } 
            }
            if(x-1 > -1) {
                // Left
                doClick(x-1, y);
            } 
            if(x+1 < board[y].size()) {
                // Right
                doClick(x+1, y);
            } 
            if(y+1 < board.size()) {
                if(x-1 > -1) {
                    // Bottom Left
                    doClick(x-1,  y+1);
                }
                // Bottom 
                doClick(x, y+1); 
                if(x+1 < board[x].size()) {
                    // Bottom Right
                    doClick(x+1, y+1);
                }     
            } 
        }

        bool checkWin() {
            // If the number of hidden tiles matches the number of bombs
            // then the game is over as any click will have to be on a bomb space.
            if(numHidden == bombs) {
                return true;
            }
            return false;
        }

        bool turn() {
            system("clear"); 
            display();
            if(gameover) {
                system("clear"); 
                display();
                printf("GAME OVER!\n");
                return gameover; 
            }
            
            if(checkWin()) {
                printf("YOU WIN!\n");
                return checkWin();
            }

            printf("Turn: %d | Board size: %d | Bombs: %d\n", turnCount, boardSize, bombs); 
            turnCount++;       
            printf("Flag, Click, or Quit? Please enter 0, 1, or 2: \n");
            int choice;
            int x;
            int y;
            scanf("%d", &choice);
            if(choice == 2){
                gameover = true;
                printf("Exiting game!");
                return checkWin();
            }
            printf("X coord: \n");
            scanf("%d", &x);
            printf("Y coord: \n");
            scanf("%d", &y);

            if(x < 0 || x > boardSize || y < 0 || y > boardSize) {
                printf("Coordinates are out of bounds! Try again!\n");
                return false;
            }

            if(choice == 0) {
                board[y][x].flagged = true; 
            } else if(choice == 1) {
                doClick(x,y);  
            } else {
                printf("Invalid Choice! Try again!\n");
            }
            return false;
        }
};


int main() {

    int n = 0;
    int b = 0;
    printf("Enter the board size:\n");
    scanf("%d", &n);
    printf("Enter the number of bombs: \n");
    scanf("%d", &b);
    while(b >= n*n) {
        printf("Too many bombs. Try again: \n");
        scanf("%d", &b);
    }
    MineSweeper game(n, b);
    bool gameover = game.turn();
    while(!gameover) {
        gameover = game.turn();
    }
    return 1;
}
