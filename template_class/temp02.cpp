#include <iostream>
using namespace std;
#pragma warning(disable : 5208)

//base class--------------------------------s.
template <typename myTypeName>
class MyclassBase {		
    public:
    myTypeName user;
    MyclassBase() {};
    MyclassBase(myTypeName In) {user=In;};
    ~MyclassBase() {};
};//base class------------------------------e.

//------------------------------------------s.
struct DerivedA {
    int da;
};
struct DerivedB : public DerivedA {
    int db;
};//----------------------------------------e.

//------------------------------------------s.
static void gmain() {
    DerivedA da;
    da.da = 123;
    MyclassBase<DerivedA> host00(da);
    std::cout << host00.user.da << std::endl;

    DerivedB db;
    db.da = 234;
    db.db = 345;
    MyclassBase<DerivedB> host01(db);
    std::cout << host01.user.da << std::endl;
    std::cout << host01.user.db << std::endl;
}//-----------------------------------------e.

//------------------------------------------s.
int main(int argc, char **argv) {
    gmain();
return 0;
}//-----------------------------------------e.
