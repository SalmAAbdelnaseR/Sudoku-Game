#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
extern easy_game_data[13][13];
extern easy_game_sol [13][13];
extern hard_game_data[13][13];
extern hard_game_sol[13][13];
int* secure_data_array[35] = {0};
int G_raw,G_col,G_answer;
int hint=3;
///***************************prototypes****************************************************************
void SetColor(int ForgC);
void clearScreen(void);
void intro_fun(void);
void array_print_2D (int arr[][13],int col,int raw) ;
int scan_data(int (*arr)[13],int size);
void protect_fixed_data (int arr[13][13],int size);
int check_fixed_data (int arr[13][13],int size,int raw,int col);
int comparing (int game_data[13][13],int right_sol[13][13],int size);
int scan_data(int (*arr)[13],int size);
void reset (int arr[][13],int size,int secure_size) ;
///*****************************************App**************************************************************
int App_fn(void)
{
    int level,hint_check,fixed_data,end_check=-1;
    int scan_flag=1;
    char Reset_Continue='c';

    hint=3;
    intro_fun();
    SetColor(14);
    printf("please write \n1  >> for an easy level \n2  >>  for a hard level\nlevel:");
    SetColor(15);
    scanf("%d",&level);
    if(level==1)
    {
        protect_fixed_data (easy_game_data,13);
        array_print_2D (easy_game_data,13,13);
        while (Reset_Continue=='C'||Reset_Continue=='c')
        {
L:
            scan_flag= scan_data(easy_game_data,13);
            while(scan_flag==-1)
            {
                scan_flag= scan_data(easy_game_data,13);
            }
            fixed_data= check_fixed_data (easy_game_data,35, G_raw, G_col);
            if (fixed_data==1)
            {
                if (G_answer==-1)
                {
                    easy_game_data[G_raw][G_col]=easy_game_sol[G_raw][G_col];
                    hint--;
                }
                else
                {
                    easy_game_data[G_raw][G_col]=G_answer;
                }

                end_check=comparing (easy_game_data,easy_game_sol,13);
                if (end_check==1)
                {
                    array_print_2D (easy_game_data,13,13);
                    SetColor(5);
                    printf("\n====================================================================================================\n");
                    SetColor(14);
                    printf("\n>>>>>>>>>>>>>>>>>>>>>>Congratulations<<<<<<<<<<<<<<<<<<<<<\n");
                    SetColor(5);
                    printf("\n====================================================================================================\n");
                    SetColor(15);
                    return 0 ;
                }
                array_print_2D (easy_game_data,13,13);
            }
            else
            {
                array_print_2D (easy_game_data,13,13);
                SetColor(11);
                printf("if you want to reset please enter 'R',else enter anything. \n");
                SetColor(15);
                fflush(stdin);
                scanf("%c",&Reset_Continue);
                if (Reset_Continue!='R'&&Reset_Continue!='r')
                {
                    goto L;
                }
                else if (Reset_Continue=='R'||Reset_Continue=='r')
                {
                    reset(easy_game_data,13,35);
                    Reset_Continue='c';
                    clearScreen();
                    App_fn();
                }
            }
            SetColor(11);
            printf("If you want to reset please enter 'R',else enter anything.\n");
            SetColor(15);
            fflush(stdin);
            scanf("%c",&Reset_Continue);
            if (Reset_Continue!='R'&&Reset_Continue!='r')
            {
                goto L;
            }
            else if (Reset_Continue=='R'||Reset_Continue=='r')
            {
                reset(easy_game_data,13,35);
                Reset_Continue='c';
                clearScreen();
                App_fn();
            }

        }
    }
    else if(level==2)
    {
        protect_fixed_data (hard_game_data,13);
        array_print_2D (hard_game_data,13,13);
        while (Reset_Continue=='C'||Reset_Continue=='c')
        {

L1:
            scan_flag= scan_data(hard_game_data,13);
            while(scan_flag==-1)
            {
                scan_flag= scan_data(hard_game_data,13);
            }
            fixed_data= check_fixed_data (hard_game_data,35, G_raw, G_col);
            if (fixed_data==1)
            {
                if (G_answer==-1)
                {
                    hard_game_data[G_raw][G_col]=hard_game_sol[G_raw][G_col];
                    hint--;
                }
                else
                {
                    hard_game_data[G_raw][G_col]=G_answer;
                }

                end_check=comparing (hard_game_data,hard_game_sol,13);
                if (end_check==1)
                {
                    array_print_2D (easy_game_data,13,13);
                    SetColor(5);
                    printf("\n====================================================================================================\n");
                    SetColor(14);
                    printf("\n>>>>>>>>>>>>>>>>>>>>>>Congratulations<<<<<<<<<<<<<<<<<<<<<\n");
                    SetColor(5);
                    printf("\n====================================================================================================\n");
                    SetColor(15);
                    return 0 ;
                }
                array_print_2D (hard_game_data,13,13);
            }
            else
            {
                array_print_2D (hard_game_data,13,13);
                SetColor(11);
                printf("if you want to reset please enter 'R',else enter anything. \n");
                SetColor(15);
                fflush(stdin);
                scanf("%c",&Reset_Continue);
                if (Reset_Continue!='R'&&Reset_Continue!='r')
                {
                    goto L1;
                }
                else if (Reset_Continue=='R'||Reset_Continue=='r')
                {
                    reset(hard_game_data,13,35);
                    Reset_Continue='c';
                    clearScreen();
                    App_fn();
                }
            }
            SetColor(11);
            printf("If you want to reset please enter 'R',else enter anything.\n");
            SetColor(15);
            fflush(stdin);
            scanf("%c",&Reset_Continue);
            if (Reset_Continue!='R'&&Reset_Continue!='r')
            {
                goto L1;
            }
            else if (Reset_Continue=='R'||Reset_Continue=='r')
            {
                reset(hard_game_data,13,35);
                Reset_Continue='c';
                clearScreen();
                App_fn();
            }

        }
    }
    else
    {
        App_fn();
    }
}
///****************************************introduction*******************************************************
void intro_fun(void)
{
    int option;
    SetColor(3);
    printf(" ============================================================================================================\n");
    SetColor(11);
    printf("                                                    SuDoKu                                                   \n");
    SetColor(3);
    printf(" ============================================================================================================\n\n");
    SetColor(3);
    printf("  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");
    SetColor(14);
    printf("Welcome in our Game , I hope you enjoy ") ;
    SetColor(3);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n\n") ;
    SetColor(15);
    printf("    >>>>>>  If you want a description for this game please enter 1 , if you want to skip enter 0  <<<<<<\n");
    scanf("%d",&option);
    if (option==1)
    {
        SetColor(3);
        printf(" ====================================================================================================================\n");
        SetColor(13);
        printf("                                                    Tutorial                                                    \n");
        SetColor(3);
        printf(" ====================================================================================================================\n");
        SetColor(15);
        printf(">>>In this game you can choose an easy level or a hard level<<<\n\n");
        printf("\n>>>You can use a hint 3 times , just you must enter number of row and number of column.<<<\n\n");
        printf("\n>>>It is forbidden to overwrite  fixed data.<<<\n\n");
        printf("\n>>>Also you have erase and reset options.<<<\n\n");
        SetColor(3);
        printf(" ====================================================================================================================\n");
        SetColor(13);
        printf("                                                    let's start                                                    \n");
        SetColor(3);
        printf(" ====================================================================================================================\n");
        SetColor(15);
    }

}
///*******************************protect fixed data**********************************************************

