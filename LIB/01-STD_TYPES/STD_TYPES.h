/********************************************************/
/*	Author	    : zaki ahmed							*/
/*  Date 	    : 18 September 2020						*/
/*  Version     : V03									*/
/*	LOG         : V01 -> Initial creation				*/
/*				: V02 -> Add to sign data				*/
/*				: V03 -> Add to TRUE,FALSE,NULLPTR		*/
/*  Description : file contains Standard Data Types 	*/
/********************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef _STD_TYPES_H
#define _STD_TYPES_H


#define NOK          0
#define OK           1
#define NULL_POINTER 2
#define NULL         0


typedef unsigned char 		u8;
typedef unsigned short int 	u16;
typedef unsigned long int 	u32;

typedef signed char 		s8;
typedef signed short int 	s16;
typedef signed long  int 	s32;

typedef float  				f32;
typedef double 				f64;


#define TRUE         		0x01U
#define FALSE        		0x00U
#define NULLPTR      		((void*)0)

#define SET          		(1U)
#define CLR          		(0U)

#endif //_STD_TYPES_H