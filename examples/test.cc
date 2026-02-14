#include <iostream>

#include "xcmixin/xcmixin.hpp"
XCMIXIN_PRE_DECL(name_method)
XCMIXIN_PRE_DECL(new_name_method)
XCMIXIN_METHOD_REQUIRE(name_method, xcmixin_no_hiding(name,int()););

XCMIXIN_METHOD_DEF_BEGIN(name_method)
int name() { return 1; }
XCMIXIN_METHOD_DEF_END()

XCMIXIN_METHOD_DEF_BEGIN(new_name_method)
int name() { return 12; }
XCMIXIN_METHOD_DEF_END()

class MyClass;

XCMIXIN_IMPL_METHOD_BEGIN(name_method)
XCMIXIN_IMPL_METHOD_FOR(MyClass)
int name() { return 1; }
int name(int i) { return 2; }
int name(int i) const { return 3; }
XCMIXIN_IMPL_METHOD_END()

XCMIXIN_IMPL_METHOD_BEGIN(new_name_method)
XCMIXIN_IMPL_METHOD_EXTEND_FOR(name_method, MyClass)
// using base::name;
// int name(int i) const { return 4; }
XCMIXIN_IMPL_METHOD_END()

using recorder = xcmixin::method_recorder< name_method>;

class MyClass : public xcmixin::impl_methods_recorders<MyClass, recorder> {
    xcmixin_init_class;
};



int main() {
    MyClass my_class;

    std::cout << my_class.name();


    return 0;
}