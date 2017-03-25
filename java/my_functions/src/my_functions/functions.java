package my_functions;

import java.util.*;


public class functions {

	// transfer integer to binary string
	static public String int2Binary (int n)
	{
		String binary = "";
		
		if(n==0)
			return "0";
		
		while(n!=0)
		{
			switch (n%2)
			{
				case 0:
					binary = "0"+binary;break;
				case 1:
					binary = "1"+binary;break;
			}
			n/=2;	
		}//end of while
		
		return binary;
	}
	
	// find out the Longest Binary Gap
	// Dependency
	// int2Binary
	static public int BinaryGap(int n)
	{
		String b_string=int2Binary(n);
		int max = 0, count = 0, head=0, tail=1;
		
		while(tail < b_string.length())
		{
			
			
			if (b_string.substring(head, head+1).equals(b_string.substring(tail, tail+1)))
			{
				if(count>0)
				{
					head=tail-1;
					
					if (count>max)
						max=count;
					
					count=0;
				}
				else
				{
					head+=1;
					tail=head+1;
				}
			}
			else
			{
				count+=1;
				tail=tail+1;
			}
		}
		return max;
	}
	
	static public void printArr(int [] A)
	{
		for(int i=0;i<A.length;i++)
		{
			System.out.print(A[i] +"  ");
		}
		System.out.println("");
	}
	
	//find the Odd Occurrences In Array
	static public int OddOccurrencesInArray(int [] A)
	{
		Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		int max=0;
		
		for(int i=0;i<A.length;i++)
		{

			if(map.get(A[i])==null)
			{
				map.put(A[i], A[i]);
				max=max+A[i];
			}
			else
			{
				map.put(A[i], null);
				max=max-A[i];
			}
		}
		
		return max;
	}
	
	//shift right the array A K times 
	static public int[] CyclicRotation(int[] A, int K)
	{
		int arrLeng=A.length;
		if(arrLeng==0 || arrLeng==1 || K==0)
			return A; 
				
		int[] temp=new int[arrLeng];
		
		K=K%arrLeng;
		
		for(int i=0;i<arrLeng;i++)
		{
			if((i+K)>(arrLeng-1))
			{
				temp[K-(arrLeng-i)]=A[i];
			}
			else
			{
				temp[i+K]=A[i];
			}
		}
		return temp;
	}
	
	//count minimal number of jumps from position X to Y.
	static public int FrogJmp(int X, int Y, int D)
	{
		if (X==Y)
			return 0;
		
		return (Y-X)%D==0?(Y-X)/D:((Y-X)/D)+1;
	}
	
	//Find the missing element in a given permutation
	static public int PermMissingElem(int A[])
	{
		
		if (A.length==0)
			return 1;
		
		if(A.length==1)
			return A[0];
			
		
		int sum=0;
		int max=0;
		
		for(int i=0;i<A.length;i++)
		{
			if (max<A[i])
				max=A[i];
			sum+=A[i];
		}
		
		
		return (max*(max+1)/2)-sum;
	}
	
	//Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|
	static public int TapeEquilibrium(int[] A)
	{
		int sum1=0;
		int sum2=Arrays.stream(A).sum();
		int minDiff=Integer.MAX_VALUE;
		
		for (int i=0;i<A.length;i++)
		{
			int diff=0;
			sum1+=A[i];
			sum2-=A[i];
			
			diff=Math.abs(sum1-sum2);
			minDiff=Math.min(diff, minDiff);
		}
		return minDiff;
	}
	
	//Check whether array A is a permutation
	static public int PermCheck(int[] A)
	{
		int[] counter = new int [A.length];
		 
        for(int i= 0; i< A.length; i++){
            if (A[i] < 1 || A[i] > A.length) {
                // Out of range
                return 0;
            }
            else if(counter[A[i]-1] == 1) {
                // met before
                return 0;
            }
            else {
                // first time meet
                counter[A[i]-1] = 1;
            }
        }
        return 1;
	}
	
	//Fine the earliest time when a frog can jump to the other side of a river
	static public int FrogRiverOne(int X, int[] A)
	{
		int [] temp=new int[X];
		
		for (int i=0;i<A.length;i++)
		{
			if(temp[A[i]-1]!=A[i])
			{
				temp[A[i]-1]=A[i];
				X--;
			}
			
			if (X==0)
				return i;
		}
		return -1;
		
		
		
	}
	
}
