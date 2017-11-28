//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUI
#define __GUI

//-------------------------------------------------------------------

#include "lib.h"
#include "Rect.h"

#define COLOR WORD

#define BLACK cHwDisplayGraphic::Black
#define NAVY cHwDisplayGraphic::Navy
#define DARKGREEN cHwDisplayGraphic::DarkGreen
#define DARKCYAN cHwDisplayGraphic::DarkCyan
#define MAROON cHwDisplayGraphic::Maroon
#define PURPLE cHwDisplayGraphic::Purple
#define OLIVE cHwDisplayGraphic::Olive
#define GREY cHwDisplayGraphic::Grey
#define DARKGREY cHwDisplayGraphic::DarkGrey
#define BLUE cHwDisplayGraphic::Blue
#define GREEN cHwDisplayGraphic::Green
#define CYAN cHwDisplayGraphic::Cyan
#define RED cHwDisplayGraphic::Red
#define MAGENTA cHwDisplayGraphic::Magenta
#define YELLOW cHwDisplayGraphic::Yellow
#define WHITE cHwDisplayGraphic::White

class GUI 
{
protected:
	cDevDisplayGraphic *disp;	
public:
	static Rect screenRect;

	static GUI& getInstance()
	{
		static GUI instance;
		return instance;
	}
	
	GUI() 
	{
		
	}
	
	static void init(cDevDisplayGraphic *_disp, int _width, int _height)
	{
		getInstance().disp = _disp;
		GUI::screenRect = Rect(0, 0, _width, _height);
	}
	
	GUI(GUI const&);
	void operator=(GUI const&);
	
	static void drawRect(Rect _rect, COLOR _color)
	{
		getInstance().disp->drawRectangle(_rect.x, _rect.y, _rect.w, _rect.h, _color );
	}
	
	static void drawString(Rect _r, COLOR _tColor, COLOR _bgColor, char *_title)
	{
		cDevDisplayGraphic *disp = getInstance().disp;
		disp->setTextColor(_tColor);
    disp->setBackColor(_bgColor);
		disp->drawText(_r.x, _r.y, _title);
	}
};

#endif

//EOF
