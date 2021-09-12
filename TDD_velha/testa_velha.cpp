
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa velha")
{
	int teste1[3][3] = {{2, 0, 1},
						{2, 0, 1},
						{0, 2, 1}};
	REQUIRE(VerificaVelha(teste1) == 0);
}

TEST_CASE("x row win")
{
	int test3[3][3] = {{0, 0, 0},
					   {1, 1, 1},
					   {2, 0, 1}};
	REQUIRE(VerifySet(test3, 1, 1) == 1);
	REQUIRE(VerifySet(test3, 2, 1) == -1);
}

TEST_CASE("o row win")
{
	int test4[3][3] = {{0, 0, 0},
					   {2, 2, 2},
					   {1, 0, 1}};
	REQUIRE(VerifySet(test4, 2, 1) == 2);
	REQUIRE(VerifySet(test4, 1, 1) == -1);
}

TEST_CASE("x column win")
{
	int test5[3][3] = {{1, 0, 0},
					   {1, 2, 2},
					   {1, 0, 2}};
	REQUIRE(VerifySet(test5, 1, 0) == 1);
	REQUIRE(VerifySet(test5, 2, 0) == -1);
}

TEST_CASE("o column win")
{
	int test6[3][3] = {{2, 0, 0},
					   {2, 1, 1},
					   {2, 0, 1}};
	REQUIRE(VerifySet(test6, 1, 0) == -1);
	REQUIRE(VerifySet(test6, 2, 0) == 2);
}

TEST_CASE("both row win")
{
	int test7[3][3] = {{1, 1, 1},
					   {2, 2, 2},
					   {2, 0, 1}};
	REQUIRE(VerifySet(test7, 1, 1) == 1);
	REQUIRE(VerifySet(test7, 2, 1) == 2);
}

TEST_CASE("diagonal x win")
{
	int test8[3][3] = {{1, 2, 1},
					   {2, 1, 2},
					   {1, 2, 1}};
	REQUIRE(VerifyDiagonal(test8, 1, 1) == 1);
	REQUIRE(VerifyDiagonal(test8, 1, 0) == 1);
}

TEST_CASE("diagonal o win")
{
	int test8[3][3] = {{2, 1, 2},
					   {1, 2, 1},
					   {2, 1, 2}};
	REQUIRE(VerifyDiagonal(test8, 2, 1) == 2);
	REQUIRE(VerifyDiagonal(test8, 2, 0) == 2);
}

TEST_CASE("diagonal fail")
{
	int test9[3][3] = {{2, 1, 2},
					   {1, 2, 1},
					   {1, 2, 1}};
	REQUIRE(VerifyDiagonal(test9, 2, 1) == -1);
}

TEST_CASE("diagonal fail if")
{
	int test10[3][3] = {{2, 1, 2},
						{1, 0, 1},
						{1, 2, 1}};
	REQUIRE(VerifyDiagonal(test10, 2, 1) == -1);
}

TEST_CASE("impossible game double win")
{
	int test11[3][3] = {{1, 1, 1},
						{2, 2, 2},
						{2, 0, 1}};
	REQUIRE(VerificaVelha(test11) == -2);
}

TEST_CASE("completion test")
{
	int test12[3][3] = {{1, 0, 1},
						{2, 0, 2},
						{2, 0, 1}};
	REQUIRE(VerifyCompletion(test12) == -1);
}

TEST_CASE("completion test case2")
{
	int test13[3][3] = {{1, 2, 1},
						{2, 1, 2},
						{2, 1, 1}};
	REQUIRE(VerifyCompletion(test13) == 0);
}