#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//double p_rand;

// k

//------------------------------------------------------------------
unsigned long long r_next = 1;

/*
 *  int rand()
 *      Taken from the K&R C programming language book. Page 46.
 *      returns a pseudo-random integer of 0..32767. Note that
 *      this is compatible with the System V function rand(), not
 *      with the bsd function rand() that returns 0..(2**31)-1.
 */
unsigned long int lrand ()
{
	r_next = r_next * 1103515245ULL + 12345ULL;
	return ((unsigned int)(r_next / 4294967296ULL) % 2147483648ULL);
}

/*
 *  srand(seed)
 *      companion routine to rand(). Initializes the seed.
 */
void
lsrand(unsigned long int seed)
{
	r_next = seed;
}
//------------------------------------------------------------------




double randoom() {
	double zz=lrand();
	double ww=zz/2147483648ULL;
	return ww;
}

struct T_i_j {
    double T_max;
    int i_max;
    int j_max;
};

struct T_i_j time1(int mn, double p1_n, double q1_n, double q2_n,double q12_n, double pq12_n, double r_n){
  double T, Tn_max;
  int i, j , k, k1, n; 
  int index_x, index_y, light_x, light_y;
  int flag;
  double p_rand;
  int i_max_n,       j_max_n=j;
  Tn_max = 0.0;
  n = 750000;
  k1=1;
  
  lsrand(time(NULL)); 

  for(i=0;i<=mn;i++){ // i - размер x
    //  printf(" \n i = %i", i);
    
    for(j=0;j<=mn;j++){ // j - размер y
   if((i+j)<=mn){     
    T=0;    
        
        
        for(k=1;k<n+1;k++){ // k - итераций
            
         //    printf(" \n i = %i, j= %i , k = %i\n", i, j, k);
 	       
//index_x=i+j;
//index_y=0;
light_x=i;
light_y=j;
flag=1;

while(flag==1){
        
p_rand=randoom(); //rand()%s;


if(p_rand<p1_n){ // p1

    light_x=light_x+1;

    
    if((light_x+light_y)>mn) flag = 0;
    else T=T+1;
}else{
    if(p_rand<(p1_n+q1_n)){//q1

        light_x=light_x-1;
    
    
    
        
        if(light_x<0) flag=0;
        else         T=T+1;
    }else{
        if(p_rand<(p1_n+q1_n+q2_n)){ //q2
           
          
           
            light_y=light_y-k1;
                 
    
            if(light_y<0) flag=0;
           else             T=T+1;
        }else{
            if(p_rand<(p1_n+q1_n+q2_n+q12_n)){//q12
                
             
      
                light_x=light_x-1;
                
            
                light_y=light_y-k1;
                    
              

            if(light_x<0) flag=0;
           else{                if(light_y<0) flag=0;
           else T=T+1;
           }
               

                
            }
            else{
                if(p_rand<(p1_n+q1_n+q2_n+q12_n+pq12_n)){//pq12
                    
   
                light_x=light_x+1;
      
                light_y=light_y-k1;
          
    
                  
                
            if(light_y<0){ flag=0;}
           else{
               T=T+1;
                    
                       }}
            else{ //r
                T=T+1;
             
    

            }
            
        }
    }
}


    
    
} 





}//while
    T++;    
   
    } //k
    T=T/n; //среднее для данного i,j - для таких длин x,y

  
    
    if(T>Tn_max){Tn_max=T;
        i_max_n=i;
       j_max_n=j;
        
    } 

   }//if
    
}//j

} //i

struct T_i_j b;
b.T_max = Tn_max;
b.i_max=i_max_n;
b.j_max = j_max_n;
 return b;   
}

//}

