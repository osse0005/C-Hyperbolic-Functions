/**************************************************************************************
 Filename:          hyperbolic.c
 Version:           1.0
 Author:            Tim Osse
 Student No:        040585009
 Lab Sect:          310
 Assignment #:      1
 Assignment name:   Assignment 1 - Hyperbolic Functions
 Due Date:          October 19, 2012
 Submission Date:   October 19, 2012
 Professor:         Andrew Tyler
 Purpose:           Investigate Maclaurin series approximations to sinh(x) and
 *  cosh(x), approximate values and exact values with exact percent error and 
 * truncation error 
 **************************************************************************************/

#include <stdio.h>
#include <math.h>

double sih(void);//sinh(x) function
double coh(void);//cosh(x) function

int main (int argc, const char * argv[]){
    char response = 0;
    while(response != '3'){
        
    printf("\n**********************************\n");
        printf("\tMaclaurin Series\n");
        printf("Select the function to evaluate\n\n");
        printf("1 = sinh(x)\n");
        printf("2 = cosh(x)\n");
        printf("3 = quit\n\n");
        scanf("%c", &response);
        printf("**********************************\n");
        
        switch (response) {
            case '1':
                sih();
                break;
            case '2':
                coh();
                break;
            case '3':
                return 0;
                break;
            default:
                break;
        }    
    }//end while loop
    return 0;
}

/*****************************************************************************************
 * Function name:      sinh
 * Purpose:            Calculates a Maclaurin series approximations for sinh(x), asking
 *                     the user for the power of the highest term and a value for x. Use 
 *                     math library to get exact maclaurin series with exact error and truncated
 *                     Prints out results.
 * In parameters:      n/a
 * Out parameters:     double - result of the calculation
 * Version:            1.0
 * Author:             Tim Osse
 *****************************************************************************************/
