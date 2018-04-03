#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void game(int hp);
void viewtank(double a,double b);
int mainmenu(void);
void help(void);
void score(double last, double first);
void rscore(void);
void vscore(void);

int main(void)
{
    int a,hp;
    srand(time(NULL));
    while(1)
    {
        a=mainmenu();
        switch(a)
        {
        case 1:
            printf("\n\nInput HP of both players ===>> ");
            scanf("%d",&hp);
            fflush(stdin);
            game(hp);
            break;
        case 2:
            help();
            break;
        case 3:
            vscore();
            break;
        case 4:
            rscore();
            break;
        case 5:
            return 0;
        }
    }
}

void game(int hp)
{
    double distance,angle1=7.5,angle2=7.5,drop,mass,displacement;
    int turn=0,hp1=hp,hp2=hp,weight=1,power,damage,wind;
    int i,j,k;
    char input='A';
    distance=40+rand()%31;
    while(1)
    {
        if(turn%2==0)
        {
            system("color 0B");
            system("cls");
            weight=1+rand()%3;
            if(weight==1) mass=1;
            else if(weight==2) mass=1.1;
            else if(weight==3) mass=1.2;
            wind=-10+rand()%21;

            while(1)
            {
                system("cls");
                viewtank(angle1,angle2);
                printf("\n\n---------------------------------------------------------------------\n");
                printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
                printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
                printf("---------------------------------------------------------------------\n\n");
                printf("--------------------------Player 1 Choose----------------------------\n\n");
                printf("Cycle Angle: %g",angle1);

                input=getch();
                fflush(stdin);
                if(input==80)
                {
                    if(angle1>=15) angle1=angle1-7.5;
                }
                else if(input==72)
                {
                    if(angle1<=82.5) angle1=angle1+7.5;
                }
                else if(input=='\n' || input=='\r') break;
            }
            system("cls");
            viewtank(angle1,angle2);
            printf("\n\n---------------------------------------------------------------------\n");
            printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
            printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
            printf("---------------------------------------------------------------------\n\n");
            printf("--------------------------Player 1 Choose----------------------------\n\n");
            printf("Selected Angle: %g\n\n",angle1);

            while(1)
            {
                printf("Input Power(0-100): ");
                scanf("%d",&power);
                fflush(stdin);
                if(power>=0 && power<=100) break;
            }

            system("cls");
            viewtank(angle1,angle2);
            printf("\n\n---------------------------------------------------------------------\n");
            printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
            printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
            printf("---------------------------------------------------------------------\n\n");
            printf("--------------------------Player 1 Choose----------------------------\n\n");
            printf("Selected Angle: %g\n\n",angle1);
            printf("Selected Power: %d\n\n",power);

            drop=((power/mass)*sin((2*angle1*3.14159)/180))+wind;
            printf("Projectile landed at %g KM\n\n",drop);

            displacement=fabs(distance-drop);
            printf("Displacement: %g\n\n",(-1)*(distance-drop));

            if(displacement<=3)
            {
                printf("Critical HIT!!!\a\n\n");
                hp2=hp2-5*weight;
            }
            else if(displacement<=6)
            {
                printf("Good HIT!!\a\n\n");
                hp2=hp2-5*weight*0.7;
            }
            else if(displacement<=10)
            {
                printf("SCRATCH!\a\n\n");
                hp2=hp2-5*weight*0.3;
            }
            else printf("MISS!\n\n");
            printf("Press Any Key to continue\n");
            getch();
            fflush(stdin);
        }
        else
        {
            system("color 0D");
            system("cls");
            weight=1+rand()%3;
            if(weight==1) mass=1;
            else if(weight==2) mass=1.1;
            else if(weight==3) mass=1.2;
            wind=-10+rand()%21;

            while(1)
            {
                system("cls");
                viewtank(angle1,angle2);
                printf("\n\n--------------------------------------------------------------------\n");
                printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
                printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
                printf("---------------------------------------------------------------------\n\n");
                printf("--------------------------Player 2 Choose----------------------------\n\n");
                printf("Cycle Angle: %g",angle2);

                input=getch();
                fflush(stdin);
                if(input==80)
                {
                    if(angle2>=15) angle2=angle2-7.5;
                }
                else if(input==72)
                {
                    if(angle2<=82.5) angle2=angle2+7.5;
                }
                else if(input=='\n' || input=='\r') break;
            }
            system("cls");
            viewtank(angle1,angle2);
            printf("\n\n---------------------------------------------------------------------\n");
            printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
            printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
            printf("---------------------------------------------------------------------\n\n");
            printf("--------------------------Player 2 Choose----------------------------\n\n");
            printf("Selected Angle: %g\n\n",angle2);

            while(1)
            {
                printf("Input Power(0-100): ");
                scanf("%d",&power);
                fflush(stdin);
                if(power>=0 && power<=100) break;
            }

            system("cls");
            viewtank(angle1,angle2);
            printf("\n\n--------------------------------------------------------------------\n");
            printf("Turn: %d\t\t\tPlayer1 HP: %d\t\tPlayer2 HP: %d\n\n",turn+1,hp1,hp2);
            printf("Distance: %g KM\t\tWind= %d KM\t\tPayload Mass: %d GTon\n",distance,wind,weight);
            printf("---------------------------------------------------------------------\n\n");
            printf("--------------------------Player 2 Choose----------------------------\n\n");
            printf("Selected Angle: %g\n\n",angle2);
            printf("Selected Power: %d\n\n",power);

            drop=((power/mass)*sin((2*angle1*3.14159)/180))+wind;
            printf("Projectile landed at %g KM\n\n",drop);

            displacement=fabs(distance-drop);
            printf("Displacement: %g\n\n",(-1)*(distance-drop));

            if(displacement<=3)
            {
                printf("Critical HIT!!!\a\n\n");
                hp1=hp1-5*weight;
            }
            else if(displacement<=6)
            {
                printf("Good HIT!!\a\n\n");
                hp1=hp1-5*weight*0.7;
            }
            else if(displacement<=10)
            {
                printf("SCRATCH!\a\n\n");
                hp1=hp1-5*weight*0.3;
            }
            else printf("MISS!\n\n");
            printf("Press Any Key to continue\n");
            getch();
            fflush(stdin);
        }
        turn++;
        system("cls");
        if(hp2<=0)
        {
            printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
            printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
            printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
            printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
            printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");
            printf("================================================ Player 1 WINS!! ======================================================\a\n\n");
            score(hp1,hp);
            printf("=========================================== Press Any Key to Continue ==================================================\n");
            getch();
            fflush(stdin);
            return;
        }
        else if(hp1<=0)
        {
            printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
            printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
            printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
            printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
            printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");
            printf("================================================ Player 2 WINS!! =======================================================\a\n\n");
            score(hp2,hp);
            printf("=========================================== Press Any Key to Continue ==================================================\n");
            getch();
            fflush(stdin);
            return;
        }
    }
}

