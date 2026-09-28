// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CrimeForgeSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CRIMEFORGE_CrimeForgeSettings_generated_h
#error "CrimeForgeSettings.generated.h already included, missing '#pragma once' in CrimeForgeSettings.h"
#endif
#define CRIMEFORGE_CrimeForgeSettings_generated_h

#define FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCrimeForgeSettings(); \
	friend struct Z_Construct_UClass_UCrimeForgeSettings_Statics; \
public: \
	DECLARE_CLASS(UCrimeForgeSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CrimeForge"), NO_API) \
	DECLARE_SERIALIZER(UCrimeForgeSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCrimeForgeSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCrimeForgeSettings(UCrimeForgeSettings&&); \
	UCrimeForgeSettings(const UCrimeForgeSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCrimeForgeSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCrimeForgeSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCrimeForgeSettings) \
	NO_API virtual ~UCrimeForgeSettings();


#define FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_21_PROLOG
#define FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_24_INCLASS_NO_PURE_DECLS \
	FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRIMEFORGE_API UClass* StaticClass<class UCrimeForgeSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_CrimeForgeSettings_h


#define FOREACH_ENUM_ECRIMEFORGESTARTGAMETYPE(op) \
	op(ECrimeForgeStartGameType::NONE) \
	op(ECrimeForgeStartGameType::STEAM) \
	op(ECrimeForgeStartGameType::MICROSOFT_STORE) \
	op(ECrimeForgeStartGameType::EPIC_GAMES) 

enum class ECrimeForgeStartGameType : uint8;
template<> struct TIsUEnumClass<ECrimeForgeStartGameType> { enum { Value = true }; };
template<> CRIMEFORGE_API UEnum* StaticEnum<ECrimeForgeStartGameType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
