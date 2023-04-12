#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 5208)

//--------------------------------------s.
typedef struct my_Sample_base {
    void funcBaseMemba00(){printf("void funcBaseMemba00();\n");};
    void funcBaseMemba01(){printf("void funcBaseMemba01();\n");};
}my_Sample_base;
//--------------------------------------e.

//--------------------------------------s.
typedef struct my_Sample_derive : my_Sample_base {
    private:
    my_Sample_base *Receiver=NULL;
    public:
    void cbBaseMemba00(void(my_Sample_base::*pFunc)()) {
        (Receiver->*pFunc)();
    }
    typedef void(my_Sample_base::*CallbackFName)();
    void cbBaseMemba01(CallbackFName pFunc) {
        (Receiver->*pFunc)();
    }
    void funcSameMemba00() {printf("void funcSameMemba00();\n");}
    void funcSameMemba01() {printf("void funcSameMemba01();\n");}
}my_Sample_derive;
//--------------------------------------e.

//--------------------------------------s.
static void gmain() {
    my_Sample_derive data;
    typedef void(my_Sample_base::*cbBasefunc)();
    cbBasefunc cbBaseName[2] = {&my_Sample_base::funcBaseMemba00,&my_Sample_base::funcBaseMemba01};
    data.cbBaseMemba01(cbBaseName[0]);
    data.cbBaseMemba00(cbBaseName[1]);

    typedef void(my_Sample_derive::*cbSamefunc)();
    cbSamefunc cbSameName[2] = {&my_Sample_derive::funcSameMemba00,&my_Sample_derive::funcSameMemba01};
    (data.*cbSameName[0])();
    (data.*cbSameName[1])();
}//-------------------------------------e.

//--------------------------------------s.
int main( int argc, char **argv ) 
{
    gmain();
return 0;
}//--------------------------------------e.