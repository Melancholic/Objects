#include "functions.h"
#include <cmath>
#include<QDebug>
#define PI 3.14159265

/*double functions::sin(double x){
    return 100*sin(x);
}*/

double functions::cos(double x){

    return 200*sin(x/150);
}

double functions::arc(double x){
    static bool minus =false;
    double res= 250*sin(acos(x/250));
    if(res!=res){
       minus=!minus;
    }
    return (minus)?-res:res;
}

double functions::parabol(double x){
    return 0.01*x*x;
}

double functions::x2(double x){
    return 2*x;
}

double functions::x10(double x){
    return 10*x;
}

double functions::xx(double x){
    return 0.0001*x*x*x;
}

double functions::minus(double x){
    return -x;
}

double functions::x(double x){
    return x;
}
