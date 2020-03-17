// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(TUTORIAL, Log, All);
//#define TTLOG_CALLINFO(FString(__FUNCTION__) + TEXT("(") + Fstring::FromInt(__LINE__) + TEXT(")"))
//#define TTLOG_S(Verbosity) UE_LOG(TUTORIAL, Verbosity, TEXT("%s"), *TTLOG_CALLINFO)
//#define TTLOG(Verbosity, Format, ...) UE_LOG(TUTORIAL, Verbosity, TEXT("%s%s"), *TTLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))