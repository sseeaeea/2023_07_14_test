#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Containers/Set.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTArray, "Beluga.TArray", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTArray::RunTest(const FString& Parameters)
{
	TArray<int32> IntArray;
	IntArray.Init(2, 5);
	//IntArray == [2,2,2,2,2]

	TArray<FString> StrArr;
	StrArr.Add(TEXT("My name is")); // Add 배열에 복사
	StrArr.Emplace(TEXT("In Ho")); // Emplace 새로 생성
	// StrArr == ["My name is","In Ho"]

	StrArr.Insert(TEXT("Jang"), 1);
	// StrArr == ["My name is","Jang", "In Ho"]

	StrArr.SetNum(5);
	// StrArr == ["My name is","Jang", "In Ho", "", ""]

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTmap, "Beluga.Tmap", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTmap::RunTest(const FString& Parameters)
{
	TMap<int32, FString> Map;

	Map.Add(1, TEXT("Ramen"));
	Map.Add(3, TEXT("Sin"));
	Map.Add(4, TEXT("RA"));
	Map.Add(6, TEXT("Men"));
	// Map == [
	//  { Key: 1, Value: "Ramen" },
	//  { Key: 3, Value: "Sin"   },
	//  { Key: 4, Value: "RA"    },
	//  { Key: 6, Value: "Men"   }
	// ]

	Map.Emplace(2, TEXT("Bul")); // 임시생성을 피함
	// Map == [
	//  { Key: 1, Value: "Ramen" },
	//  { Key: 3, Value: "Sin"   },
	//  { Key: 4, Value: "RA"    },
	//  { Key: 6, Value: "Men"   },
	//  { Key: 2, Value: "Bul"   }
	// ]

	TMap<int32, FString> Map2;
	Map2.Emplace(4, TEXT("AR"));
	Map2.Emplace(2, TEXT("luB"));
	Map2.Emplace(5, TEXT("Mango"));
	Map.Append(Map2);
	// Map == [
	//  { Key: 1, Value: "Ramen" },
	//  { Key: 3, Value: "Sin"   },
	//  { Key: 4, Value: "AR"    },
	//  { Key: 6, Value: "Men"   },
	//  { Key: 2, Value: "luB"   },
	//  { Key: 5, Value: "Mango" }
	// ]

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTSetTest, "Beluga.TSet", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTSetTest::RunTest(const FString& Parameters)
{
	TSet<FString> Game;
	Game.Add(TEXT("Maple"));
	Game.Add(TEXT("LostArk"));
	Game.Add(TEXT("D&F"));
	// Game == [ "Maple", "LostArk", "D&F" ]

	Game.Emplace(TEXT("DJMAX"));
	// Game == [ "Maple", "LostArk", "D&F", "DJMAX" ]

	TSet<FString> Game2;
	Game2.Emplace(TEXT("Hearts of Iorn"));
	Game2.Emplace(TEXT("Battle Grounds"));
	Game2.Emplace(TEXT("Goose Goose Duck"));
	Game2.Emplace(TEXT("DJMAX"));
	Game.Append(Game2);
	// Game == [ "Maple", "LostArk", "D&F", "DJMAX", "Hearts of Iorn", "Battle Grounds", "Goose Goose Duck" ]

	return true;
}