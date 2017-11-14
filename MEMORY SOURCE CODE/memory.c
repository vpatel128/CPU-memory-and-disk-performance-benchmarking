#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

float ar1[3];
int v=-1;

/*
   start=clock();               // clock time note in start variable
   end = clock();               // clock time note in end variable
*/
//  SeqRWB() - sequential read write operation perform for 1 B block size

void* SeqRWB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   memcpy(dest, src, 1);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;       // difference of end time and start time
   return 0;
}

//  SeqRWKB() - sequential read write operation perform for 1 KB block size

void* SeqRWKB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   memcpy(dest, src, 1024);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;      // difference of end time and start time
   return 0;
}

//  SeqRWMB() - sequential read write operation perform for 1 MB block size

void* SeqRWMB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   memcpy(dest, src, 1024 * 1024);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;         // difference of end time and start time
   return 0;
}

//  RndmRWB() - Random read write operation perform for 1 B block size

void* RndmRWB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int **src1, **dest1;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   src1=&src;
   dest1=&dest;
   *src1= *src1+rand()%100;
   *dest1= *dest1+rand()%100;
   memcpy(*dest1, *src1, 1);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;        // difference of end time and start time
   return 0;
}

//  RndmRWKB() - Random read write operation perform for 1 KB block size

void* RndmRWKB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int **src1, **dest1;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   src1=&src;
   dest1=&dest;
   *src1= *src1+rand()%100;
   *dest1= *dest1+rand()%100;
   memcpy(*dest1, *src1, 1024);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;       // difference of end time and start time
   return 0;
}

//  RndmRWMB() - Random read write operation perform for 1 MB block size

void* RndmRWMB(void* a)
{
   clock_t start, end;
   char * src, * dest;
   int **src1, **dest1;
   int length = 1024 * 1024 * 30,i;
   start = clock();
   src = (char *)malloc (length * sizeof (char));
   dest = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    src[i]= 'a';
   }
   src1=&src;
   dest1=&dest;
   *src1= *src1+rand()%100;
   *dest1= *dest1+rand()%100;
   memcpy(*dest1, *src1, 1024 * 1024);
   end = clock();
   ar1[++v]=(double)(end - start) / CLOCKS_PER_SEC ;       // difference of end time and start time
   return 0;
}

int main()
{
        int select;
        float l,l1,t,t1,th,th1,lavg,thavg;
	pthread_t thread1,thread2;
		printf("1.Sequential 1B 1 thread\n2.Sequential 1KB 1 thread\n3.Sequential 1MB 1 thread \n 4. Sequential 1B 2 threads\n 5. Sequential 1KB 2 threads\n 6.Sequential 1MB 2 threads \n 7.Random 1B 1 thread \n 8.Random 1KB 1 thread \n 9. Random 1MB 1 threadClose \n 10. Random 1B 2 threads\n 11. Random 1KB 2 threads\n 12. Random 1MB 2 thread\n 13. Close");
	printf("Enter your Choice: ");
	scanf("%d",&select);
	switch(select)
	{
		case 1:
		pthread_create(&thread1,NULL,&SeqRWB,NULL);      // create 1 thread and call SeqRWB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
   		l=(t/1)*1000;                                             // calculate latency and throughput    
   		th=(1/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 2:
		pthread_create(&thread1,NULL,&SeqRWKB,NULL);         // create 1 thread and call SeqRWKB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
		l=(t/1024)*1000;                                             // calculate latency and throughput    
   		th=(1/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
                case 3:
		pthread_create(&thread1,NULL,&SeqRWMB,NULL);          // create 1 thread and call SeqRWMB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
   		l=(t/(1024*1024))*1000;                                             // calculate latency and throughput    
   		th=(1/t);
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 4:
		pthread_create(&thread1,NULL,&SeqRWB,NULL);          // create 2 threads and call SeqRWB
		pthread_create(&thread2,NULL,&SeqRWB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
   		l=(t/1)*1000;
   		th=(1/(1024*1024*t));
   		l1=(t1/1)*1000;
   		th1=(1/(1024*1024*t1));
   		lavg=(l+l1)/2;                                             // calculate latency and throughput    
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
		break;
		case 5:
		pthread_create(&thread1,NULL,&SeqRWKB,NULL);          // create 2 threads and call SeqRWKB
		pthread_create(&thread2,NULL,&SeqRWKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
    		l=(t/1024)*1000;
		l1=(t1/1024)*1000;
   		th=(1/(1024*t));
		th1=(1/(1024*t1));
		lavg=(l+l1)/2;                                             // calculate latency and throughput    
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
		break;
		case 6:
		pthread_create(&thread1,NULL,&SeqRWMB,NULL);          // create 2 threads and call SeqRWMB
		pthread_create(&thread2,NULL,&SeqRWMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
   		l=(t/(1024*1024))*1000;
   		th=(1/t);                                             // calculate latency and throughput    
		l1=(t1/(1024*1024))*1000;
   		th1=(1/t1);
		lavg=(l+l1)/2;
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
		break;
		case 7:
		pthread_create(&thread1,NULL,&RndmRWB,NULL);               // create 1 thread and call RndmRWB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
   		l=(t/1)*1000;                                             // calculate latency and throughput    
   		th=(1/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 8:
		pthread_create(&thread1,NULL,&RndmRWKB,NULL);            // create 1 thread and call RndmRWKB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
		l=(t/1024)*1000;
   		th=(1/(1024*t));                                             // calculate latency and throughput    
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 9:
		pthread_create(&thread1,NULL,&RndmRWMB,NULL);            // create 1 thread and call RndmRWMB
		pthread_join(thread1,NULL);
		t=ar1[0];
		printf("time taken for 1st thread%f",t);
   		l=(t/(1024*1024))*1000;
   		th=(1/t);                                             // calculate latency and throughput    
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 10:
		pthread_create(&thread1,NULL,&RndmRWB,NULL);           // create 2 threads and call RndmRWB
		pthread_create(&thread2,NULL,&RndmRWB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
   		l=(t/1)*1000;
   		th=(1/(1024*1024*t));
   		l1=(t1/1)*1000;
   		th1=(1/(1024*1024*t1));
   		lavg=(l+l1)/2;                                             // calculate latency and throughput    
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
		break;
		case 11:
		pthread_create(&thread1,NULL,&RndmRWKB,NULL);               // create 2 threads and call RndmRWKB
		pthread_create(&thread2,NULL,&RndmRWKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
    		l=(t/1024)*1000;
		l1=(t1/1024)*1000;
   		th=(1/(1024*t));
		th1=(1/(1024*t1));
		lavg=(l+l1)/2;                                             // calculate latency and throughput    
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
                break;
		case 12:
		pthread_create(&thread1,NULL,&RndmRWMB,NULL);              // create 2 threads and call RndmRWMB
		pthread_create(&thread2,NULL,&RndmRWMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		t=ar1[0];
		t1=ar1[1];
		printf("time taken for 1st thread%f",t);
     		printf("time taken for 2nd thread%f",t1);
   		l=(t/(1024*1024))*1000;
   		th=(1/t);
		l1=(t1/(1024*1024))*1000;                           
   		th1=(1/t1);
		lavg=(l+l1)/2;                                              // calculate latency and throughput     
		thavg=(th+th1)/2;
		printf("Latency: %f\n", lavg );
   		printf("Throughput: %f\n",thavg);
		break;
		case 13:
		exit(0);
		break;
	}
}	




