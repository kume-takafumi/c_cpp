#include <iostream>
using namespace std;
#pragma warning(disable : 5208)

//base class--------------------------------s.
template <typename myTypeNameA, typename myTypeNameB>
class MyclassBase {		
    public:
    myTypeNameA *puserA=NULL;
    myTypeNameB *puserB=NULL;
    MyclassBase() {};
    MyclassBase(myTypeNameA InA, myTypeNameB InB) {
        puserA=&InA;
        puserB=&InB;
    };
    ~MyclassBase() {};
};//base class------------------------------e.

//------------------------------------------s.
template <typename myTypeNameA>
struct DerivedA {
    myTypeNameA da;
};
template <typename myTypeNameB>
struct DerivedB {
    myTypeNameB db;
};//----------------------------------------e.

//------------------------------------------s.
static void gmain() {
    DerivedA<int> da; da.da=123;
    DerivedB<int> db; db.db=234;
    MyclassBase<DerivedA<int>,DerivedB<int>> host(da,db);
    std::cout << host.puserA->da << std::endl;
    std::cout << host.puserB->db << std::endl;
}//-----------------------------------------e.

//------------------------------------------s.
int main(int argc, char **argv) {
    gmain();
return 0;
}//-----------------------------------------e.
