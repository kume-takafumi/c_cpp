//make dt
//./stringsplit.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./stringsplit.h"

//----------------------------------------------------------------------s.
int funcStringDataExchange(char *InputsCharX1d) {
	//char str[256] = "abc,defgh,ij";
	char str[1024] = "\0";
	sprintf(str,"%s",InputsCharX1d);
	const char *const separator = ",";
	char *token = strtok( str, separator );
	int size = 0;
	while( token != NULL ){
	    //puts( token );
	    token = strtok( NULL, separator );
		size++;
	}
	return size;
}
//----------------------------------------------------------------------e.

//----------------------------------------------------------------------s.
/*処理1: 用途:変換関数。1次元char型配列を->2次元char型が配列へ分割する処理。*/
char **funcStringDataExchange(char **OutDataXY2d, char *InputsCharX1d, int ponoff)
{
	const char *const separator = ",";
	char str[1024] = "\0";
	sprintf(str,"%s",InputsCharX1d);	
	char *token = strtok( str, separator );
	int count = 0;
	while( token != NULL ){
		if(ponoff==2)printf("%s\n", token);
		/*in*/strcpy( OutDataXY2d[count], token );
	    token = strtok( NULL, separator );
		count++;
	}//ponoff = 1;
	if(ponoff==1) {
		for(int s = 0; s < count; s++) {
			printf("%s ", OutDataXY2d[s]);
		}printf("\n");
	}
return OutDataXY2d;
}
//----------------------------------------------------------------------e.

//---------------------------------------------------------------------s.
void mys_base_stringsplit::splitDataRegisterPushued(int ponoff)
{
	unutYLine = mymemory(unutYLine, unitXLine);
	for(int x = 0; x < unitXLine; x++) {
		unutYLine[x] = funcStringDataExchange(UserAnyArray1d[x]);
	}	
	split2darry = mymemory3d(split2darry, unitXLine, unutYLine);
	for(int x = 0; x < unitXLine; x++) {
		split2darry[x] = funcStringDataExchange( split2darry[x], UserAnyArray1d[x], (int)-1 );
	}
	if(ponoff==1) {
	 	printf("//const format-------------------------------------s.\n");
	 	for(int x = 0; x < unitXLine; x++) {
	 		printf("%d(x): %2d(ys): %s\n", x, unutYLine[x], UserAnyArray1d[x]);
	 	}
	 	printf("split process -> -> <1d char> -> -> <2d char> -> ->\n");
	 	for(int x = 0; x < unitXLine; x++) {
	 		printf("%d(x): %2d(ys): ",x, unutYLine[x]);
	 		for(int y = 0; y < unutYLine[x]; y++) {
	 			printf("%s ", split2darry[x][y]);
	 		} printf("\n");
	 	}printf("//const format-------------------------------------e.\n");
	}
}//---------------------------------------------------------------------e.

//---------------------------------------------------------------------s.
void mys_base_stringsplit::splitDataRegisterPushued(mys_base_stringsplit::nestchar *request, int ponoff)
{
	if(ponoff==1)printf("//user any extra----------------------------------e.\n");
	/*in*/UserAnyArray1d = mymemory(UserAnyArray1d, unitXLine);
	for(int x = 0; x < unitXLine; x++) {
		/*in*/strcpy( UserAnyArray1d[x], request[x].charArray );
		if(ponoff==1)printf("%d, %s\n", funcStringDataExchange( request[x].charArray ), UserAnyArray1d[x] );
	}
	splitDataRegisterPushued((int)-1);
}//---------------------------------------------------------------------e.

//---------------------------------------------------------------------s.
static void gmain_split00() 
{
	int ponnof = 1;
	mys_base_stringsplit::nestchar constUserFormat[3] = {{"sec05"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3,4,5,6,7"}};
	mys_base_stringsplit _csnamesp(3),*csnamesp=&_csnamesp;
	csnamesp->splitDataRegisterPushued(constUserFormat,-ponnof);
	if(ponnof==1) {
		for(int x = 0; x < csnamesp->unitXLine; x++) {
			printf("%d(x): %2d(s): ", x, csnamesp->unutYLine[x]);
			for(int y = 0; y < csnamesp->unutYLine[x]; y++) {
				printf("%s ", csnamesp->split2darry[x][y]);
			} 	printf("\n");
		}
		printf("---------------------------(end)\n");
	}
}//---------------------------------------------------------------------e.

//---------------------------------------------------------------------s.
static void gmain_split01()
{
	int ponnof = 1;
	mys_base_stringsplit::nestchar constUserFormat[4][3] = {
		{{"sec05,sec15"},{"AAAAAA,BBBBBB,CCCCCC"},{"0,0,0"}},
		{{"sec15"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3"}},
		{{"sec05"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3,4,5,6,7"}},
		{{"sec05"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3,4,5,6,7"}},
	};
	for(int ruz = 0; ruz < 4; ruz++) {
		mys_base_stringsplit _csnamesp(3),*csnamesp=&_csnamesp;
		csnamesp->splitDataRegisterPushued(constUserFormat[ruz],-ponnof);
		if(ponnof==1) {
			for(int x = 0; x < csnamesp->unitXLine; x++) {
				printf("%d(x): %2d(s): ", x, csnamesp->unutYLine[x]);
				for(int y = 0; y < csnamesp->unutYLine[x]; y++) {
					printf("%s ", csnamesp->split2darry[x][y]);
				} 	printf("\n");
			}
			printf("---------------------------(ruz)\n");
		}
	}
}//---------------------------------------------------------------------e.

//---------------------------------------------------------------------s.
static void gmain_split02() 
{
	int ponnof = 1;
	mys_base_stringsplit::nestchar constUserFormat[4][3] = {
		{{"sec05,sec15"},{"AAAAAA,BBBBBB,CCCCCC"},{"0,0,0"}},
		{{"sec15"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3"}},
		{{"sec25"},{"AAAAAA,BBBBBB,CCCCCC"},{"1,2,3,4,5,6,7"}},
		{{"sec35"},{"dict,NewralNetwork"},{"10,256,256,512,512,10"}},
	};
	mys_delived_stringsplit _csnamesp(4,3),*csnamesp=&_csnamesp;
	for(int ruz = 0; ruz < csnamesp->requserzLine; ruz++) {
		csnamesp->splitDataRegisterPushued( &csnamesp->requestuserarray[ruz], constUserFormat[ruz], -ponnof);
	}
	if(ponnof==1) {
		for(int ruz = 0; ruz < csnamesp->requserzLine; ruz++) {
			for(int x = 0; x < csnamesp->requestuserarray[ruz].unitXLine; x++) {
				printf("%d(x): %2d(s): ", x, csnamesp->requestuserarray[ruz].unutYLine[x]);
				for(int y = 0; y < csnamesp->requestuserarray[ruz].unutYLine[x]; y++) {
					printf("%s ", csnamesp->requestuserarray[ruz].split2darry[x][y]);
				} 	printf("\n");
			}
			printf("---------------------------%d(ruz)\n",ruz);
		}
	}
}//---------------------------------------------------------------------e.

//----------------------------------s.
static void gmain() {
	//gmain_split00();
	//gmain_split01();
	gmain_split02();
}//---------------------------------e.

//----------------------------------s.
int main( int argc , char **argv ) {
	printf("int main( int argc , char **argv );\n");
	gmain();
return 0;
}//----------------------------------e.