double sih(void){
    
    int a;//series loop index
    int power = 0;//number of term in series
    double range = 0.0;//max value of x
    double inc;//increment value range / 10
    double x=0.0;//range divided by 10 incremented to range
    double series=0.0;//approximate maclaurin series
    double exactSeries=0.0;//exact maclaurin series using math lib.
    double error=0.0;//first neglected term
    double eerror=0.0;//exact error
    double eerrortop=0.0;//top portion of exact error function
    double eerrorbot=0.0;//bottom portion of exact error function
    double eperror=0.0;//exact error percentage
    double tperror=0.0;//truncated error using 1st neglected term in percentage
    double f0 = 0.0;//derivatives of sine
    double f1 = 1.0;
    double f2 = 0.0;
    double f3 = 1.0;
    double f4 = 0.0;
    double f5 = 1.0;
    double f6 = 0.0;
    double f7 = 1.0;
    double f8 = 0.0;
    double f9 = 1.0;
    double f10 = 0.0;
    double f11 = 1.0;
    double f12 = 0.0;
    double t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12=0.0;//Individual terms in Maclaurin series equation
    
    printf("Evaluating sinh series\n\n");
    printf("Please enter the highest power of x in the sinh series (0 through 10):");
    scanf("%d", &power);
    
    printf("\nPlease enter the value of x at which to evaluate (-10.0 through 10.0): ");
    scanf("%lf", &range);
    inc = range/10;
    
    printf("\nMACLAURIN SERIES TO SINH");
    
    printf("\n  X\t\t Series\t\t Exact\t\tExact %% Error\t Trunc. %% Error\n");
    
    switch(power){
        
        case 0:
              for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                       
                series = t0;
                if(t1 == 0){
                    error = t2;
                }
                else{
                    error = t1;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for  
            break;
        case 1:
          for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
                       
                series = t0 + t1;
                if(t2 == 0){
                    error = t3;
                }
                else{
                    error = t2;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 2:
           for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
                       
                series = t0 + t1 + t2;
                if(t3 == 0){
                    error = t4;
                }
                else{
                    error = t3;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 3:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
                       
                series = t0 + t1 + t2 + t3;
                if(t4 == 0){
                    error = t5;
                }
                else{
                    error = t4;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 4:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
                       
                series = t0 + t1 + t2 + t3 + t4;
                if(t5 == 0){
                    error = t6;
                }
                else{
                    error = t5;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 5:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5;
                if(t6 == 0){
                    error = t7;
                }
                else{
                    error = t6;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 6:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6;
                if(t7 == 0){
                    error = t8;
                }
                else{
                    error = t7;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror);
            }//end for
            break;
        case 7:
           for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7;
                if(t8 == 0){
                    error = t9;
                }
                else{
                    error = t8;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 8:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
                if(t9 == 0){
                    error = t10;
                }
                else{
                    error = t9;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 9:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                t11 = (f11*((x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9;
                if(t10 == 0){
                    error = t11;
                }
                else{
                    error = t10;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 10:
            
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                t11 = (f11*((x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11)));
                t12 = (f12*((x * x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11*12)));        
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10;
                if(t11 == 0){
                    error = t12;
                }
                else{
                    error = t11;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        default:
            printf("Invalid Input.\n");
    }//end switch
    
 return 0;   
}//end soh function

/*****************************************************************************************
 * Function name:      coh
 * Purpose:            Calculates a Maclaurin series approximations for cosh(x), asking
 *                     the user for the power of the highest term and a value for x. Use 
 *                     math library to get exact maclaurin series with exact error and truncated
 *                     Prints out results.
 * In parameters:      n/a
 * Out parameters:     double - result of the calculation
 * Version:            1.0
 * Author:             Tim Osse
 *****************************************************************************************/
double coh(void){
    int a;//series loop index
    int power = 0;//number of term in series
    double range = 0.0;//max value of x
    double inc;//increment value range / 10
    double x=0.0;//range divided by 10 incremented to range
    double series=0.0;//approximate maclaurin series
    double exactSeries=0.0;//exact maclaurin series using math lib.
    double error=0.0;//first neglected term
    double eerror=0.0;//exact error
    double eerrortop=0.0;//top portion of exact error function
    double eerrorbot=0.0;//bottom portion of exact error function
    double eperror=0.0;//exact error percentage
    double tperror=0.0;//truncated error using 1st neglected term in percentage
    double f0 = 1.0;//derivatives of sine
    double f1 = 0.0;
    double f2 = 1.0;
    double f3 = 0.0;
    double f4 = 1.0;
    double f5 = 0.0;
    double f6 = 1.0;
    double f7 = 0.0;
    double f8 = 1.0;
    double f9 = 0.0;
    double f10 = 1.0;
    double f11 = 0.0;
    double f12 = 1.0;
    double t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12=0;//Individual terms in Maclaurin series equation
    
    printf("Evaluating sinh series\n\n");
    printf("Please enter the highest power of x in the sinh series (0 through 10):");
    scanf("%d", &power);
    
    printf("\nPlease enter the value of x at which to evaluate (-10.0 through 10.0): ");
    scanf("%lf", &range);
    inc = range/10;
    
    printf("\nMACLAURIN SERIES TO SINH");
    
    printf("\n  X\t\t Series\t\t Exact\t\tExact %% Error\t Trunc. %% Error\n");
    
    switch(power){
        
        case 0:
              for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                       
                series = t0;
                if(t1 == 0){
                    error = t2;
                }
                else{
                    error = t1;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for  
            break;
        case 1:
          for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
                       
                series = t0 + t1;
                if(t2 == 0){
                    error = t3;
                }
                else{
                    error = t2;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 2:
           for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
                       
                series = t0 + t1 + t2;
                if(t3 == 0){
                    error = t4;
                }
                else{
                    error = t3;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 3:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
                       
                series = t0 + t1 + t2 + t3;
                if(t4 == 0){
                    error = t5;
                }
                else{
                    error = t4;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 4:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
                       
                series = t0 + t1 + t2 + t3 + t4;
                if(t5 == 0){
                    error = t6;
                }
                else{
                    error = t5;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 5:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5;
                if(t6 == 0){
                    error = t7;
                }
                else{
                    error = t6;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 6:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6;
                if(t7 == 0){
                    error = t8;
                }
                else{
                    error = t7;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror);
            }//end for
            break;
        case 7:
           for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7;
                if(t8 == 0){
                    error = t9;
                }
                else{
                    error = t8;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 8:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
                if(t9 == 0){
                    error = t10;
                }
                else{
                    error = t9;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 9:
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                t11 = (f11*((x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11)));
                       
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9;
                if(t10 == 0){
                    error = t11;
                }
                else{
                    error = t10;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        case 10:
            
            for (a =0;a<11;++a,x+=inc){
                t0 = f0;
                t1 = (f1*(x));
                t2 = (f2*((x * x)/(1*2)));
                t3 = (f3*((x * x * x)/(1*2*3)));
				t4 = (f4*((x * x * x * x)/(1*2*3*4)));
				t5 = (f5*((x * x * x * x * x)/(1*2*3*4*5)));
				t6 = (f6*((x * x * x * x * x * x)/(1*2*3*4*5*6)));
				t7 = (f7*((x * x * x * x * x * x * x)/(1*2*3*4*5*6*7)));
                t8 = (f8*((x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8)));
                t9 = (f9*((x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9)));
                t10 = (f10*((x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10)));
                t11 = (f11*((x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11)));
                t12 = (f12*((x * x * x * x * x * x * x * x * x * x * x * x)/(1*2*3*4*5*6*7*8*9*10*11*12)));        
                series = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10;
                if(t11 == 0){
                    error = t12;
                }
                else{
                    error = t11;
                }
                exactSeries = sinh(x);//Exact series using math lib function
                eerrortop = (series - exactSeries);
                eerrorbot = exactSeries;
                if(eerrortop == 0){
                   eerror = 0;
                }
                if(eerrorbot == 0){
                   eerror = 0; 
                }
                else{
                   eerror = (series - exactSeries)/exactSeries;//check nom and denom for 0
                }
                eperror = eerror*100;
      
                if(error == 0){
                   tperror = 0; 
                }
                if(series == 0){
                    tperror = 0;
                }
                else{
                   tperror = (error/series)*100; 
                }
                
                printf("% 11.3e\t% 11.5e\t% 11.5e\t% 11.5e\t% 11.5e\n",x,series,exactSeries,eperror,tperror); 
            }//end for
            break;
        default:
            printf("Invalid Input.\n");
    }//end switch 
	return 0;
}//end class
