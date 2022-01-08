#include <iostream>
#include <cmath>
using namespace std;
#define UNASSIGNED 0  

#define N 9

class Solution 
{
    
    public:
   // int ans[9][9];
   bool isSafe(int grid[N][N], int i, int j, int n)
   {
       for(int k=0;k<N;k++)
       {
           if(grid[i][k]==n || grid[k][j]==n)
           {
              return false;
           }
       }
      int s=sqrt(N);
      int rs=i-i%s;
      int cs=j-j%s;

      for(int i=0;i<s;i++)
      {
          for(int j=0;j<s;j++)
          {
              if(grid[i+rs][j+cs]==n)
              {
                 return false;
              }
          }
       }
    
      return true;
   }

  bool SolveSudoku(int grid[N][N])  
   { 
        int i,j;

      for(i=0;i<N;i++)
      {
           bool flag=false;
           for(j=0;j<N;j++)
           {
              if(grid[i][j]==0)
              {
                  flag=true;
                  break;
              }
           }
          if(flag==true)
          {
            break;
          }
      }

      if(i==N && j==N)
      {
         return true;
      }
       
      for(int k=1;k<=N;k++)
      {
         if(isSafe(grid,i,j,k))
         {
             grid[i][j]=k;
                
             if(SolveSudoku(grid)==true)
             return true;
                
             grid[i][j]=0;
         }
       }      
       return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid);
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    cout<<"Enter empty cells as zero"<<endl;

    int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;

        return 0;
}

