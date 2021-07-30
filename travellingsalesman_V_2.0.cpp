#include<conio.h>
#include "bits/stdc++.h"
#include<time.h>
#include<windows.h>
using namespace std;
int lines=99999;

//find next minimum number
void pwellcome(){
	//ccolor(26);

	char welcome[] =" Welcome";
	char welcome2[]=" To";
	char welcome3[]=" SpeedWagon Express";
	char welcome4[]=" Delivery Route Identifier";
	cout<<"\n\n\n\n\n\t\t\t";
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		cout<<welcome[wlc];
		Sleep(100);
	}
	//ccolor(26);
	cout<<"\n\n\t\t\t\t ";
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		cout<<welcome2[wlc2];
		Sleep(100);
	}
	//ccolor(26);
	cout<<"\n\n\n\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			cout<<welcome3[wlc3];
		}
		else{

			cout<<welcome3[wlc3];
		}

		Sleep(100);
	}
	//ccolor(26);
	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			cout<<welcome4[wlc3];
		}
		else{

			cout<<welcome4[wlc3];
		}
		Sleep(100);
	}
	//ccolor(26);

}
int find_next(vector<vector <int> >& cost,int minimum)
{

  int low=99999;

  for(int i=0;i<cost.size();i++)
  {

	for(int j=0;j<cost[0].size();j++)
	{

	  if(low>cost[i][j] && cost[i][j]>minimum)

		low = cost[i][j];
    }

  }

  return low;
}

bool ans(vector<vector <int> >& cost,int row,int minimum,vector<int>& out,int tot )
{

  for(int j=0;j<cost[0].size();j++)
  {

    if(cost[row][j]<=minimum)
	{

	  if(tot == cost.size() && j==0)

	    return true;

	 	 if(find(out.begin(), out.end(),j)==out.end())
			{
       		 out.push_back(j);
        	 tot++;
       		 if(!ans(cost,j,minimum,out,tot))
				{

				  out.pop_back();
         		  tot--;
        		}
        else
          return true;
     	    }
    }
  }
  cout << endl;
  return false;
}

void update(vector<vector <int> >& cost)
{

  // operation on rows

  int i,j,min,n =cost.size() ;

  for(i=0;i<n;i++)
  {
   	min=cost[i][0];

	// finding minimum element in each row

	for(j=0;j<n;j++)
	{
        if(min>cost[i][j])
        min=cost[i][j];
    }
    //subtract the minimum element from each element of the respective rows

	for(j=0;j<n;j++)
      cost[i][j]=cost[i][j]-min;

  }


  // operation on colums

  for(i=0;i<n;i++)
  {
    min=cost[0][i];

    // find the minimum element in each column

    for(j=0;j<n;j++)
	{
      if(min>cost[j][i])
        min=cost[j][i];
    }

    //subtract the minimum element from each element of the respective columns

	if(min>0)
	{
      for(j=0;j<n;j++)
        cost[j][i]=cost[j][i]-min;
    }
  }
}


//to find the number of lines that can cross all the zeros of matrix

int check(vector<vector <int> >& cost,vector<vector <int> >& cross,int *sr,int *sc,int row,int col,int n,int tot)
{

  // cout << row <<" " << col << " "<< n << " " << tot << endl;


  if(row>=n)
  {

    	if(lines>=tot)
		{
     	 	for(int i=0;i<n;i++)
			  {
        		for(int j=0;j<n;j++)
				{

		  			cross[i][j]=0;
        		}
      		  }

	  		lines = tot;

      			for(int i=0;i<n;i++)
				  {

	    			if(sr[i])
					{

		  			for(int j=0;j<n;j++)
					  {

						if(cross[i][j]==-1)
              				cross[i][j] = 2;
            			else
              				cross[i][j] = 1;
          			  }
       				 }
     			  }

	  			for(int i=0;i<n;i++)
				{

					if(sc[i])
					{

		 				 for(int j=0;j<n;j++)
						  {
            				if(cross[j][i]==1)
             			    	cross[j][i] = 2;
            				else
              					cross[j][i] = -1;
          				  }
        			}
      			}
    	}

    // cout << endl;

    return tot;
  }


  	for(int i=row;i<n;i++)
	  {

    	for(int j=col;j<n;j++)
		{

	  		if(!cost[i][j] && !sr[i] && !sc[j])
			  {
        		sr[i] = 1;
        		int val1,val2;
        		val1 = check(cost,cross,sr,sc,i+1,0,n,tot+1);
		        sr[i] = 0;
		        sc[j] = 1;
		        if(j==n-1)
         		val2 = check(cost,cross,sr,sc,i+1,0,n,tot+1);
        	else
         		val2 = check(cost,cross,sr,sc,i,j+1,n,tot+1);
        		sc[j] = 0;
        		return min(val1,val2);
      		 }
    	}
    col=0;
  	}
}


