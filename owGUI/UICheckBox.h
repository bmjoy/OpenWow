#pragma once

#include "UIElement.h"

class UICheckBox : public UIElement {
	typedef UIElement base;
public:
	UICheckBox(IUIMgr* _uimgr);
	virtual ~UICheckBox() override;

	 void Init(cvec2 _position);

	bool IsChecked() const { return isChecked; }

	virtual void OnRenderUI();

	// IInputrListener
	bool OnMouseButtonPressed(int _button, int _mods, cvec2 _mousePos) override;

protected:
	bool isChecked;
	Image* checkBoxImages[2];
};
