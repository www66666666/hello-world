#include <stdio.h>
#include <stdlib.h>



typedef struct {
    char *name;    // 姓名
    int age;             // 年龄
    int sex;   // 性别
    int tel;	       // 电话
    int integral;	   // 积分
    int arr_id;         //  id
} User;


User add_user(){
    User u;
    u.name = malloc(sizeof(char));
    printf("请输入姓名:\n");
    scanf("%s",u.name);
    printf("请输入年龄:\n");
    scanf("%d",&u.age);
    printf("请输入性别(1男2女):\n");
    scanf("%d",&u.sex);
    printf("请输入电话:\n");
    scanf("%d",&u.tel);
    printf("请输入积分:\n");
    scanf("%d",&u.integral);
    return u;
}


int main(){

    int id = 0; //用户id
    int uid; //用户输入id
    int a;  //菜单选项
    User  users[30];
    User b;

    while (1)
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
                for(int i=0; i<id; i++)
                {
                    if (users[i].arr_id != 0) {
                         printf("id:%d    姓名:%s     性别:%d   电话:%d     积分:%d\n",users[i].arr_id, users[i].name,users[i].sex,users[i].tel, users[i].integral);
                    }  
                }
                break;
            case 2:
                
                printf("----单个会员-----\n");
                printf("请输入你要查找会员的id:\n");
                scanf("%d",&uid);
                for(int i=0;i<id;i++)
                {
                    if(uid==users[i].arr_id){
                        printf("id:%d    姓名:%s   性别 :%d     电话:%d     积分:%d\n",users[i].arr_id, users[i].name,users[i].sex,users[i].tel, users[i].integral);
                    }
                }
                break;
            case 3:
                if(id>30){
                    printf("会员有限，请等待...\n");
                    break;
                }
                users[id].arr_id = id+1;
                b = add_user();
                users[id].arr_id = id+1;
                users[id].name = b.name;
                users[id].age = b.age;
                users[id].sex = b.sex;
                users[id].tel = b.tel;
                users[id].integral = b.integral;
                printf("注册成功！\n请牢记你的id：%d\n",id+1);
                id++;
                break;
            case 4:
                printf("-----修改会员-----\n");
                printf("请输入要修改会员的id:\n");
                scanf("%d",&uid);
                for(int i=0;i<id;i++)
                {
                    if(uid==users[i].arr_id){
                        printf("该会员原姓名为: %s\n", users[i].name);
                        printf("请输入修改姓名:");
                        scanf("%s",users[i].name);
                        printf("该会员原电话为: %d\n", users[i].tel);
                        printf("请输入修改电话: ");
                        scanf("%d", &users[i].tel);
                        printf("修改成功!\n");
                    }
                }
                break;
            case 5:
                printf("-----删除会员-----\n");
                printf("请输入要删除会员的id:\n");
                scanf("%d",&uid);
                for(int i=0;i<id;i++)
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
                for (int  i = 0; i < id; i++)
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
