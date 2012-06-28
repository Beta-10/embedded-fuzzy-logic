/*******************************************************************************
* File Name: defuzz.c  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file contains the main source code to execute defuzzifications.
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
* Function Name: defuzzify
*******************************************************************************
*
* Summary:
*  Defuzzification of fuzzy set
* 
* Parameters:  
*  type: Type of defuzzification methods (Reserved for future version)
* 	 0 - Centroid
*  res: Resolution
*  member_func:  Struct of fuzzy set
*
* Return: 
*  double: Crisp value
*
*******************************************************************************/
double defuzzify(int type, int res, member_func A)
{
	double c_value = 0;		//Crisp value
	double bin = 0;	
	int i_row = 0;
	int i_res = 0;
	double k[A.num_func][4];	//Gradient
	double x1,x2,y;
	double end_y = 0;
	double sum_yx = 0;
	double sum_y = 0;
	int pointer[A.num_func];
	
	bin = (double)(A.range[1] - A.range[0])/res;		//Calculate bin	
	grad_derv(A, k);					//Calculate gradient
	
	for (i_row = 0; i_row < A.num_func; i_row++)		//Padding with 0
		pointer[i_row] = 0;
	
	for (i_res = 0; i_res < res+1; i_res++)
	{
		x1 = (double)bin*(double)i_res;
		
		for(i_row = 0; i_row < A.num_func; i_row++)
		{
			if ((x1 > A.xfunc[i_row][pointer[i_row]+1]) && (pointer[i_row] < 4))
				pointer[i_row]++;
			
			//Execute only if x1 falls within the span
			if ((x1 >= A.xfunc[i_row][pointer[i_row]]) && (x1 <= A.xfunc[i_row][pointer[i_row]+1]))
			{
				x2 = x1 - (double)A.xfunc[i_row][pointer[i_row]];
				y = k[i_row][pointer[i_row]]*x2 + (double)A.yfunc[i_row][pointer[i_row]];
				//Uncomment to view equations
				//printf("%f = %f * %f + %d, ",y,k[i_row][pointer[i_row]],x2,A.yfunc[i_row][pointer[i_row]]);
				
				if (y > 1) y = 1;					//Saturate values to 1
				if (y > A.mapped[i_row]) y = A.mapped[i_row];		//Saturated values to mapped fuzzy set
				if (y > end_y) end_y = y;				//Compare value within terms
			}
		}	
		sum_yx += (end_y*x1);
		sum_y += end_y;	
		//Uncomment the following code view fuzzy area
		//printf("f(x) = %f when x = %f\r\n",end_y,x1);
		end_y = 0;								//Clear result;
	}
	
	c_value = sum_yx/sum_y;
	
	return c_value;
}