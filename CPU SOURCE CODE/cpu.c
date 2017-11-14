#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>

clock_t start, end;

   /*
     * cpuI() - Perform Integer arithmetic operations
    */

void* cpuI(void* x)
{
   int  add,add1,add2,add3,add4,add5,add6,add7,add8,add9,add10,add11,add12,add13,add14,add15,add16,add17,add18,add19,add20,add21,add22,add23,add24,add25,add26,add27,add28,add29,mul,mul1,mul2,mul3,mul4,mul5,mul6,mul7,mul8,mul9,mul10,mul11,mul12,mul13,mul14,mul15,mul16,mul17,mul18,mul19,mul20,mul21,mul22,mul23,mul24,mul25,mul26,mul27,mul28,mul29,div,div1,div2,div3,div4,div5,div6,div7,div8,div9,div10,div11,div12,div13,div14,div15,div16,div17,div18,div19,div20,div21,div22,div23,div24,div25,div26,div27,div28,div29,sub,sub1,sub29,sub2,sub3,sub4,sub5,sub6,sub7,sub8,sub9,sub10,sub11,sub12,sub13,sub14,sub15,sub16,sub17,sub18,sub19,sub20,sub21,sub22,sub23,sub24,sub25,sub26,sub27,sub28;
   int i;
   for(i=0;i<10000000;i++)
   {
   add = 4 + 7;
   add1 = 4 + 5;
   add2 = 5 + 8;
   add3 = 5 + 8;
   add4 = 4 + 7;
   add5 = 4 + 7;
   add6 = 4 + 7;
   add7 = 4 + 7;
   add8 = 4 + 7;
   add9 = 4 + 7;
   add10 = 4 + 7;
   add11 = 4 + 7;
   add12 = 4 + 7;
   add13 = 4 + 7;
   add14 = 4 + 7;
   add15 = 4 + 7;
   add16 = 4 + 7;
   add17 = 4 + 7;
   add18 = 4 + 7;
   add19 = 4 + 7;
   add20 = 4 + 7;
   add21 = 4 + 7; 
   add22 = 4 + 7;
   add23 = 4 + 7;
   add24 = 4 + 7;
   add25 = 4 + 7;
   add26 = 4 + 7;
   add27 = 4 + 7; 
   add28 = 4 + 7;
   add29 = 4 + 7;

   sub = 8 - 5;
   sub1 = 8 - 5;
   sub2 = 8 - 5;
   sub3 = 8 - 5;
   sub4 = 8 - 5;
   sub5 = 8 - 5;
   sub6 = 8 - 5;
   sub7 = 8 - 5;
   sub8 = 8 - 5;
   sub9 = 8 - 5;
   sub10 = 8 - 5;
   sub11 = 8 - 5;
   sub12 = 8 - 5;
   sub13 = 8 - 5;
   sub14 = 8 - 5;
   sub15 = 8 - 5;
   sub16 = 8 - 5;
   sub17 = 8 - 5;
   sub18 = 8 - 5;
   sub19 = 8 - 5;
   sub20 = 8 - 5;
   sub21 = 8 - 5;
   sub22 = 8 - 5;
   sub23 = 8 - 5;
   sub24 = 8 - 5;
   sub25 = 8 - 5;
   sub26 = 8 - 5;
   sub27 = 8 - 5;
   sub28 = 8 - 5;
   sub29 = 8 - 5;

   mul = 5 * 8;
   mul1 = 5 * 8;
   mul2 = 5 * 8;
   mul3 = 5 * 8;
   mul4 = 5 * 8;
   mul5 = 5 * 8;
   mul6 = 5 * 8;
   mul7 = 5 * 8;
   mul8 = 5 * 8;
   mul9 = 5 * 8;
   mul10 = 5 * 8;
   mul11 = 5 * 8;
   mul12 = 5 * 8;
   mul13 = 5 * 8;
   mul14 = 5 * 8;
   mul15 = 5 * 8;
   mul16 = 5 * 8;
   mul17 = 5 * 8;
   mul18 = 5 * 8;
   mul19 = 5 * 8;
   mul20 = 5 * 8;
   mul21 = 5 * 8;
   mul22 = 5 * 8;
   mul23 = 5 * 8;
   mul24 = 5 * 8;
   mul25 = 5 * 8;
   mul26 = 5 * 8;
   mul27 = 5 * 8;
   mul28 = 5 * 8;
   mul29 = 5 * 8;

   div = 4 / 2;  
   div1 = 4 / 2;  
   div2 = 4 / 2; 
   div3 = 4 / 2;  
   div4 = 4 / 2;  
   div5 = 4 / 2;  
   div6 = 4 / 2;  
   div7 = 4 / 2;  
   div8 = 4 / 2;  
   div9 = 4 / 2;  
   div10 = 4 / 2;  
   div11 = 4 / 2;  
   div12 = 4 / 2;  
   div13 = 4 / 2;  
   div14 = 4 / 2;  
   div15 = 4 / 2; 
   div16 = 4 / 2;  
   div17 = 4 / 2;  
   div18 = 4 / 2;  
   div19 = 4 / 2;  
   div20 = 4 / 2; 
   div21 = 4 / 2;  
   div22 = 4 / 2;  
   div23 = 4 / 2;  
   div24 = 4 / 2;  
   div25 = 4 / 2;  
   div26 = 4 / 2;  
   div27 = 4 / 2;  
   div28 = 4 / 2;  
   div29 = 4 / 2;  
   }
   return 0;
}

    /*
     * cpuF() - Perform Floating arithmetic operations
    */

