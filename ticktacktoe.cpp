#include<iostream>

using namespace std;

char array[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int r,c;
char t='X';
string n1,n2;
bool draw=false;

void f1()
{
    cout << "   |   |   "<<endl;
    cout << array[0][0] << "  | " << array[0][1] << " |  " << array[0][2] << endl;
    cout << "___|___|___"<<endl;
    cout << "   |   |   "<<endl;
    cout << array[1][0] << "  | " << array[1][1] << " |  " << array[1][2] << endl;
    cout << "___|___|___"<<endl;
    cout << "   |   |   "<<endl;
    cout << array[2][0] << "  | " << array[2][1] << " |  " << array[2][2] << endl;
    cout << "   |   |   "<<endl;


}

void f2()
{
    int d;
    if(t=='X')
    {
        cout << n1 << "'s turn:";
        cin >> d;
    }
     if(t=='O')
    {
        cout << n2 << "'s turn:";
        cin >> d;
    }
    if(d==1)
    {
        r=0;
        c=0;
    }
    else if(d==2)
    {
        r=0;
        c=1;
    }
    else if(d==3)
    {
        r=0;
        c=2;
    }
    else if(d==4)
    {
        r=1;
        c=0;
    }
    else if(d==5)
    {
        r=1;
        c=1;
    }
    else if(d==6)
    {
        r=1;
        c=2;
    }
    else if(d==7)
    {
        r=2;
        c=0;
    }
    else if(d==8)
    {
        r=2;
        c=1;
    }
    else if(d==9)
    {
        r=2;
        c=2;
    }
    else 
    {
        cout << "Invalid move!"<< endl;
    }
    if(t=='X'&& array[r][c]!='X'&&array[r][c]!='O')
    {
        array[r][c]='X';
        t='O';
    }
    else if(t=='O'&& array[r][c]!='X'&&array[r][c]!='O')
    {
        array[r][c]='O';
        t='X';
    }
    else 
    {
        f2();
    }
}

bool f3()
{
    for(int i=0;i<3;i++)
    {
        if(array[i][0]==array[i][1]&&array[i][0]==array[i][2]||array[0][i]==array[1][i]&&array[0][i]==array[2][i])
        {
            return true;
        }
        if(array[0][0]==array[1][1]&&array[0][0]==array[2][2]||array[0][2]==array[1][1]&&array[0][2]==array[2][0])
        {
            return true;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(array[i][j]!='X'&&array[i][j]!='O')
            {
                return false;
            }
            
        }
    }
    draw =true;
   return false;
}

int main()
{
    cout << "Enter first player name:" ;
    cin >>n1;
    cout << "Enter second player name:";
    cin >>n2;
    while(true)
    {
        f1();
        f2();
        if(f3()==true||draw==true)
        {
            break;
        }
    }
    if(draw==true)
    {
        cout << "It is a draw!";
    }
    else if(t=='X')
    {
        cout << n2 << " wins!";
    }
    else if(t=='O')
    {
        cout << n1 <<" wins!";
    }
    return 0;
}