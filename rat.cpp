
#include<stdio.h>
#include<bits/stdc++.h>
#include <windows.h>
using namespace std;

#define N 7


bool solveMazeUtil(char maze[N][N], int x, int y);

void simple(char maze[N][N])
{
  int t,r;
  cout<<"Here you are allowed to use 14 blocks. 2 per column "<<endl;
  cout<<"Constraints"<<endl;
  cout<<"1.cant put a block in cells covering 1st & 2nd row with 1st and 2nd column"<<endl;
  cout<<"2.cant put a block in cells covering 6th & 7th row with 6th and 7th column"<<endl;
lb:  for(int i=0;i<N;i++)
  {
     cout<<"enter block location in column "<<i+1<<endl;
     cin>>t;
     cin>>r;
     if(t>N || r>N)
     {
             cout<<"location out of maze"<<endl;
             goto lb;
     }
     if(i==0)
     {

         if((t==1 || r==2)||(t==2 || r==1))
         {
             cout<<"cant have blocks here"<<endl;
             goto lb;
         }
         else
         {
          maze[t-1][i] = '0';
          maze[r-1][i] = '0';
         }
     }
     if(i==1)
     {
         if((t==1 || r==2)||(t==2 || r==1))
         {
             cout<<"cant have blocks here"<<endl;
             goto lb;
         }
         else
         {
          maze[t-1][i] = '0';
          maze[r-1][i] = '0';
         }
     }
     if(i==5)
     {
         if((t==6 || r==7)||(t==7 || r==6))
         {
             cout<<"cant have blocks here"<<endl;
             goto lb;
         }
         else
         {
          maze[t-1][i] = '0';
          maze[r-1][i] = '0';
         }


     }
     if(i==6)
     {
         if((t==6 || r==7)||(t==7 || r==6))
         {
             cout<<"cant have blocks here"<<endl;
             goto lb;
         }
         else
         {
          maze[t-1][i] = '0';
          maze[r-1][i] = '0';
         }

     }
     maze[t-1][i] = '0';
     maze[r-1][i] = '0';

  }
}
void clean(char maze[N][N])
{
    cout<<"Constraint error. Row cant have more than 4 blocks"<<endl;
    for(int p=0;p<N;p++)
        for(int k=0;k<N;k++)
          maze[p][k]='1';
}
void dgerror(char maze[N][N])
{
    cout<<"Constraint error. diagonal cant have all the blocks"<<endl;
    for(int p=0;p<N;p++)
        for(int k=0;k<N;k++)
          maze[p][k]='1';

}
void tough(char maze[N][N])
{
 int c;
 cout<<"Here you can use 7 blocks "<<endl;
 cout<<"Constraints-"<<endl;
 cout<<"1.Can't have all the blocks in a single row or column or in a diagonal"<<endl;
 cout<<"2.every column can have only one block"<<endl;
 cout<<"3.cant put a block in cells covering 1st & 2nd row with 1st and 2nd column"<<endl;
 cout<<"4.cant put a block in cells covering 6th & 7th row with 6th and 7th column"<<endl;

 lb1: for(int i=0;i<N;i++)
  {
   cout<<"enter location in column "<<i+1<<endl;
   cin>>c;
   if(c>N)
    {
      cout<<"location out of maze"<<endl;
      goto lb1;
    }
   if(i==0)
     {

         if(c==1 or c==2)
         {
             cout<<"cant have blocks here"<<endl;
             goto lb1;
         }
         else
         {
          maze[c-1][i] = '0';
         }
     }
     if(i==1)
     {
         if(c==1 || c==2)
         {
             cout<<"cant have blocks here"<<endl;
             goto lb1;
         }
         else
         {
          maze[c-1][i] = '0';
         }

      }
      if(i==5)
     {

         if(c==6 or c==7)
         {
             cout<<"cant have blocks here"<<endl;
             goto lb1;
         }
         else
         {
          maze[c-1][i] = '0';
         }
     }

    if(i==6)
     {

         if(c==6 or c==7)
         {
             cout<<"cant have blocks here"<<endl;
             goto lb1;
         }
         else
         {
          maze[c-1][i] = '0';
         }
     }
   maze[c-1][i] = '0';
  }
  for(int i=0;i<N;i++)
  {
      int cnt = 0;
   for(int j=0;j<N;j++)
   {
       if(maze[i][j]=='0')
         cnt++;
   }
   if(cnt>4)
   {
    clean(maze);
    goto lb1;
   }
  }
  int d[9];
  for(int j=0;j<9;j++)
  {
      d[j]=0;
  }
   for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      if(i+j==2)
      {
          if(maze[i][j]=='1')
           d[0]++;

      }
      else if(i+j==3)
      {
         if(maze[i][j]=='1')
           d[1]++;
      }
      else if(i+j==4)
      {
         if(maze[i][j]=='1')
           d[2]++;
      }
      else if(i+j==5)
      {
         if(maze[i][j]=='1')
           d[3]++;
      }
      else if(i+j==6)
      {
         if(maze[i][j]=='1')
           d[4]++;
      }
      else if(i+j==7)
      {
         if(maze[i][j]=='1')
           d[5]++;
      }
      else if(i+j==8)
      {
         if(maze[i][j]=='1')
           d[6]++;
      }
      else if(i+j==9)
      {
         if(maze[i][j]=='1')
           d[7]++;
      }
      else if(i+j==10)
      {
         if(maze[i][j]=='1')
           d[8]++;
      }

    }

  }
  if(d[0]==3)
  {
      dgerror(maze);
      goto lb1;
  }
  else if(d[1]==4)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[2]==5)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[3]==6)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[4]==7)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[5]==6)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[6]==5)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[7]==4)
  {
      clean(maze);
      goto lb1;
  }
  else if(d[8]==3)
  {
      clean(maze);
      goto lb1;
  }



}
void printSolution(char sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
           cout<<" "<<sol[i][j];
        cout<<endl;
    }
}

