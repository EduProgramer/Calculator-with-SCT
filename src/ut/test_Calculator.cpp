#include "catch.hpp"

#include "Calculator.hpp"

TEST_CASE( "Calculator can do basic operations on two numbers", "[Calculator]" )
{
    Calculator calc;

    SECTION( "Add 15.0 to 36.0" )
    {
        calc.add( 15.0 );
        calc.calculate( 36.0 );
        REQUIRE( calc.getStatus() == 51.0 );
    }

    SECTION( "Add 16.0 to 16.0" )
    {
        calc.add( 16.0 );
        calc.calculate( 16.0 );
        REQUIRE( calc.getStatus() == 32.0 );
    }
}
