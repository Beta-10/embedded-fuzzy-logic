/*******************************************************************************
* File Name: pre_struct.h  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file provides the main structure of different variables.
* 
* Author: Siew Hon Teay
* Diagnostics and Sustainability Research Group(DIASUS)
*
*******************************************************************************
Copyright(c) 2012 S.H.Teay, DIASUS 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************************/

//****DO NOT CHANGE THE CODE UNLESS NECESSARY****

//*****Declaration and type definition of structures*****
typedef int mat_col[5];		//Zero order of pointer to column of matrix
typedef double
 mat_col_m[4];			//First order of pointer to column of matrix

typedef struct {
	char *name;		//Name of input
	int num_func;		//Number of functions in universe of discourse
	mat_col *xfunc;		//Parameters of set
	mat_col *yfunc;		//Contribution of set to membership functions
	int *range;
	double *mapped;		//Mapped value for x
	double *weight;		//Weight of mapped value
	int network;		//Reserve for future expansion, where:
				//0 - Triangular
				//1 - Trapezoidal
				//2 - B-spline
	int type;		//Type of membership function:
				//0 - input
				//1 - output
} member_func;

//*****Declaration of functions*****
//Link - map_function.c
void grad_derv(member_func A, mat_col_m *y);
void map_func(member_func A, mat_col_m *m, short x);
//Link - f_operators.c
double f_intersection(int type, double num,...);
double f_union(int type, double num,...);
double f_complement(int type, double set);
//Link - user_param.h
void declaration(void);
//Link - user_rules.h
void user_ruleset(void);
//Link - defuzz.c
double defuzzify(int type, int res, member_func A);