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
	/** 在 LevelEditor.MainMenu 中添加打开技能编辑器界面的Btn */
	void AddOpenGASEditorViewButton();

	/** 打开技能编辑器界面 */
	void ActionOpenGASEditorView();
	
private:

	CSkywalkerGASEditorView SkywalkerGASEditorView;
};
