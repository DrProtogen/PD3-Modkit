// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CrimeForge/Public/ModMetadataObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModMetadataObject() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
CRIMEFORGE_API UClass* Z_Construct_UClass_UModMetadataObject();
CRIMEFORGE_API UClass* Z_Construct_UClass_UModMetadataObject_NoRegister();
CRIMEFORGE_API UScriptStruct* Z_Construct_UScriptStruct_FModDependencyDescriptorData();
UPackage* Z_Construct_UPackage__Script_CrimeForge();
// End Cross Module References

// Begin ScriptStruct FModDependencyDescriptorData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData;
class UScriptStruct* FModDependencyDescriptorData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModDependencyDescriptorData, (UObject*)Z_Construct_UPackage__Script_CrimeForge(), TEXT("ModDependencyDescriptorData"));
	}
	return Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.OuterSingleton;
}
template<> CRIMEFORGE_API UScriptStruct* StaticStruct<FModDependencyDescriptorData>()
{
	return FModDependencyDescriptorData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Dependencies Descriptor */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dependencies Descriptor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mod Reference of the dependency mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mod Reference of the dependency mod" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SemVersion_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compatible version range of the mod, it should follow the semver range format */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compatible version range of the mod, it should follow the semver range format" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All dependencies must be enabled at runtime */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All dependencies must be enabled at runtime" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOptional_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this dependency mod is optional, and the game should silently ignore it not being present */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this dependency mod is optional, and the game should silently ignore it not being present" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBasePlugin_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this dependency mod is a plugin that already exists in the base game */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this dependency mod is a plugin that already exists in the base game" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SemVersion;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static void NewProp_bOptional_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOptional;
	static void NewProp_bBasePlugin_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBasePlugin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModDependencyDescriptorData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModDependencyDescriptorData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_SemVersion = { "SemVersion", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModDependencyDescriptorData, SemVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SemVersion_MetaData), NewProp_SemVersion_MetaData) };
void Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FModDependencyDescriptorData*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FModDependencyDescriptorData), &Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
void Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bOptional_SetBit(void* Obj)
{
	((FModDependencyDescriptorData*)Obj)->bOptional = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bOptional = { "bOptional", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FModDependencyDescriptorData), &Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bOptional_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOptional_MetaData), NewProp_bOptional_MetaData) };
void Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bBasePlugin_SetBit(void* Obj)
{
	((FModDependencyDescriptorData*)Obj)->bBasePlugin = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bBasePlugin = { "bBasePlugin", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FModDependencyDescriptorData), &Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bBasePlugin_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBasePlugin_MetaData), NewProp_bBasePlugin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_SemVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bOptional,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewProp_bBasePlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CrimeForge,
	nullptr,
	&NewStructOps,
	"ModDependencyDescriptorData",
	Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::PropPointers),
	sizeof(FModDependencyDescriptorData),
	alignof(FModDependencyDescriptorData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModDependencyDescriptorData()
{
	if (!Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.InnerSingleton, Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData.InnerSingleton;
}
// End ScriptStruct FModDependencyDescriptorData

// Begin Class UModMetadataObject
void UModMetadataObject::StaticRegisterNativesUModMetadataObject()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UModMetadataObject);
UClass* Z_Construct_UClass_UModMetadataObject_NoRegister()
{
	return UModMetadataObject::StaticClass();
}
struct Z_Construct_UClass_UModMetadataObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n*\x09We use this object to display mod properties using details view.\n*\x09This is based on UPluginMetadataObject from the PluginBrowser engine plugin.\n*/" },
#endif
		{ "IncludePath", "ModMetadataObject.h" },
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "We use this object to display mod properties using details view.\nThis is based on UPluginMetadataObject from the PluginBrowser engine plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The default Unreal Engine Version field. This is set automatically to match the first section of SemVersion */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The default Unreal Engine Version field. This is set automatically to match the first section of SemVersion" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionName_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the version for this mod. Usually you want this to match SemVersion */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the version for this mod. Usually you want this to match SemVersion" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SemVersion_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Version number for the mod. Should always increase with new releases, and should follow the semver format. */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Version number for the mod. Should always increase with new releases, and should follow the semver format." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendlyName_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Friendly name of the mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Friendly name of the mod" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Description of the mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Description of the mod" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** This is set automatically to Modding to group mods together */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is set automatically to Modding to group mods together" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreatedBy_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The name(s) of the author(s) of the mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name(s) of the author(s) of the mod" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreatedByURL_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** URL of the author(s) of the mod. Could be a GitHub link for example. This is optional. */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "URL of the author(s) of the mod. Could be a GitHub link for example. This is optional." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DocsURL_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Documentation URL for the mod. In-game mod list will offer a button to users labeled \"Open Documentation\", http:// prefix is optional */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Documentation URL for the mod. In-game mod list will offer a button to users labeled \"Open Documentation\", http:// prefix is optional" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SupportURL_MetaData[] = {
		{ "Category", "Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Support URL for the mod. In-game mod list will offer a button to users labeled \"Get Support\", http:// prefix is optional */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Support URL for the mod. In-game mod list will offer a button to users labeled \"Get Support\", http:// prefix is optional" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Dependencies_MetaData[] = {
		{ "Category", "Dependencies" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Other mods that are required by the mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Other mods that are required by the mod" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemoteVersionRange_MetaData[] = {
		{ "Category", "Remote" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A semver range of accepted versions of the mod on remote clients. If unspecified, it defaults to the current SemVersion */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A semver range of accepted versions of the mod on remote clients. If unspecified, it defaults to the current SemVersion" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequiredOnRemote_MetaData[] = {
		{ "Category", "Remote" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this mod accepts being missing on the remote, i.e. behaving as a client-/server-side only mod */" },
#endif
		{ "ModuleRelativePath", "Public/ModMetadataObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this mod accepts being missing on the remote, i.e. behaving as a client-/server-side only mod" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VersionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SemVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FriendlyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CreatedBy;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CreatedByURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DocsURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SupportURL;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Dependencies_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Dependencies;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RemoteVersionRange;
	static void NewProp_bRequiredOnRemote_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequiredOnRemote;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModMetadataObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_VersionName = { "VersionName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, VersionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionName_MetaData), NewProp_VersionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_SemVersion = { "SemVersion", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, SemVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SemVersion_MetaData), NewProp_SemVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_FriendlyName = { "FriendlyName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, FriendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendlyName_MetaData), NewProp_FriendlyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_CreatedBy = { "CreatedBy", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, CreatedBy), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreatedBy_MetaData), NewProp_CreatedBy_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_CreatedByURL = { "CreatedByURL", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, CreatedByURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreatedByURL_MetaData), NewProp_CreatedByURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_DocsURL = { "DocsURL", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, DocsURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DocsURL_MetaData), NewProp_DocsURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_SupportURL = { "SupportURL", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, SupportURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SupportURL_MetaData), NewProp_SupportURL_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Dependencies_Inner = { "Dependencies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FModDependencyDescriptorData, METADATA_PARAMS(0, nullptr) }; // 3064606785
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Dependencies = { "Dependencies", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, Dependencies), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Dependencies_MetaData), NewProp_Dependencies_MetaData) }; // 3064606785
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_RemoteVersionRange = { "RemoteVersionRange", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModMetadataObject, RemoteVersionRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemoteVersionRange_MetaData), NewProp_RemoteVersionRange_MetaData) };
void Z_Construct_UClass_UModMetadataObject_Statics::NewProp_bRequiredOnRemote_SetBit(void* Obj)
{
	((UModMetadataObject*)Obj)->bRequiredOnRemote = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UModMetadataObject_Statics::NewProp_bRequiredOnRemote = { "bRequiredOnRemote", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UModMetadataObject), &Z_Construct_UClass_UModMetadataObject_Statics::NewProp_bRequiredOnRemote_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequiredOnRemote_MetaData), NewProp_bRequiredOnRemote_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModMetadataObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_VersionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_SemVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_FriendlyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_CreatedBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_CreatedByURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_DocsURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_SupportURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Dependencies_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_Dependencies,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_RemoteVersionRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModMetadataObject_Statics::NewProp_bRequiredOnRemote,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModMetadataObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UModMetadataObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CrimeForge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModMetadataObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModMetadataObject_Statics::ClassParams = {
	&UModMetadataObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UModMetadataObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UModMetadataObject_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModMetadataObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UModMetadataObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UModMetadataObject()
{
	if (!Z_Registration_Info_UClass_UModMetadataObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModMetadataObject.OuterSingleton, Z_Construct_UClass_UModMetadataObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModMetadataObject.OuterSingleton;
}
template<> CRIMEFORGE_API UClass* StaticClass<UModMetadataObject>()
{
	return UModMetadataObject::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UModMetadataObject);
UModMetadataObject::~UModMetadataObject() {}
// End Class UModMetadataObject

// Begin Registration
struct Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FModDependencyDescriptorData::StaticStruct, Z_Construct_UScriptStruct_FModDependencyDescriptorData_Statics::NewStructOps, TEXT("ModDependencyDescriptorData"), &Z_Registration_Info_UScriptStruct_ModDependencyDescriptorData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModDependencyDescriptorData), 3064606785U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModMetadataObject, UModMetadataObject::StaticClass, TEXT("UModMetadataObject"), &Z_Registration_Info_UClass_UModMetadataObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModMetadataObject), 1309871601U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_1706674917(TEXT("/Script/CrimeForge"),
	Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PAYDAY3_Source_Plugins_CrimeForge_Source_CrimeForge_Public_ModMetadataObject_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
