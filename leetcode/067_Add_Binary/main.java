public class main {
	
	public static void main(String[] args) { 
		
		String a="1010";
		String b="1011";
		String output=addBinary(a,b);
		System.out.println(output);
	}
	
	public static String addBinary(String a, String b) {
		int ac=0;
		String longStr=null;
		String shortStr=null;
		String returnStr="";
		String tempStr=""; 
		int longLen=0;
		int shortLen=0;
		
		if(a.length()>=b.length())
		{
			longStr=a;
			shortStr=b;
			longLen=a.length();
			shortLen=b.length();
		}
		else
		{
			longStr=b;
			shortStr=a;
			longLen=b.length();
			shortLen=a.length();
		}
		
		for (int i=longLen,j=shortLen;i>0 || j>0; i--, j--)
		{
			char temp;
			if(j>0)
				temp=(char)((int)(longStr.charAt(i-1))+(int)(shortStr.charAt(j-1))+ac);
			else
				temp=(char)((int)(longStr.charAt(i-1))+48+ac);

			if (temp=='`'){
				tempStr+='0';
				ac=0;	
			}else if (temp=='a'){
				tempStr+='1';
				ac=0;	
			}else if (temp=='b'){
				tempStr+='0';
				ac=1;	
			}else if (temp=='c'){
				tempStr+='1';
				ac=1;	
			}
		}
		
		if(ac==1){
			tempStr+="1";
		}
		
		for(int i=tempStr.length()-1;i>=0;i--)
		{
			returnStr+=tempStr.charAt(i);
		}

		return returnStr;
    }
}
