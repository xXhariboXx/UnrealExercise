// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZADANIEREKRUTACYJNE_DamagableActor_generated_h
#error "DamagableActor.generated.h already included, missing '#pragma once' in DamagableActor.h"
#endif
#define ZADANIEREKRUTACYJNE_DamagableActor_generated_h

#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_RPC_WRAPPERS \
	virtual bool ServerUpdateHealth_Validate(float ); \
	virtual void ServerUpdateHealth_Implementation(float fDamage); \
	virtual void HandleDamage_Implementation(float fDamageValue); \
 \
	DECLARE_FUNCTION(execServerUpdateHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fDamage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerUpdateHealth_Validate(Z_Param_fDamage)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerUpdateHealth_Validate")); \
			return; \
		} \
		this->ServerUpdateHealth_Implementation(Z_Param_fDamage); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fDamageValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HandleDamage_Implementation(Z_Param_fDamageValue); \
		P_NATIVE_END; \
	}


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execServerUpdateHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fDamage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerUpdateHealth_Validate(Z_Param_fDamage)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerUpdateHealth_Validate")); \
			return; \
		} \
		this->ServerUpdateHealth_Implementation(Z_Param_fDamage); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_fDamageValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HandleDamage_Implementation(Z_Param_fDamageValue); \
		P_NATIVE_END; \
	}


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_EVENT_PARMS \
	struct DamagableActor_eventHandleDamage_Parms \
	{ \
		float fDamageValue; \
	}; \
	struct DamagableActor_eventServerUpdateHealth_Parms \
	{ \
		float fDamage; \
	};


extern ZADANIEREKRUTACYJNE_API  FName ZADANIEREKRUTACYJNE_HandleDamage;
extern ZADANIEREKRUTACYJNE_API  FName ZADANIEREKRUTACYJNE_ServerUpdateHealth;
#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_CALLBACK_WRAPPERS
#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesADamagableActor(); \
	friend ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ADamagableActor(); \
	public: \
	DECLARE_CLASS(ADamagableActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ZadanieRekrutacyjne"), NO_API) \
	DECLARE_SERIALIZER(ADamagableActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ADamagableActor*>(this); } \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_INCLASS \
	private: \
	static void StaticRegisterNativesADamagableActor(); \
	friend ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ADamagableActor(); \
	public: \
	DECLARE_CLASS(ADamagableActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ZadanieRekrutacyjne"), NO_API) \
	DECLARE_SERIALIZER(ADamagableActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ADamagableActor*>(this); } \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADamagableActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamagableActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamagableActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamagableActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamagableActor(ADamagableActor&&); \
	NO_API ADamagableActor(const ADamagableActor&); \
public:


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamagableActor(ADamagableActor&&); \
	NO_API ADamagableActor(const ADamagableActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamagableActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamagableActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamagableActor)


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__fMaxHealth() { return STRUCT_OFFSET(ADamagableActor, fMaxHealth); } \
	FORCEINLINE static uint32 __PPO__fCurrentHealth() { return STRUCT_OFFSET(ADamagableActor, fCurrentHealth); } \
	FORCEINLINE static uint32 __PPO__bIsDead() { return STRUCT_OFFSET(ADamagableActor, bIsDead); } \
	FORCEINLINE static uint32 __PPO__BaseComponent() { return STRUCT_OFFSET(ADamagableActor, BaseComponent); }


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_12_PROLOG \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_EVENT_PARMS


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_PRIVATE_PROPERTY_OFFSET \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_RPC_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_CALLBACK_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_INCLASS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_PRIVATE_PROPERTY_OFFSET \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_CALLBACK_WRAPPERS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_INCLASS_NO_PURE_DECLS \
	ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ZadanieRekrutacyjne_Source_ZadanieRekrutacyjne_DamagableActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
