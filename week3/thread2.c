#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun_1(void *arg)
{
    pthread_t id ;
    int * ptr=(int *)arg;
int size =*ptr;
for (int i=0;i<size;i++)
printf("The argument recieved =%d \n",*(++ptr));
    id=pthread_self();
    printf("This is a thread function1: and my id =%ld\n", id);
    return 0;
}


int main()
{
    pthread_t id1, id2, id3;
    int x[10];
printf("enter the elemnts :\n");
for (int i=0;i<5;i++)
{
scanf("%d",&x[i]);

}
    id2 = pthread_self(); // obtain the main thread id
    printf("Main thread:id=%ld\n", id2);

    /*
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                       void *(*start_routine)(void *), void *arg);

    argument-1: pthread_t *thread : location for storing thread id
    argument-2: const pthread_attr_t *attr : thread attribute address:
                // NULL -- OS will allocate default attributes
    argument-3: void *(*start_routine)(void *): function pointer,
                pass the address of thread function
    argument-4: void *arg : argument to the thread function
    */

    // Create new thread
    pthread_create(&id1, NULL, &thread_fun_1, (void *)&x); // thread 1
    

    printf("The thread id=%ld \n", id1);
    

    sleep(4);

    return 0;
}
