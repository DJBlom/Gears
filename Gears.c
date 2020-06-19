#include <stdio.h>



int gcd(int n, int m);

int main(void)
{
	int t;

	do
	{
		printf("Input number of Gear Teeth:> ");
		scanf("%d", &t);
	}
	while (t < 5);

	int i, tr, p, hcf, rem, newR, newT, newTH, sum, max, min, remi,sumi, reme, sumu, newP, holeN, Hover;
	int pN[] = {15, 17, 18, 19, 20, 21, 23, 24, 27, 29, 31, 33, 37, 39, 41, 43, 47, 49};

	p = 40;
	tr = p / t;
	rem = p - t;
	hcf = gcd(p, t);
	newR = rem / hcf;
	newT = t / hcf;
	newP = p / hcf;


	for (i = 0; i <= 17; i++)
	{
		if (pN[i] % newT == 0)
		{
			if (t <= p && p % t != 0)
			{
				sum = t * tr;
				max = (sum < p) ? p : sum;
				min = (sum < p) ? sum : p;
				remi = max - min;
				sumi = (remi < hcf) ? hcf : remi;
				reme = (remi < hcf) ? remi : hcf;
				sumu = sumi / reme;


				if (tr >= 2)
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * sumu;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);
					break;
				}
				else if (tr == 1)
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * newR;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);	
					break;
				}
				else
				{
					holeN = pN[i];
					newTH = pN[i] / newT;
					Hover = newTH * sumi;
					printf("Amount of Turns = %d\n", tr);
					printf("Amount of spaces to move over = %d\n", Hover);
					printf("Hole number = %d\n", holeN);	
					break;
				}
			}
			else if (p % t == 0)
			{
				holeN = pN[i];
				printf("Amount of Turns = %d\n", tr);
				printf("Hole number = %d\n", holeN);
				break;
			}
			else if (t >= p)
			{
				holeN = pN[i];
				newTH = pN[i] / newT;
				Hover = newTH * newP;
				printf("Amount of Turns = %d\n", tr);
				printf("Amount of spaces to move over = %d\n", Hover);
				printf("Hole number = %d\n", holeN);
				break;
			}
			else
			{
				printf("NO MATCH\n");
				break;
			}
		}
	}

	return 0;
}

int gcd(int n, int m)
{
	if (m == 0)
	{
		return n;
	}
	else
	{
		return gcd(m, n % m);
	}
}
