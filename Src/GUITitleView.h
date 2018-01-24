//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUITITLEVIEW
#define __GUITITLEVIEW

//-------------------------------------------------------------------

#include "View.h"
#include "GUILabel.h"

class GUITitleView : public View
{
public:
	GUILabel *titleLabel;

	GUITitleView(Rect _rect, COLOR _color, const char *_title)
		: View(_rect, _color)
	{
		titleLabel = new GUILabel(Rect(_rect.x, _rect.y, _rect.w, 30), _color, _title);
		titleLabel->textColor = 1 - _color;
		addChild(*titleLabel);
	}
};

#endif
//EOF