bool isSafe(char maze[N][N], int x, int y)
{

    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == '1')
        return true;

    return false;
}

bool solveMaze(char maze[N][N])
{

    //printSolution(sol);
    //Sleep(1000);
    if(solveMazeUtil(maze, 0, 0) == false)
    {
        cout<<"Rat cant cross the maze. you won!!"<<endl;
        return false;
    }
    system("CLS");
    printSolution(maze);
    Sleep(500);
    cout<<"Rat successfully crossed the maze. you Lost"<<endl;
    return true;
}

bool solveMazeUtil(char maze[N][N], int x, int y)
{
    system("CLS");
    printSolution(maze);
    Sleep(500);
    if(x == N-1 && y == N-1)
    {
        maze[x][y] = '*';
        return true;
    }

    if(isSafe(maze, x, y) == true)
    {

        maze[x][y] = '*';



        if (solveMazeUtil(maze, x+1, y) == true)
           {
             return true;
           }

       else if (solveMazeUtil(maze, x, y+1) == true)
           {
             return true;
           }
        else if (solveMazeUtil(maze, x-1, y) == true)
           {
             return true;
           }
        else if (solveMazeUtil(maze, x, y-1) == true)
          {
              return true;
          }

       maze[x][y] = '#';
       system("CLS");
       printSolution(maze);
       Sleep(500);
       return false;
    }

    return false;
}

// driver program to test above function
int main()
{
int x;

char maze[N][N];
for(int i=0;i<N;i++)
{
  for(int j=0;j<N;j++)
  {
      maze[i][j] = '1';
  }

}
cout<<"Enter difficulty level (1.Simple 2.Tough)"<<endl;
cin>>x;
if(x==1)
{
 simple(maze);
}
else if(x==2)
{
 tough(maze);
}

    /*char maze[N][N]  =  {
        {'1', '1', '1', '0', '1', '0'},
        {'1', '0', '1', '1', '1', '0'},
        {'1', '0', '1', '0', '1', '0'},
        {'1', '1', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '1', '1'}
    };*/

    solveMaze(maze);
    return 0;
}


