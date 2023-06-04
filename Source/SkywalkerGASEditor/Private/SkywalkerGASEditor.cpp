// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkywalkerGASEditor.h"

#include "ToolMenus.h"
#include "Widgets/Layout/SConstraintCanvas.h"

#define LOCTEXT_NAMESPACE "FSkywalkerGASEditorModule"

void FSkywalkerGASEditorModule::StartupModule()
{
	AddOpenGASEditorViewButton();
}

void FSkywalkerGASEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FSkywalkerGASEditorModule::AddOpenGASEditorViewButton()
{
	// ����LevelEditor.MainMenu
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");

	// ��λLevelEditor.MainMenu�е�Section
	// LevelEditor.MainMenuû��Section��˴���NAME_None
	FToolMenuSection& Section = Menu->FindOrAddSection(NAME_None);
	
	// ��ʼ�����Ӳ˵�Entry
	FToolMenuEntry& MakeEntry =
		Section.AddSubMenu(
			"SkywalkerToolMenus",						// ���Ӳ˵� Name
			LOCTEXT("Skywalker", "Skywalker"),	// ��ǩ
			LOCTEXT("Skywalker_ToolTip", "Skywalker"), // ToolTip
			FNewToolMenuChoice()                    // �����ﻹ������һЩ��ֵ�����
		);

	// ����Entry���ֵ�λ��
	MakeEntry.InsertPosition = FToolMenuInsert("Help", EToolMenuInsertType::After);

	// LevelEditor.MainMenu.NewMenuByUToolMenusע��Ϊ�²˵�
	static const FName BaseMenuName = "LevelEditor.MainMenu.SkywalkerToolMenus";
	Menu = UToolMenus::Get()->RegisterMenu(BaseMenuName);

	// ���²˵������Section��Entry
	FToolMenuSection& NewSection = Menu->AddSection("SkywalkerGAS", FText::FromString("SkywalkerGAS"));
	NewSection.AddMenuEntry(
		"SkywalkerGAS Editor",
		FText::FromString("Open SkywalkerGAS Editor"),
		FText::FromString("Open SkywalkerGAS Editor"),
		FSlateIcon(),
		FToolUIActionChoice(FExecuteAction::CreateRaw(this, &FSkywalkerGASEditorModule::ActionOpenGASEditorView))
	);
}

void FSkywalkerGASEditorModule::ActionOpenGASEditorView()
{
	// �����´���
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString("Alice Window"))
		.SizingRule(ESizingRule::UserSized)
		.ClientSize(FVector2D(1000.f, 700.f))
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.ScreenPosition(FVector2D(0, 0))
		.IsEnabled(true)
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	// ���ô�������
	Window->SetContent
	(
		SNew(SConstraintCanvas)
		+ SConstraintCanvas::Slot()
		.Alignment(0.5f)
		.Anchors(0.5f)
		.Offset(FMargin(0.0f, 0.0f, 300.f, 100.f))
		.AutoSize(true)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Hello, Alice Window !"))
		]
	);

	// ��ʾ�´���
	FSlateApplication::Get().AddWindow(Window);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSkywalkerGASEditorModule, SkywalkerGASEditor)