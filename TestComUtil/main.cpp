#include <singleton.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "====================" << "test StaticSingleton" << "=====================" <<std::endl;
    std::cout << "test int = " << ComUtil::StaticSingleton<int>::instance() << std::endl;
    int a = 1, b = 2, c = 3, d = 4;
    ComUtil::StaticSingleton<DummyStaticSingleton1>::instance(a, b);
    ComUtil::StaticSingleton<DummyStaticSingleton1>::instance(c, d);
    DummyStaticSingleton::instance(a, b);

    std::cout << "====================" << "test LazyStaticSingleton" << "=====================" << std::endl;
    ComUtil::LazySingleton<DummyLazySingleton1>::instance(a, "test DummyLazySingleton1", b);
    ComUtil::LazySingleton<DummyLazySingleton1>::instance(a, "test DummyLazySingleton2", b);
    DummyLazySingleton::instance(a,"test DummyLazySingleton3", b);

}