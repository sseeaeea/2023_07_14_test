#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"
#include "Math/Vector.h"
#include "Math/Quat.h"
#include "Math/Rotator.h"
#include "Math/Matrix.h"
#include "Math/TransformNonVectorized.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFVectorTest, "Beluga.FVector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFVectorTest::RunTest(const FString& Parameters)
{
	FVector VectorA(1.0f, 2.0f, 3.0f);
	FVector VectorB(4.0f, 5.0f, 6.0f);

	FVector VectorSum = VectorA + VectorB;
	FVector VectorDifference = VectorA - VectorB;
	FVector VectorScaled = VectorA * 2.0f;

	UE_LOG(LogTemp, Warning, TEXT("VectorSum: %s"), *VectorSum.ToString());
	UE_LOG(LogTemp, Warning, TEXT("VectorDifference: %s"), *VectorDifference.ToString());
	UE_LOG(LogTemp, Warning, TEXT("VectorScaled: %s"), *VectorScaled.ToString());


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFRotatorTest, "Beluga.FRotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFRotatorTest::RunTest(const FString& Parameters)
{


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFQuatTest, "Beluga.FQuat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFQuatTest::RunTest(const FString& Parameters)
{


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFMatrixTest, "Beluga.FMatrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFMatrixTest::RunTest(const FString& Parameters)
{


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFTransformTest, "Beluga.FTransform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFTransformTest::RunTest(const FString& Parameters)
{


	return true;
}