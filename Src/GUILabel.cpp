//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUILabel.h"

void GUILabel::onDraw(Rect _r)
{
	View::onDraw(_r);
	GUI::drawString(rect, textColor, backgroundColor, title);
}

void GUILabel::setTitle(const char *_title)
{
	if (strLen < strlen(_title) || title == NULL)
	{
		if (title != NULL)
		{
			delete title;
		}
		strLen = strlen(_title);
		title = (char*)malloc(sizeof(char) * strLen + 1);
		if (title == NULL)
			return;
	}
	
	memcpy(title, _title, sizeof(char) * strLen + 1);
	redraw();
}

//EOF
