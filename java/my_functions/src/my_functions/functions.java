package my_functions;

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
}
