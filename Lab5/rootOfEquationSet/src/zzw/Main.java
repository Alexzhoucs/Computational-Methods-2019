package zzw;

public class Main
{
	//private final String inputFileName = "input.txt";
	public static void main(String args[])
	{
		final String inputFileName = "input.txt";
		final String outputFileName = "output.csv";

		equationSet eqs = new equationSet();
		eqs.inputFromFile(inputFileName);
		eqs.jacobi(outputFileName);



	}
}
