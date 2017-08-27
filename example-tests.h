#pragma once

#include "UnitTestFramework.h"
#include <sstream>

TEST_CASE("Timestamp", Timestamp_ClassKeepsAssignedData)
{
    const Timestamp ts(10000ul);
    Assert::AreEqual(ts.GetValue(), 10000ul);
}

TEST_CASE("Timestamp", Timestamp_SetChangesData)
{
    Timestamp ts(10000ul);
    Assert::AreEqual(ts.GetValue(), 10000ul);

    ts.SetValue(20000ul);
    Assert::AreEqual(ts.GetValue(), 20000ul);
}


TEST_CASE("Timestamp", Timestamp_DefaultTimestampIsZero)
{
  const Timestamp ts;
  Assert::AreEqual(ts.GetValue(), 0ul);
}

TEST_CASE("Timestamp", Timestamp_OutputStreamPrintsData)
{
  const Timestamp ts1(10000ul);
  const Timestamp ts2(20000ul);
  std::ostringstream oss1;
  std::ostringstream oss2;

  oss1 << ts1;
  Assert::AreEqual(oss1.str(), std::string("10000"));

  oss2 << ts1 << ' ' << ts2;
  Assert::AreEqual(oss2.str(), std::string("10000 20000"));
}

TEST_CASE("Timestamp", Timestamp_InputStreamSetsData)
{
  Timestamp ts1;
  Timestamp ts2(10000ul);
  std::istringstream iss1("20000");
  std::istringstream iss2("30000 40000");

  iss1 >> ts1;
  Assert::AreEqual(ts1.GetValue(), 20000ul);

  iss2 >> ts1 >> ts2;
  Assert::AreEqual(ts1.GetValue(), 30000ul);
  Assert::AreEqual(ts2.GetValue(), 40000ul);
}

TEST_CASE("Timestamp", Timestamp_AdditionAssignmentChangesData)
{
  Timestamp ts1(10000ul);

  ts1 += 20000ul;
  Assert::AreEqual(ts1.GetValue(), 30000ul);

  (ts1 += 20000ul) += 30000ul;
  Assert::AreEqual(ts1.GetValue(), 80000ul);

}

TEST_CASE("Timestamp", Timestamp_AdditionCalculatesCorrectly)
{
  const Timestamp ts1(10000ul);
  const Timestamp ts2(20000ul);

  Timestamp ts3 = ts1 + ts2;
  Assert::AreEqual(ts3.GetValue(), 30000ul);
}