//main
int main() {
//input

//int flag; //int n; // количество итераций 
int m,m1,m2,m1_max,m2_max; //mem
int s; //int k1;//int  i_max_n, j_max_n; //, i_max_2, j_max_2;

int i1,i2,j1, j2;

double p1_1, q1_1, q2_1, q12_1, pq12_1, r_1; //val.prob
double p1_2, q1_2, q2_2, q12_2, pq12_2, r_2; //val.prob
double T_max, T12;//Tn_max, T12;// T1_max, T2_max, T12;

double T2_opti,T1_opti,T1[41],T2[41];
int i1_1[41],j1_1[41],i2_1[41],j2_1[41],m1_1[41],m2_1[41];


printf ("p1_1\n");
scanf ("%lf", &p1_1);
printf ("q1_1\n");
scanf ("%lf", &q1_1);
printf ("q2_1\n");
scanf ("%lf", &q2_1);
printf ("q12_1\n");
scanf ("%lf", &q12_1);
printf ("pq12_1\n");
scanf ("%lf", &pq12_1);
r_1 = 1-p1_1-q1_1-q2_1-q12_1-pq12_1;


printf ("p1_2\n");
scanf ("%lf", &p1_2);

printf ("q1_2\n");
scanf ("%lf", &q1_2);
printf ("q2_2\n");
scanf ("%lf", &q2_2);
printf ("q12_2\n");
scanf ("%lf", &q12_2);
printf ("pq12_2\n");
scanf ("%lf", &pq12_2);
r_2 = 1-p1_2-q1_2-q2_2-q12_2-pq12_2;

printf(" \n p1_1 = %lf, q1_1= %lf, q2_1 = %lf, q12_1 = %lf, pq12_1= %lf, r_1 = %lf \n", p1_1, q1_1, q2_1, q12_1, pq12_1, r_1);

printf(" \n p1_2 = %lf, q1_2= %lf, q2_2 = %lf, q12_2 = %lf, pq12_2= %lf, r_2 = %lf \n", p1_2, q1_2, q2_2, q12_2, pq12_2,r_2);


T_max=0.0;

    for(m=40;m>0;m=m-5){
        
       T_max=0.0; 

printf("\n\n\n m = %i",m); //size of m scanf("%i", &m);

struct T_i_j a,c;

for(m1=0;m1<=m;m1++){


    m2 = m-m1;
    

    
a = time1 (m1, p1_1, q1_1, q2_1, q12_1, pq12_1, r_1);



T1[m1]=a.T_max;
i1_1[m1]=a.i_max;
j1_1[m1]=a.j_max;
m1_1[m1]=m1;






c = time1 (m2, p1_2, q1_2, q2_2, q12_2, pq12_2, r_2);

T2[m1]=c.T_max;

i2_1[m1]=c.i_max;
j2_1[m1]=c.j_max;
m2_1[m1]=m2;

T12=a.T_max+c.T_max;



if(T_max< T12){T_max = T12; 
m1_max=m1;
m2_max=m2;
i1= a.i_max; //i_max_1;          a.i_max,a.j_max
i2= c.i_max;//i_max_2;   
j1=a.j_max;//j_max_1;
j2=c.j_max;//.._2;  
}


}


  printf("\n \n T1_max: %4.2lf, T2_max: %4.2lf, T_max: %4.2lf, m1= %i x1= %i y1= %i, m2= %i x2= %i y2= %i", T1[m1_max], T2[m1_max],T_max, m1_max,i1,j1,m2_max,i2,j2);

    T_max=0.0;
  i1=0;
  
  for(s=0;s<=m;s++){
  
      if(T1[s]>T2[s]){
          if(T2[s]>T_max){ T_max=T2[s]; i1=s;}
          
    } else {
        if(T1[s]>T_max){ T_max=T1[s]; i1=s;}
        
    }
      
}
T_max=T1[i1]+T2[i1];
 printf("\n второй критерий\n T1_max: %4.2lf, T2_max: %4.2lf, T_max: %4.2lf m1 = %i x1= %i y1= %i, m2=%i x2= %i y2= %i",T1[i1],T2[i1], T_max, m1_1[i1], i1_1[i2], j1_1[i1], m2_1[i1], i2_1[i1], j2_1[i1]);
  
  
    }
    
   

}
