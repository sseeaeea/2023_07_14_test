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
	FRotator RotatorA(0.0f, 45.0f, 0.0f);
	FRotator RotatorB(0.0f, 90.0f, 0.0f);

	FRotator RotatorSum = RotatorA + RotatorB;
	FRotator RotatorDifference = RotatorA - RotatorB;
	FRotator RotatorScaled = RotatorA * 2.0f;

	UE_LOG(LogTemp, Warning, TEXT("RotatorSum: %s"), *RotatorSum.ToString());
	UE_LOG(LogTemp, Warning, TEXT("RotatorDifference: %s"), *RotatorDifference.ToString());
	UE_LOG(LogTemp, Warning, TEXT("RotatorScaled: %s"), *RotatorScaled.ToString());


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFQuatTest, "Beluga.FQuat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFQuatTest::RunTest(const FString& Parameters)
{
	FQuat QuatA(FRotator(0.0f, 45.0f, 0.0f));
	FQuat QuatB(FRotator(0.0f, 90.0f, 0.0f));

	FQuat QuatProduct = QuatA * QuatB;
	FQuat QuatInverse = QuatA.Inverse();

	UE_LOG(LogTemp, Warning, TEXT("QuatProduct: %s"), *QuatProduct.ToString());
	UE_LOG(LogTemp, Warning, TEXT("QuatInverse: %s"), *QuatInverse.ToString());


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFMatrixTest, "Beluga.FMatrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFMatrixTest::RunTest(const FString& Parameters)
{
	FMatrix MatrixA(
		FVector(1.0f, 0.0f, 0.0f),
		FVector(0.0f, 1.0f, 0.0f),
		FVector(0.0f, 0.0f, 1.0f),
		FVector(0.0f, 0.0f, 0.0f)
	);

	FMatrix MatrixB(
		FVector(1.0f, 0.0f, 0.0f),
		FVector(0.0f, 1.0f, 0.0f),
		FVector(0.0f, 0.0f, 1.0f),
		FVector(1.0f, 2.0f, 3.0f)
	);

	FMatrix MatrixProduct = MatrixA * MatrixB;
	FVector TransformedVector = MatrixA.TransformVector(FVector(1.0f, 2.0f, 3.0f));

	UE_LOG(LogTemp, Warning, TEXT("MatrixProduct: %s"), *MatrixProduct.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TransformedVector: %s"), *TransformedVector.ToString());


	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaFTransformTest, "Beluga.FTransform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaFTransformTest::RunTest(const FString& Parameters)
{
	FTransform TransformA(FQuat(FRotator(0.0f, 45.0f, 0.0f)), FVector(1.0f, 2.0f, 3.0f));
	FTransform TransformB(FQuat(FRotator(0.0f, 90.0f, 0.0f)), FVector(4.0f, 5.0f, 6.0f));

	FTransform TransformProduct = TransformA * TransformB;
	FVector TransformedVector = TransformA.TransformPosition(FVector(1.0f, 2.0f, 3.0f));

	UE_LOG(LogTemp, Warning, TEXT("TransformProduct: %s"), *TransformProduct.ToString());
	UE_LOG(LogTemp, Warning, TEXT("TransformedVector: %s"), *TransformedVector.ToString());


	return true;
}