package my_functions;

import java.util.*;
import java.util.function.IntUnaryOperator;


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
	
	//Find the minimal positive integer not occurring in a given sequence.
	static public int MissingInteger(int[] A)
	{
		 int max = A.length;
		    int threshold = 1;
		    boolean[] bitmap = new boolean[max + 1];

		    //populate bitmap and also find highest positive int in input list.
		    for (int i = 0; i < A.length; i++) {
		        if (A[i] > 0 && A[i] <= max) {
		            bitmap[A[i]] = true;
		        }

		        if (A[i] > threshold) {
		            threshold = A[i];
		        }
		    }

		    //find the first positive number in bitmap that is false.
		    for (int i = 1; i < bitmap.length; i++) {
		        if (!bitmap[i]) {
		            return i;
		        }
		    }

		    //this is to handle the case when input array is not missing any element.
		    return (threshold+1);
		
		
		
	}

	//Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
	static public int[] MaxCounters(int N, int[] A)
	{
		int [] temp=new int[N];
		int max=0;
		for (int i=0;i<A.length;i++)
		{
			if(1<=A[i] && A[i]<=N)
			{
				temp[A[i]-1]++;
				if(max<temp[A[i]-1])
					max=temp[A[i]-1];
			}
			else 
			{
				Arrays.fill(temp, max);
			}
		}
		return temp;
	}

	//Compute number of integers divisible by k in range [a..b].
	static public int CountDiv(int A, int B, int K)
	{
		int min=0, max=0;
		
		min=(int)Math.ceil((double)A/(double)K);
		max=(int)Math.floor(B/K);
		
		return (max-min)+1;
	}

	//Count the number of passing cars on the road.
	static public int PassingCars(int[] A)
	{
		int count=0; //to east
		int passing=0;
		
		for(int i=0;i<A.length;i++)
		{
			if(A[i]==1)
			{
				//ask how many 0 have you saw before [i]
				passing+=count;
				if(passing > 1e9) return -1;
			}
			else
			{
				//to east +1
				count++;
			}
		}
		 return passing;
	}
	
	// Compute number of distinct values in an array.
	static public int Distinct(int[] A)
	{
		Arrays.sort(A);
		int dup=0;
		
		for(int i=1;i<A.length;i++)
		{
			if(A[i]==A[i-1])
				dup++;
		}
		return A.length-dup;
	}


}
