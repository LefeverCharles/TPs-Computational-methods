#include <iostream>


double function(double x){
	return (3*x*x*x+2*x+1);
}

double derivative(double x){
	return (9*x*x+2);
}

int main() {
	double epsilon[] = {0.1,0.01,0.001,0.0001,0.00001};
	for(double e: epsilon){
        	printf("Epsilon = %f\n\n",e);
		for(double eval = 0; eval<=1; eval+=e){
			//printf("X = %f\n",eval);
    			double f = function(eval);
   			double df = derivative(eval);
			//printf("Derivative = %f\n\n",df);
        		double f_before = function(eval-e);
	        	double f_after = function (eval+e);
        		double df_before = (f-f_before)/e;
        		//printf("Derived number by the left = %f\n",df_before);
        		//printf("Error by the left = %f\n\n",df_before-df);
        		double df_after = (f_after-f)/e;
        		//printf("Derived number by the right = %f\n",df_after);
        		//printf("Error by the right = %f\n\n",df_after-df);
        		double df_centered = (f_after-f_before)/(2*e);
        		//printf("Derived number centered = %f\n",df_centered);
        		//printf("Error centered = %f\n\n\n",df_centered-df);
		}

    	}
    	return 0;
}


