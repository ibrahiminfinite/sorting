#include <gtest/gtest.h>

#include "InsertionSort.h"


TEST(SortingTest, SortSuccess)
{
    std::vector<int> keys{5,2,4,6,1,3};
    std::vector<int> sortedKeys{1,2,3,4,5,6};

    insertionSort(keys);
    ASSERT_EQ(keys, sortedKeys);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}