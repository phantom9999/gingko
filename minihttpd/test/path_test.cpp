#include <pthread.h>
#include <string>
// #include "minihttpd/path.h"
#include "gtest/gtest.h"

TEST(PathTest, Ops) {
  ::std::string filePath("/home/work/noah/thirdparty/yii");
  // EXPECT_EQ("yii", argus::common::Path::getBaseName(filePath.c_str()));
  // EXPECT_EQ("/home/work/noah/thirdparty/", argus::common::Path::getDirectory(filePath.c_str()));
}

