//原文網址：https://itw01.com/ANHEWN7.html

#include <stdio.h>
int g1 = 0 , g2 = 0 , g3 = 0 ; 
int max ( int i ) {      
	int m1 = 0 , m2 , m3 = 0 , * p_max ;      
	static n1_max = 0 , n2_max , n3_max = 0 ;      
	p_max = ( int * ) malloc ( 10 ) ;      
	printf ( "列印max程式地址\n" ) ;      
	printf ( "in max: 0x%08x\n\n" , max ) ;      
	printf ( "列印max傳入引數地址\n" ) ;      
	printf ( "in max: 0x%08x\n\n" , & i ) ;      
	printf ( "列印max函式中靜態變數地址\n" ) ;      
	printf ( "0x%08x\n" , & n1_max ) ; //列印各本地變數的記憶體地址      
	printf ( "0x%08x\n" , & n2_max ) ;      
	printf ( "0x%08x\n\n" , & n3_max ) ;      
	printf ( "列印max函式中區域性變數地址\n" ) ;      
	printf ( "0x%08x\n" , & m1 ) ; //列印各本地變數的記憶體地址      
	printf ( "0x%08x\n" , & m2 ) ;      
	printf ( "0x%08x\n\n" , & m3 ) ;      
	printf ( "列印max函式中malloc分配地址\n" ) ;      
	printf ( "0x%08x\n\n" , p_max ) ; //列印各本地變數的記憶體地址      
	if ( i ) return 1 ;      
	else return 0 ; 
} 

int main ( int argc , char * * argv ) 
{      
	static int s1 = 0 , s2 , s3 = 0 ;      
	int v1 = 0 , v2 , v3 = 0 ;      
	int * p ;           
	p = ( int * ) malloc ( 10 ) ;      
	printf ( "列印各全域性變數(已初始化)的記憶體地址\n" ) ;      
	printf ( "0x%08x\n" , & g1 ) ; //列印各全域性變數的記憶體地址      
	printf ( "0x%08x\n" , & g2 ) ;      
	printf ( "0x%08x\n\n" , & g3 ) ;      
	printf ( "======================\n" ) ;      
	printf ( "列印程式初始程式main地址\n" ) ;      
	printf ( "main: 0x%08x\n\n" , main ) ;      
	printf ( "列印主參地址\n" ) ;      
	printf ( "argv: 0x%08x\n\n" , argv ) ;      
	printf ( "列印各靜態變數的記憶體地址\n" ) ;      
	printf ( "0x%08x\n" , & s1 ) ; //列印各靜態變數的記憶體地址      
	printf ( "0x%08x\n" , & s2 ) ;      
	printf ( "0x%08x\n\n" , & s3 ) ;      
	printf ( "列印各區域性變數的記憶體地址\n" ) ;      
	printf ( "0x%08x\n" , & v1 ) ; //列印各本地變數的記憶體地址      
	printf ( "0x%08x\n" , & v2 ) ;      
	printf ( "0x%08x\n\n" , & v3 ) ;      
	printf ( "列印malloc分配的堆地址\n" ) ;      
	printf ( "malloc: 0x%08x\n\n" , p ) ;      
	printf ( "======================\n" ) ;      
	max ( v1 ) ;      
	printf ( "======================\n" ) ;      
	printf ( "列印子函式起始地址\n" ) ;      
	printf ( "max: 0x%08x\n\n" , max ) ;      
	return 0 ; 
} 
