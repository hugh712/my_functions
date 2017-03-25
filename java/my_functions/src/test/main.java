package test;
import my_functions.functions;


public class main {
	
	public static void main(String[] args) { 
		int input[]={2,1,1,2,3,1};
		int output;
		output=functions.Distinct(input);
	
		//functions.printArr(output);
		System.out.println(output);
	}
}
