#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

clock_t start[2], end[2];
int v=-1,n=-1,num;
float ar1[3];
double loops,loop;

/*
   start[++v]=clock();               // clock time note in start array
   end[++n] = clock();               // clock time note in end array
*/
//  SeqRB() - sequential read operation perform for 1 B block size

void* SeqRB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    start[++v]=clock();
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<10000;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    fread(buff, 1, 1, fptr);
    loops++;
    } 
    fclose(fptr); 
    end[++n]=clock();
    return 0;   
}

//  SeqRKB() - sequential read operation perform for 1 KB block size

void* SeqRKB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    start[++v]=clock();
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<10000;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    fread(buff, 1, 1024, fptr);
    loops++; 
    }
    fclose(fptr); 
    end[++n] = clock();
    return 0;   
}

//  SeqRMB() - sequential read operation perform for 1 MB block size

void* SeqRMB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    start[++v]=clock();    
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<100;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    fread(buff, 1, 1024 * 1024, fptr); 
    loop++;
    }
    fclose(fptr); 
    end[++n]=clock();
    return 0;   
}

//  RndmRB() - Random read operation perform for 1 B block size

void* RndmRB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    int r;
    start[++v]=clock();
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<10000;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    r= rand()%100;
    fseek(fptr, r, SEEK_SET);
    fread(buff, 1, 1, fptr); 
    loops++; 
    }
    fclose(fptr); 
    end[++n]=clock();
    return 0;     
}

//  RndmRKB() - Random read operation perform for 1 KB block size

void* RndmRKB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    int r;
    start[++v]=clock();
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<10000;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    r= rand()%100;
    fseek(fptr, r, SEEK_SET);
    fread(buff, 1, 1024, fptr); 
    loops++; 
    }
    fclose(fptr); 
    end[++n]=clock();
    return 0;     
 }

//  RndmRMB() - Random read operation perform for 1 MB block size

void* RndmRMB(void* a)
{
    int i;
    FILE *fptr;
    char *buff;
    long filelen;
    int r;
    start[++v]=clock();
    fptr = fopen("diskread.txt", "rb"); 
    for(i=0;i<100;i++)
    {
    fseek(fptr, 0, SEEK_END);          
    filelen = ftell(fptr);             
    rewind(fptr);                      
    buff = (char *)malloc((filelen+1)*sizeof(char)); 
    r= rand()%100;
    fseek(fptr, r, SEEK_SET);
    fread(buff, 1, 1024 * 1024, fptr); 
    loop++; 
    }
    fclose(fptr); 
    end[++n]=clock();
    return 0;     
}


//  SeqWB() - sequential write operation perform for 1 B block size

void* SeqWB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fwrite(buff, 1, 1, fptr);
   end[++n]=clock();
   return 0;
}


//  SeqWKB() - sequential write operation perform for 1 KB block size

void* SeqWKB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fwrite(buff, 1, 1024, fptr);
    end[++n]=clock();
   return 0;
}

//  SeqWMB() - sequential write operation perform for 1 MB block size

void* SeqWMB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
   for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fwrite(buff, 1, 1024 * 1024, fptr);
    end[++n]=clock();
   return 0;
}


//  RndmWB() - Random write operation perform for 1 B block size

void* RndmWB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
      for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fseek(fptr,rand()%100,SEEK_SET);
   fwrite(buff, 1, 1, fptr);
    end[++n]=clock();
   return 0;  
}

//  RndmWKB() - Random write operation perform for 1 KB block size

void* RndmWKB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
      for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fseek(fptr,rand()%100,SEEK_SET);
   fwrite(buff, 1, 1024, fptr);
    end[++n]=clock();
   return 0;   
}

//  RndmWMB() - Random write operation perform for 1 MB block size

void* RndmWMB(void* a)
{
   FILE *fptr;
   char * buff;
    start[++v]=clock();
   int length = 1024 * 1024 * 30,i;
   buff = (char *)malloc (length * sizeof (char));
      for(i=0;i<31457280;i++)
   {
    buff[i]= 'a';
   }
   fptr = fopen("diskwrite.txt", "w");
   fseek(fptr,rand()%100,SEEK_SET);
   fwrite(buff, 1, 1024 * 1024, fptr);
    end[++n]=clock();
   return 0;    
}

