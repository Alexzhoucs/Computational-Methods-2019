package zzw;

import java.io.PrintWriter;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.text.DecimalFormat;

public class equationSet
{
	private double[][] A;
	private double[] b;
	private int order = 0;

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

			b = new double[order];
			for (int i = 0; i < order; i++)
				b[i] = Double.valueOf(numbers[i]);

			A = new double[order][order];
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

	void jacobi(String outputFileName)
	{
		DecimalFormat df = new DecimalFormat("0.############E0");			//输出数据格式化

		double[] x = new double[order];
		for (int i = 0; i < order; i++)
			x[i] = 0;

		double difference = 1;                    //定义一个大于停止条件的初值
		int steps = 0;
		StringBuffer resultSB = new StringBuffer("");
		resultSB.append("Jacobi:");
		resultSB.append(",");
		for (int i = 1; i <= order; i++)
			resultSB.append("X" + i +',');
		resultSB.append("difference");
		resultSB.append("\n");

		resultSB.append("k = " + steps + ",");
		for (int i = 0; i < order; i++)
			resultSB.append(x[i] + ",");
		resultSB.append("\n");


//---------------------------------------------算法主体

		while (difference > 1e-5)
		{
			steps++;
			double[] newX = new double[order];                //自动清0

			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < order; j++)
				{
					if (j == i) continue;
					newX[i] += A[i][j] * x[j];
				}
				newX[i] -= b[i];
				newX[i] = newX[i] / A[i][i] * (-1);
			}

			resultSB.append("k = " + steps + ",");					//输出分步数据
			for (int i = 0; i < order; i++)
				resultSB.append(df.format(newX[i]) + ",");

			for(int i = 0;i <order;i++)
				x[i] = Math.abs(x[i] - newX[i]);
			difference = x[0];
			for(int i = 1;i < order;i++)
				if(x[i] > difference)
					difference = x[i];

			resultSB.append(df.format(difference));
			resultSB.append("\n");

			System.arraycopy(newX,0,x,0,order);
		}

		System.out.println(resultSB.toString());

		File outputFile = new File(outputFileName);
		try (PrintWriter out = new PrintWriter(outputFile))
		{
			out.print(resultSB.toString());
		} catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
	}


}
