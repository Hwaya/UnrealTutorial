// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABPawn_generated_h
#error "ABPawn.generated.h already included, missing '#pragma once' in ABPawn.h"
#endif
#define ARENABATTLE_ABPawn_generated_h

#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_RPC_WRAPPERS
#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABPawn(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_AABPawn(); \
public: \
	DECLARE_CLASS(AABPawn, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABPawn) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAABPawn(); \
	friend ARENABATTLE_API class UClass* Z_Construct_UClass_AABPawn(); \
public: \
	DECLARE_CLASS(AABPawn, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABPawn) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABPawn(AABPawn&&); \
	NO_API AABPawn(const AABPawn&); \
public:


#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABPawn(AABPawn&&); \
	NO_API AABPawn(const AABPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABPawn)


#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_PRIVATE_PROPERTY_OFFSET
#define ArenaBattle_Source_ArenaBattle_ABPawn_h_10_PROLOG
#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_RPC_WRAPPERS \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_INCLASS \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ArenaBattle_Source_ArenaBattle_ABPawn_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_PRIVATE_PROPERTY_OFFSET \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_INCLASS_NO_PURE_DECLS \
	ArenaBattle_Source_ArenaBattle_ABPawn_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ArenaBattle_Source_ArenaBattle_ABPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
