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
	// 持有LevelEditor.MainMenu
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");

	// 定位LevelEditor.MainMenu中的Section
	// LevelEditor.MainMenu没有Section因此传入NAME_None
	FToolMenuSection& Section = Menu->FindOrAddSection(NAME_None);
	
	// 开始制作子菜单Entry
	FToolMenuEntry& MakeEntry =
		Section.AddSubMenu(
			"SkywalkerToolMenus",						// 新子菜单 Name
			LOCTEXT("Skywalker", "Skywalker"),	// 标签
			LOCTEXT("Skywalker_ToolTip", "Skywalker"), // ToolTip
			FNewToolMenuChoice()                    // 在这里还可以做一些奇怪的事情
		);

	// 设置Entry出现的位置
	MakeEntry.InsertPosition = FToolMenuInsert("Help", EToolMenuInsertType::After);

	// LevelEditor.MainMenu.NewMenuByUToolMenus注册为新菜单
	static const FName BaseMenuName = "LevelEditor.MainMenu.SkywalkerToolMenus";
	Menu = UToolMenus::Get()->RegisterMenu(BaseMenuName);

	// 在新菜单下添加Section和Entry
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
	// 创建新窗口
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString("Alice Window"))
		.SizingRule(ESizingRule::UserSized)
		.ClientSize(FVector2D(1000.f, 700.f))
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.ScreenPosition(FVector2D(0, 0))
		.IsEnabled(true)
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	// 设置窗口内容
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

	// 显示新窗口
	FSlateApplication::Get().AddWindow(Window);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSkywalkerGASEditorModule, SkywalkerGASEditor)