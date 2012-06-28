/*******************************************************************************
* File Name: user_rules.h  
* Version 0.30 (Update 25-6-2012)
*
* Description:
*  This file contains user-defined rules of fuzzy operations
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

/*******************************************************************************
*  User-defined rules
*  User can set its own rules in this linker file. Currently, 3 fuzzy operators 
*  are supported in the current version (union, intersection and compliment). 
*  Examples are listed in the following function <user_ruleset(.)>.
********************************************************************************/

void user_ruleset(void)
{	
	double result;			//For internal comparison
	
	//***** Rules 1 - IF i1 is LOW AND i2 is V.LOW THEN o1 is V.LOW *****
	result = f_intersection(1,2,i1.mapped[0],i2.mapped[0]);
	o1.mapped[0] = f_union(0,2,o1.mapped[0],result);
	//***** OR *****
	//***** Rules 2 - IF i1 is LOW AND i2 is LOW THEN o1 is LOW *****
	result = f_intersection(1,2,i1.mapped[0],i2.mapped[1]);
	o1.mapped[1] = f_union(0,2,o1.mapped[1],result);
	//***** OR *****
	//***** Rules 3 - IF i1 is LOW AND i2 is MEDIUM THEN o1 is MEDIUM *****
	result = f_intersection(1,2,i1.mapped[0],i2.mapped[2]);
	o1.mapped[2] = f_union(0,2,o1.mapped[2],result);
	//***** OR *****
	//***** Rules 4 - IF i1 is LOW AND i2 is HIGH THEN o1 is MEDIUM *****
	result = f_intersection(1,2,i1.mapped[0],i2.mapped[3]);
	o1.mapped[2] = f_union(0,2,o1.mapped[2],result);
	//***** OR *****
	//***** Rules 5 - IF i1 is LOW AND i2 is HIGH THEN o1 is HIGH *****
	result = f_intersection(1,2,i1.mapped[0],i2.mapped[4]);
	o1.mapped[3] = f_union(0,2,o1.mapped[3],result);
	//***** OR *****
	//***** Rules 6 - IF i1 is MEDIUM AND i2 is V.LOW THEN o1 is LOW *****
	result = f_intersection(1,2,i1.mapped[1],i2.mapped[0]);
	o1.mapped[1] = f_union(0,2,o1.mapped[1],result);
	//***** OR *****
	//***** Rules 7 - IF i1 is MEDIUM AND i2 is LOW THEN o1 is LOW *****
	result = f_intersection(1,2,i1.mapped[1],i2.mapped[1]);
	o1.mapped[1] = f_union(0,2,o1.mapped[1],result);
	//***** OR *****
	//***** Rules 8 - IF i1 is MEDIUM AND i2 is MEDIUM THEN o1 is MEDIUM *****
	result = f_intersection(1,2,i1.mapped[1],i2.mapped[2]);
	o1.mapped[2] = f_union(0,2,o1.mapped[2],result);
	//***** OR *****
	//***** Rules 9 - IF i1 is MEDIUM AND i2 is HIGH THEN o1 is HIGH *****
	result = f_intersection(1,2,i1.mapped[1],i2.mapped[3]);
	o1.mapped[3] = f_union(0,2,o1.mapped[3],result);
	//***** OR *****
	//***** Rules 10 - IF i1 is MEDIUM AND i2 is V.HIGH THEN o1 is HIGH *****
	result = f_intersection(1,2,i1.mapped[1],i2.mapped[4]);
	o1.mapped[3] = f_union(0,2,o1.mapped[3],result);
	//***** OR *****
	//***** Rules 11 - IF i1 is HIGH AND i2 is V.LOW THEN o1 is MEDIUM *****
	result = f_intersection(1,2,i1.mapped[2],i2.mapped[0]);
	o1.mapped[2] = f_union(0,2,o1.mapped[2],result);
	//***** OR *****
	//***** Rules 12 - IF i1 is HIGH AND i2 is LOW THEN o1 is MEDIUM *****
	result = f_intersection(1,2,i1.mapped[2],i2.mapped[1]);
	o1.mapped[2] = f_union(0,2,o1.mapped[2],result);
	//***** OR *****
	//***** Rules 13 - IF i1 is HIGH AND i2 is MEDIUM THEN o1 is HIGH *****
	result = f_intersection(1,2,i1.mapped[2],i2.mapped[2]);
	o1.mapped[3] = f_union(0,2,o1.mapped[3],result);
	//***** OR *****
	//***** Rules 14 - IF i1 is HIGH AND i2 is HIGH THEN o1 is V.HIGH *****
	result = f_intersection(1,2,i1.mapped[2],i2.mapped[3]);
	o1.mapped[4] = f_union(0,2,o1.mapped[4],result);
	//***** OR *****
	//***** Rules 15 - IF i1 is HIGH AND i2 is V.HIGH THEN o1 is V.HIGH *****
	result = f_intersection(1,2,i1.mapped[2],i2.mapped[4]);
	o1.mapped[4] = f_union(0,2,o1.mapped[4],result);	
}
