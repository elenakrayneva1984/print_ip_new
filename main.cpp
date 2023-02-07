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
        /*print_ip(int8_t{-1});
        print_ip(int16_t{0});
        print_ip( int32_t{2130706433} );
        print_ip( int64_t{8875824491850138409} );

        print_ip(std::string{"Hello, World!"});

        print_ip( std::vector<int>{100, 200, 300, 400} ); 
        print_ip( std::list<short>{400, 300, 200, 100} ); 
        print_ip( std::make_tuple(123, 456, 789, 0) );*/
        //std::tuple<std::string, std::string, std::string> tStr{"abc", "def", "gij"};
        //print_ip(tStr);
        cout<<"Hello print_ip_new"<<endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
