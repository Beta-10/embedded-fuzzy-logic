/*******************************************************************************
* File Name: user_param.h  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file contains assignment of parameters for global resources.
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
//*****Declarations of parameters*****
//***** Input 1: i1*****
member_func i1;
//Term: low,medium,high
int i1_xfunc[3][5] = {{-50,0,50,50,50},{0,50,100,100,100},{50,100,150,150,150}}; 
int i1_yfunc[3][5] = {{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0}};
int i1_range[2] = {0,100};
double i1_mapped[3];
double i1_weight[3] = {1,1,1};

//***** Input 2: i2*****
member_func i2;
//Term: v.low,low,medium,high,v.high
int i2_xfunc[5][5] = {{-25,0,25,25,25},{0,25,50,50,50},{25,50,75,75,75},{50,75,100,100,100},{75,100,125,125,125}};
int i2_yfunc[5][5] = {{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0}};
int i2_range[2] = {0,100};
double i2_mapped[5];
double i2_weight[5] = {1,1,1,1,1};

//***** Output: o1*****
member_func o1;
//Term: v.low,low,medium,high,v.high
int o1_xfunc[5][5] = {{-25,0,25,25,25},{0,25,50,50,50},{25,50,75,75,75},{50,75,100,100,100},{75,100,125,125,125}};
int o1_yfunc[5][5] = {{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0}}; 
int o1_range[2] = {0,100};
double o1_mapped[5];
double o1_weight[5] = {1,1,1,1,1};

double m[5][4];	//1st order membership function of fuzzy set

void declaration(void)
{
	i1.name = "i1\0";
	i1.num_func = 3;
	i1.xfunc = i1_xfunc;
	i1.yfunc = i1_yfunc;
	i1.range = i1_range;
	i1.mapped = i1_mapped;
	i1.weight = i1_weight;
	i1.network = 1;
	i1.type = 0;
	
	i2.name = "i2\0";
	i2.num_func = 5;
	i2.xfunc = i2_xfunc;
	i2.yfunc = i2_yfunc;
	i2.range = i2_range;
	i2.mapped = i2_mapped;
	i2.weight = i2_weight;
	i2.network = 1;
	i2.type = 0;
	
	o1.name = "o1\0";
	o1.num_func = 5;
	o1.xfunc = o1_xfunc;
	o1.yfunc = o1_yfunc;
	o1.range = o1_range;
	o1.mapped = o1_mapped;
	o1.weight = o1_weight;
	o1.network = 1;
	o1.type = 1;
}

