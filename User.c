#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct user{
    char name[10];    // 姓名
    char sex[10];         // 性别
    char tel[11];	       // 电话
    int integral;	        // 积分
    int arr_id;              //  id池
};

struct user users[30];	// 定义结构体的数组
int id=0;   //  用户id

int main()
{
    int a;                     //  主菜单选项
    int i;                     //  for循环中变量声明
    char n[10];        //  积分管理输入姓名
    int num;             //  要修改的积分数值
    int uid;               //  用户要操作的id

    while(1)
    {
        printf("======欢迎进入会员管理理系统======\n");
        printf("------主菜单------\n");
        printf("1. 查看所有会员\n");
        printf("2. 查看单个会员\n");
        printf("3. 新增会员\n");
        printf("4. 修改会员\n");
        printf("5. 删除会员\n");
        printf("6. 积分管理\n");
        printf("0. 退出\n"); 
        printf("请输入你的选项：");
        scanf("%d",&a);

        switch(a)
        {
            case 0:
                exit(0); 
                break;
            case 1:
                printf("-----所有会员-----\n");
                for(i=0; i<id; i++)
                {
                    if (users[i].arr_id != 0) {
                         printf("id:%d    姓名:%s     性别:%s   电话:%s     积分:%d\n",users[i].arr_id, users[i].name, users[i].sex, users[i].tel, users[i].integral);
                    }  
                }
                break;
            case 2:
                printf("----单个会员-----\n");
                printf("请输入你要查找会员的id:\n");
                scanf("%d",&uid);
                for(i=0;i<id;i++)
                {
                    if(uid==users[i].arr_id){
                        printf("id:%d    姓名:%s   性别 :%s     电话:%s     积分:%d\n",users[i].arr_id, users[i].name, users[i].sex, users[i].tel, users[i].integral);
                    }
                }
                break;
            case 3:
                if(id>30){
                    printf("会员有限，请等待...\n");
                    break;
                }
                users[id].arr_id = id+1;
                printf("-----新增会员-----\n");
                printf("请输入姓名: ");
                scanf("%s", users[id].name);
                printf("请输入性别: ");
                scanf("%s", users[id].sex);
                printf("请输入电话: ");
                scanf("%s", users[id].tel);
                printf("请输入积分: ");
                scanf("%d", &users[id].integral);
                printf("注册成功！\n请牢记你的id：%d\n",id+1);
                id++;
                break;
            case 4:
                printf("-----修改会员-----\n");
                printf("请输入要修改会员的id:\n");
                scanf("%d",&uid);
                for(i=0;i<id;i++)
                {
                    if(uid==users[i].arr_id){
                        printf("该会员原姓名为: %s\n", users[i].name);
                        printf("请输入修改姓名:");
                        scanf("%s",users[i].name);
                        printf("该会员原性别为: %s\n", users[i].sex);
                        printf("请输入修改性别: ");
                        scanf("%s", users[i].sex);
                        printf("该会员原电话为: %s\n", users[i].tel);
                        printf("请输入修改电话: ");
                        scanf("%s", users[i].tel);
                        printf("修改成功!\n");
                    }
                }
                break;
            case 5:
                printf("-----删除会员-----\n");
                printf("请输入要删除会员的id:\n");
                scanf("%d",&uid);
                for(i=0;i<id;i++)
                {
                    if(uid==users[i].arr_id){
                        for (int j = i ;j < id;j++) {
                             users[j]=users[j+1];
                        }
                    }
                }
                printf("删除成功!\n");
                break;
            case 6:
                printf("-----积分管理-----\n");
                printf("请输入会员id: ");
                scanf("%d", &uid);
                for ( i = 0; i < id; i++)
                {
                    if(uid==users[i].arr_id){
                        printf("该账户原有积分为: %d\n", users[i].integral);
                        printf("请输入修改数值: ");
                        scanf("%d",& users[i].integral);
                        printf("更改成功!\n");
                    }
                } 
                break;
            default:
                printf("你输入的指令有错，请重新输入\n");
                break;
        }
    }
}

extern int Main_age()
{
    printf("======欢迎进入会员管理理系统======\n");
    printf("------主菜单------\n");
    printf("1. 查看所有会员\n");
    printf("2. 查看单个会员\n");
    printf("3. 新增会员\n");
    printf("4. 修改会员\n");
    printf("5. 删除会员\n");
    printf("6. 积分管理\n");
    printf("0. 退出\n"); 
    printf("请输入你的选项：");
    return 0;
}