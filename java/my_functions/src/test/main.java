package test;
import my_functions.functions;

public class main {
	
	public static void main(String[] args) { 
		int input[]={3,4,4,6,1,4,4};
		int output[];
		output=functions.MaxCounters(5,input);
	
		functions.printArr(output);
		//System.out.println(output);
	}
}
