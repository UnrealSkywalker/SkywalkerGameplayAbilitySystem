// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "EditorView/SkywalkerGASEditorView.h"

class FSkywalkerGASEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** �� LevelEditor.MainMenu ����Ӵ򿪼��ܱ༭�������Btn */
	void AddOpenGASEditorViewButton();

	/** �򿪼��ܱ༭������ */
	void ActionOpenGASEditorView();
	
private:

	CSkywalkerGASEditorView SkywalkerGASEditorView;
};
