#include <iostream>
using namespace std;

double function0(double x){
	if(x> 0){
		return 1;
		}
	if(x<0){
		return 0;
		}
	return 1/2;
	}

double boundary0(bool isLower){
	if(isLower){
		return 0;
		}
	return 1;
	}

double analytical_function0(double x,double t){
	return function0(x-t);}

int main(){
	const double delta_x = 0.8;
	const double lower_boundary = -40;
	const double upper_boundary = 40;

	const double delta_t = 0.5; //Smaller than the delta_x to ensure stability

	double t_goal[3] = {5,10,20};
	//Initial state
	double f0_upwind[41][100];
	for(int i = 0; i < 100; i++){
		f0_upwind[0][i] = function0(lower_boundary + i*delta_x);
		}

	//Upwind calculation
	for(int n = 1; n <=40; n++){
		f0_upwind[n][0] = boundary0(true);
		for(int i = 1; i <= 100; i++){
			f0_upwind[n][i] = ((3./8.) * f0_upwind[n-1][i]) + ((5./8.) * f0_upwind[n-1][i-1]);
			}
		}
	//Exact result
	double f0_calculus[41][100];
	for(int n = 0; n<=40; n++){
		for(int i = 0; i<100; i++){
			f0_calculus[n][i] = analytical_function0(i*delta_x+lower_boundary,n*delta_t);
			}
		}
	cout << "For time = 5:" << endl;
	for(int i=0; i<100;i++){
		printf("%f ",f0_upwind[10][i]);
		printf("%f\n",f0_calculus[10][i]);

	}
	return 0;
}
