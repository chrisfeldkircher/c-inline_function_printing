//
//  maths.h
//  maths-library
//
//  Created by Chris on 27.03.21.
//

#ifndef maths_h
#define maths_h


#endif /* maths_h */

float integral(double b, int intervals);
float derivative(double x);
void drawfunc(double(*fun_ptr)(double), int ymin, int ymax, int xmin, int xmax, float h);
void drawderiv(int ymin, int ymax, int xmin, int xmax, float h);
void drawint(int ymin, int ymax, int xmin, int xmax, float h);
double f(double x);