int main()
{ pwellcome();
system("CLS");

  int ch=0;int retry=0;
  int i,j,n,a,counter =0;
  cout<<"Delivery  Management System\n\n";

do{
	  cout <<"Enter the total number of deliveries you have received:"<< endl;
	  cin >> n;
	  vector<vector<int> > cost(n, vector<int>(n));
	  vector<vector<int> > cross(n, vector<int>(n));

	  /* Enter the cost matrix*/


 	 cout <<"Enter the cost matrix"<< endl;
 		 for(i=0;i<n;i++)
  		 {

     		printf("\n");

	 			for(j=0;j<n;j++)
				 {
       				 cout << "cost["<<i<<"]["<<j<<"] = ";

					cin >> cost[i][j];
    			 }
  		 }
  	 cout << endl;

  // Entered cost matrix

  cout <<"Cost matrix:"<< endl;
  cout<<endl;
  	for(i=0;i<n;i++)
  	{
      	for(j=0;j<n;j++)
        	cout << cost[i][j] << " ";
     		 cout << endl;
    }

  update(cost);

  

  loop:;

  int sr[n] = {0},sc[n] = {0};

  for(i=0;i<n;i++)
  {

    for(j=0;j<n;j++)
	{
      cross[i][j]=0;
    }
  }

  /*Draw minimum number of horizontal and vertical lines to cover all zeros in
  resulting matrix*/
  a = 0;
  a = check(cost,cross, sr, sc,0,0,n,0);

  cout << endl;

 
  lines = 99999;

  

  /* If minimum number of lines, a is equal to the order of the matrix n then
  assignment can be optimally completed.*/

  if(a==n)
  {
    vector<int> out;
    int minimum = 0;
    out.push_back(0);
    repeat:;
    if(ans(cost,0,minimum,out,1))
	{
      cout  << endl;ch=1;
      

	  /* Display the order in which assignments will be completed*/

	  for(i=0;i<n;i++)
	  {
          cout << out[i]+1 << "-->";

	  }
      cout << "1";
      cout << endl;
      cout << endl;
      return 0;
    }
    else
	{
      cout <<"\n No Optimal with current minimum, Let's check for next minimum"<<endl;
      minimum = find_next(cost,minimum);
      goto repeat;
    }

  }
  else
  {
    int min =99999;

	for(i=0;i<n;i++)
	{

	  for(j=0;j<n;j++)
	  {

	    if(!cross[i][j])
		{

	      if(min>cost[i][j])
		  {
            min = cost[i][j];
          }
        }
      }
    }
    cout << min;

	for(i=0;i<n;i++)
	{

	  for(j=0;j<n;j++)
	  {

	    if(cross[i][j]==2)
		{
          cost[i][j] += min;
        }
        else if(cross[i][j]==0)
		{
          cost[i][j] -= min;
        }
      }
    }
  }

  cout << endl;

  if (counter < 10)
  {
    counter = counter+1;
    cout <<"\nIntermediate Matrix: "<<endl;

    for(i=0;i<n;i++)
	{

      for(j=0;j<n;j++)
        cout << cost[i][j] << " ";
        cout <<endl;
    }
  }
  else
  {
    cout <<"\nOptimal solution to given problem is not possible" << endl;
    return 0;
  }
  goto loop;
  if(ch==0)
  {
  	cout<<"May be you have wrongly entered the matrix,do you want to retry";
  	cout<<"Enter 1, if you want to retry :";
  	cin>>retry;

  }


  }while(retry==1);
}
