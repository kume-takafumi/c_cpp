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
static void gmain() {
    MyclassBase<char>host00('a');
    std::cout << host00.user << std::endl;
    MyclassBase<int>host01(123);
    std::cout << host01.user << std::endl;
    MyclassBase<double>host02(3.3);
    std::cout << host02.user << std::endl;
    char s3[32] = {"321"};
    MyclassBase<char*>host03(s3);
    std::cout << host03.user << std::endl;
}//-----------------------------------------e.

//------------------------------------------s.
int main(int argc, char **argv) {
    gmain();
return 0;
}//-----------------------------------------e.
