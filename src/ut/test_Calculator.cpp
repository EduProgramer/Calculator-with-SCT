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

    SECTION( "Subtract 7.0 from 16.0" )
    {
        calc.subtract( 16.0 );
        calc.calculate( 7.0 );
        REQUIRE( calc.getStatus() == 9.0 );
    }

    SECTION( "Subtract 8.0 from 23.0" )
    {
        calc.subtract( 23.0 );
        calc.calculate( 8.0 );
        REQUIRE( calc.getStatus() == 15.0 );
    }
}