/*this function to fill an array of pointer with fixed data addresses */
void protect_fixed_data (int arr[13][13],int size)
{
    int i, j,k=0;
    for (i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if (arr[i][j]>=1&&arr[i][j]<=9)
            {
                secure_data_array[k]= *(arr+i)+j;
                k++;
            }
        }
    }
}
/*this fn to check if this place that user want to write on it  is available or not using addresses  */
int check_fixed_data (int arr[13][13],int secure_size,int raw,int col)
{
    int k=0;
    for (k; k< secure_size; k++)
    {
        if ((*(arr+raw)+col)==secure_data_array[k])
        {
            SetColor(4);
            printf(" \n\n        \a                   Error             \a        \n\n");
            SetColor(15);
            printf("Enter your answer in another place , it is fixed data\n") ;
            return -1;
        }
    }
    return 1;

}
///********************************compare with correct solution**********************************************
/*this function to compare between what user enters and correct answer */
/* return 1 if they are the same , else return -1*/

int comparing (int game_data[13][13],int right_sol[13][13],int size)
{
    int i,j;
    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if (game_data[i][j]==right_sol[i][j])
            {

            }
            else
            {
                return -1;
            }
        }
    }

    return 1;
}
///**********************************Reset********************************************************************
void reset (int arr[][13],int size,int secure_size)
{
    /*this function  clears all places except fixed places. also it clears secure data array */
    int i,j,k,flag=0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            flag=0;
            for (k=0; k<secure_size; k++)
            {
                if (secure_data_array[k]== (*(arr+i)+j))
                {
                    flag=1;
                }
            }
            if (flag==0&&(arr[i][j]!='|')&&(arr[i][j]!='-'))
            {
                arr[i][j]=0;
            }
        }
    }
    array_print_2D(easy_game_data,13,13);
    for (k=0; k<secure_size; k++)
    {
        secure_data_array[k]=0;
    }

}

