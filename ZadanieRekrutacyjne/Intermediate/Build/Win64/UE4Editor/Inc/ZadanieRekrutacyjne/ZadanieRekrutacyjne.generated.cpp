// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ZadanieRekrutacyjne.h"
#include "ZadanieRekrutacyjne.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1ZadanieRekrutacyjne() {}
FName ZADANIEREKRUTACYJNE_HandleDamage = FName(TEXT("HandleDamage"));
FName ZADANIEREKRUTACYJNE_NetMulticastSetColor = FName(TEXT("NetMulticastSetColor"));
FName ZADANIEREKRUTACYJNE_ServerSetLightColor = FName(TEXT("ServerSetLightColor"));
	void IDamagable::HandleDamage(float fDamageValue)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleDamage instead.");
	}
	void UDamagable::StaticRegisterNativesUDamagable()
	{
		FNativeFunctionRegistrar::RegisterFunction(UDamagable::StaticClass(), "HandleDamage",(Native)&IDamagable::execHandleDamage);
	}
	IMPLEMENT_CLASS(UDamagable, 723335143);
	void IDamagable::Execute_HandleDamage(UObject* O, float fDamageValue)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDamagable::StaticClass()));
		Damagable_eventHandleDamage_Parms Parms;
		UFunction* const Func = O->FindFunction(ZADANIEREKRUTACYJNE_HandleDamage);
		if (Func)
		{
			Parms.fDamageValue=fDamageValue;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IDamagable*)(O->GetNativeInterfaceAddress(UDamagable::StaticClass())))
		{
			I->HandleDamage_Implementation(fDamageValue);
		}
	}
	void ADamagableActor::HandleDamage(float fDamageValue)
	{
		DamagableActor_eventHandleDamage_Parms Parms;
		Parms.fDamageValue=fDamageValue;
		ProcessEvent(FindFunctionChecked(ZADANIEREKRUTACYJNE_HandleDamage),&Parms);
	}
	void ADamagableActor::StaticRegisterNativesADamagableActor()
	{
		FNativeFunctionRegistrar::RegisterFunction(ADamagableActor::StaticClass(), "HandleDamage",(Native)&ADamagableActor::execHandleDamage);
	}
	IMPLEMENT_CLASS(ADamagableActor, 4085819390);
	void ALightBulb::NetMulticastSetColor(FLinearColor color)
	{
		LightBulb_eventNetMulticastSetColor_Parms Parms;
		Parms.color=color;
		ProcessEvent(FindFunctionChecked(ZADANIEREKRUTACYJNE_NetMulticastSetColor),&Parms);
	}
	void ALightBulb::ServerSetLightColor(FLinearColor color)
	{
		LightBulb_eventServerSetLightColor_Parms Parms;
		Parms.color=color;
		ProcessEvent(FindFunctionChecked(ZADANIEREKRUTACYJNE_ServerSetLightColor),&Parms);
	}
	void ALightBulb::StaticRegisterNativesALightBulb()
	{
		FNativeFunctionRegistrar::RegisterFunction(ALightBulb::StaticClass(), "NetMulticastSetColor",(Native)&ALightBulb::execNetMulticastSetColor);
		FNativeFunctionRegistrar::RegisterFunction(ALightBulb::StaticClass(), "ServerSetLightColor",(Native)&ALightBulb::execServerSetLightColor);
	}
	IMPLEMENT_CLASS(ALightBulb, 1198699784);
	void AMyPawn::ServerSetLightColor(FLinearColor color)
	{
		MyPawn_eventServerSetLightColor_Parms Parms;
		Parms.color=color;
		ProcessEvent(FindFunctionChecked(ZADANIEREKRUTACYJNE_ServerSetLightColor),&Parms);
	}
	void AMyPawn::StaticRegisterNativesAMyPawn()
	{
		FNativeFunctionRegistrar::RegisterFunction(AMyPawn::StaticClass(), "ServerSetLightColor",(Native)&AMyPawn::execServerSetLightColor);
	}
	IMPLEMENT_CLASS(AMyPawn, 4171458188);
	void AZadanieRekrutacyjneGameModeBase::StaticRegisterNativesAZadanieRekrutacyjneGameModeBase()
	{
	}
	IMPLEMENT_CLASS(AZadanieRekrutacyjneGameModeBase, 1686482312);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UDestructibleComponent_NoRegister();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ENGINE_API class UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_APawn();
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();

	ZADANIEREKRUTACYJNE_API class UFunction* Z_Construct_UFunction_UDamagable_HandleDamage();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_UDamagable_NoRegister();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_UDamagable();
	ZADANIEREKRUTACYJNE_API class UFunction* Z_Construct_UFunction_ADamagableActor_HandleDamage();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ADamagableActor_NoRegister();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ADamagableActor();
	ZADANIEREKRUTACYJNE_API class UFunction* Z_Construct_UFunction_ALightBulb_NetMulticastSetColor();
	ZADANIEREKRUTACYJNE_API class UFunction* Z_Construct_UFunction_ALightBulb_ServerSetLightColor();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ALightBulb_NoRegister();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_ALightBulb();
	ZADANIEREKRUTACYJNE_API class UFunction* Z_Construct_UFunction_AMyPawn_ServerSetLightColor();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_AMyPawn_NoRegister();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_AMyPawn();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_AZadanieRekrutacyjneGameModeBase_NoRegister();
	ZADANIEREKRUTACYJNE_API class UClass* Z_Construct_UClass_AZadanieRekrutacyjneGameModeBase();
	ZADANIEREKRUTACYJNE_API class UPackage* Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
	UFunction* Z_Construct_UFunction_UDamagable_HandleDamage()
	{
		UObject* Outer=Z_Construct_UClass_UDamagable();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("HandleDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x0C020C00, 65535, sizeof(Damagable_eventHandleDamage_Parms));
			UProperty* NewProp_fDamageValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("fDamageValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(fDamageValue, Damagable_eventHandleDamage_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MyCategory"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Damagable.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("classes using this interface must implement ReactToHighNoon"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDamagable_NoRegister()
	{
		return UDamagable::StaticClass();
	}
	UClass* Z_Construct_UClass_UDamagable()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			UInterface::StaticClass();
			Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
			OuterClass = UDamagable::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20104081;

				OuterClass->LinkChild(Z_Construct_UFunction_UDamagable_HandleDamage());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UDamagable_HandleDamage(), "HandleDamage"); // 1453490090
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Damagable.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDamagable(Z_Construct_UClass_UDamagable, &UDamagable::StaticClass, TEXT("UDamagable"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDamagable);
	UFunction* Z_Construct_UFunction_ADamagableActor_HandleDamage()
	{
		UObject* Outer=Z_Construct_UClass_ADamagableActor();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("HandleDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x0C020C00, 65535, sizeof(DamagableActor_eventHandleDamage_Parms));
			UProperty* NewProp_fDamageValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("fDamageValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(fDamageValue, DamagableActor_eventHandleDamage_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MyCategory"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("DamagableActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ADamagableActor_NoRegister()
	{
		return ADamagableActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ADamagableActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
			OuterClass = ADamagableActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ADamagableActor_HandleDamage());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_BaseComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(BaseComponent, ADamagableActor), 0x00400000000a000d, Z_Construct_UClass_UDestructibleComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ADamagableActor_HandleDamage(), "HandleDamage"); // 677233061
				OuterClass->Interfaces.Add(FImplementedInterface(Z_Construct_UClass_UDamagable_NoRegister(), VTABLE_OFFSET(ADamagableActor, IDamagable), false ));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("DamagableActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("DamagableActor.h"));
				MetaData->SetValue(NewProp_BaseComponent, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_BaseComponent, TEXT("Category"), TEXT("BaseComponent"));
				MetaData->SetValue(NewProp_BaseComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_BaseComponent, TEXT("ModuleRelativePath"), TEXT("DamagableActor.h"));
				MetaData->SetValue(NewProp_BaseComponent, TEXT("ToolTip"), TEXT("Base destructable component"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADamagableActor(Z_Construct_UClass_ADamagableActor, &ADamagableActor::StaticClass, TEXT("ADamagableActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADamagableActor);
	UFunction* Z_Construct_UFunction_ALightBulb_NetMulticastSetColor()
	{
		UObject* Outer=Z_Construct_UClass_ALightBulb();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("NetMulticastSetColor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x80844C41, 65535, sizeof(LightBulb_eventNetMulticastSetColor_Parms));
			UProperty* NewProp_color = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("color"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(color, LightBulb_eventNetMulticastSetColor_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FLinearColor());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("LightBulb.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALightBulb_ServerSetLightColor()
	{
		UObject* Outer=Z_Construct_UClass_ALightBulb();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerSetLightColor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x80A40C41, 65535, sizeof(LightBulb_eventServerSetLightColor_Parms));
			UProperty* NewProp_color = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("color"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(color, LightBulb_eventServerSetLightColor_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FLinearColor());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("LightBulb.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALightBulb_NoRegister()
	{
		return ALightBulb::StaticClass();
	}
	UClass* Z_Construct_UClass_ALightBulb()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
			OuterClass = ALightBulb::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ALightBulb_NetMulticastSetColor());
				OuterClass->LinkChild(Z_Construct_UFunction_ALightBulb_ServerSetLightColor());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_LightSource = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LightSource"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(LightSource, ALightBulb), 0x00400000000a001d, Z_Construct_UClass_UPointLightComponent_NoRegister());
				UProperty* NewProp_LightBulbMeshComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LightBulbMeshComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(LightBulbMeshComponent, ALightBulb), 0x00400000000a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALightBulb_NetMulticastSetColor(), "NetMulticastSetColor"); // 756722469
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALightBulb_ServerSetLightColor(), "ServerSetLightColor"); // 401785446
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("LightBulb.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("LightBulb.h"));
				MetaData->SetValue(NewProp_LightSource, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_LightSource, TEXT("Category"), TEXT("LightBulbComponents"));
				MetaData->SetValue(NewProp_LightSource, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_LightSource, TEXT("ModuleRelativePath"), TEXT("LightBulb.h"));
				MetaData->SetValue(NewProp_LightSource, TEXT("ToolTip"), TEXT("Point Light component"));
				MetaData->SetValue(NewProp_LightBulbMeshComponent, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_LightBulbMeshComponent, TEXT("Category"), TEXT("LightBulbComponents"));
				MetaData->SetValue(NewProp_LightBulbMeshComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_LightBulbMeshComponent, TEXT("ModuleRelativePath"), TEXT("LightBulb.h"));
				MetaData->SetValue(NewProp_LightBulbMeshComponent, TEXT("ToolTip"), TEXT("Light Bulb mesh component"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALightBulb(Z_Construct_UClass_ALightBulb, &ALightBulb::StaticClass, TEXT("ALightBulb"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALightBulb);
	UFunction* Z_Construct_UFunction_AMyPawn_ServerSetLightColor()
	{
		UObject* Outer=Z_Construct_UClass_AMyPawn();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ServerSetLightColor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x80A20CC0, 65535, sizeof(MyPawn_eventServerSetLightColor_Parms));
			UProperty* NewProp_color = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("color"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(color, MyPawn_eventServerSetLightColor_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FLinearColor());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("MyPawn.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyPawn_NoRegister()
	{
		return AMyPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_AMyPawn()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
			OuterClass = AMyPawn::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_AMyPawn_ServerSetLightColor());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_LightBulb = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LightBulb"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(LightBulb, AMyPawn), 0x0010000000020015, Z_Construct_UClass_ALightBulb_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AMyPawn_ServerSetLightColor(), "ServerSetLightColor"); // 2198161443
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MyPawn.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("MyPawn.h"));
				MetaData->SetValue(NewProp_LightBulb, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_LightBulb, TEXT("Category"), TEXT("LightBulbComponents"));
				MetaData->SetValue(NewProp_LightBulb, TEXT("ModuleRelativePath"), TEXT("MyPawn.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyPawn(Z_Construct_UClass_AMyPawn, &AMyPawn::StaticClass, TEXT("AMyPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPawn);
	UClass* Z_Construct_UClass_AZadanieRekrutacyjneGameModeBase_NoRegister()
	{
		return AZadanieRekrutacyjneGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AZadanieRekrutacyjneGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_ZadanieRekrutacyjne();
			OuterClass = AZadanieRekrutacyjneGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900288;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ZadanieRekrutacyjneGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ZadanieRekrutacyjneGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZadanieRekrutacyjneGameModeBase(Z_Construct_UClass_AZadanieRekrutacyjneGameModeBase, &AZadanieRekrutacyjneGameModeBase::StaticClass, TEXT("AZadanieRekrutacyjneGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZadanieRekrutacyjneGameModeBase);
	UPackage* Z_Construct_UPackage__Script_ZadanieRekrutacyjne()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/ZadanieRekrutacyjne")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x3524B05C;
			Guid.B = 0x60809888;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
