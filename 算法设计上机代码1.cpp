#include<stdio.h>
#include<math.h>
int sort(int a[],int size){
	if(size == 0)
	return 0;
	for(int i = 0;i<size;i++)
	    for(int j=i+1;j<size;j++)
		{
		if(a[j]<a[i]){
			int temp = a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		}
return 0;
}
int merge(int r[],int left,int mid,int right,int *extra){
	int i,j,k;
	i=left;        //第一部分开始的位置
	j=mid + 1;     //第二部分开始的位置
	k=0;
	while(i<= mid && j <= right)
	    if(r[i]<r[j]){
	    	extra[k]=r[i];
			k++;
			i++;
		}
		else
		{
			extra[k]=r[j];
			k++;
			j++;
		}
	while(i<=mid)
	    extra[k++]=r[i++];
	while(j<=right)
	    extra[k++]=r[j++];
return 0;
}
int merge_sort(int a[],int first,int last){
	int size = last - first;
	int* tfirst;
	int q = (int)sqrt(size);
	if(size>3){
		int q_first;
		int q_last;
		for(int i=0;i<q;i++){
			q_first = first + i*q;
			q_last = q_first + q;
			merge_sort(a,q_first,q_last);
		}
		merge_sort(a,q_last,last);
	}
	else
	{
		tfirst = a + first;
		sort(tfirst,size);
	}

	return q;
}
int main(){
	int a[11];
	int i;
	int b[10];
	printf("请输10个数\n");
	for(i=1;i<=10;i++)
	    scanf("%d",&a[i]);
	int q = merge_sort(a,1,11);
	for(i=1;i<3;i++){
	    merge(a,1,q*i,q*i+q,b);
	    for(int j = 1;j<=q*i+q;j++)
	    a[j] = b[j-1];
	}
	merge(a,1,q*i,10,b);
	    printf("排序后的顺序是\n");
	for(i=0;i<=9;i++)
	    printf("%3d",b[i]);
		printf("\n");
		return 0; 
}

