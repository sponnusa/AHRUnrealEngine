// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

//=============================================================================
// PolysExporterOBJ
//=============================================================================

#pragma once
#include "PolysExporterOBJ.generated.h"

UCLASS()
class UPolysExporterOBJ : public UExporter
{
	GENERATED_UCLASS_BODY()


	// Begin UExporter Interface
	virtual bool ExportText( const FExportObjectInnerContext* Context, UObject* Object, const TCHAR* Type, FOutputDevice& Ar, FFeedbackContext* Warn, uint32 PortFlags=0 ) override;
	// End UExporter Interface
};



