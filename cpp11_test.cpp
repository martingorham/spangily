#include <iostream>
#include <string>
#include <type_traits>

template < typename T >
void display( T&& t)
{
    if ( std::is_rvalue_reference<T&&>::value )
    {
        std::cout << t << " is an rvalue." << std::endl;
    }
    else
    {
        std::cout << t << " is an lvalue." << std::endl;
    }
}

void process(void) {}

template <typename Type, typename... Args>
void process( Type&& type, Args&&... args )
{
    display( std::forward<Type>(type) );

    process( std::forward<Args>(args)... );
}

int main(int argc, char* argv[] )
{
    std::string value ("martin");
    const std::string test("test value");

    size_t x = 42;

    process(std::string("hello"), value.size(), x, true, value, "This is some text", std::move(test));

    return 0;
}
