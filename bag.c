#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int t=0;
int nums=0;
int things[MAX];

int stack[MAX];
int top=0;
int count=0;

void readData(FILE* fp){
    fscanf(fp,"%d %d",&t,&nums);
    for(int i=0;i<nums;i++){
        fscanf(fp,"%d",&things[i]);
    }
}

void print(int n){
    for(int i=0;i<n;i++){
        printf("%d ",things[stack[i]]);
    }
    printf("\n");
}
void find(int i, int sum) {
    if (sum == t) {
        count++;
        print(top);
        return;
    }
    if (i >= nums) return;

    for (int k = i; k < nums; k++) {
        if ((things[k]+sum)<=t ) {
            stack[top++] = k;
            find(k + 1, sum + things[k]);
            top--;
        }
    }
}

int main(){
    int sum=0;
    int i=0;
    int mode=0;
    printf("请选择输入方式: 1.控制台 2.文件\n");
    scanf("%d",&mode);
    if(mode==2){
            FILE* fp=fopen("input.txt","r");
            if(fp==NULL){
                printf(" openfile error");
                return -1;
            }
            readData(fp);
            fclose(fp);
    }else{
        printf("请输入背包容量T和物品数量n\n接着输入每件物品的体积\n");
        readData(stdin);
    }
    find(i,sum);
    if (count == 0)
        printf("无解\n");
    else
        printf("共找到 %d 组解\n", count);
    system("pause");   // 程序停住，显示"请按任意键继续..."
    return 0;
}
