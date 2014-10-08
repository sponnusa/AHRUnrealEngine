// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#if UE_ENABLE_ICU

#include <unicode/umachine.h>

class FICUInternationalization
{
public:
	FICUInternationalization(FInternationalization* const I18N);

	bool Initialize();
	void Terminate();

	void SetCurrentCulture(const FString& Name);
	void GetCultureNames(TArray<FString>& CultureNames) const;
	FCulturePtr GetCulture(const FString& Name);

private:
#if (IS_PROGRAM || !IS_MONOLITHIC)
	void LoadDLLs();
	void UnloadDLLs();
#endif

	FCulturePtr FindOrMakeCulture(const FString& Name);

private:
	FInternationalization* const I18N;

	TArray< void* > DLLHandles;

	TMap<FString, FCultureRef> CachedCultures;

	static UBool OpenDataFile(const void* context, void** fileContext, void** contents, const char* path);
	static void CloseDataFile(const void* context, void* const fileContext, void* const contents);

	// Tidy class for storing the count of references for an ICU data file and the file's data itself.
	struct FICUCachedFileData
	{
		FICUCachedFileData(const int64 FileSize);
		FICUCachedFileData(const FICUCachedFileData& Source);
		FICUCachedFileData(FICUCachedFileData&& Source);
		~FICUCachedFileData();

		uint32 ReferenceCount;
		void* Buffer;
	};

	// Map for associating ICU data file paths with cached file data, to prevent multiple copies of immutable ICU data files from residing in memory.
	TMap<FString, FICUCachedFileData> PathToCachedFileDataMap;
};

#endif