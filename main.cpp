/**
 * @file main.cpp
 *
 * Methods for printing ip addresses represented in different ways.
 */
#include <cassert>
#include <type_traits>
#include <vector>
#include <list>
#include <string>
#include <tuple>
#include <iostream>
#include <cstdlib>

#define PointDeterminated  '.'

using namespace std;


/**
 * @brief template Prints for int type out contents of an ip address represented.
 */
/// @brief 
/// @tparam T 
/// @tparam type 
/// @param data 
template <typename T, typename std::enable_if<std::is_integral< T >::value, bool>::type = true>
void print_ip(T data){
    static constexpr size_t size_byte = sizeof(T);
    for(auto i = size_byte; i--;){
        cout<<((data>>(i<<3))&0xff);
        if(i>0)
            cout<<PointDeterminated;
    }
    cout<<endl;
}
/**
 *  @brief Prints out contents of an ip address represented as a string.
 */
/// @brief 
/// @param data 
void print_ip(const string& data)
{
    cout << data << endl;
}

/**
 * @brief template Prints for is std::vector<int> or std::list<short> type out contents of an ip address represented.
 */
/// @brief 
/// @tparam T 
/// @tparam type 
/// @param container 
template <typename T, 
typename enable_if<is_same< T, vector<int>>::value or is_same< T, list<short>>::value, bool>::type = true>
void print_ip(T container){
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        cout << *it;
        if (it != prev(container.end()))
            cout << PointDeterminated;
    }
    cout << endl;
}
/**
 * @brief template Prints for tuple type out contents of an ip address represented.
 */
/// @brief 
/// @tparam TypeFirst 
/// @tparam ...Types 
/// @param tFirst 
/// @param ...tArgs 
template <typename TypeFirst, typename... Types>
void PrintTuple(const TypeFirst& tFirst, const Types&... tArgs) {

    std::cout << tFirst << PointDeterminated;
    auto index = sizeof...(Types)-1;

    auto printElem = [&tFirst, &index](const auto& x) {
        static_assert (std::is_same_v<decltype(tFirst), decltype(x)>, "Tuple's types is diffrent!");
        std::cout << x;

        if(index-- > 0)
            std::cout << PointDeterminated;
    };

    (printElem(tArgs), ...);
    std::cout << std::endl;
}

/// @brief 
/// @tparam ...Types 
/// @param tuple 
template <typename... Types>
static void print_ip(const std::tuple<Types...>& tuple)
{
    std::apply(PrintTuple<Types...>, tuple); 
}

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @return Program exit status
 */
int main()
{
    try
    {
        print_ip(int8_t{-1});
        print_ip(int16_t{0});
        print_ip( int32_t{2130706433} );
        print_ip( int64_t{8875824491850138409} );

        print_ip(std::string{"Hello, World!"});

        print_ip( std::vector<int>{100, 200, 300, 400} ); 
        print_ip( std::list<short>{400, 300, 200, 100} ); 
        print_ip( std::make_tuple(123, 456, 789, 0) );
        //std::tuple<std::string, std::string, std::string> tStr{"abc", "def", "gij"};
        //print_ip(tStr);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
