#ifndef COLOREDTERMINAL_H
#define COLOREDTERMINAL_H
#include "Terminal.h"

class ColoredTerminal : public Terminal 
{
private:
	static bool _color_initialized;
public:
	ColoredTerminal();
	void set_cell(int x, int y, char symbol, chtype color);
	void draw_text(int x, int y, const std::string& text, chtype color);
	//bool isColored();
};

#endif