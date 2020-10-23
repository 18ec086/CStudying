#include <stdio.h>
#include <math.h>
#define element 100
int range(int str[]) {// measure the range of array
	int p=0;
	while (str[p++]!=-1);
	return p - 1;
}
double avg(int str[]) {//calculate the array
	int a = range(str);
	int  sum = 0;
	for (int i = 0;i < a;i++) {
		sum += str[i];
	}
	return (double)sum / a;
}
void sort(int str[]) {//Sort the array
	int i = 0, j, tmp, a = range(str), b = a / 2;
	for (i = 0;i < a;i++) {
		for (j = i + 1;j < a;j++) {
			if (str[j] < str[i]) {
				tmp = str[j];
				str[j] = str[i];
				str[i] = tmp;
			}
		}
	}
}
void prtstr(int str[]) {//print element of array
	int i;
	for (i = 0;i < range(str);i++) {
		printf("%d\n",str[i]);
	}
}
double median(int str[]) {//calculate median of the array
	int a = range(str), b = a / 2;
	if (a % 2 == 1) return str[b + 1];
	else
	{
		return (str[b] + str[b + 1]) / 2;
	}
}

double variance(int str[]) {//calculate variance
	int a = range(str),i;
	double b = avg(str),sum=0;
	for (i = 0;i < a;i++) {
		sum += pow((str[i]-b),2);
	}
	return sum / a;
}
int mode(int str[]) {//calculate mode of the array
	int i = 0,j, a=range(str),p = 0, q=0,r;
	for (i = 0;i < a;i++) {
		for (j = 0;j < a;j++) {
			if (str[j] == str[i])p++;
		}
		if (p >= q)r = str[i];
	}
	return r;

}


int main() {
	int data[element];//an array to store data of whole number
	int i=0,j,a;
	do {
		scanf_s("%d",&data[i]);
		i++;
	} while (data[i-1] != -1);
	sort(data);
	printf("平均値は%lf\n",avg(data));
	printf("中央値は%lf\n", median(data));
	printf("最頻値は%d\n",mode(data));
	printf("分散は%lf\n",variance(data));
	printf("標準偏差は%lf\n",sqrt(variance(data)));
	
	

}
