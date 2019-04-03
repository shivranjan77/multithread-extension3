#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *avg(void *str);
void *min(void *ptr);
void *max(void *ptr);
double average;        
int minimum;
int maximum;
typedef struct datastruct
{
    int size;
    int * values;
}datastruct;

void main(int z, char *w[])
{
printf("\n To Execute the Program For desired Output As per question write on terminal ./a.out 90 81 78 95 79 72 85\n");
    
int i = 0;    
int copy[z-1];
for(i; i < (z -1); i++)
    {
        copy[i] = atoi(w[i+1]);
    }
    pthread_t thread1, thread2, thread3;
    int  t1, t2, t3; 
    datastruct ds = {z - 1, copy};
    t1 = pthread_create(&thread1, NULL, (void *) avg, (void *) &ds);
    t2 = pthread_create(&thread2, NULL, (void *) min, (void *) &ds);
    t3 = pthread_create(&thread3, NULL, (void *) max, (void *) &ds);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    printf("The average:  %g\n", average);
    printf("The minimum:  %d\n", minimum);
    printf("The maximum:  %d\n", maximum);
}
 
void *avg(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;
    
    int sz= copy->size;
    int i;
    
    for(i = 0; i < sz; i++)
    {
        average += (copy->values[i]);    
    }                           
    average = (int)(average / sz); 
}
void *min(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;
    
    int sz = copy->size;
    int i;
    
    minimum = (copy->values[0]);
    for(i = 1; i < sz; i++)
    {
        if(minimum > (copy->values[i]))
        {
            minimum = (copy->values[i]);
        }
    }
}

