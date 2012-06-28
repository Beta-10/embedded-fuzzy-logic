/*******************************************************************************
* File Name: map_function.c  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file contains the main source code of mapping fuzzy sets to the 
*  membership functions.
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
#include "pre_struct.h"

/****************************************************************************** 
* Function Name: grad_derv
*******************************************************************************
*
* Summary:
*  Calculate gradient of fuzzy set
* 
* Parameters:  
*  member_func: Struct of fuzzy set
*  mat_col_m: Matrix of gradient
*
* Return: 
*  void
*
*******************************************************************************/
void grad_derv(member_func A, mat_col_m *m)
{
	int delta_x = 0;
	int delta_y = 0;
	static int i_row = 0;
	static int i_col = 0;
	
	for(i_row = 0; i_row < A.num_func; i_row++)
	{
		for(i_col = 0; i_col < 4; i_col++)
		{
			delta_y = A.yfunc[i_row][i_col+1]-A.yfunc[i_row][i_col];
			delta_x = A.xfunc[i_row][i_col+1]-A.xfunc[i_row][i_col];
						
			if(!delta_x)						//Avoid division by 0
				{
					if(delta_y) m[i_row][i_col] = 0xFFFF;
					else m[i_row][i_col] = 0;
				}
			else m[i_row][i_col] = (float)delta_y/(float)delta_x;
		}
	}
}

/****************************************************************************** 
* Function Name: map_func
*******************************************************************************
*
* Summary:
*  Map datasets to fuzzy output (To be used after grad_derv). Mapped data is 
*  stored in A.mapped.
* 
* Parameters:  
*  member_func: Struct of fuzzy set
*  mat_col_m: Matrix of gradient
*  x: Dataset
*
* Return: 
*  void
*
*******************************************************************************/
void map_func(member_func A, mat_col_m *m, short x)
{
	static int i_row = 0;
	static int i_col = 0;
	static float in_A = 0;
	static float in_B = 0;
	
	for (i_row = 0; i_row < A.num_func; i_row++)
	{
		for (i_col = 0; i_col < 4; i_col++)
		{	
			if ((x >= A.xfunc[i_row][i_col]) && (x <= A.xfunc[i_row][i_col+1])) //Execute only if x is within the range
			{
				in_A = m[i_row][i_col]*(x - A.xfunc[i_row][i_col]) + A.yfunc[i_row][i_col];
				if (in_A > 1) in_A = 1;		//Saturate values to 1
				if (in_A > in_B) in_B = in_A;
			}
		}
		A.mapped[i_row] = in_B;
		in_B = 0;
	}
}