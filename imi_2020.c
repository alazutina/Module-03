#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//main
int main() {
//input

int flag;    
int n; // количество итераций 
int m; //mem
int s, k_param=100, t1=1;
int k1;
int i,j,k, i_max, j_max;
int index_x, index_y,light_x, light_y, i_min,j_min;

double p1, q1, q2, q12, pq12, r; //val.prob
double T, T_max, T_min;
double p_rand;
int im;

double  max_x[100];//так как  на прямой x=-1 мы имеем m+1 поглощающих состояний  y=-1, 0, …, m, 
double  max_y[100];// так как на прямой y=-1 мы имеем m+2 поглощающих состояний  x=-1, 0, …, m+1,
double  max_x_y[100];// так как  на прямой x+y=m+1 мы имеем m поглощающих состояний  y=m, …, 0.

double  max_x2[100];//так как  на прямой x=-1 мы имеем m+1 поглощающих состояний  y=-1, 0, …, m, 
double  max_y2[100];// так как на прямой y=-1 мы имеем m+2 поглощающих состояний  x=-1, 0, …, m+1,
double  max_x_y2[100];

double x0;
double y0;

printf("\n p1 = "); 
scanf("%lf", &p1);
printf("\n q1 = ");
scanf("%lf", &q1);
printf("\n q2 = ");
scanf("%lf", &q2);
printf("\n q12 = ");
scanf("%lf", &q12);
printf("\n pq12 = ");
scanf("%lf", &pq12);

r = 1- p1-q1-q2-q12-pq12;


printf(" \n p1 = %lf, q1= %lf, q2 = %lf, q12 = %lf, pq12= %lf, r = %lf \n", p1, q1, q2, q12, pq12, r);



for(k1=1;k1<=1;k1++){
     for(m=21;m<=51;m=m+5){
 
        

printf("\n m = %i",m-1); //size of m scanf("%i", &m);


T_max=0; 
 
i_max=0;
j_max=0;

n=10000000; //
 
 lsrand(time(NULL)); 
for(j=0;j<m;j++){ // i - размер x
    
    for(i=0;i<m;i++){ // j - размер y

        

 
   if((i+j)<m){     
  //  T_min=0;    
     //         printf(" \n i = %i, j= %i \n", i, j);
    
    //Обнуление массивов для вычисления числа попаданий в поглощающие состояния
for(im=0;im<=m;im++)max_x_y[im]=0;
for(im=0;im<=m+1;im++)max_x[im]=0;
for(im=0;im<=m+1;im++)max_y[im]=0;


//Обнуление массивов для вычисления стоимостей перераспределения памяти при выходе из состояния x0,y0 
for(im=0;im<=m;im++)max_x_y2[im]=0;
for(im=0;im<=m+1;im++)max_x2[im]=0;
for(im=0;im<=m+1;im++)max_y2[im]=0;

//1. На прямой x=-1 мы имеем m+2 поглощающих состояний  y= -1, 0, …, m,   Да верно!
//  то есть точки (-1, -1),  (-1,0).…, ( -1, m).

for(im=0;im<m+1;im++){//if((light_x)=-1 
    if(light_y>im) max_y2[im]=(light_y-im)*k_param*t1; else
max_y2[im]=light_y*t1+(im-light_y)*k_param*t1;
}
//2. На прямой y=-1 мы имеем m+3 поглощающих состояний  x=-1, 0, …, m+1, Да верно!
// то есть точки (-1, -1),  (0, -1).…, ( m+1, -1).

for(im=0;im<m+1;im++)//if(light_y)=-1 
    if(light_x>im) max_x2[im]=(light_x-im)*k_param*t1+im*t1; else
max_x2[im]=light_x*t1+(im -light_x)*k_param*t1;


//3. На прямой x+y=m+1 мы имеем m+1 поглощающих состояний для y=0, …, m,  Да верно!
// то есть точки (0, m+1),  (1,m).…, (m,1).

for(im=0;im<m;im++){if( (light_x+light_y) >im) max_x_y2[im]= (light_x+light_y-im)*k_param*t1+im*t1; 
    else max_x_y2[im]=(light_x+light_y)*t1+(im -light_x-light_y)*k_param*t1;
}

        for(k=1;k<n+1;k++){ // k - итераций
            
           
 	       
light_x=i;
light_y=j;

flag=1;
x0=i;
y0=j;


while(flag==1){
          
p_rand=randoom(); //rand()%s;

if(p_rand<p1){ // p1
   light_x=light_x+1;
   if((light_x+light_y)>m){flag = 0; max_x_y[light_y]++;}
            }else{
    if(p_rand<(p1+q1)){//q1
       light_x=light_x-1;
       if(light_x<0) {flag=0; max_y[light_y+1]++; }//printf("1 Y! y[%i] = %f ", light_y+1,  max_y[light_y+1]);}// printf(" Y! %f ", max_y[light_y]);}
    }else{
        if(p_rand<(p1+q1+q2)){ //q2
            light_y=light_y-1;
            if(light_y<0) {flag=0;max_x[light_x]++;}
                 }else{
            if(p_rand<(p1+q1+q2+q12)){//q12
                light_x=light_x-1;
                light_y=light_y-1;
             

            if((light_y<0) & (light_x<0)){flag=0; max_y[0]++; }// printf(" Y[000] ");}
            else {if((light_x<0) & (light_y>=0)){flag=0; max_y[light_y+1]++;}// printf("2 Y! y[%i] = %f ", light_y+1,  max_y[light_y+1]);}//}//printf(" Y ");}
           else{if((light_y<0) & (light_x>=0)) {flag=0;max_x[light_x]++;}}
         
           }
            }
            else{
                if(p_rand<(p1+q1+q2+q12+pq12)){//pq12
                    
                 
                      light_x=light_x+1;
                      light_y=light_y-1;
              
            if(light_y<0){ flag=0;max_x[light_x]++;}
        

            }
            
        }
    }
}

} 


}//while
        
   
    } //k



T=0;

for(im=0;im<m+1;im++) T = T + max_x[im]*max_x2[im];
//printf("\n 1 T = %lf, ", T );
for(im=0;im<m+1;im++)T = T + max_y[im]*max_y2[im];
//printf("\n 2 T = %lf, ", T );
for(im=0;im<m;im++)T = T + max_x_y[im]*max_x_y2[im];


T=T/n;
if((j==0) && (i==0)){T_min=T; i_min=i;  j_min=j;//printf("\n T: %4.2lf, i= %i, j= %i", T, i,j);
    
}
  
    
  if(T<T_min){T_min=T;
        i_min=i;
        j_min=j;
        
    }
       }//if
    
}//j

} //i
   // }

printf("\n  T_min: %4.2lf, x= %i, y= %i", T_min, i_min,j_min);
    }
 }

}

//}
