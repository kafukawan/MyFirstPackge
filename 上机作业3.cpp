#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
    return *(int *)a-*(int *)b;
} 
int main(){
    int n;//序列数
    scanf("%d",&n);
    int p[n],p1[n];
    int times=0;

    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        p1[i]=p[i];
    } 
    
    for(int i=0;i<n-1;i++){
        qsort(p,n,sizeof(int),cmp1);
        p[0]=p[0]+p[1];
        times+=p[0]-1;
        p[1]=100000;
    } 
    printf("最少次数：%d\n",times);
    
    times=0;
    return 0;
}