void viewtank(double a,double b)
{
    char d1,d2,file1[3],file2[3],array1[150],array2[150];
    FILE *fp1,*fp2;
    int i,j=-1,k=0;

    if(a==7.5) d1='A';
    else if(a==15) d1='B';
    else if(a==22.5) d1='C';
    else if(a==30) d1='D';
    else if(a==37.5) d1='E';
    else if(a==45) d1='F';
    else if(a==52.5) d1='G';
    else if(a==60) d1='H';
    else if(a==67.5) d1='I';
    else if(a==75) d1='J';
    else if(a==82.5) d1='K';
    else if(a==90) d1='L';

    if(b==7.5) d2='A';
    else if(b==15) d2='B';
    else if(b==22.5) d2='C';
    else if(b==30) d2='D';
    else if(b==37.5) d2='E';
    else if(b==45) d2='F';
    else if(b==52.5) d2='G';
    else if(b==60) d2='H';
    else if(b==67.5) d2='I';
    else if(b==75) d2='J';
    else if(b==82.5) d2='K';
    else if(b==90) d2='L';

    file1[0]='1';
    file1[1]=d1;
    file1[2]='\0';

    file2[0]='2';
    file2[1]=d2;
    file2[2]='\0';

    fp1=fopen(file1,"r");
    fp2=fopen(file2,"r");

    fgets(array1,150,fp1);
    fgets(array2,150,fp2);

    for(i=0; i<9; i++)
    {
        while(1)
        {
            printf("%c",array1[j]);
            j++;
            if((j+1)%15==0) break;
        }
        printf("               ********              ");
        while(1)
        {
            printf("%c",array2[k]);
            k++;
            if((k+1)%15==0) break;
        }
        printf("\n");
    }
    return;

}

