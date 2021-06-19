#include <iostream>
using namespace std;
namespace adl
{
    template <typename _Tp>
    constexpr _Tp &&
    forward(typename std::remove_reference<_Tp>::type &__t) noexcept
    {
        return static_cast<_Tp &&>(__t);
    }

    /**
   *  @brief  Forward an rvalue.
   *  @return The parameter cast to the specified type.
   *
   *  This function is used to implement "perfect forwarding".
   */
    template <typename _Tp>
    constexpr _Tp &&
    forward(typename std::remove_reference<_Tp>::type &&__t) noexcept
    {
        static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
                                                             " substituting _Tp is an lvalue reference type");
        return static_cast<_Tp &&>(__t);
    }
} // namespace adl
template <typename fun, typename a, typename b>
void exec(fun f, a &&tmpa, b &&tmpb)
{
    f(std::forward(tmpa), std::forward(tmpb));
}
/* 
cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’ 
*/
int tmp(int &&a, int &&b)
{
    cout << a * b << endl;
}

int main()
{
    int a = 5;
    int b = 6;
    exec(tmp, std::move(a), 6);
}
