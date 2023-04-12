#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 5208)

//----------------------------------------------s.
//コーバック関数1.
void callback1(char *mystring) {
    printf("[%s].\n",mystring);
}//---------------------------------------------e.

//----------------------------------------------s.
//コールバック関数2.
void callback2(char *mystring) {
    printf("[%s].\n",mystring);
}//---------------------------------------------e.

//----------------------------------------------s.
//コールバック関数を呼び出す関数.
void func0(void(*GoToCallBackFuncName)(char *s), char *s) {
    GoToCallBackFuncName(s);
};//---------------------------------------------e.

//----------------------------------------------s.
//コールバック関数を呼び出す関数.
typedef void (*cbFuncPointer)(char *s);
void func1(cbFuncPointer CB_CallName,char *s) {
    CB_CallName(s);
}//---------------------------------------------e.

//----------------------------------------------s.
static void gmain() 
{
    printf("start:00----------------------.\n");
    func0(callback1,"call back 1:");
    func0(callback2,"call back 2:");

    printf("start:01----------------------.\n");
    cbFuncPointer NameCut[2] = {callback1, callback2};
    char mychardata[2][16] = {"call back 1:","call back 2:"};
    for(int x = 0; x < 2; x++) {
        func1(NameCut[x],mychardata[x]);
    }
}//---------------------------------------------e.

//------------------------------------------------------------s.
int main( int argc, char **argv ) 
{
    gmain();
return 0;
}//------------------------------------------------------------e.
