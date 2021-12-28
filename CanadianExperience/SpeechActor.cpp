#include "pch.h"
#include "SpeechActor.h"

CSpeechActor::CSpeechActor(const std::wstring& name) : CActor(name)
{

}
CSpeechActor::~CSpeechActor()
{

}

void CSpeechActor::Draw(Gdiplus::Graphics* graphics)
{
	CActor::Draw(graphics);
	if (IsEnabled())
	{
		Gdiplus::FontFamily fontFamily(L"Arial");
		Gdiplus::Font fontThree(&fontFamily, 52);
		Gdiplus::SolidBrush brown(Gdiplus::Color(139, 69, 19));
		const WCHAR* toDraw = mDialogue.c_str();
		graphics->DrawString(toDraw,  // String to draw
			-1,         // String length, -1 so it figures it out on its own
			&fontThree,      // The font to use
			Gdiplus::PointF(GetPosition().X + 30, GetPosition().Y-220),   // Where to draw 
			&brown);    // The brush to draw the text with
	}
}
