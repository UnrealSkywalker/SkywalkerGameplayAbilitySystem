#pragma once

#include "CoreMinimal.h"

class CSkywalkerGASEditorView
{
	TWeakPtr<class SWindow> EditorWindow;
	
public:
	CSkywalkerGASEditorView();
	~CSkywalkerGASEditorView();

	void Create();

	void OnShow();

	void OnHide();

private:
	TSharedRef<SWindow> CreateWindow();
};
