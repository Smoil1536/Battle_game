#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char p1[10], p2[10];
void print_design(int, int);
int even_odd(int);
void print_attacks();

int main(void)
{
    int p1_HP = 100, p2_HP = 100;
    char choice[5];
    int eee, i = 0;
    int tmp;

    printf("Pick a name(player 1) : ");
    scanf("%s", p1);

    printf("Pick a name(player 2) : ");
    scanf("%s", p2);
    system("cls");
    print_design(p1_HP, p2_HP);
     
    while(p1_HP > 0 && p2_HP > 0)
    {
            eee = even_odd(i);
            print_attacks();
            printf("Enter your choice (player %d): ",eee);
            scanf("%s", choice);

            srand(time(NULL));
            system("cls");
            if(strcmp(choice, "Punch") == 0 || strcmp(choice, "punch") == 0)
            {
                tmp = rand() % (12-7+1) + 7;
                if(eee == 1)
                {
                    p2_HP -= tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s punched %s (C=) !\n", p1, p2);
                }
                else if(eee == 2)
                {
                    p1_HP -= tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s punched %s (C=) !\n", p2, p1);
                }
            }
            else if(strcmp(choice, "Kick") == 0 || strcmp(choice, "kick") == 0)
            {
                tmp = rand() % (15-8+1) + 8;
                if(eee == 1)
                {
                    p2_HP -= tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s kicked %s (/```) !\n", p1, p2);
                }
                else if(eee == 2)
                {
                    p1_HP -= tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s kicked %s (/```) !\n", p2, p1);
                }
            }
            else if(strcmp(choice, "Heal") == 0 || strcmp(choice, "heal") == 0)
            {
                tmp = rand() % (16-5+1) + 5;
                if((eee == 1 && p1_HP > 80) || (eee == 2 && p2_HP > 80))
                {
                    print_design(p1_HP, p2_HP);
                    printf("\nYour HP is above 80 !");
                    continue;
                }

                else if(eee == 1)
                {
                    p1_HP += tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s healed (`+`) !",p1);
                }

                else if(eee == 2)
                {
                    p2_HP += tmp;
                    print_design(p1_HP, p2_HP);
                    printf("\n%s healed (`+`) !",p2);
                }
            }
            else
            {
                print_design(p1_HP, p2_HP);
                printf("\nUse given options bruh O_O\n");
                i--;
            }

        i++;
    }

    system("cls");
    print_design(p1_HP, p2_HP);
    if(p1_HP > p2_HP)
        printf("\n%s wins the game !\n\n", p1);
    else
        printf("\n%s wins the game\n\n", p2);
    

    return 0;
}

void print_design(int HP1, int HP2)
{
    if(HP1 < 0)
        HP1 = 0;
    else if(HP2 < 0)
        HP2 = 0;

    printf("+------------+        +------------+");
    printf("\n| Player 1   |        | Player 2   |");
    printf("\n+------------+        +------------+\n");
    printf("| %-11s",p1);
    printf("|   VS   | %-11s",p2);
    printf("|\n+------------+        +------------+\n");
    printf("| HP : %-3zu   |        | HP : %-3zu   |",HP1, HP2);
    printf("\n+------------+        +------------+\n");

}

void print_attacks()
{
    printf("\n+-------+  +------+  +------+");
    printf("\n| Punch |  | Kick |  | Heal |");
    printf("\n+-------+  +------+  +------+\n\n");
}

int even_odd(int num)
{
    if(num % 2 == 0)
        return 1;
    else
        return 2;
}
