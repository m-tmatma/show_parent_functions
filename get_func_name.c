#include <stdio.h>
#define __USE_GNU
#include <dlfcn.h>

void hoge() {
    Dl_info info;
    dladdr(__builtin_return_address(0), &info);
    printf("[%s] parent func name => %p [%s]\n",
           __func__,
           __builtin_return_address(0),
           info.dli_sname);
}

void foo() {
    hoge();

    Dl_info info;
    dladdr(__builtin_return_address(0), &info);
    printf("[%s] parent func name => %p [%s]\n",
           __func__,
           __builtin_return_address(0),
           info.dli_sname);
}

int main(int argc, char const* argv[])
{
    hoge();

    foo();

    return 0;
}
