//./stringsplit.h
#ifndef STRINGSPLIT_H
#define STRINGSPLIT_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//---------------------------------------------------s.
template <class myType>
myType **mymemory(myType**CharMemory2d, int Xsize) {
	CharMemory2d = new myType*[Xsize];
	for(int x = 0; x < Xsize; x++) {
		CharMemory2d[x] = new myType[1024];
	}
	return CharMemory2d;
}//--------------------------------------------------e.
//---------------------------------------------------s.
template <class myType>
void myfree(myType**CharMemory2d,int uaFreeSize) {
	for(int x = 0; x < uaFreeSize; x++) {
		delete [] CharMemory2d[x];
	}delete [] CharMemory2d;
}//--------------------------------------------------e.
//---------------------------------------------------s.
template <class myType>
myType *mymemory(myType*intMemory1d, int Xsize) {
	intMemory1d = new myType[Xsize];
	return intMemory1d;
}//--------------------------------------------------e.
//---------------------------------------------------s.
template <class myType>
void myfree(myType*intMemory1d) {
	delete [] intMemory1d;
}//--------------------------------------------------e.
//---------------------------------------------------s.
template <class myType>
myType***mymemory3d(myType***CharMemory3d, int SizeXLine, int *SizeYvector) {
	CharMemory3d = new myType**[SizeXLine];
	for(int x = 0; x < SizeXLine; x++) {
		CharMemory3d[x] = new myType*[SizeYvector[x]];
		for(int y = 0; y < SizeYvector[x]; y++) {
			CharMemory3d[x][y] = new myType[1024];
			CharMemory3d[x][y][0] = '\0';
		}
	}
	return CharMemory3d;
}//--------------------------------------------------e.
//---------------------------------------------------s.
template <class myType>
void myfree3d(myType***CharMemory3d, int SizeXLine, int *SizeYvector) {
	for(int x = 0; x < SizeXLine; x++) {
		for(int z = 0; z < SizeYvector[x]; z++) {
			delete [] CharMemory3d[x][z];
		} delete [] CharMemory3d[x];
	} delete [] CharMemory3d;
}//---------------------------------------------------e.

//------------------------------------------------------------s.
typedef struct mys_base_stringsplit
{
	char charArray[1024];
	typedef struct nestchar{
		char charArray[1024];
	}nestchar;
	int unitXLine = NULL;
	int *unutYLine = NULL;
	char **UserAnyArray1d = NULL;
	char ***split2darry = NULL;
	virtual void splitDataRegisterPushued(int ponoff);
	virtual void splitDataRegisterPushued(nestchar *request, int ponoff);
	void allfree() {
		myfree3d(split2darry, unitXLine, unutYLine);
		myfree(UserAnyArray1d, unitXLine);
		myfree(unutYLine);
	}
	mys_base_stringsplit() {}
	mys_base_stringsplit(int InunitXLine) {
		unitXLine = InunitXLine;
	}
	//~mys_base_stringsplit() {}
} mys_base_stringsplit;
//------------------------------------------------------------e.

//------------------------------------------------------------s.
typedef struct mys_delived_stringsplit : public mys_base_stringsplit
{
	int requserzLine=0;
	mys_base_stringsplit *requestuserarray=NULL;
	void splitDataRegisterPushued(mys_base_stringsplit *requestuserarray, int ponoff){
		requestuserarray->splitDataRegisterPushued(ponoff);
	}
	void splitDataRegisterPushued(mys_base_stringsplit *requestuserarray, mys_base_stringsplit::nestchar *request, int ponoff){
		requestuserarray->splitDataRegisterPushued(request,ponoff);
	}
	using mys_base_stringsplit::mys_base_stringsplit;
	mys_delived_stringsplit(int Inruz, int InunitXLine) : mys_base_stringsplit::mys_base_stringsplit(InunitXLine) {
		requserzLine = Inruz;
		requestuserarray = new mys_base_stringsplit[Inruz];
		for(int ruz = 0; ruz < requserzLine; ruz++) {
			requestuserarray[ruz].unitXLine = InunitXLine;
		}
	}
	~mys_delived_stringsplit() {
		if(requserzLine!=0) {
			for(int ruz = 0; ruz < requserzLine; ruz++) {
				requestuserarray[ruz].allfree();
			} delete [] requestuserarray;
		}
	}
}mys_delived_stringsplit;
//------------------------------------------------------------e.

#endif