#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int t=0;
int nums=0;
int bestVal=0;
int things[MAX];
int thingsVal[MAX];

int stack[MAX];
int top=0;

int bestStack[MAX];
int bestTop=0;

int suffix[MAX+1];

void readData(FILE* fp){
    fscanf(fp,"%d %d",&t,&nums);
    for(int i=0;i<nums;i++){
        fscanf(fp,"%d",&things[i]);
    }
    for(int i=0;i<nums;i++){
        fscanf(fp,"%d",&thingsVal[i]);
    }
}

void compareVal(int n,int val){
    if(val>bestVal){
        bestVal=val;
        bestTop=0;
        for(int i=0;i<n;i++){
            bestStack[bestTop++]=stack[i];
        }
    }
}

void find(int i, int sum,int val) {
    compareVal(top,val);
    if (i >= nums) return;
    if(val+suffix[i]<=bestVal)return;

    for (int k = i; k < nums; k++) {
        if ((things[k]+sum)<=t ) {
            stack[top++] = k;
            find(k + 1, sum + things[k],val+thingsVal[k]);
            top--;
        }
    }
}

int main(){
    int sum=0;
    int val=0;
    int i=0;
    int mode=0;
    printf("请选择输入方式: 1.控制台 2.文件\n");
    scanf("%d",&mode);
    if(mode==2){
            FILE* fp=fopen("inputVal.txt","r");
            if(fp==NULL){
                printf(" openfile error");
                return -1;
            }
            readData(fp);
            fclose(fp);
    }else{
        printf("请输入背包容量T和物品数量n\n接着输入每件物品的体积\n接着输入每件物品价值\n");
        readData(stdin);
    }
    suffix[nums]=0;
    for(int i=nums-1;i>=0;i--){
        suffix[i]=suffix[i+1]+thingsVal[i];
    }
    find(i,sum,val);
    if (bestTop == 0)
        printf("无解\n");
    else{
        printf("体积为:");
        for(int i=0;i<bestTop;i++){
            printf("%d ",things[bestStack[i]]);
        }
        printf("\n");
        printf("最大价值为:%d\n",bestVal);
    }
    system("pause");   // 程序停住，显示"请按任意键继续..."
    return 0;
}
