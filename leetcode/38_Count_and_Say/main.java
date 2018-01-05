public class main {
	
	public static void main(String[] args) { 
		
		int n=9;
		String output=countAndSay(n);
		System.out.println(output);
	}
	
	public static String countAndSay(int n) {
        if (n==1)
        	return "1";
        String str;
        int i,j=0;
        
        str="11";
        
        if (n==2)
        	return str;
        
        for (i=2;i<n;i++)
    	{
        	int targetCurr=0;
        	String temp="";
        	String tempC;
        	for(int stri=0;stri<str.length();)
    		{
        		int calculateC=stri;
        		char curr=str.charAt(stri);
        		int count=0;
        		
        		for(j=stri;j<str.length();j++)
    			{
        			if (curr==str.charAt(j))
    				{
    					stri++;
    					count++;
    				}
    				else
    					break;	
    			}
        		tempC=Integer.toString(count);
        		temp=temp+tempC;
        		temp=temp+str.charAt(calculateC);
    		}
        	str=temp;
    	}
        return str;
    }
}
