#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIRDS 5


void gotoligcol(int lig, int col) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void displayMap(char map[10][20]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void moveRandomly(int *row, int *col) {
    int randomMove = rand() % 4; // 0: up, 1: left, 2: down, 3: right

    switch (randomMove) {
        case 0:
            (*row)--;
            break;
        case 1:
            (*col)--;
            break;
        case 2:
            (*row)++;
            break;
        case 3:
            (*col)++;
            break;
    }
}
char snoopyMap[10][20] = {
        {' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|'}
    };

int game();
int main(){
    hideCursor();
    system("cls");
    displayMap(snoopyMap);
    gotoligcol(4,9);
    printf("Welcome to Snoopy's");
    gotoligcol(5,10);
    printf("Bird Hunt Game!");
    gotoligcol(6,7);
    printf("Press any key to start...\n");
    _getch();  // Wait for a key press to start the game
    system("cls");
    game();
    return 0;
}
int game() {
    srand(time(NULL));

    int snoopyRow = 4;
    int snoopyCol = 0;

    int ballRow = 5;
    int ballCol = 10;
    int ballVelocityRow = 1; // Initial velocity in the vertical direction
    int ballVelocityCol = 1; // Initial velocity in the horizontal direction

    int timeLimit = 30; // Time limit in seconds
    clock_t startTime = clock();

    int numBird = 0;
    char Bird[MAX_BIRDS]={'B','B','B','B','B'};
    int birdCaught[MAX_BIRDS] = {0};
    int birdRow[MAX_BIRDS]={5,8,3,2,4};
    int birdCol[MAX_BIRDS]= {3,7,10,9,15};
    
    displayMap(snoopyMap);
    hideCursor();
    char move; 

    while (1) {
        
        // Check the time
        clock_t currentTime = clock();
        double elapsedSeconds = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
        int remainingTime = timeLimit - elapsedSeconds;

        //movement of snoopy
        gotoligcol(snoopyRow + 1, snoopyCol * 2 +1);
        printf("S");

        if (_kbhit()) {
            move = getch();

            switch (move) {
                case 'w':
                    snoopyRow--;
                    break;
                case 'a':
                    snoopyCol--;
                    break;
                case 's':
                    snoopyRow++;
                    break;
                case 'd':
                    snoopyCol++;
                    break;
                case 'c':
                    system("cls");
                    displayMap(snoopyMap);
                    printf("Game stopped by the user.\n");
                    return 0;
                default:
                    printf("Invalid move! Use 'w', 'a', 's', or 'd'. Press 'c' to stop.\n");
                    continue;
            }
        }

        snoopyRow = (snoopyRow < 0) ? 0 : ((snoopyRow > 8) ? 8 : snoopyRow);
        snoopyCol = (snoopyCol < 0) ? 0 : ((snoopyCol > 18) ? 18 : snoopyCol);

        // Update ball position with bouncing effect
        ballRow += ballVelocityRow;
        ballCol += ballVelocityCol;

        // Check for collision with walls and reverse the velocity if needed
        if (ballRow <= 0 || ballRow >= 8) {
            ballVelocityRow = -ballVelocityRow;
        }

        if (ballCol <= 0 || ballCol >= 18) {
            ballVelocityCol = -ballVelocityCol;
        }

        system("cls");
        displayMap(snoopyMap);

        gotoligcol(ballRow + 1, ballCol * 2 + 1);
        printf("O");

        //Printing the Birds
        for (int i = 0; i < MAX_BIRDS; ++i) {
            gotoligcol(birdRow[i]+1,birdCol[i]*2+1);
            printf("%c",Bird[i]);
        }

        // Print remaining time under the table
        gotoligcol(11, 0);
        printf("Remaining Time: %d seconds", remainingTime);

        // Print Level
        gotoligcol(12, 0);
        printf("LEVEL 1");

        // Print victory message if the ball and Snoopy collide
        if (snoopyRow == ballRow && snoopyCol == ballCol) {
            system("cls");
            displayMap(snoopyMap);
            printf("To Slow! You lose");
            break;
        }

        // Check if time is up
        if (remainingTime <= 0) {
            system("cls");
            displayMap(snoopyMap);
            printf("Time's up! You lose.\n");
            break;
        }

        for (int i = 0; i < MAX_BIRDS; i++) {
            if (!birdCaught[i] && snoopyRow == birdRow[i] && snoopyCol == birdCol[i]) {
                Bird[i] = ' ';
                birdCaught[i] = 1;  // Set the flag for this bird to true
                numBird++;          // Increment numBird by 1
            }
        }
        
        if(numBird==MAX_BIRDS){
            system("cls");
            displayMap(snoopyMap);
            printf("Congratulations! \nYou Win!\n");
            break;
        }
        gotoligcol(13, 0);
        printf("Bird Eaten : %d",numBird);

    }
    return 0;
}