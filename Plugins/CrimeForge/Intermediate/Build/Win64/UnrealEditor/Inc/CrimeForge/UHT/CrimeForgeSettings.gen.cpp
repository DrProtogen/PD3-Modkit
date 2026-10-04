// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CrimeForge/Public/CrimeForgeSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrimeForgeSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
CRIMEFORGE_API UClass* Z_Construct_UClass_UCrimeForgeSettings();
CRIMEFORGE_API UClass* Z_Construct_UClass_UCrimeForgeSettings_NoRegister();
CRIMEFORGE_API UEnum* Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType();
UPackage* Z_Construct_UPackage__Script_CrimeForge();
// End Cross Module References

// Begin Enum ECrimeForgeStartGameType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECrimeForgeStartGameType;
static UEnum* ECrimeForgeStartGameType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECrimeForgeStartGameType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECrimeForgeStartGameType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType, (UObject*)Z_Construct_UPackage__Script_CrimeForge(), TEXT("ECrimeForgeStartGameType"));
	}
	return Z_Registration_Info_UEnum_ECrimeForgeStartGameType.OuterSingleton;
}
template<> CRIMEFORGE_API UEnum* StaticEnum<ECrimeForgeStartGameType>()
{
	return ECrimeForgeStartGameType_StaticEnum();
}
struct Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "EPIC_GAMES.DisplayName", "Epic Games Store" },
		{ "EPIC_GAMES.Name", "ECrimeForgeStartGameType::EPIC_GAMES" },
		{ "MICROSOFT_STORE.DisplayName", "Microsoft Store / Xbox" },
		{ "MICROSOFT_STORE.Name", "ECrimeForgeStartGameType::MICROSOFT_STORE" },
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
		{ "NONE.DisplayName", "Do not launch" },
		{ "NONE.Name", "ECrimeForgeStartGameType::NONE" },
		{ "STEAM.DisplayName", "Steam" },
		{ "STEAM.Name", "ECrimeForgeStartGameType::STEAM" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECrimeForgeStartGameType::NONE", (int64)ECrimeForgeStartGameType::NONE },
		{ "ECrimeForgeStartGameType::STEAM", (int64)ECrimeForgeStartGameType::STEAM },
		{ "ECrimeForgeStartGameType::MICROSOFT_STORE", (int64)ECrimeForgeStartGameType::MICROSOFT_STORE },
		{ "ECrimeForgeStartGameType::EPIC_GAMES", (int64)ECrimeForgeStartGameType::EPIC_GAMES },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CrimeForge,
	nullptr,
	"ECrimeForgeStartGameType",
	"ECrimeForgeStartGameType",
	Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType()
{
	if (!Z_Registration_Info_UEnum_ECrimeForgeStartGameType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECrimeForgeStartGameType.InnerSingleton, Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECrimeForgeStartGameType.InnerSingleton;
}
// End Enum ECrimeForgeStartGameType

// Begin Class UCrimeForgeSettings
void UCrimeForgeSettings::StaticRegisterNativesUCrimeForgeSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCrimeForgeSettings);
UClass* Z_Construct_UClass_UCrimeForgeSettings_NoRegister()
{
	return UCrimeForgeSettings::StaticClass();
}
struct Z_Construct_UClass_UCrimeForgeSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Single Project Settings object for all CrimeForge configuration.\n *\n * It is registered manually under Project Settings -> Plugins -> CrimeForge so the editor shows\n * one CrimeForge page with normal expandable categories.\n */" },
#endif
		{ "IncludePath", "CrimeForgeSettings.h" },
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single Project Settings object for all CrimeForge configuration.\n\nIt is registered manually under Project Settings -> Plugins -> CrimeForge so the editor shows\none CrimeForge page with normal expandable categories." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PD3GamePath_MetaData[] = {
		{ "Category", "General|PAYDAY 3" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* General ------------------------------------------------------------------------------ */" },
#endif
		{ "DisplayName", "PAYDAY 3 Game Path" },
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "General ------------------------------------------------------------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCopyModsToGame_MetaData[] = {
		{ "Category", "General|PAYDAY 3" },
		{ "DisplayName", "Copy Mods To Game" },
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LaunchGameAfterPacking_MetaData[] = {
		{ "Category", "General|PAYDAY 3" },
		{ "DisplayName", "Launch Game After Packing" },
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModSelection_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Internal state ----------------------------------------------------------------------- */" },
#endif
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal state -----------------------------------------------------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMigratedLegacyCrimeForgeGameSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/CrimeForgeSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PD3GamePath;
	static void NewProp_bCopyModsToGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCopyModsToGame;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LaunchGameAfterPacking_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LaunchGameAfterPacking;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ModSelection_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ModSelection_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ModSelection;
	static void NewProp_bMigratedLegacyCrimeForgeGameSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMigratedLegacyCrimeForgeGameSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCrimeForgeSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_PD3GamePath = { "PD3GamePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrimeForgeSettings, PD3GamePath), Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PD3GamePath_MetaData), NewProp_PD3GamePath_MetaData) };
void Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bCopyModsToGame_SetBit(void* Obj)
{
	((UCrimeForgeSettings*)Obj)->bCopyModsToGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bCopyModsToGame = { "bCopyModsToGame", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCrimeForgeSettings), &Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bCopyModsToGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCopyModsToGame_MetaData), NewProp_bCopyModsToGame_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_LaunchGameAfterPacking_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_LaunchGameAfterPacking = { "LaunchGameAfterPacking", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrimeForgeSettings, LaunchGameAfterPacking), Z_Construct_UEnum_CrimeForge_ECrimeForgeStartGameType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LaunchGameAfterPacking_MetaData), NewProp_LaunchGameAfterPacking_MetaData) }; // 2914092134
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection_ValueProp = { "ModSelection", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection_Key_KeyProp = { "ModSelection_Key", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection = { "ModSelection", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCrimeForgeSettings, ModSelection), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModSelection_MetaData), NewProp_ModSelection_MetaData) };
void Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bMigratedLegacyCrimeForgeGameSettings_SetBit(void* Obj)
{
	((UCrimeForgeSettings*)Obj)->bMigratedLegacyCrimeForgeGameSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bMigratedLegacyCrimeForgeGameSettings = { "bMigratedLegacyCrimeForgeGameSettings", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCrimeForgeSettings), &Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bMigratedLegacyCrimeForgeGameSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMigratedLegacyCrimeForgeGameSettings_MetaData), NewProp_bMigratedLegacyCrimeForgeGameSettings_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCrimeForgeSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_PD3GamePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bCopyModsToGame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_LaunchGameAfterPacking_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_LaunchGameAfterPacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_ModSelection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCrimeForgeSettings_Statics::NewProp_bMigratedLegacyCrimeForgeGameSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrimeForgeSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCrimeForgeSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CrimeForge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCrimeForgeSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCrimeForgeSettings_Statics::ClassParams = {
	&UCrimeForgeSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCrimeForgeSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCrimeForgeSettings_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCrimeForgeSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UCrimeForgeSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCrimeForgeSettings()
{
	if (!Z_Registration_Info_UClass_UCrimeForgeSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCrimeForgeSettings.OuterSingleton, Z_Construct_UClass_UCrimeForgeSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCrimeForgeSettings.OuterSingleton;
}
template<> CRIMEFORGE_API UClass* StaticClass<UCrimeForgeSettings>()
{
	return UCrimeForgeSettings::StaticClass();
}
UCrimeForgeSettings::UCrimeForgeSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCrimeForgeSettings);
UCrimeForgeSettings::~UCrimeForgeSettings() {}
// End Class UCrimeForgeSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECrimeForgeStartGameType_StaticEnum, TEXT("ECrimeForgeStartGameType"), &Z_Registration_Info_UEnum_ECrimeForgeStartGameType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2914092134U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCrimeForgeSettings, UCrimeForgeSettings::StaticClass, TEXT("UCrimeForgeSettings"), &Z_Registration_Info_UClass_UCrimeForgeSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCrimeForgeSettings), 3320255275U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_4203096927(TEXT("/Script/CrimeForge"),
	Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
