#include "bit_stuff.h"
#include "unity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

static void test_countOnes(void)
{
    TEST_ASSERT_EQUAL_UINT32(0, count_ones(0x0));
    TEST_ASSERT_EQUAL_UINT32(32, count_ones(0xffffffff));
    TEST_ASSERT_EQUAL_UINT32(16, count_ones(0x5a5a5a5a));
}

static void test_make_bitmask_creates_mask_with_correct_width(void)
{
    unsigned int mask = 0;
    make_bitmask(1, 0, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x1, mask);
    make_bitmask(2, 0, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x3, mask);
    make_bitmask(5, 0,&mask);
    TEST_ASSERT_EQUAL_HEX32(0x1f, mask);
    make_bitmask(32, 0, &mask);
    TEST_ASSERT_EQUAL_HEX32(0xffffffff, mask);
}

static void test_make_bitmask_creates_mask_with_correct_width_and_shift(void)
{
    unsigned int mask = 0;
    make_bitmask(1, 1, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x2, mask);
    make_bitmask(1, 7, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x80, mask);
    make_bitmask(1, 8, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x100, mask);
    make_bitmask(3, 15, &mask);
    TEST_ASSERT_EQUAL_HEX32(0x38000, mask);
    make_bitmask(8, 30, &mask);
    TEST_ASSERT_EQUAL_HEX32(0xC0000000, mask);
}

static void test_countOnesInBitMask(void)
{
    unsigned int i = 0, mask = 0;
    for (i = 0; i < 32; i++)
    {
        make_bitmask(i, 0, &mask);
        TEST_ASSERT_EQUAL_UINT32(i, count_ones(mask));
    }
}

static void test_apply_bit_mask(void)
{
  unsigned int masked_value = 0;
  apply_bitmask(0b10101110,0b11000011, &masked_value);
  TEST_ASSERT_EQUAL(0b10000010, masked_value);
}

static void test_flip_bit(void)
{
  unsigned int updated_value = 0;
  flip_bit(0b1011, 0, &updated_value);
  TEST_ASSERT_EQUAL(0b1010, updated_value);

  flip_bit(0b1011, 2, &updated_value);
  TEST_ASSERT_EQUAL(0b1111, updated_value);
}

static void test_extract_nibbles_from_byte(void)
{
  uint8_t high_nibble = 0, low_nibble = 0;
  extract_nibbles_from_byte(0b10111001, &high_nibble, &low_nibble);
  TEST_ASSERT_EQUAL(0b1001, low_nibble);
  TEST_ASSERT_EQUAL(0b1011, high_nibble);
}

static void test_combine_nibles_to_byte(void)
{
  uint8_t value = 0;
  combine_nibles_to_byte(0b1011, 0b0101, &value);
  TEST_ASSERT_EQUAL(0b10110101,value);
}

int main(void)
{
    UnityBegin();

    MY_RUN_TEST(test_make_bitmask_creates_mask_with_correct_width);
    MY_RUN_TEST(test_make_bitmask_creates_mask_with_correct_width_and_shift);
    MY_RUN_TEST(test_countOnes);
    MY_RUN_TEST(test_countOnesInBitMask);
    MY_RUN_TEST(test_apply_bit_mask);
    MY_RUN_TEST(test_flip_bit);
    MY_RUN_TEST(test_extract_nibbles_from_byte);
    MY_RUN_TEST(test_combine_nibles_to_byte);

    return UnityEnd();
}
