#include "../math_module.h"
#include "unity.h"
#include "unity_fixture.h"



extern int Counter;

void setUp(void)
{
}

void tearDown(void)
{
}
void test_timer_isr(void)
{

  TEST_ASSERT_EQUAL( 0, timer_isr(1,1, 1, 0, 0, 0));
}
void test_timer_isr2(void)
{

  TEST_ASSERT_EQUAL( 1, timer_isr(10,0, 1, 0, 0, 0));
}
void test_timer_isr3(void)
{

  TEST_ASSERT_EQUAL( 2, timer_isr(0,0, 1, 0, 0, 0));
}
void test_timer_isr4(void)
{
  TEST_ASSERT_EQUAL( 3, timer_isr(1,0, 1, 0, 0, 0));
}
void test_timer_isr5(void)
{
  TEST_ASSERT_EQUAL( 4, timer_isr(10,0, 0, 0x01, 2, 0));
}
void test_timer_isr6(void)
{
  TEST_ASSERT_EQUAL( 5, timer_isr(10,0, 0, 0x05, 2, 0));
} 
void test_timer_isr7(void)
{
  TEST_ASSERT_EQUAL( 6, timer_isr(10,0, 0, 0x01, 3, 0));
} 
void test_timer_isr8(void)
{
  TEST_ASSERT_EQUAL( 7, timer_isr(0,1, 0, 0, 0, 1));
} 
void test_timer_isr9(void)
{
  TEST_ASSERT_EQUAL( 8, timer_isr(0,2, 0, 0, 0, 1));
} 
void test_timer_isr10(void)
{
  TEST_ASSERT_EQUAL( 9, timer_isr(0,3, 0, 0, 0, 1));
} 
void test_timer_isr11(void)
{
  TEST_ASSERT_EQUAL( 10, timer_isr(0,0, 0, 0, 0, 1));
} 
void test_timer_isr12(void)
{
  TEST_ASSERT_EQUAL( 11, timer_isr(0,0, 0, 0, 0, 0));
} 
void test_timer_isr13(void)
{
  TEST_ASSERT_EQUAL( 12, timer_isr(1,0, 0, 0, 0, 0));
}  

void run_All_Tests(){
	RUN_TEST(test_timer_isr);
	RUN_TEST(test_timer_isr2);
	RUN_TEST(test_timer_isr3);
	RUN_TEST(test_timer_isr4);
	RUN_TEST(test_timer_isr5);
	RUN_TEST(test_timer_isr6);
	RUN_TEST(test_timer_isr7);
	RUN_TEST(test_timer_isr8);
	RUN_TEST(test_timer_isr9);
	RUN_TEST(test_timer_isr10);
	RUN_TEST(test_timer_isr11);
	RUN_TEST(test_timer_isr12);
	RUN_TEST(test_timer_isr13);
}

int main(void)
{
	UNITY_BEGIN();
	run_All_Tests();
	return UNITY_END();
}