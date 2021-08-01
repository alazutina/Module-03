#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mkl.h>

void inverse(double* A, int N1) {
	lapack_int *IPIV = (lapack_int *)malloc(N1 * sizeof(lapack_int));
	int LWORK = N1*N1;
	//double *WORK = (double *)malloc(LWORK * sizeof(double));
	int INFO;

	LAPACKE_dgetrf(LAPACK_ROW_MAJOR,N1,N1,A,N1,IPIV);
	LAPACKE_dgetri(LAPACK_ROW_MAJOR,N1,A,N1,IPIV);

	free(IPIV);
	//free(WORK);
}

int main(){
    
int m;

int x_1_, x_2_, y_1_, y_2_,m1_max,m2_max;
 
 double T12_max,t111,t222;

double p1,q1,q2,q12,pq12,r;
int i,j,m1,m2;
FILE* fp;

double p1_1, q1_1, q2_1, q12_1, pq12_1, r_1; //val.prob
double p1_2, q1_2, q2_2, q12_2, pq12_2, r_2; //val.prob


fp=fopen("f.out","w");



printf ("m\n");scanf ("%i", &m);


T12_max = 0.0;

p1_1=0.5;
q1_1=0.1;
q2_1=0.1;
q12_1=0.1;
pq12_1=0.1;
r_1 = 1- p1_1-q1_1-q2_1-q12_1-pq12_1;


p1_2=0.5;
q1_2=0.1;
q2_2=0.1;
q12_2=0.1;
pq12_2=0.1;
r_2 = 1- p1_2-q1_2-q2_2-q12_2-pq12_2;


printf(" \n p1_1 = %lf, q1_1= %lf, q2_1 = %lf, q12_1 = %lf, pq12_1= %lf, r_1 = %lf \n", p1_1, q1_1, q2_1, q12_1, pq12_1, r_1);

printf(" \n p1_2 = %lf, q1_2= %lf, q2_2 = %lf, q12_2 = %lf, pq12_2= %lf, r_2 = %lf \n", p1_2, q1_2, q2_2, q12_2, pq12_2,r_2);


int s_1,s_2; //кол-во состояний

   double A1 [200*200];
    double *A;
    
      double  B1 [200*200];
 double *B;

for(m1=0;m1<=m;m1++){

    m2 = m-m1;
    
s_1=(m1+1)*(m1+2)/2;
s_2=(m2+1)*(m2+2)/2;

   A = new double [s_1*s_1];
   B = new double [s_2*s_2];

    
    for (i=0; i<s_1; i++) {
        for (j=0; j<s_1; j++) {
            A1[i*s_1+j]=0;
            if (i==j) A1[i*s_1+j]=r_1;
        }
        
    }
    
        for (i=0; i<s_2; i++) {
        for (j=0; j<s_2; j++) {
            B1[i*s_2+j]=0;
            if (i==j) B1[i*s_2+j]=r_2;
        }
        
    }

      int s1,s2;
      s1=m1;
      s2=m1;
      
  for (i=0; i<s_1; i++) {
    
          if(i== (s1)) { 
              A1[i*s_1+i+1]=0.0;
              A1[(i+1)*s_1+i]=0.0;
              A1[(i+s2)*s_1+i]=0.0; 
               A1[(i+s2+1)*s_1+i-1]=0.0; 
              s1=s1+s2;
             s2--;
        }
          
            else{
                A1[i*s_1+i+1]=p1_1;
                
                A1[(i+1+s2)*s_1+i]=q2_1;
                
                A1[(i+1+s2)*s_1+i+1]=pq12_1;
                
                A1[(i+1+s2+1)*s_1+i]=q12_1;
                
                A1[(i+1)*s_1+i]=q1_1;
        }
        
      }


      s1=m2;
      s2=m2;
    
      for (i=0; i<s_2; i++) {
    
          if(i== (s1)) { 
               B1[i*s_2+i+1]=0.0;
              B1[(i+1)*s_2+i]=0.0;
              B1[(i+s2)*s_2+i]=0.0; 
               B1[(i+s2+1)*s_2+i-1]=0.0; 
              s1=s1+s2;
             s2--;

        }
          
            else{
                B1[i*s_2+i+1]=p1_2;                
                B1[(i+1+s2)*s_2+i]=q2_2;
                B1[(i+1+s2)*s_2+i+1]=pq12_2;
                B1[(i+1+s2+1)*s_2+i]=q12_2;
                B1[(i+1)*s_2+i]=q1_2;
        }
        
      }
  
     
  
     
     for (i=0; i<s_1; i++) {
      for (j=0; j<s_1; j++) {
          A[i*s_1+j]=A1[i*s_1+j];
    fprintf(fp," %f ", A[i*s_1+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }
   
   
        
     for (i=0; i<s_2; i++) {
      for (j=0; j<s_2; j++) {
          B[i*s_2+j]=B1[i*s_2+j];
    fprintf(fp," %f ", B[i*s_2+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }

    for (i=0; i<s_1; i++) {
        for (j=0; j<s_1; j++) {
          if(i==j){ A[i*s_1+j]=1-A[i*s_1+j];}
           else{A[i*s_1+j]=0-A[i*s_1+j];}
             
        }

    }
    
        for (i=0; i<s_2; i++) {
        for (j=0; j<s_2; j++) {
          if(i==j){ B[i*s_2+j]=1-B[i*s_2+j];}
           else{B[i*s_2+j]=0-B[i*s_2+j];}

        }

    }
    
fprintf(fp,"\n");
fprintf(fp,"\n");


inverse(A, s_1);
     
        inverse(B, s_2);

    double t1, t1_max;
    t1=0;
    t1_max=0;
    int i1_max, j1_max;
    i1_max=0;
    j1_max=0;
 
   for (i=0; i<s_1; i++) {
    t1=0;
        for (j=0; j<s_1; j++) {
            
            t1=t1+A[i*s_1+j];
            
         
        }
        if (i==m1+2){  
        }
        
    if(t1>t1_max){t1_max = t1;
         i1_max = i;
   
    }  
   
    
   }
    
  

    
    i=0;
    s1=m1+1;
    int flag;
    flag=1;
    i1_max=i1_max+1;
     
   
    
    
    do{
        
    if(i1_max>s1){   i1_max = i1_max - s1;
                    i++ ;
                    s1--;
        
        
    } else { j = i1_max-1;
        flag=0;
    }
    }
    
    
    while(flag==1);
   
    
    int x1, y1;
    
    x1 = j;
    y1=i;
 
     double t2, t2_max;
    t2=0;
    t2_max=0;
    int i2_max, j2_max;
    i2_max=0;
    j2_max=0;
    
   for (i=0; i<s_2; i++) {
    t2=0;
        for (j=0; j<s_2; j++) {
            
            t2=t2+B[i*s_2+j];
            
         
        }
        if (i==m2+2){  
            
        }
        
    if(t2>t2_max){t2_max = t2;
         i2_max = i;
   
    }  
    
   }


    
    i=0;
    s2=m2+1;
    int flag1;
    flag1=1;
    i2_max=i2_max+1;

    
    do{
        
    if(i2_max>s2){   i2_max = i2_max - s2;
                    i++ ;
                    s2--;
        
        
    } else { j = i2_max-1;
        flag1=0;
    }
    }
    
    
    while(flag1==1);
   
    
     int x2, y2;
    
    x2 = j;
    y2=i;

    
    
if(T12_max < (t1_max+t2_max) ){ T12_max = t1_max + t2_max;
    t111=t1_max;
    t222=t2_max;
    x_1_=x1;
    y_1_=y1;
    
   x_2_=x2;
    y_2_=y2;
    
    m1_max =m1;
    m2_max =m-m1;
}       
   
   delete A;
   delete B;
    
}

printf("m = %i tmax = %f t1 =%f m1=%i x1=%i, y1=%i  t2=%f m2= %i x2=%i, y2=%i\n",m, T12_max, t111, m1_max, x_1_, y_1_, t222, m2_max, x_2_, y_2_);
return 0;

}
