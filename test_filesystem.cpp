#include "gtest/gtest.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <filesystem>

class TestFilesystem: public ::testing::Test
{
public:
	void TestCwd(void) const;
};
	
TEST_F(TestFilesystem, TestCwd) { return TestCwd(); };

void TestFilesystem::TestCwd(void) const
{
  auto const boost_cwd = boost::filesystem::current_path();
  auto const std_cwd = std::filesystem::current_path();
  
  ASSERT_EQ(boost_cwd.string(), std_cwd.string());
  
  return;
}
