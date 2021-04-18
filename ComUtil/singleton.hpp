#include <utility>
#include <ostream>
#include <tuple>
#include <mutex>
#include <string>

namespace ComUtil {
    template <class T>
    class StaticSingleton {
    public:
        template <typename ... Args>
        static T& instance(Args&&... args) {
            std::cout << "args size:"<< sizeof...(args) << std::endl ;
            static T obj(std::forward<Args>(args)...);
            return obj;
        }
    protected:
        StaticSingleton() {};
    private:
        StaticSingleton(const StaticSingleton&) = delete;
        StaticSingleton(StaticSingleton&&) = delete;
        StaticSingleton& operator=(const StaticSingleton&) = delete;
        StaticSingleton& operator=(StaticSingleton&&) = delete;
    };

    template <class T>
    class OnceFlag {
    public:
        std::once_flag m_flag;
    };

    template <class T>
    class LazySingleton {
    public:
        template <typename... Args>
        static T& instance(Args&&... args) {
            std::cout << "args size:" << sizeof...(args) << std::endl;
            static T* pObj;
            static OnceFlag<T> flag;
            std::call_once(flag.m_flag, [&]() {
                pObj = new T(std::forward<Args>(args)...);
            });
            return *pObj;
        }
    protected:
        LazySingleton() {};
    private:
        LazySingleton(const LazySingleton&) = delete;
        LazySingleton(LazySingleton&&) = delete;
        LazySingleton& operator = (const LazySingleton&) = delete;
        LazySingleton& operator = (LazySingleton&&) = delete;
    };
}


#include <iostream>

class DummyStaticSingleton : public ComUtil::StaticSingleton<DummyStaticSingleton> {
protected:
    DummyStaticSingleton(int a, int b) {
        std::cout << "==========!" << a << b << std::endl;
    };
    friend class ComUtil::StaticSingleton<DummyStaticSingleton>;
};

class DummyStaticSingleton1{
public:
    DummyStaticSingleton1(int a, int b) {
        std::cout << "==========!" << a << b << std::endl;
    };
};

class DummyLazySingleton : public ComUtil::LazySingleton<DummyLazySingleton> {
protected:
    DummyLazySingleton(int a, const std::string& b, int c) {
        std::cout << "=========" << a << b << c << std::endl;
    };
    friend class ComUtil::LazySingleton<DummyLazySingleton>;
};

class DummyLazySingleton1 {
public:
    DummyLazySingleton1(int a, const std::string& b, int c) {
        std::cout << "=========" << a << b << c << std::endl;
    };
};