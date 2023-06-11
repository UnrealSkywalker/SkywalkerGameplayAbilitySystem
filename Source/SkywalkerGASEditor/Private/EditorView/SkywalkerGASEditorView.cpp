#include "SkywalkerGASEditorView.h"

#include "Widgets/Layout/SConstraintCanvas.h"

CSkywalkerGASEditorView::CSkywalkerGASEditorView()
{
	
}

CSkywalkerGASEditorView::~CSkywalkerGASEditorView()
{
	
}

void CSkywalkerGASEditorView::Create()
{
}

void CSkywalkerGASEditorView::OnShow()
{
	if (!EditorWindow.IsValid())
	{
		EditorWindow = CreateWindow();
	}
	
	EditorWindow.Pin()->ShowWindow();
}

void CSkywalkerGASEditorView::OnHide()
{
	EditorWindow.Pin()->HideWindow();
}

TSharedRef<SWindow> CSkywalkerGASEditorView::CreateWindow()
{
	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString("Alice Window"))
		.SizingRule(ESizingRule::UserSized)
		.ClientSize(FVector2D(1000.f, 700.f))
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.ScreenPosition(FVector2D(0, 0))
		.IsEnabled(true)
		.SupportsMinimize(true)
		.SupportsMaximize(true);

	// ÉèÖÃ´°¿ÚÄÚÈÝ
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

	FSlateApplication::Get().AddWindow(Window, false);

	return Window;
}
