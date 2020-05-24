#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class set
{
    int *ar;
    int size;
    public:
    set()
    {
        size=10;
        ar=new int[size];
    }
    void input();
    void display();
    void cardinality();
    void powerset();
};

void set::input()
{
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	ar=new int[size];
	cout<<"Enter the array elements"<<endl;
	for(int i=0;i<size;i++)
	cin>>ar[i];
}

void set::display()
{
    cout<<"The given set is {";
    for(int i=0;i<size;i++)
    {
        if(i == 0)
            cout<<ar[i];
        else 
            cout<<"," <<ar[i];
    }
    cout<<"}"<<endl;
}

void set::cardinality()
{
	cout<<"The cardinality of given set is "<<size<<endl;
}



void set::powerset()
{
    int count,temp;
    count=pow(2,size);
    cout<<"{ {},";
    for(int i=1;i<count;i++)
    {
        temp=i;
        cout<<"{";
        for(int j=0;j<size;j++)
        {
            if(temp&1)
            cout<<ar[j]<<",";
            temp=temp>>1;
        }
        cout<<"\b}";
    }
	cout<<" }";
}
int factorial(int n)
{
	if(n==1)
	return 1;
	else
	return n*factorial(n-1);
}

                  
int main()
{
	int v;
	cout<<"Enter 1 to get cardinality and power set of a set and 2 for recursive clculation of C(n,r) and P(n,r): "<<endl;
	cin>>v;
	switch(v)
	{
	case 1:	
		{
		int ch;
	
		set a;
		a.input();
		a.display();
		a.cardinality();
		    cout<<"Enter your choice"<<endl;
	        cout<<"1.Power set"<<endl<<"2.Exit"<<endl;
	        cin>>ch;
			switch(ch)
			{
				case 1: a.powerset();
					    break;
					    
				case 2:exit(0);
				
				default:cout<<"wrong choice!!..";
						break;
			}
	     
	  
	    break;}
	
	case 2:
		{
		int n, r;
	cout<<"\n Enter value of n: ";
	cin>>n;
	cout<<"\n Enter value of r: ";
	cin>>r;
	cout<<"\n Number of Permutations(nPr): "<<factorial(n)/(double)factorial(n-r);
	cout<<"\n Number of Combinations(nCr): "<<(double)factorial(n)/(factorial(n- r)*factorial(r));
	break;}
}
    return 0;
}
