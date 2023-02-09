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
#include <algorithm>

#define PointDeterminated  '.'

using namespace std;
/// @brief ////////
namespace temp{
    /// @brief ///
    /// @tparam T 
    template< typename T >
    using EnableInteger = std::enable_if_t< std::is_integral_v< T > && !std::is_same_v<T, bool>> ;

    /// @brief /
    /// @tparam T 
    template<typename T>
    using EnableString = enable_if_t<std::is_same_v<std::decay_t<T>, std::string>>;


    /// @brief ///////
    /// @tparam T 
    template <typename T>
    using EnableListVector = enable_if_t<is_same_v< T, vector<typename T::value_type>> 
                                || is_same_v< T, list<typename T::value_type>>, void>;

    template<typename T, typename... Types>
    using EnableAllTypesEqual = enable_if_t<std::conjunction_v<std::is_same<T, Types>...>>;
}

/// @brief ///
/// @tparam T 
/// @param val 
/// @return 
template< typename T>
typename temp::EnableInteger< T >
print_ip(const T& val){
    uint8_t* sim = (uint8_t *) &val + sizeof(T)-1;
    for (uint16_t i = 0; i < sizeof(T)-1; i++)
        cout<<(uint16_t)*sim--<<PointDeterminated; 

    cout<<(uint16_t)*sim<<endl;
}
/// @brief ///
/// @tparam T 
/// @param s 
/// @return 
template<typename T>
typename temp::EnableString<T>
print_ip(const T& s){
    cout<<s<<endl;
}

/// @brief ///
/// @tparam T 
/// @param conteiner 
/// @return 
template<typename T>
typename temp::EnableListVector<T>
print_ip(const T& conteiner){

    if(conteiner.empty()) return;

    cout << *conteiner.cbegin();
    std::for_each(std::next(conteiner.cbegin()), std::cend(conteiner), [](const auto &i){ cout << PointDeterminated << i; });
    cout<<endl;
}

template <typename T, typename... Types>
void PrintTuple(const T& tFirst, const Types&... tArgs) {

    std::cout << tFirst << PointDeterminated;
    auto index = sizeof...(Types)-1;

    auto printElem = [&tFirst, &index](const auto& x) {
        std::cout << x;

        if(index-- > 0)
            std::cout << PointDeterminated;
    };

    (printElem(tArgs), ...);
    std::cout << std::endl;
}
/// @brief ///
/// @tparam ...Types 
/// @tparam T 
/// @param tuple 
/// @return 
template <typename T, typename... Types>
typename temp::EnableAllTypesEqual<T, Types...>
print_ip(const std::tuple<T, Types...>& tuple)
{
    std::apply(PrintTuple<T, Types...>, tuple); 
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
        //std::tuple<std::string, std::string, std::string> tStr{"abc", "def"," 10"};
        //print_ip(tStr);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
