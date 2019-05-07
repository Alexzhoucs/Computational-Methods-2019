package zzw;

public class Main
{
	//private final String inputFileName = "input.txt";
	public static void main(String args[])
	{
		final String inputFileName = "input.txt";
		final String outputFileName1 = "output-Jacobi.csv";
		final String outputFileName2 = "output-GaussSeidel.csv";

		equationSet eqs = new equationSet();
		eqs.inputFromFile(inputFileName);
		eqs.jacobi(outputFileName1);
		eqs.GaussSeidel(outputFileName2);



	}
}