int mainmenu(void)
{
    int r=0;
    char choice;
    system("cls");
    system("color 0A");

    while(1)
    {
        system("cls");

        printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
        printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
        printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
        printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
        printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");

        if(r==0)
        {
            printf("\t\t\t\t=====================>>>>PLAY<<<<=====================\n");
            printf("\t\t\t\t=========================HELP=========================\n");
            printf("\t\t\t\t=========================SCORE========================\n");
            printf("\t\t\t\t=========================RESET========================\n");
            printf("\t\t\t\t=========================QUIT=========================\n");
        }
        else if(r==1)
        {
            printf("\t\t\t\t=========================PLAY=========================\n");
            printf("\t\t\t\t=====================>>>>HELP<<<<=====================\n");
            printf("\t\t\t\t=========================SCORE========================\n");
            printf("\t\t\t\t=========================RESET========================\n");
            printf("\t\t\t\t=========================QUIT=========================\n");
        }
        else if(r==2)
        {
            printf("\t\t\t\t=========================PLAY=========================\n");
            printf("\t\t\t\t=========================HELP=========================\n");
            printf("\t\t\t\t=====================>>>>SCORE<<<<====================\n");
            printf("\t\t\t\t=========================RESET========================\n");
            printf("\t\t\t\t=========================QUIT=========================\n");
        }
        else if(r==3)
        {
            printf("\t\t\t\t=========================PLAY=========================\n");
            printf("\t\t\t\t=========================HELP=========================\n");
            printf("\t\t\t\t=========================SCORE========================\n");
            printf("\t\t\t\t=====================>>>>RESET<<<<====================\n");
            printf("\t\t\t\t=========================QUIT=========================\n");
        }
        else if(r==4)
        {
            printf("\t\t\t\t=========================PLAY=========================\n");
            printf("\t\t\t\t=========================HELP=========================\n");
            printf("\t\t\t\t=========================SCORE========================\n");
            printf("\t\t\t\t=========================RESET========================\n");
            printf("\t\t\t\t=====================>>>>QUIT<<<<=====================\n");
        }

        printf("\n\n_______________________________________________________________________________________________________________________\n");
        printf("_______________________________________________________________________________________________________________________\n");

        choice=getch();
        fflush(stdin);
        if(choice==72) r--;
        else if (choice==80) r++;
        else if(choice=='\n' || choice=='\r') return r+1;
        if(r>4) r=r%5;
        else if(r<0) r=4;
    }
}

