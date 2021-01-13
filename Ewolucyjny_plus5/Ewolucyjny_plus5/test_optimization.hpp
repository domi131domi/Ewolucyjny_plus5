# pragma once
# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;

void p00_ab ( int problem, int m, double a[], double b[] );
double *p00_compass_search ( int problem, int m, double x0[], double delta_tol, double delta_init, int k_max, double *fx, int *k );
double *p00_f ( int problem, int m, int n, double x[] );
int p00_problem_num ( );
double *p00_sol ( int problem, int m, int &know );
string p00_title ( int problem );
void p01_ab ( int m, double a[], double b[] );
double *p01_f ( int m, int n, double x[] );
double *p01_sol ( int m, int &know );
string p01_title ( );
void p02_ab ( int m, double a[], double b[] );
double *p02_f ( int m, int n, double x[] );
double *p02_sol ( int m, int &know );
string p02_title ( );
void p03_ab ( int m, double a[], double b[] );
double *p03_f ( int m, int n, double x[] );
double *p03_sol ( int m, int &know );
string p03_title ( );
void p04_ab ( int m, double a[], double b[] );
double *p04_f ( int m, int n, double x[] );
double *p04_sol ( int m, int &know );
string p04_title ( );
void p05_ab ( int m, double a[], double b[] );
double *p05_f ( int m, int n, double x[] );
double *p05_sol ( int m, int &know );
string p05_title ( );
void p06_ab ( int m, double a[], double b[] );
double *p06_f ( int m, int n, double x[] );
double *p06_sol ( int m, int &know );
string p06_title ( );
void p07_ab ( int m, double a[], double b[] );
double *p07_f ( int m, int n, double x[] );
double *p07_sol ( int m, int &know );
string p07_title ( );
void p08_ab ( int m, double a[], double b[] );
double *p08_f ( int m, int n, double x[] );
double *p08_sol ( int m, int &know );
string p08_title ( );
void p09_ab ( int m, double a[], double b[] );
double *p09_f ( int m, int n, double x[] );
double *p09_sol ( int m, int &know );
string p09_title ( );
void p10_ab ( int m, double a[], double b[] );
double *p10_f ( int m, int n, double x[] );
double *p10_sol ( int m, int &know );
string p10_title ( );
void p11_ab ( int m, double a[], double b[] );
double *p11_f ( int m, int n, double x[] );
double *p11_sol ( int m, int &know );
string p11_title ( );
void p12_ab ( int m, double a[], double b[] );
double *p12_f ( int m, int n, double x[] );
double *p12_sol ( int m, int &know );
string p12_title ( );
double r8_abs ( double x );
double r8_max ( double x, double y );
double *r8col_uniform_new ( int m, int n, double a[], double b[], int *seed );
void r8vec_copy ( int n, double a1[], double a2[] );
double *r8vec_indicator_new ( int n );
double r8vec_max ( int n, double r8vec[] );
double r8vec_min ( int n, double r8vec[] );
void timestamp ( );
