/*******************************************************************************
* File Name: f_operators.c  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file contains the main source code of fuzzy relations/operations 
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

#include <stdio.h>
#include <stdarg.h>
#include "pre_struct.h"

/****************************************************************************** 
* Function Name: f_intersection
*******************************************************************************
*
* Summary:
*  Calculation of membership value using intersection relations 
*  (triangular norms)
* 
* Parameters:  
*  type: Type of operators
* 		 0 - Product operator
* 		 1 - MIN operator
*  num:  Total number of fuzzy sets to be calculate
*  ...:  Fuzzy sets
*
* Return: 
*  double: Intersection of fuzzy set
*
*******************************************************************************/
double f_intersection(int type, double num,...)
{
	va_list ap;						//Declaration of variable list
	double data;
	int i = 0;						//Index
	float result = 1;
	
	va_start(ap, num);					//Initialise variable list of ap with arg1
	switch (type)
	{
		case 0:
		for (i = 0; i < num; i++) result *= va_arg(ap,double);
		break;
		
		case 1:
		for (i = 0; i < num; i++)
			if ((data = va_arg(ap,double)) < result) result = data;
		break;
	}
	va_end(ap);
	return result;
}

/****************************************************************************** 
* Function Name: f_union
*******************************************************************************
*
* Summary:
*  Calculation of membership value using union relations
*  (triangular co-norms)
* 
* Parameters:  
*  type: Type of operators (Reserved for future version)
* 		 0 - MAX operator
*  num:  Total number of fuzzy sets to be calculate
*  ...:  Fuzzy sets
*
* Return: 
*  double: Intersection of fuzzy set
*
*******************************************************************************/
double f_union(int type, double num,...)
{
	va_list ap;						//Declaration of variable list
	double data;
	int i = 0;						//Index
	float result = 0;
	
	va_start(ap, num);					//Initialise variable list of ap with arg1
	for (i = 0; i < num; i++)
		if ((data = va_arg(ap,double)) > result) result = data;
	va_end(ap);
	return result;
}

/****************************************************************************** 
* Function Name: f_complement
*******************************************************************************
*
* Summary:
*  Calculation of complement membership value of fuzzy expression
* 
* Parameters:  
*  type: Type of operators (Reserved for future version)
* 		 0 - Inverse function (f(x) = 1 - x)
*  set:  Fuzzy set
*
* Return: 
*  double: Intersection of fuzzy set
*
*******************************************************************************/
double f_complement(int type, double set)
{
	double result = 0;
	return result = 1 - set;
}
