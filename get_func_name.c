/*
    gcc get_func_name.c  -ldl -rdynamic
*/
#include <stdio.h>
#define __USE_GNU
#include <dlfcn.h>

void hoge3() {
    Dl_info info[3];

    dladdr(__builtin_return_address(0), &info[0]);
    dladdr(__builtin_return_address(1), &info[1]);
    dladdr(__builtin_return_address(2), &info[2]);
    printf("[%s] parent func name => %p[%s] => %p[%s] => %p[%s]\n",
           __func__,
           __builtin_return_address(2), info[2].dli_sname,
           __builtin_return_address(1), info[1].dli_sname,
           __builtin_return_address(0), info[0].dli_sname
    );
}

void hoge2() {
    hoge3();
}

void hoge() {
    hoge2();
}

void foo() {
    hoge();
}

int main(int argc, char const* argv[])
{
    hoge();

    foo();

    return 0;
}