void help(void)
{
    system("cls");
    system("color 0C");
    printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
    printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
    printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
    printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
    printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");
    printf("===================================================>>>>>Help<<<<<===================================================\n\n");
    printf("\t\t\t\t\t\t------>>LORE<<------\n\n");
    printf("It is the year 2999++. In a distant Utopia, humans have finally reached the peak of their quantum creations. From the\n");
    printf("ashes of their previous nuclear wars, they have created anti-matter exquisite rail guns, capable of packing punches\n");
    printf("almost as strong as Chuck Norris. In spite of their weird 'text-book' designs, they are capable of launching projectiles\n");
    printf("of specific anti-matter, that only harms their opponents, and not themselves. In such an war-breaking environment,\n");
    printf("a team of three persons decides to wage friendly battles among nations to prove their superiority and to claim the\n");
    printf("thrones of the seven and a half kingdoms. Do you have the courage to battle it out???\n\n\n");
    printf("\t\t\t\t\t\t----->>GAMEPLAY<<-----\n\n");
    printf("At the beginning of each game, the WARDROBE ( World Artillery Railgun Development & Research Official Board Ex) will select\n");
    printf("a specific distance between the Rail-guns of the two opposing teams. As 1 comes before 2, player 1 will get the first shot.\n");
    printf("Unfair in low HP, right? Well, WARDROBE does not care. And they have given you the permission to select HP before each match.\n");
    printf("Each turn, players will face the difficulty of winds, generated by high quality fans and anti-matter (Nuclear is old school)\n");
    printf("projectiles of different weights. By controlling the winds, weight, angle of the cannon and the power, only the best of the\n");
    printf("bests (Luckiest of luckiests in low HP) will survive. So, are you ready to play (in not low HP)?\n\n\n");
    printf("\t\t\t\t\t\t---->>Control<<----\n\n");
    printf("Main Menu : Press 'UP' and 'DOWN' arrow keys to navigate, 'ENTER' to select. I do not know how you have made to the HELP menu.\n\n");
    printf("In-Game : Use 'UP' and 'DOWN' arrow keys to cycle through angles and press 'ENTER' to confirm.\n");
    printf("Input power using the keyboard. Do not try to enter more or less power than capacity. You just have to input again.\n");
    printf("If you wish to cheat against your opponent, it is completely fine. Just do not get caught.\n");
    printf("The closer the projectile lands to target, the more damage it will deal, ranging from critical,good shots to simple scratch.\n\n");
    printf("N.B. > Using 0 power will make the projectile land on yourself, But you do not take damage. As developers, we can do that...\n\n");
    printf("GOOD LUCK... . . . ... . . . ...\n\n");
    printf("========================================>>>>>>>>>PRESS ANY TO RETURN<<<<<<<<<=============================================\n");
    getch();
    fflush(stdin);
    return;
}

void score(double last, double first)
{
    double cscore,hscore;
    cscore=(last/first)*1000;
    printf("=================================================== Score %g =========================================================\n\n",cscore);
    FILE *fp;
    fp=fopen("score","rb");
    fread(&hscore, sizeof (double), 1, fp);
    if(hscore<cscore)
    {
        printf("=========================================== CONGRATS!! NEW HIGH SCORE ==================================================\a\n\n");
        fclose(fp);
        fp=fopen("score","wb");
        fwrite(&cscore, sizeof (double), 1, fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
    return;
}

void rscore(void)
{
    system("cls");
    system("color 0E");
    FILE *fp;
    fp=fopen("score","wb");
    double score=0;
    fwrite(&score, sizeof (double), 1, fp);
    fclose(fp);
    printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
    printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
    printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
    printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
    printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");
    printf("============================================== Score has been reset!! ===============================================\a\n\n");
    printf("============================================ Press Any Key to Continue ==============================================\n");
    getch();
    fflush(stdin);
    return;
}

void vscore(void)
{
    system("cls");
    system("color 0E");
    FILE *fp;
    fp=fopen("score","rb");
    double score;
    fread(&score, sizeof (double), 1, fp);
    printf(" ________   _________   ___________  _____  _________    __________ ___________  _____  _         ________    _______\n");
    printf("|        \\ |         \\ |           |   |   |            /                |         |    |        |           /\n");
    printf("|________/ |_________/ |           |   |   |_________  |                 |         |    |        |________   \\______\n");
    printf("|          |         \\ |           | \\ |   |           |                 |         |    |        |                   \\ \n");
    printf("|          |          \\|___________|  \\|   |_________   \\__________      |       __|__  |_______ |________    _______/ \n\n\n\n");
    printf("                                                 Highest Score %g\n\n",score);
    fclose(fp);
    printf("============================================ Press Any Key to Continue ==============================================\n");
    getch();
    fflush(stdin);
    return;
}
