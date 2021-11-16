#include<iostream>
/* math.h header file is included for abs() function */
#include<cmath>
using namespace std;
/**
 * AtA|b = x
 * @param mat an nxn+1 matrix, where m is the number of equations, and the last element of each
 * matrix is the b value
 * @return
 */
vector<double> gaussian(vector<vector<double>> mat)
{

   int i =0;
   int j =0;
   int n = (int)mat.size();
   int k =0;
   vector<double> res(n,0);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(abs(mat[i][i]) < abs(mat[j][i]))
            {
                for(k=0;k<n+1;k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
                    mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];
                }
            }
        }
    }

   	/* performing Gaussian elimination */
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            float f=mat[j][i]/mat[i][i];
            for(k=0;k<n+1;k++)
            {
            	mat[j][k]=mat[j][k]-f*mat[i][k];
      }
        }
    }

    /* Backward substitution for discovering values of unknowns */
    for(i=n-1;i>=0;i--)          
    {                     
        res[i]=mat[i][n];
                    
        for(j=i+1;j<n;j++)
        {
        	if(i!=j)
        	{
        	    res[i]=res[i]-mat[i][j]*res[j];
    }          
  }
  res[i]=res[i]/mat[i][i];  
    }
    
    cout<<"\nThe values of unknowns for the above equations=>\n";
    for(i=0;i<n;i++)
    {
    	cout<<res[i]<<"\n";
    }
      
    return res;
}