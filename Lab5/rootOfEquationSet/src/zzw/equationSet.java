package zzw;

import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

public class equationSet
{
	private double[][] A;
	private double[] b;
	private long order = 0;

	void inputFromFile(String fileName)
	{
		//final String fileName = "input.txt";
		System.out.println("请将输入文件 " + fileName + " 放入运行根目录中。");
		System.out.println("\n开始从文件中读取数据");

		File file = new File(fileName);

		try
		{
			Scanner sc = new Scanner(file);
			String bString = sc.nextLine();
			String numbers[] = bString.split("\\s");
			order = numbers.length;

			b = new double[(int)order];
			for (int i = 0; i < order; i++)
				b[i] = Double.valueOf(numbers[i]);

			A = new double[(int)order][(int)order];
			for (int i = 0; i < order; i++)
			{
				String lineString = sc.nextLine();
				numbers = lineString.split("\\s");
				for (int j = 0; j < order; j++)
					A[i][j] = Double.valueOf(numbers[j]);
			}

		} catch (FileNotFoundException e)
		{
			System.out.println("ERROR in method inputFromFile: 无法找到输入文件");
			//return;
		} catch (NullPointerException e)
		{
			e.printStackTrace();
		}

		System.out.println("文件读取成功！");
	}


}
