//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUITITLEVIEW
#define __GUITITLEVIEW

//-------------------------------------------------------------------

#include "GUIView.h"
#include "GUILabel.h"

class GUITitleView : public GUIView
{
public:
	GUILabel *titleLabel;

	GUITitleView(Rect _rect, COLOR _color, const char *_title)
		: GUIView(_rect, _color)
	{
		titleLabel = new GUILabel(Rect(_rect.x, _rect.y, _rect.w, 30), _color, _title);
		titleLabel->textColor = 1 - _color;
		addChild(titleLabel);
	}
};

#endif
//EOF
