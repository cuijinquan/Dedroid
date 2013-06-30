/*
 *
 *  Copyright (C) 2013  Anwar Mohamed <anwarelmakrahy[at]gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to Anwar Mohamed
 *  anwarelmakrahy[at]gmail.com
 *
 */

#include <Windows.h>
#include <stdio.h>
#include "..\Dedroid\cAndroid.h"

INT main(INT argc, CHAR* argv[])
{
	cAndroid android("H:\\Github\\Dedroid\\Dedroid\\Debug\\sample.apk");

	if (android.isReady) 
		printf("DexFile Loaded at 0x%08x with size %d bytes\n\n", android.DexBuffer, android.DexBufferSize);

	//printf("= Strings ==========\n");
	//for (UINT i=0; i<android.nStringItems; i++)
	//	printf("%d %s\n", android.StringItems[i].StringSize, android.StringItems[i].Data);

	printf(	"Total String Items: \t%d\n"
			"      Type Descripters \t%d\n"
			"      Method Items \t%d\n"
			"      Field Items \t%d\n"
			"      Prototype Items \t%d\n", 
			android.nStringIDs,
			android.nTypeIDs,
			android.nMethodIDs,
			android.nFieldIDs,
			android.nPrototypeIDs);
	
	//printf("\n= Field Items ======\n\n");
	//for (UINT i=0; i<android.nFieldIDs; i++)
	//	printf("%s\n", android.StringItems[android.DexFieldIds[i].StringIndex].Data);

	//printf("\n= Type Descripters =\n\n");
	//for (UINT i=0; i<android.nTypeIDs; i++)
	//	printf("%s\n", android.StringItems[android.DexTypeIds[i].StringIndex].Data);

	//printf("\n= Method Items =====\n\n");
	//for (UINT i=0; i<android.nMethodIDs; i++)
	//	printf("%s\n", android.StringItems[android.DexMethodIds[i].StringIndex].Data);

	//printf("\n= Prototype Items ==\n\n");
	//for (UINT i=0; i<android.nPrototypeIDs; i++)
	//	printf("%s\n", android.StringItems[android.DexProtoIds[i].StringIndex].Data);

	for (UINT i=0; i<1 /*android.nClassDefinitions*/; i++)
	{
		//printf("%s\n", android.StringItems[android.DexClassDefs[i].sourceFileIdx].Data);
		printf(	"\nClass #%d:\n" 
				"\tClass Descriptor: '%s'\n"
				"\tAccess Flags: 0x%04x\n"
				"\tSuper Class: '%s'\n"
				"\tSource File: '%s'\n",
				android.DexClasses[i].Index,
				android.DexClasses[i].Descriptor,
				android.DexClasses[i].AccessFlags,
				android.DexClasses[i].SuperClass,
				android.DexClasses[i].SourceFile);
	}

	system("PAUSE");
	return 0;
}