void* cpuF(void* y)
{
    float add,add1,add2,add3,add4,add5,add6,add7,add8,add9,add10,add11,add12,add13,add14,add15,add16,add17,add18,add19,add20,add21,add22,add23,add24,add25,add26,add27,add28,add29,mul,mul1,mul2,mul3,mul4,mul5,mul6,mul7,mul8,mul9,mul10,mul11,mul12,mul13,mul14,mul15,mul16,mul17,mul18,mul19,mul20,mul21,mul22,mul23,mul24,mul25,mul26,mul27,mul28,mul29,div,div1,div2,div3,div4,div5,div6,div7,div8,div9,div10,div11,div12,div13,div14,div15,div16,div17,div18,div19,div20,div21,div22,div23,div24,div25,div26,div27,div28,div29,sub,sub1,sub29,sub2,sub3,sub4,sub5,sub6,sub7,sub8,sub9,sub10,sub11,sub12,sub13,sub14,sub15,sub16,sub17,sub18,sub19,sub20,sub21,sub22,sub23,sub24,sub25,sub26,sub27,sub28;
   int i;
   for(i=0;i<10000000;i++)
   {
   add = 4.7f + 5;
   add1 = 4.7f + 5;
   add2 = 4.7f + 5;
   add3 = 4.7f + 5;
   add4 = 4.7f + 5;
   add5 = 4.7f + 5;
   add6 = 4.7f + 5;
   add7 = 4.7f + 5;
   add8 = 4.7f + 5;
   add9 = 4.7f + 5;
   add10 = 4.7f + 5;
   add11 = 4.7f + 5;
   add12 = 4.7f + 5;
   add13 = 4.7f + 5;
   add14 = 4.7f + 5;
   add15 = 4.7f + 5;
   add16 = 4.7f + 5;
   add17 = 4.7f + 5;
   add18 = 4.7f + 5;
   add19 = 4.7f + 5;
   add20 = 4.7f + 5;
   add21 = 4.7f + 5; 
   add22 = 4.7f + 5;
   add23 = 4.7f + 5;
   add24 = 4.7f + 5;
   add25 = 4.7f + 5;
   add26 = 4.7f + 5;
   add27 = 4.7f + 5; 
   add28 = 4.7f + 5;
   add29 = 4.7f + 5;

   sub = 5.8f - 4;
   sub1 = 5.8f - 4;
   sub2 = 5.8f - 4;
   sub3 = 5.8f - 4;
   sub4 = 5.8f - 4;
   sub5 = 5.8f - 4;
   sub6 = 5.8f - 4;
   sub7 = 5.8f - 4;
   sub8 = 5.8f - 4;
   sub9 = 5.8f - 4;
   sub10 = 5.8f - 4;
   sub11 = 5.8f - 4;
   sub12 = 5.8f - 4;
   sub13 = 5.8f - 4;
   sub14 = 5.8f - 4;
   sub15 = 5.8f - 4;
   sub16 = 5.8f - 4;
   sub17 = 5.8f - 4;
   sub18 = 5.8f - 4;
   sub19 = 5.8f - 4;
   sub20 = 5.8f - 4;
   sub21 = 5.8f - 4;
   sub22 = 5.8f - 4;
   sub23 = 5.8f - 4;
   sub24 = 5.8f - 4;
   sub25 = 5.8f - 4;
   sub26 = 5.8f - 4;
   sub27 = 5.8f - 4;
   sub28 = 5.8f - 4;
   sub29 = 5.8f - 4;

   mul = 4.7f * 5.8f;
   mul1 = 4.7f * 5.8f;
   mul2 = 4.7f * 5.8f;
   mul3 = 4.7f * 5.8f;
   mul4 = 4.7f * 5.8f;
   mul5 = 4.7f * 5.8f;
   mul6 = 4.7f * 5.8f;
   mul7 = 4.7f * 5.8f;
   mul8 = 4.7f * 5.8f;
   mul9 = 4.7f * 5.8f;
   mul10 = 4.7f * 5.8f;
   mul11 = 4.7f * 5.8f;
   mul12 = 4.7f * 5.8f;
   mul13 = 4.7f * 5.8f;
   mul14 = 4.7f * 5.8f;
   mul15 = 4.7f * 5.8f;
   mul16 = 4.7f * 5.8f;
   mul17 = 4.7f * 5.8f;
   mul18 = 4.7f * 5.8f;
   mul19 = 4.7f * 5.8f;
   mul20 = 4.7f * 5.8f;
   mul21 = 4.7f * 5.8f;
   mul22 = 4.7f * 5.8f;
   mul23 = 4.7f * 5.8f;
   mul24 = 4.7f * 5.8f;
   mul25 = 4.7f * 5.8f;
   mul26 = 4.7f * 5.8f;
   mul27 = 4.7f * 5.8f;
   mul28 = 4.7f * 5.8f;
   mul29 = 4.7f * 5.8f;

   div = 5.8f / 2.4f;  
   div1 = 5.8f / 2.4f;  
   div2 = 5.8f / 2.4f;  
   div3 = 5.8f / 2.4f;  
   div4 = 5.8f / 2.4f;  
   div5 = 5.8f / 2.4f;  
   div6 = 5.8f / 2.4f;  
   div7 = 5.8f / 2.4f;  
   div8 = 5.8f / 2.4f;  
   div9 = 5.8f / 2.4f;  
   div10 = 5.8f / 2.4f;  
   div11 = 5.8f / 2.4f;  
   div12 = 5.8f / 2.4f;  
   div13 = 5.8f / 2.4f;  
   div14 = 5.8f / 2.4f;  
   div15 = 5.8f / 2.4f;  
   div16 = 5.8f / 2.4f;  
   div17 = 5.8f / 2.4f;  
   div18 = 5.8f / 2.4f;  
   div19 = 5.8f / 2.4f;  
   div20 = 5.8f / 2.4f;  
   div21 = 5.8f / 2.4f;  
   div22 = 5.8f / 2.4f;  
   div23 = 5.8f / 2.4f;  
   div24 = 5.8f / 2.4f;  
   div25 = 5.8f / 2.4f;  
   div26 = 5.8f / 2.4f;  
   div27 = 5.8f / 2.4f;  
   div28 = 5.8f / 2.4f;  
   div29 = 5.8f / 2.4f;  
   }
   return 0;
}

