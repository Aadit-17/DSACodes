#include <stdio.h>
#include <stdlib.h>

struct patient
{
    int hospital_number;
    char patient_name[50];
    int age;
    int token;
    int height;
    int weight;
    char reason[100];
};

void swap(struct patient *a, struct patient *b)
{
    struct patient temp = *a;
    *a = *b;
    *b = temp;
}

int helperFun(struct patient *a, int l, int h)
{
    int p = a[h].token;
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j].token <= p)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i + 1);
}

void quick_sort(struct patient *patients, int l, int h)
{
    if (l < h)
    {
        int p = helperFun(patients, l, h);
        quick_sort(patients, l, p - 1);
        quick_sort(patients, p + 1, h);
    }
}


void display(struct patient *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %d %d %d %s\n", p[i].hospital_number, p[i].patient_name, p[i].age, p[i].token, p[i].height, p[i].weight, p[i].reason);
    }
}


int main()
{
    int n;
    printf("Enter number of patients : ");
    scanf("%d", &n);
    struct patient p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of patient number %d: \n", i + 1);
        printf("Hospital number: ");
        scanf("%d", &p[i].hospital_number);
        printf("Patient name: ");
        scanf("%s", p[i].patient_name);
        printf("Age: ");
        scanf("%d", &p[i].age);
        printf("Token number: ");
        scanf("%d", &p[i].token);
        printf("Height: ");
        scanf("%d", &p[i].height);
        printf("Weight: ");
        scanf("%d", &p[i].weight);
        printf("Reason(Disease): ");
        scanf("%s", p[i].reason);
    }
    quick_sort(p, 0, n - 1);
    printf("Sorted order based on token number is\n");
    display(p, n);
    return 0;
}