///********************************scan i/p*******************************************************************

int scan_data(int (*arr)[13],int size)
{

    int raw,col,answer=0;
    char A_H='A';
    SetColor(5);
    printf("\n====================================================================================================\n");
    SetColor(15);
    printf("\n\n please enter number of row from 1 to 9 :  ");
    scanf("%d",&raw);
    printf("\n\n please enter number of column from 1 to 9:  ");
    scanf("%d",&col);
    SetColor(11);
    printf("\n if you want to use hint ,please enter'H', else enter anything :");
    SetColor(15);
    fflush(stdin);
    scanf("%c",&A_H);
    if ((A_H=='H'||A_H=='h')&&hint>0)
    {
        answer=-1;
        A_H='a';
    }
    else if ((A_H=='H'||A_H=='h')&&hint<=0)
    {
        printf("you can not use a hint option again , please try to solve\n");
        printf("\n please enter your answer from 1 to 9 and 0 if you want to erase it :  ");
        scanf("%d",&answer);

    }
    else
    {
        printf("\n please enter your answer from 1 to 9 and 0 if you want to erase it:  ");
        scanf("%d",&answer);
    }

    SetColor(5);
    printf("\n====================================================================================================\n");
    SetColor(15);

    if (((answer>=0&&answer<=9 )|| answer==-1) && (raw>=1&&raw<=9)&&(col>=1&&col<=9))
    {
        if (raw>=4 && raw <7)
        {
            raw=raw+1;
        }
        else if (raw>=7 && raw <11)
        {
            raw=raw+2;
        }
        if (col>=4 && col <=6)
        {
            col=col+1;
        }
        else if (col>=7 && col <11)
        {
            col=col+2;
        }
        G_raw=raw;
        G_col=col;
        G_answer=answer;
    }
    else
    {
        SetColor(4);
        printf("                                >>>>>>>>>>>>>>>Error<<<<<<<<<<<<<<<<<<            \n\n\n");
        SetColor(15);
        printf("                >>> You must enter a number from 1 to 9 for row and col.<<< \n                >>> You must enter an answer from 0 to 9 ,0 to clear.<<<\n\n\n");
        SetColor(11);
        printf("                                >>>>>>>>>>>>please try again<<<<<<<<<<<<<            \n");
        SetColor(15);
        return -1;
    }
    return 1;
}
///******************************print*****************************************************************
void array_print_2D (int arr[][13],int col,int raw)
{
    int i,j;
    for(i=0; i<raw; i++)
    {
        printf("   ");

        for(j=0; j<col; j++)
        {
            if (arr[i][j]=='|'||arr[i][j]=='-')
            {

                SetColor(3);
                printf("%c  ",arr[i][j]);

            }
            else if (arr[i][j]!=0)
            {

                        SetColor(13);
                        printf("%d  ",arr[i][j]);


                }

            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    SetColor(15);
}
///*********************************Design***********************************************************
void SetColor(int ForgC)
{
    WORD wColor;
    //This handle is needed to get the current background attribute

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


void clearScreen()
{
    system("cls");
}


