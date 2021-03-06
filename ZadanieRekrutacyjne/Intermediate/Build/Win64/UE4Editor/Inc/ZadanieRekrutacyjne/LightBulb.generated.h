// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;
#ifdef ZADANIEREKRUTACYJNE_LightBulb_generated_h
#error "LightBulb.generated.h already included, missing '#pragma once' in LightBulb.h"
#endif
#define ZADANIEREKRUTACYJNE_LightBulb_generated_h

#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_RPC_WRAPPERS \
	virtual bool NetMulticastSetColor_Validate(FLinearColor ); \
	virtual void NetMulticastSetColor_Implementation(FLinearColor color); \
	virtual bool NetMulticastToggleLight_Validate(); \
	virtual void NetMulticastToggleLight_Implementation(); \
	virtual bool NetMulticastTogglePulsing_Validate(); \
	virtual void NetMulticastTogglePulsing_Implementation(); \
 \
	DECLARE_FUNCTION(execNetMulticastSetColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastSetColor_Validate(Z_Param_color)) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastSetColor_Validate")); \
			return; \
		} \
		this->NetMulticastSetColor_Implementation(Z_Param_color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNetMulticastToggleLight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastToggleLight_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastToggleLight_Validate")); \
			return; \
		} \
		this->NetMulticastToggleLight_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNetMulticastTogglePulsing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastTogglePulsing_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastTogglePulsing_Validate")); \
			return; \
		} \
		this->NetMulticastTogglePulsing_Implementation(); \
		P_NATIVE_END; \
	}


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNetMulticastSetColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastSetColor_Validate(Z_Param_color)) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastSetColor_Validate")); \
			return; \
		} \
		this->NetMulticastSetColor_Implementation(Z_Param_color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNetMulticastToggleLight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastToggleLight_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastToggleLight_Validate")); \
			return; \
		} \
		this->NetMulticastToggleLight_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNetMulticastTogglePulsing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->NetMulticastTogglePulsing_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("NetMulticastTogglePulsing_Validate")); \
			return; \
		} \
		this->NetMulticastTogglePulsing_Implementation(); \
		P_NATIVE_END; \
	}


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_EVENT_PARMS \
	struct LightBulb_eventNetMulticastSetColor_Parms \
	{ \
		FLinearColor color; \
	};


extern ZADANIEREKRUTACYJNE_API  FName ZADANIEREKRUTACYJNE_NetMulticastSetColor;
extern ZADANIEREKRUTACYJNE_API  FName ZADANIEREKRUTACYJNE_NetMulticastToggleLight;
extern ZADANIEREKRUTACYJNE_API  FName ZADANIEREKRUTACYJNE_NetMulticastTogglePulsing;
#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_CALLBACK_WRAPPERS
#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesALightBulb(); \
	friend ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ALightBulb(); \
	public: \
	DECLARE_CLASS(ALightBulb, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ZadanieRekrutacyjne"), NO_API) \
	DECLARE_SERIALIZER(ALightBulb) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_INCLASS \
	private: \
	static void StaticRegisterNativesALightBulb(); \
	friend ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ALightBulb(); \
	public: \
	DECLARE_CLASS(ALightBulb, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ZadanieRekrutacyjne"), NO_API) \
	DECLARE_SERIALIZER(ALightBulb) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALightBulb(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALightBulb) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightBulb); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightBulb); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightBulb(ALightBulb&&); \
	NO_API ALightBulb(const ALightBulb&); \
public:


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightBulb(ALightBulb&&); \
	NO_API ALightBulb(const ALightBulb&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightBulb); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightBulb); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALightBulb)


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LightBulbMeshComponent() { return STRUCT_OFFSET(ALightBulb, LightBulbMeshComponent); } \
	FORCEINLINE static uint32 __PPO__LightSource() { return STRUCT_OFFSET(ALightBulb, LightSource); }


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_10_PROLOG \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_EVENT_PARMS


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_PRIVATE_PROPERTY_OFFSET \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_RPC_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_CALLBACK_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_INCLASS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_PRIVATE_PROPERTY_OFFSET \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_CALLBACK_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_INCLASS_NO_PURE_DECLS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_LightBulb_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
