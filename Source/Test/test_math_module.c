#include "../math_module.h"
#include "unity.h"

/* sometimes you may want to get at local data in a module.
 * for example: If you plan to pass by reference, this could be useful
 * however, it should often be avoided */
extern int Counter;

void setUp(void)
{
  /* This is run before EACH TEST */
}

void tearDown(void)
{
}

void test_add(void)
{
  /* All of these should pass */
  TEST_ASSERT_EQUAL( 0, add(1,2));
}

void test_add2(void)
{
	TEST_ASSERT_EQUAL( 1, add(1,-3));
}	
void main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_add);
	RUN_TEST(test_add2);
	return UNITY_END();
}