/*
   start=clock();               // clock time note in start variable
   end = clock();               // clock time note in end variable
*/

int main()
{
        int select;
        double t,l,gIops,gFlops;
	pthread_t thread1,thread2, thread3, thread4;
	printf("1. Floating point operations 1 thread\n2. Floating point operations 2 threads\n3. Floating point operations 4 threads\n4. Integer point operations 1 thread\n 5. Integer point operations 2 threads\n 6. Integer point perations 4 threads \n 7. Close\n");
		printf("Enter your Choice: ");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
		start=clock();                                  
		pthread_create(&thread1,NULL,&cpuF,NULL);      // create 1 thread and call cpuF
		pthread_join(thread1,NULL);
		end = clock();                                 
                t= (double)(end - start) / CLOCKS_PER_SEC ;    // difference of end time and start time
		printf("t%f",t);
                gFlops=((243)/(t*100));                        // Calculate gFlops
                printf("Giga FlOPS: %f\n", gFlops);            
		break;
		case 2:
                start=clock();                                 
		pthread_create(&thread1,NULL,&cpuF,NULL);      //  create 2 threads and call cpuF 
                pthread_create(&thread2,NULL,&cpuF,NULL);       
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	        end = clock();
                t= (double)(end - start) / CLOCKS_PER_SEC ;    // difference of end time and start time
		printf("t%f",t);
                gFlops=((243*2)/(t*100));                      // Calculate gFlops
                printf("Giga FlOPS: %f\n", gFlops);
		break;
                case 3:
		start=clock();
		pthread_create(&thread1,NULL,&cpuF,NULL);      //  create 4 threads and call cpuF
		pthread_create(&thread2,NULL,&cpuF,NULL);
		pthread_create(&thread3,NULL,&cpuF,NULL);
		pthread_create(&thread4,NULL,&cpuF,NULL);
                pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		pthread_join(thread3,NULL);
		pthread_join(thread4,NULL);
		end = clock();
                t= (double)(end - start) / CLOCKS_PER_SEC ;     // difference of end time and start time
		printf("t%f",t);
                gFlops=((243*4)/(t*100));                       // Calculate gFlops
                printf("Giga FlOPS: %f\n", gFlops);
		break;
		case 4:
		start=clock();
		pthread_create(&thread1,NULL,&cpuI,NULL);       //  create 1 thread and call cpuI
		pthread_join(thread1,NULL);
		end = clock();
                t= (double)(end - start) / CLOCKS_PER_SEC ;     // difference of end time and start time
		printf("t%f",t);
                gIops=((243)/(t*100));                          // Calculate gIops
                printf("Giga IOPS: %f\n", gIops);
		break;
		case 5:
		start=clock();
		pthread_create(&thread1,NULL,&cpuI,NULL);       //  create 2 threads and call cpuI
		pthread_create(&thread2,NULL,&cpuI,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		end = clock();
                t= (double)(end - start) / CLOCKS_PER_SEC ;    // difference of end time and start time
		printf("t%f",t);
                gIops=((243*2)/(t*100));                       // Calculate gIops
                printf("Giga IOPS: %f\n", gIops);
		break;
		case 6:
		start=clock();
		pthread_create(&thread1,NULL,&cpuI,NULL);     //  create 2 threads and call cpuI
		pthread_create(&thread2,NULL,&cpuI,NULL);
		pthread_create(&thread3,NULL,&cpuI,NULL);
		pthread_create(&thread4,NULL,&cpuI,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		pthread_join(thread3,NULL);
		pthread_join(thread4,NULL);
		end = clock();
                t= (double)(end - start) / CLOCKS_PER_SEC ;   // difference of end time and start time
		printf("t%f",t);
                gIops=((243*4)/(t*100));                      // Calculate gIops
                printf("Giga IOPS: %f\n", gIops);
		case 7:
		exit(0);
		break;
		}
}	




