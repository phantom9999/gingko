#include <pthread.h>
#include "minihttpd/timestamp.h"
#include "gtest/gtest.h"
#include "glog/logging.h"

namespace argus {
namespace common {

TEST(TimestampTest, Ops) {
  Timestamp stamp = Timestamp::now();
  LOG(INFO) << stamp.toFormattedString();
}

}
}

