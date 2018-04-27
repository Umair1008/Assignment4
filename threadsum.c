#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * add(void * arg);

int arr[1000];
int sum=0;

int main()
{
    for(int i=0; i<1000; i++)
        {
                arr[i]=i;
//                printf("%d",arr[i]);
        }

	pthread_t aThread[10];
	int size=0;
	for(int i=0; i<10; i++)
	{
		pthread_create(&aThread[i],NULL,add,(void*)&size);
		size = size +100;
	}
	for(int i=0; i<10; i++)
	{
	pthread_join(aThread[i],NULL);
	}
	printf("%d\n",sum);
//	printf("Umair");
	return 0;

}

void * add(void * arg)
{
	int* size=(int*)arg;
	int num=*size;
	for(int i=num; i<num+100; i++)
	{
		sum=sum+i;
	}

//	printf("%d\n",sum);

	return NULL;
}