int main()
{
        int select;
	double l,l1,t,t1,th,th1,lavg,thavg;
        pthread_t thread1,thread2;
		printf("1.Read Sequential 1B 1 thread\n2. Read Sequential 1KB 1 thread\n3. Read Sequential 1MB 1 thread \n 4. Read Sequential 1B 2 threads\n 5. Read Sequential 1KB 2 threads\n 6. Read Sequential 1MB 2 threads \n 7. Read Random 1B 1 thread \n 8. Read Random 1KB 1 thread \n 9. Read Random 1MB 1 thread \n 10. Read Random 1B 2 threads\n 11. Read Random 1KB 2 threads\n 12. Read Random 1MB 2 thread\n13. Write Sequential 1B 1 thread\n14. Write Sequential 1KB 1 thread\n15. Write Sequential 1MB 1 thread \n 16. Write Sequential 1B 2 threads\n 17. Write Sequential 1KB 2 threads\n 18. Write Sequential 1MB 2 threads \n 19. Write Random 1B 1 thread \n 20. Write Random 1KB 1 thread \n 21. Write Random 1MB 1 threadClose \n 22. Write Random 1B 2 threads\n 23. Write Random 1KB 2 threads\n 24. Write Random 1MB 2 thread\n 25. Close\n");
		printf("Enter your Choice: ");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
		pthread_create(&thread1,NULL,&SeqRB,NULL);
		pthread_join(thread1,NULL);
		t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;        // difference of end time and start time
		printf("t%f",t);
   		l=(t/loops)*1000;
   		th=((loops*loops*1)/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 2:
		pthread_create(&thread1,NULL,&SeqRKB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
		printf("t%f",t);
   		l=(t/(loops*1024))*1000;
   		th=((loops*loops)/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
                case 3:
		pthread_create(&thread1,NULL,&SeqRMB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
		printf("t%f",t);
   		l=(t/(loop*1024*1024))*1000;
   		th=((loop*loop)/(t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 4:
   		pthread_create(&thread1,NULL,&SeqRB,NULL);
		pthread_create(&thread2,NULL,&SeqRB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		printf("\nStart time 1: %f\tStart time 2: %f\n",(float)start[0]/1000,(float)start[1]/1000);
                printf("End time 1: %f\tEnd time 2: %f\n",(float)end[0]/1000,(float)end[1]/1000);
		t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
 		l=(t/loops)*1000;
   		th=((loops*loops*2)/(1024*1024*t));
		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 5:
		pthread_create(&thread1,NULL,&SeqRKB,NULL);
		pthread_create(&thread2,NULL,&SeqRKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
                t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
    		l=(t/(loops*1024))*1000;
   		th=((loops*loops*2)/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 6:
		pthread_create(&thread1,NULL,&SeqRMB,NULL);
		pthread_create(&thread2,NULL,&SeqRMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
   		t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
                l=(t/(loop*1024*1024))*1000;
   		th=((loop*loop*2)/(t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 7:
		pthread_create(&thread1,NULL,&RndmRB,NULL);
		pthread_join(thread1,NULL);
		t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/loops)*1000;
   		th=((loops*loops*1)/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 8:
		pthread_create(&thread1,NULL,&RndmRKB,NULL);
		pthread_join(thread1,NULL);
		t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/(loops*1024))*1000;
   		th=((loops*loops)/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 9:
		pthread_create(&thread1,NULL,&RndmRMB,NULL);
		pthread_join(thread1,NULL);
		t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/(loop*1024*1024))*1000;
   		th=((loop*loop)/(t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 10:
		pthread_create(&thread1,NULL,&RndmRB,NULL);
		pthread_create(&thread2,NULL,&RndmRB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		printf("\nStart time 1: %f\tStart time 2: %f\n",(float)start[0]/1000,(float)start[1]/1000);
                printf("End time 1: %f\tEnd time 2: %f\n",(float)end[0]/1000,(float)end[1]/1000);
 	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
              	l=(t/loops)*1000;
   		th=((loops*loops*2)/(1024*1024*t));
		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 11:
		pthread_create(&thread1,NULL,&RndmRKB,NULL);
		pthread_create(&thread2,NULL,&RndmRKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
                t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
    		l=(t/(loops*1024))*1000;
   		th=((loops*loops*2)/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
                break;
		case 12:
		pthread_create(&thread1,NULL,&RndmRMB,NULL);
		pthread_create(&thread2,NULL,&RndmRMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
       	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
     		l=(t/(loop*1024*1024))*1000;
   		th=((loop*loop*2)/(t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 13:
		pthread_create(&thread1,NULL,&SeqWB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/1)*1000;
   		th=(1/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 14:
		pthread_create(&thread1,NULL,&SeqWKB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/1024)*1000;
   		th=(1/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
                case 15:
		pthread_create(&thread1,NULL,&SeqWMB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/(1024*1024))*1000;
   		th=(1/t);
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 16:
		pthread_create(&thread1,NULL,&SeqWB,NULL);
		pthread_create(&thread2,NULL,&SeqWB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
     		l=(t/1)*1000;
   		th=(1*2/(1024*1024*t));
		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 17:
		pthread_create(&thread1,NULL,&SeqWKB,NULL);
		pthread_create(&thread2,NULL,&SeqWKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
         	l=(t/1024)*1000;
   		th=(1*2/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 18:
		pthread_create(&thread1,NULL,&SeqWMB,NULL);
		pthread_create(&thread2,NULL,&SeqWMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
         	l=(t/(1024*1024))*1000;
   		th=(1*2/t);
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
   		break;
		case 19:
		pthread_create(&thread1,NULL,&RndmWB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/1)*1000;
   		th=(1/(1024*1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 20:
		pthread_create(&thread1,NULL,&RndmWKB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/1024)*1000;
   		th=(1/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 21:
		pthread_create(&thread1,NULL,&RndmWMB,NULL);
		pthread_join(thread1,NULL);
                t=(double)(end[0] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
   		l=(t/(1024*1024))*1000;
   		th=(1/t);
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 22:
		pthread_create(&thread1,NULL,&RndmWB,NULL);
		pthread_create(&thread2,NULL,&RndmWB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
    	        l=(t/1)*1000;
   		th=((1*2)/(1024*1024*t));
		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
		break;
		case 23:
		pthread_create(&thread1,NULL,&RndmWKB,NULL);
		pthread_create(&thread2,NULL,&RndmWKB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
                l=(t/1024)*1000;
   		th=((1*2)/(1024*t));
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
                break;
		case 24:
		pthread_create(&thread1,NULL,&RndmWMB,NULL);
		pthread_create(&thread2,NULL,&RndmWMB,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        t=(double)(end[1] - start[0]) / CLOCKS_PER_SEC;       // difference of end time and start time
     		l=(t/(1024*1024))*1000;
   		th=((1*2)/t);
   		printf("Latency: %f\n", l );
   		printf("Throughput: %f\n",th);
   		break;
		case 25:
		exit(0);
		break;
		}
}	



