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
	
	
}
