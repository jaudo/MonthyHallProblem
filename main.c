#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    printf("Monty Hall simulation with Monte Carlo method by Carlos Agorreta\n carlosagorreta@gmail.com \n");
    system("pause");
    srand(time(NULL));   // should only be called once
    rand();
     int o=0, prize,picks[3],erand,pick,trobat=0;
   int i=0,exps,win_tot=0,win_change=0,win_no=0,lose_tot=0,lose_change=0,lose_no=0;
   int change,change_c=0,stay_c=0;
    float win_no_stat=0,win_change_stat=0; //max is 65000
    //init random function
    //================
    system("cls");
    printf("Introduce number of experiments: ");
    scanf("%u",&exps);
    for(i=0;i<exps;i++) //i number of experiments
    {
        //init game init() function
        for(o=0;o<3;o++)//clean picks
        {
            picks[o]=0; //0 is goat, 1 is prize
        }
        prize=rand()%3; //random position of prize
        picks[prize]=1; //set price
        pick=rand()%3; //set election
        //============
        //erase process ==> erase() future function//
        trobat=0; //no need to reinit o because for do it for us
        erand=0;
        while(trobat == 0)//clean picks
        {
            if (picks[prize]==picks[pick]) //random erase
            {
                erand=rand()%3;
                if((erand!=prize) && (erand!=pick)) //otherwise only 1 option to erase
                {
                    picks[erand]=2;
                    trobat=1;
                    erand--;
                }
            erand++;
            }
            else //otherwise only 1 option to erase
            {
              if((erand!=prize) && (erand!=pick))
            {
            picks[erand]=2;
            trobat=1;
            erand--;
            }
            erand++;
            }
        }
        trobat=0;
       //==========================
        change=rand()%2; //player second decision, decision 0 stay 1 changes pick
        if (change==1)
        {
            o=0;
            change_c++;
         while(trobat==0)//clean picks
        {
            if(o != erand && o != pick )
            {
                pick = o;
                trobat=1;
            }
            o++;
        }

        }
        //end game, checking result
        if(picks[pick]==picks[prize])
        {
            win_tot++;
            if(change==1) win_change++;
            if (change==0) win_no++;
        }
        else
        {
            lose_tot++;
            if(change==1) lose_change++;
            if (change==0) lose_no++;

        }
    }
            // stats() function
         stay_c=exps-change_c;
        if((win_no || lose_no) != 0 )
        {
          win_no_stat=((float)win_no/(float)stay_c)*100;
        }
        if((win_change || lose_change) != 0 )
        {
         win_change_stat=((float)win_change/((float)change_c))*100;
        }
        //print stats
        printf("Showing results: \n");
        printf("of %u experiments, bot changed %u times\n\n",exps,change_c);
        printf("of that %u times user stayed, user won %u,\nmaking a %f %% win percentage\n\n",stay_c,win_no,win_no_stat);
        printf("of that %u times user changed, user won %u,\nmaking a %f %% win percentage\n\n",change_c,win_change,win_change_stat);

    system("pause");
    return 0;
}
