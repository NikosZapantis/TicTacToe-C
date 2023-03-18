#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    char playerX[15], playerO[15], signSel[2]={'X','O'};
    char sign, game[3][3];

    printf("\e[1mWELCOME to my tic tac toe game!\e[m\n\n");
    printf("\e[1mYou have to provide me your names so we can start(use space between them):\e[m ");
    scanf("%s%s", &playerX, &playerO);

    int stop = 1, who_plays = 0, winsX = 0, winsO = 0;
    while(stop == 1) {
        printf("\t\t\t\t\t\t\t\t\t\e[1mSCOREBOARD\e[m\n\t\t\t\t\t\t\t\t    %s\t%s\n\t\t\t\t\t\t\t\t      %d\t    -      %d\n", playerX, playerO, winsX, winsO);
       
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                game[i][j] = ' ';
            }
        }
        int pos1, pos2, row = 0, col = 0, cros1 = 0, cros2 = 0, flag = 0, result = 0;

        printf("\e[1mHere is an example of the positions!\e[m\n\n");
        printf("1 1\t|\t1 2\t|\t1 3\n");
        printf("--------|---------------|-----------\n"); 
        printf("2 1\t|\t2 2\t|\t2 3\n");
        printf("--------|---------------|-----------\n");
        printf("3 1\t|\t3 2\t|\t3 3\n\n");
        
        if(who_plays == 0) {

            printf("\e[1m%s is starting!\e[m\n\n", playerO);
            Sleep(1500);
            ++who_plays;
        }else {

            printf("\e[1m%s is starting!\e[m\n\n", playerX);
            Sleep(1500);
            --who_plays;
        }

        int i = 0;
        int countX1 = 0, countX2 = 0, countO1 = 0, countO2 = 0;
        while(i < 9 && flag == 0){ //MAIN loop

            if(i != 0) {
                printf("\n\t\t\t\t\t\t\t\t     \e[1mTemplate\e[m\n");
                printf("%c\t|\t%c\t|\t%c\t\t\t1 1\t|\t1 2\t|\t1 3\n",game[0][0],game[0][1],game[0][2]);
                printf("--------|---------------|--------\t\t\t--------|---------------|-----------\n");
                printf("%c\t|\t%c\t|\t%c\t\t\t2 1\t|\t2 2\t|\t2 3\n",game[1][0],game[1][1],game[1][2]);
                printf("--------|---------------|--------\t\t\t--------|---------------|-----------\n");
                printf("%c\t|\t%c\t|\t%c\t\t\t3 1\t|\t3 2\t|\t3 3\n",game[2][0],game[2][1],game[2][2]);
                putchar('\n');
            }        
            sign = signSel[i%2];

            int end = 0;
            while(end == 0) {

                printf("\e[1mPlayer with sign %c it's your turn!\e[m\nWhere do you want to place your sign?\nGive me the exact position: ", sign);
                scanf("%d%d", &pos1, &pos2);
                if(pos1 < 1 || pos1 > 3 || pos2 < 1 || pos2 > 3) {
                    printf("\n\e[1mThis place doesn't exist!\e[m\n\n");
                }else {
                    end = 1;
                    --pos1;
                    --pos2;
                }
            }

            int end1 = 0;
            while(end1 == 0) {

                if(game[pos1][pos2] == ' ') {

                    game[pos1][pos2] = sign;
                    end1 = 1;
                }else {

                    printf("\n\e[1mThis place is already taken!\e[m\n\n");
                    printf("\e[1mPlayer with sign %c it's your turn again\e[m!\nWhere do you want to place your sign?\nGive me the excact position: ", sign);
                    scanf("%d%d", &pos1, &pos2);
                    --pos1;
                    --pos2;
                    
                }
            }

            for(int j = 0; j < 3; ++j) {  //Row and col check for X tictactoe or O tictactoe
                if(game[j][0] == 'X') {
                    if(game[j][1] == 'X') {
                        if(game[j][2] == 'X') {
                            flag = 1;
                        }
                    }
                }
                if(game[0][j] == 'X') {
                    if(game[1][j] == 'X') {
                        if(game[2][j] == 'X') {
                            flag = 1;
                        }
                    }
                }
                if(game[j][0] == 'O') {
                    if(game[j][1] == 'O') {
                        if(game[j][2] == 'O') {
                            flag = 1;
                        }
                    }
                }
                if(game[0][j] == 'O') {
                    if(game[1][j] == 'O') {
                        if(game[2][j] == 'O') {
                            flag = 1;
                        }
                    }
                }
            }

            for(int i = 0; i < 3; ++i) {   //Cross tictactoe check for X or O
                for(int j = 0; j < 3; ++j) {
                    if(i == j) {
                        if(game[i][i] == 'X') {
                            ++countX1;
                        }
                        if(game[i][i] == 'O') {
                            ++countO1;
                        }
                    }
                    if(i + j == 2) {
                        if(game[i][j] == 'X') {
                            ++countX2;
                        }
                        if(game[i][j] == 'O') {
                            ++countO2;
                        }
                    }
                }
            }
            if(countX1 == 3 || countX2 == 3) {
                flag = 1;
            }else if(countO1 == 3 || countO2 == 3) {
                flag = 1;
            }else {
                countO1 = 0;
                countO2 = 0;
                countX1 = 0;
                countX2 = 0;
            }
            ++i;
        } 

        if(flag == 1) {

            if(sign == 'X' && who_plays == 0) {
                printf("%c\t|\t%c\t|\t%c\n",game[0][0],game[0][1],game[0][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[1][0],game[1][1],game[1][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[2][0],game[2][1],game[2][2]);
                putchar('\n');
                printf("\e[1mThe WINNER is:\e[m %s", playerX);
                ++winsX;
            }else if(sign == 'X' && who_plays == 1) {
                printf("%c\t|\t%c\t|\t%c\n",game[0][0],game[0][1],game[0][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[1][0],game[1][1],game[1][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[2][0],game[2][1],game[2][2]);
                putchar('\n');
                printf("\e[1mThe WINNER is:\e[m %s", playerO);
                ++winsO;
            }else if(sign == 'O' && who_plays == 0) {
                printf("%c\t|\t%c\t|\t%c\n",game[0][0],game[0][1],game[0][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[1][0],game[1][1],game[1][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[2][0],game[2][1],game[2][2]);
                putchar('\n');
                printf("\e[1mThe WINNER is:\e[m %s", playerO);
                ++winsO;
            }else if(sign == 'O' && who_plays == 1) {
                printf("%c\t|\t%c\t|\t%c\n",game[0][0],game[0][1],game[0][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[1][0],game[1][1],game[1][2]);
                printf("--------|---------------|--------\n");
                printf("%c\t|\t%c\t|\t%c\n",game[2][0],game[2][1],game[2][2]);
                putchar('\n');
                printf("\e[1mThe WINNER is:\e[m %s", playerX);
                ++winsX;
            }
        }else {
            printf("%c\t|\t%c\t|\t%c\n",game[0][0],game[0][1],game[0][2]);
            printf("--------|---------------|--------\n");
            printf("%c\t|\t%c\t|\t%c\n",game[1][0],game[1][1],game[1][2]);
            printf("--------|---------------|--------\n");
            printf("%c\t|\t%c\t|\t%c\n",game[2][0],game[2][1],game[2][2]);
            putchar('\n');
            printf("\n\e[1mTHERE IS A TIE!Nice try to both of you.\e[m");
        }

        printf("\n\n\e[1mWould you like to play again?\nTYPE '1' for yes or TYPE '0' for no: \e[m");
        scanf("%d", &stop);
        if(stop == 0) {
            printf("\n\e[1mThanks for playing!\e[m\n");
        }else {
            printf("\n\n");
            printf("//////////////////////////////////////////////////////////////////////////////////////////////");
            printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    return 0;
}