#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
char c[3][3];
void disp()
{
    int i,j;
    cout<<endl;
    for(i=0;i<3;i++)
	    {
	    for(j=0;j<3;j++)
	    {
            if(j!=2)
            cout<<" "<<c[i][j]<<" |";
            else
            cout<<" "<<c[i][j];
	    }
	    if(i!=2)
	    cout<<endl<<"------------"<<endl;
	    else
	    cout<<endl<<endl;
	    }
}
int check()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        if(c[i][0]==c[i][1] && c[i][1]==c[i][2] && c[i][0]!=' ')
        {
            return(0);
        }
        if(c[0][i]==c[1][i] && c[1][i]==c[2][i] && c[0][i]!=' ')
        {
            return(0);
        }
    }
    if(c[0][0]==c[1][1] && c[1][1]==c[2][2] && c[0][0]!=' ')
    {
        return(0);
    }
    if(c[2][0]==c[1][1] && c[1][1]==c[0][2] && c[2][0]!=' ')
    {
        return(0);
    }
    return(1);
}
int check_full()
{
    int i,j,z=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(c[i][j]==' ')
            z++;
        }
    }
    return(z);
}
int main()
{
	int flag,k,i,j,a,b,z,ch,cnt,fcnt;
	k=0;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	c[i][j]=' ';
	cout<<"----------------TIC-TAC-TOE----------------"<<endl;
	cout<<"Enter:-\n1.To play against computer\n2.To play against another player\n";
	cin>>ch;
	switch(ch)
	{
      case 1:system("cls");
             while(1)
             {
                 srand(time(NULL));
                 flag=1;
                 k++;
                 z=check_full();
                 if(z==0)
                 {
                     goto b;
                 }
                 if(k%2!=0)
                {
                    cout<<"Enter your row and column ";
                    cin>>a>>b;
                    if(c[a-1][b-1]==' ')
                    {
                        c[a-1][b-1]='O';
                        goto c;
                    }
                    else
                    {
                        k--;
                        cout<<"Invalid Move"<<endl;
                    }
                }
                else
                {
                    cout<<"Computer's Move"<<endl;
                    for(i=0;i<3;i++)
                    {
                        cnt=0;
                        fcnt=3;
                        for(j=0;j<3;j++)
                        {
                            if(c[i][j]=='X')
                            cnt++;
                            else if(c[i][j]==' ')
                            fcnt=j;
                        }
                        if(cnt==2 && fcnt!=3)
                        {
                            c[i][fcnt]='X';
                            goto c;
                        }
                    }
                    for(i=0;i<3;i++)
                    {
                        cnt=0;
                        fcnt=3;
                        for(j=0;j<3;j++)
                        {
                            if(c[j][i]=='X')
                            cnt++;
                            else if(c[j][i]==' ')
                            fcnt=j;
                        }
                        if(cnt==2 && fcnt!=3)
                        {
                            c[fcnt][i]='X';
                            goto c;
                        }
                    }
                    cnt=0;
                    fcnt=3;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][i]=='X')
                        cnt++;
                        else if(c[i][i]==' ')
                        fcnt=i;
                    }
                    if(cnt==2 && fcnt!=3)
                    {
                        c[fcnt][fcnt]='X';
                        goto c;
                    }
                    cnt=0;
                    fcnt=3;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][2-i]=='X')
                        cnt++;
                        else if(c[i][2-i]==' ')
                        fcnt=i;
                    }
                    if(cnt==2 && fcnt!=3)
                    {
                        c[fcnt][2-fcnt]='X';
                        goto c;
                    }
                    for(i=0;i<3;i++)
                    {
                        cnt=0;
                        fcnt=3;
                        for(j=0;j<3;j++)
                        {
                            if(c[i][j]=='O')
                            cnt++;
                            else if(c[i][j]==' ')
                            fcnt=j;
                        }
                        if(cnt==2 && fcnt!=3)
                        {
                            c[i][fcnt]='X';
                            goto c;
                        }
                    }
                    for(i=0;i<3;i++)
                    {
                        cnt=0;
                        fcnt=3;
                        for(j=0;j<3;j++)
                        {
                            if(c[j][i]=='O')
                            cnt++;
                            else if(c[j][i]==' ')
                            fcnt=j;
                        }
                        if(cnt==2 && fcnt!=3)
                        {
                            c[fcnt][i]='X';
                            goto c;
                        }
                    }
                    cnt=0;
                    fcnt=3;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][i]=='O')
                        cnt++;
                        else if(c[i][i]==' ')
                        fcnt=i;
                    }
                    if(cnt==2 && fcnt!=3)
                    {
                        c[fcnt][fcnt]='X';
                        goto c;
                    }
                    cnt=0;
                    fcnt=3;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][2-i]=='O')
                        cnt++;
                        else if(c[i][2-i]==' ')
                        fcnt=i;
                    }
                    if(cnt==2 && fcnt!=3)
                    {
                        c[fcnt][2-fcnt]='X';
                        goto c;
                    }
                    for(i=0;i<3;i++)
                    {
                        cnt=3;
                        fcnt=0;
                        for(j=0;j<3;j++)
                        {
                            if(c[i][j]=='X')
                            cnt=j;
                            else if(c[i][j]==' ')
                            fcnt++;
                        }
                        if(cnt!=3 && fcnt==2)
                        {
                            if(cnt==2 || cnt==0)
                            c[i][1]='X';
                            else
                            c[i][0]='X';
                            goto c;
                        }
                    }
                    for(i=0;i<3;i++)
                    {
                        cnt=3;
                        fcnt=0;
                        for(j=0;j<3;j++)
                        {
                            if(c[j][i]=='X')
                            cnt=j;
                            else if(c[j][i]==' ')
                            fcnt++;
                        }
                        if(fcnt==2 && cnt!=3)
                        {
                            if(cnt==2 || cnt==0)
                            c[1][i]='X';
                            else
                            c[0][i]='X';
                            goto c;
                        }
                    }
                    cnt=3;
                    fcnt=0;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][i]=='X')
                        cnt=i;
                        else if(c[i][i]==' ')
                        fcnt++;
                    }
                    if(cnt==2 && fcnt!=3)
                    {
                        if(cnt==2 || cnt==0)
                        c[1][1]='X';
                        else
                        c[0][0]='X';
                        goto c;
                    }
                    cnt=3;
                    fcnt=0;
                    for(i=0;i<3;i++)
                    {
                        if(c[i][2-i]=='X')
                        cnt=i;
                        else if(c[i][2-i]==' ')
                        fcnt++;
                    }
                    if(fcnt==2 && cnt!=3)
                    {
                        if(cnt==2 || cnt==0)
                        c[1][1]='X';
                        else
                        c[0][2]='X';
                        goto c;
                    }
                    while(1)
                    {
                        i=rand()%3;
                        j=rand()%3;
                        if(c[i][j]==' ')
                        {
                            c[i][j]='X';
                            break;
                        }
                    }
                    c:
                    disp();
                    flag=check();
                    if(flag==0)
                    goto b;
                }
             }
             b:
                if(flag==0)
                {
                    if(k%2!=0)
                        cout<<"You won the game";
                    else
                        cout<<"Computer won the game";
                }
                else
                    cout<<"Match Draw";
                getch();
             break;
      case 2:system("cls");
            while(1)
            {
                flag=1;
                k++;
                z=check_full();
                if(z==0)
                {
                    goto a;
                }
                if(k%2!=0)
                {
                    cout<<"Player 1, enter your row and column ";
                    cin>>a>>b;
                    if(c[a-1][b-1]==' ')
                        c[a-1][b-1]='X';
                    else
                    {
                        k--;
                        cout<<"Invalid Move"<<endl;
                    }
                }
                else
                {
                    cout<<"Player 2, enter your row and column ";
                    cin>>a>>b;
                    if(c[a-1][b-1]==' ')
                        c[a-1][b-1]='O';
                    else
                    {
                        k--;
                        cout<<"Invalid Move"<<endl;
                    }
                }
                disp();
                flag=check();
                if(flag==0)
                goto a;
            }
            a:
                if(flag==0)
                {
                    if(k%2!=0)
                        cout<<"Player 1 won the game";
                    else
                        cout<<"Player 2 won the game";
                }
                else
                    cout<<"Match Draw";
                getch();
                break;
        default:cout<<"Wrong option"<<endl;
	}
}
