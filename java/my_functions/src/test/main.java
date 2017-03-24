package test;
import my_functions.functions;

public class main {
	
	public static void main(String[] args) { 
		int input[]={9,3,9,3,9,7,9,8,7,66,66,8,55,4,4,6,6,55,22};
		int output=0;
		output=functions.OddOccurrencesInArray(input);
	
		System.out.println(output);
	}
}
