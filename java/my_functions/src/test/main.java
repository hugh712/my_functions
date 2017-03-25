package test;
import my_functions.functions;


public class main {
	
	public static void main(String[] args) { 
		int input[]={-3,1,2,-2,5,6};
		int output;
		output=functions.MaxProductOfThree(input);
	
		//functions.printArr(output);
		System.out.println(output);
	}
}
