#include <stdio.h>
#include<string.h>
struct mobile
{
    char model_name[500];
    int year;
    int cam_res;
    int ram;
    int card_size;
    char operating_system[500];
};

void main()
{
    int i,j,n;
    printf("Enter number of mobiles\n");
    scanf("%d", &n);
    struct mobile t,mi[n];


    for(i=0;i<n;i++)
    {
        printf("Enter details of mobile number %d\n", i+1);
        printf("Enter model name of your mobile\n");
        scanf("%s", mi[i].model_name);
        printf("Enter year of release of your mobile\n");
        scanf("%d", &mi[i].year);
        printf("Enter camera resolution of your mobile\n");
        scanf("%d", &mi[i].cam_res);
        printf("Enter RAM size of your mobile\n");
        scanf("%d", &mi[i].ram);
        printf("Enter memory card size of your mobile\n");
        scanf("%d", &mi[i].card_size);
        printf("Enter operating system name of your mobile\n");
        scanf("%s", mi[i].operating_system);
    }

    int x=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(mi[j].ram >mi[j+1].ram)
            {
                t=mi[j];
                mi[j]=mi[j+1];
                mi[j+1]=t;
            }
        }
    }
    printf("\nSorted order based on ram size is\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%s\n",mi[i].model_name,mi[i].year,mi[i].cam_res,mi[i].ram,mi[i].card_size,mi[i].operating_system);
    }
}
