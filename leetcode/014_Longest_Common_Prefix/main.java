public class main {
	
	public static void main(String[] args) { 
		//String []ss={"abcdefg","addghijk","abcefghd"};
		String []ss={"aa","aa"};
		String output=longestCommonPrefix(ss);
		System.out.println(output);
	}
	
	public static String longestCommonPrefix(String[] strs) {
		int point=0;
		int strsSize=0;
		int min_length=0;
		char curr=' ';
		String output;
		
		strsSize=strs.length;
		
		if (strsSize==0)
			return "";
		
		if (strsSize==1)
			return strs[0];
		
		for (int i=0; i<strsSize;i++)
		{
			if (i==0){
				min_length=strs[i].length();
				continue;
			}
			else{
				if (min_length>strs[i].length())
					min_length=strs[i].length();
			}	
		}
		
		if (min_length==0)
			return "";
		
		for(int i=0;i<min_length;i++){
			for (int j=0;j<strsSize;j++){
				if(j==0){
					curr=strs[j].charAt(i);
				}
				else{
					if(curr!=strs[j].charAt(i)){
						point=i-1;
						i=min_length;j=strsSize;break;
					}
					
				}
			}
			point++;
		}
		
		output=strs[0].substring(0, point);
		
		return output;
    }
}
