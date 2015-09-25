#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char hcards[5][3],pcards[9][2][3],name[][30]={"a high card","a pair","two pairs","three-of-a-kind","a straight","a flush","a full house","four-of-a-kind","a straight flush","a royal flush"};
int lvl[9]={0},nop,suit[4][13]={0},allca[9][4][13]={0},chknu[9][13]={0};
int checkcard(char a[3])
{
    int k,l;
    switch(a[1])
    {
        case 'h':k=0;
                 break;
        case 's':k=1;
                 break;
        case 'c':k=2;
                 break;
        case 'd':k=3;
    }
    if(isdigit(a[0]))
    l=a[0]-49;
    else
    switch(a[0])
    {
        case 't':l=9;
                 break;
        case 'j':l=10;
                 break;
        case 'q':l=11;
                 break;
        case 'k':l=12;
    }
    if(suit[k][l]==1)
    return 1;
    else
    {
        suit[k][l]=1;
        return 0;
    }
}
void hashcards(int n)
{
    int i,k,l;
    for(i=0;i<2;i++)
    {
        switch(pcards[n][i][1])
        {
            case 'h':k=0;
                    break;
            case 's':k=1;
                    break;
            case 'c':k=2;
                    break;
            case 'd':k=3;
        }
        if(isdigit(pcards[n][i][0]))
        l=pcards[n][i][0]-49;
        else
        switch(pcards[n][i][0])
        {
            case 't':l=9;
                     break;
            case 'j':l=10;
                     break;
            case 'q':l=11;
                     break;
            case 'k':l=12;
        }
        allca[n][k][l]++;
        chknu[n][l]++;
    }
    for(i=0;i<5;i++)
    {
        switch(hcards[i][1])
        {
            case 'h':k=0;
                    break;
            case 's':k=1;
                    break;
            case 'c':k=2;
                    break;
            case 'd':k=3;
        }
        if(isdigit(hcards[i][0]))
        l=hcards[i][0]-49;
        else
        switch(hcards[i][0])
        {
            case 't':l=9;
                     break;
            case 'j':l=10;
                     break;
            case 'q':l=11;
                     break;
            case 'k':l=12;
        }
        allca[n][k][l]++;
        chknu[n][l]++;
    }
}
int main()
{
    cout<<"-------------------POKER SIMULATOR-------------------"<<endl<<"Welcome to the poker hand simulator, which helps you to determine a winner in a\npoker game of 2-9 players. Standard Texas Hold'em rules apply.\n\nEvery card must be entered as a string of 2 characters.\n\nThe first character denotes the value of the card.\nAce is denoted by 1, ten by t, jack by j, queen by q, king by k and the rest of\nthe numbers by their respective numerals.\n\nThe second character denotes the suit of the card.\nHeart is denoted by h, spade by s, club by c and diamond by d."<<endl<<endl;
    char a;
    int i,j,k,cnt,fl,tmp,win;
    cout<<"Enter the no. of players in the game ";
    c:
    cin>>nop;
    if(nop>9)
    {
        cout<<"Too many players. Maximum no. of players allowed is 9. Enter no. of players again ";
        goto c;
    }
    cout<<"Enter the house cards ";
    for(i=0;i<5;i++)
    {
        a:
        cin>>hcards[i];
        if(!(isdigit(hcards[i][0]) || hcards[i][0]=='t' || hcards[i][0]=='j' || hcards[i][0]=='q' || hcards[i][0]=='k') || !(hcards[i][1]=='d' || hcards[i][1]=='s' || hcards[i][1]=='c' || hcards[i][1]=='h') || hcards[i][0]=='0' || strlen(hcards[i])!=2)
        {
            cout<<"Wrong Card Entry. Enter last card again. ";
            goto a;
        }
        if(checkcard(hcards[i]))
        {
            cout<<"Duplicate Card Entry. Enter last card again. ";
            goto a;
        }
    }
    for(i=0;i<nop;i++)
    {
        cout<<"Enter player "<<i+1<<" cards ";
        for(j=0;j<2;j++)
        {
            b:
            cin>>pcards[i][j];
            if(!(isdigit(pcards[i][j][0]) || pcards[i][j][0]=='t' || pcards[i][j][0]=='j' || pcards[i][j][0]=='q' || pcards[i][j][0]=='k') || !(pcards[i][j][1]=='d' || pcards[i][j][1]=='s' || pcards[i][j][1]=='c' || pcards[i][j][1]=='h') || pcards[i][j][0]=='0' || strlen(pcards[i][j])!=2)
            {
                cout<<"Wrong Card Entry. Enter last card again. ";
                goto b;
            }
            if(checkcard(pcards[i][j]))
            {
                cout<<"Duplicate Card Entry. Enter last card again. ";
                goto b;
            }
        }
    }
    for(i=0;i<nop;i++)
    {
        hashcards(i);
        fl=0;
        for(j=0;j<4;j++)
        {
            cnt=0;
            for(k=0;k<13;k++)
            {
                cnt+=allca[i][j][k];
            }
            if(cnt>=5)
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
        {
            if(allca[i][j][0]==1 && allca[i][j][9]==1 && allca[i][j][10]==1 && allca[i][j][11]==1 && allca[i][j][12]==1)
            {
                lvl[i]=9;
                goto end;
            }
            cnt=0;
            for(k=12;k>=0;k--)
            {
                if(allca[i][j][k]==1)
                cnt++;
                else
                cnt=0;
                if(cnt==5)
                {
                    lvl[i]=8;
                    goto end;
                }
            }
            lvl[i]=5;
            goto end;
        }
        else
        {
            for(k=0;k<13;k++)
            {
                if(chknu[i][k]==4)
                {
                    lvl[i]=7;
                    goto end;
                }
            }
            cnt=0;
            tmp=0;
            for(k=0;k<13;k++)
            {
                if(chknu[i][k]>=2)
                {
                    tmp++;
                    cnt+=chknu[i][k];
                }
                if(tmp>2)
                cnt=0;
                if(cnt>=5)
                {
                    lvl[i]=6;
                    goto end;
                }
            }
            if(chknu[i][0]>0 && chknu[i][9]>0 && chknu[i][10]>0 && chknu[i][11]>0 && chknu[i][12]>0)
            {
                lvl[i]=4;
                goto end;
            }
            cnt=0;
            for(k=12;k>=0;k--)
            {
                if(chknu[i][k]>0)
                cnt++;
                else
                cnt=0;
                if(cnt==5)
                {
                    lvl[i]=4;
                    goto end;
                }
            }
            cnt=0;
            for(k=0;k<13;k++)
            {
                if(chknu[i][k]==3)
                {
                    lvl[i]=3;
                    goto end;
                }
                if(chknu[i][k]==2)
                {
                  cnt++;
                }
                if(cnt==2)
                {
                    lvl[i]=2;
                    goto end;
                }
            }
            if(cnt==1)
            {
                lvl[i]=1;
                goto end;
            }
        }
        end:;
    }
    win=0;
    for(i=1;i<nop;i++)
    {
        if(lvl[win]<lvl[i])
        win=i;
    }
    cout<<"Winner is player "<<win+1<<" with "<<name[lvl[win]];
}
