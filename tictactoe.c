#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkForWin(char[]);
void displayBoard(char[]);
void markBoard(char , int, int, char[]);


int main()
{
    char key='Y';
   do {
       int choice,player;
       char square[10]={'0','1','2','3','4','5','6','7','8','9'};
       int gamestatus;
       char mark,PlayerName1[50],PlayerName2[50];

       player = 1;

       printf("Enter first player name=");
       gets(PlayerName1);
       printf("Enter second player name=");
       gets(PlayerName2);

       do {
           displayBoard(square);

           // change turns

            player = (player %2==1) ? 1:2;

            //get input

            printf("Player %d, Enter a number : ", player);
            scanf("%d",&choice);

            //set the correct character based on player turn
            mark = (player == 1)? 'x' : 'o';

            // set board based on user choice or invalid choice
            markBoard(mark, choice, player, square);

            gamestatus = checkForWin(square);

            player++;
        }while (gamestatus == -1);

        if(gamestatus == 1)
            printf("==>\aPlayer %s win\n",(--player==1)?PlayerName1:PlayerName2);
        else
            printf("==>\aGame draw\n");


        getchar();
        printf("Do you want to play again?\nIf yes Press Y\n");
        scanf("%c",&key);
        getchar();

   }while(key=='Y'|| key=='y');

    return 0;
}

/***************
THIS FUNCTION IS FOR RETURNING THE GAME STATUS
1 FOR GAME IS OVER WITH A RESULT
-1 FOR GAME IS IN PROGRESS
0 GAME IS OVER AND NO RESULT
***************/


int checkForWin(char square[])
{
    int returnValue = 0;
  if(square[1] == square[2] && square[2] == square[3])
  {
      returnValue =1;
  }
  else if(square[4] == square[5] && square[5] == square[6])
      returnValue = 1;

  else if(square[7] == square[8] && square[8] == square[9])
      returnValue = 1;

  else if(square[1] == square[4] && square[4] == square[7])
      returnValue = 1;

  else if(square[2] == square[5] && square[5] == square[8])
      returnValue = 1;

  else if(square[3] == square[6] && square[6] == square[9])
      returnValue = 1;

  else if(square[1] == square[5] && square[5] == square[9])
      returnValue = 1;

  else if(square[3] == square[5] && square[5] == square[7])
      returnValue = 1;

  else if (square[1] !='1' && square[2] !='2' && square[3] !='3' && square[4] !='4' &&
           square[5] !='5' && square[6] !='6' && square[7] !='7' && square[8] !='8' && square[9] !='9' )

           returnValue = 0;
  else
      returnValue = -1;


      return returnValue;

}


/***************
THIS FUNCTION IS FOR THE DISPLAY BOARD
***************/

void displayBoard(char square[])
{


    system("cls");

    printf("\n\n\n TIC TAC TOE \n\n\n");

    printf("PLAYER 1(X) - PLAYER 2(O)\n\n\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c\n",square[1],square[2],square[3]);

    printf("___|___|____\n");
    printf("   |   |    \n");

    printf(" %c | %c | %c \n",square[4],square[5],square[6]);

    printf("___|___|____\n");
    printf("   |   |    \n");

    printf(" %c | %c | %c \n",square[7],square[8],square[9]);

    printf("   |   |    \n\n");
}

/***************
Set the board with the correct character, x or o in the spot in the array
***************/

void markBoard(char mark, int choice, int player, char square[])
{
    if(choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice ==3 && square[3]== '3')
        square[3] = mark;

    else if (choice ==4 && square[4] =='4')
        square[4]= mark;

    else if (choice == 5 && square[5] == '5')
        square[5]=mark;

    else if (choice == 6 && square[6]=='6')
        square[6]=mark;

    else if (choice == 7 && square[7]=='7')
        square[7]=mark;

    else if (choice == 8 && square[8]=='8')
        square[8]=mark;

    else if (choice == 9 && square[9]=='9')
        square[9]=mark;

    else
    {
        printf("Invalid move");

        player--;
        //getch();
    }

}
