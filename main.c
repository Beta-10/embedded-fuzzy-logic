/*******************************************************************************
* File Name: fuzzylogic.c
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file provides the main source code of embedded fuzzy logic.
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
#include <stdlib.h>
#include <math.h>
#include "pre_struct.h"
#include "user_param.h"
#include "user_rules.h"

/*******************************************************************************
*  The main.c has included an example on how to use the fuzzy logic source code.
*  The <main(.)> function should be modified to meet different embedded 
*  programming environment.
********************************************************************************/

//Input variables
int i1_d = 30;					//Any value between 0 and 100
int i2_d = 67;					//Any value between 0 and 100

int main(int argc, char **argv)
{
	int i_row = 0;				//Index for row
	double c_value = 0;			//Crisp value
	
	//******Print variables for i1 and i2*****
	printf("Variable for i1: %d\r\nVariable for i2: %d\r\n\r\n",i1_d,i2_d);

	declaration();
	grad_derv(i1, m);
	map_func(i1, m, i1_d);

	grad_derv(i2, m);
	map_func(i2, m, i2_d);
	
	//*****Print i1*****
	printf("i1 input:\r\n");
	for (i_row = 0; i_row < i1.num_func; i_row++) printf("%f\r\n", i1.mapped[i_row]);
	printf("\r\n");
	
	//*****Print i2*****
	printf("i2 input:\r\n");
	for (i_row = 0; i_row < i2.num_func; i_row++) printf("%f\r\n", i2.mapped[i_row]);
	printf("\r\n");
	
	user_ruleset();				//Map i1 and i2 to o1 with user-defined rules
	
	//*****Print o1*****
	printf("o1 output:\r\n");
	for (i_row = 0; i_row < o1.num_func; i_row++) printf("%f\r\n", o1.mapped[i_row]);
	printf("\r\n");
	
	//*****Calculate o1 and crisp value*****
	c_value = defuzzify(0, 150, o1);
	printf("Crisp value = %f\r\n",c_value);
	
	//*****Map crisp value on o1*****
	grad_derv(o1, m);
	map_func(o1, m, c_value);
	
	//*****Print o1*****
	printf("\r\nFinal o1 output:\r\n");
	for (i_row = 0; i_row < o1.num_func; i_row++) printf("%f\r\n", o1.mapped[i_row]);
	printf("\r\n");

	printf("End of example\r");
	return 0;
}
