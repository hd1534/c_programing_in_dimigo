#include<stdio.h>

struct Hero{
    char name[20];
    char job[20];
    char weapon[20];
    int health;
}b = {"an","s��sdfsd��ffsdf��ȭ��","��sdf��",10000};

int main()
{
    struct Hero a = {"ȫ��","�ΰ���ȭ��","�ܼ�",10000};
    printf("name : %s\njob : %s\nweapon : %s\nhealth : %d\n",a.name,a.job,a.weapon,a.health);
    a = b;
    printf("name : %s\njob : %s\nweapon : %s\nhealth : %d\n",a.name,a.job,a.weapon,a.health);
    return 0;
}
