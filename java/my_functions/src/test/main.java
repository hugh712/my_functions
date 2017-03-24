package test;
import my_functions.functions;

public class main {
	
	public static void main(String[] args) { 
		int input[]={1,2,3,4,5,6,7,8,9,0};
		int [] output;
		output=functions.CyclicRotation(input,6);
	
		functions.printArr(input);
		functions.printArr(output);
		//System.out.println(output);
	}
}
