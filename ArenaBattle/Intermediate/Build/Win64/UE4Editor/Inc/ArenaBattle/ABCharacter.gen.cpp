// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ABCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABCharacter() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacter_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
	ARENABATTLE_API UFunction* Z_Construct_UFunction_AABCharacter_OnAttackMontageEnded();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_UABAnimInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void AABCharacter::StaticRegisterNativesAABCharacter()
	{
		UClass* Class = AABCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnAttackMontageEnded", &AABCharacter::execOnAttackMontageEnded },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AABCharacter_OnAttackMontageEnded()
	{
		struct ABCharacter_eventOnAttackMontageEnded_Parms
		{
			UAnimMontage* Montage;
			bool bInterupted;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bInterupted_SetBit = [](void* Obj){ ((ABCharacter_eventOnAttackMontageEnded_Parms*)Obj)->bInterupted = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInterupted = { UE4CodeGen_Private::EPropertyClass::Bool, "bInterupted", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ABCharacter_eventOnAttackMontageEnded_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bInterupted_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Montage = { UE4CodeGen_Private::EPropertyClass::Object, "Montage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ABCharacter_eventOnAttackMontageEnded_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bInterupted,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Montage,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AABCharacter, "OnAttackMontageEnded", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(ABCharacter_eventOnAttackMontageEnded_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AABCharacter_NoRegister()
	{
		return AABCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AABCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AABCharacter_OnAttackMontageEnded, "OnAttackMontageEnded" }, // 2899363337
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "ABCharacter.h" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackRadius_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackRadius = { UE4CodeGen_Private::EPropertyClass::Float, "AttackRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, STRUCT_OFFSET(AABCharacter, AttackRadius), METADATA_PARAMS(NewProp_AttackRadius_MetaData, ARRAY_COUNT(NewProp_AttackRadius_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackRange = { UE4CodeGen_Private::EPropertyClass::Float, "AttackRange", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, STRUCT_OFFSET(AABCharacter, AttackRange), METADATA_PARAMS(NewProp_AttackRange_MetaData, ARRAY_COUNT(NewProp_AttackRange_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ABAnim_MetaData[] = {
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ABAnim = { UE4CodeGen_Private::EPropertyClass::Object, "ABAnim", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AABCharacter, ABAnim), Z_Construct_UClass_UABAnimInstance_NoRegister, METADATA_PARAMS(NewProp_ABAnim_MetaData, ARRAY_COUNT(NewProp_ABAnim_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxCombo_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxCombo = { UE4CodeGen_Private::EPropertyClass::Int, "MaxCombo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, STRUCT_OFFSET(AABCharacter, MaxCombo), METADATA_PARAMS(NewProp_MaxCombo_MetaData, ARRAY_COUNT(NewProp_MaxCombo_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentCombo_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_CurrentCombo = { UE4CodeGen_Private::EPropertyClass::Int, "CurrentCombo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, STRUCT_OFFSET(AABCharacter, CurrentCombo), METADATA_PARAMS(NewProp_CurrentCombo_MetaData, ARRAY_COUNT(NewProp_CurrentCombo_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsComboInputOn_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			auto NewProp_IsComboInputOn_SetBit = [](void* Obj){ ((AABCharacter*)Obj)->IsComboInputOn = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsComboInputOn = { UE4CodeGen_Private::EPropertyClass::Bool, "IsComboInputOn", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AABCharacter), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_IsComboInputOn_SetBit)>::SetBit, METADATA_PARAMS(NewProp_IsComboInputOn_MetaData, ARRAY_COUNT(NewProp_IsComboInputOn_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanNextCombo_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			auto NewProp_CanNextCombo_SetBit = [](void* Obj){ ((AABCharacter*)Obj)->CanNextCombo = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanNextCombo = { UE4CodeGen_Private::EPropertyClass::Bool, "CanNextCombo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AABCharacter), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_CanNextCombo_SetBit)>::SetBit, METADATA_PARAMS(NewProp_CanNextCombo_MetaData, ARRAY_COUNT(NewProp_CanNextCombo_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttacking_MetaData[] = {
				{ "AllowPrivateAccess", "TRUE" },
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			auto NewProp_IsAttacking_SetBit = [](void* Obj){ ((AABCharacter*)Obj)->IsAttacking = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttacking = { UE4CodeGen_Private::EPropertyClass::Bool, "IsAttacking", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AABCharacter), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_IsAttacking_SetBit)>::SetBit, METADATA_PARAMS(NewProp_IsAttacking_MetaData, ARRAY_COUNT(NewProp_IsAttacking_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera = { UE4CodeGen_Private::EPropertyClass::Object, "Camera", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AABCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_Camera_MetaData, ARRAY_COUNT(NewProp_Camera_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm = { UE4CodeGen_Private::EPropertyClass::Object, "SpringArm", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AABCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_SpringArm_MetaData, ARRAY_COUNT(NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[] = {
				{ "Category", "Weapon" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ABCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Weapon = { UE4CodeGen_Private::EPropertyClass::Object, "Weapon", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AABCharacter, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(NewProp_Weapon_MetaData, ARRAY_COUNT(NewProp_Weapon_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackRadius,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackRange,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ABAnim,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxCombo,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentCombo,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsComboInputOn,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CanNextCombo,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsAttacking,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Camera,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpringArm,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Weapon,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AABCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AABCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AABCharacter, 1782151477);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AABCharacter(Z_Construct_UClass_AABCharacter, &AABCharacter::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AABCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
