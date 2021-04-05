#include "Terminal.h"
//#include <locale>
#if defined(_WIN32)
#include <curses.h>
#else
#include <ncurses.h>
#endif
//#ifdef PDCURSES_MOUSE_VERSION
//#endif

Terminal::Terminal(int width, int height)
{
//setlocale:
//	setlocale(LC_ALL, "");
	initscr();
	//raw();
	resize_term(height, width);
	mousemask(ALL_MOUSE_EVENTS|REPORT_MOUSE_POSITION, NULL);
	cbreak();

	keypad(stdscr, true);
	noecho();
	curs_set(2); //original was 0, i set it to 2(very visible)
	//timeout(0);
	//halfdelay(50);
    //notimeout(stdscr, TRUE);
    //noqiflush();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(3, COLOR_GREEN, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_WHITE);
	stdscr->_bkgd=COLOR_PAIR(1);
	
	
}

int Terminal::width() const
{
	return COLS;
}

int Terminal::height() const
{
	return LINES;
}

void Terminal::set_cell(int x, int y, char symbol)
{
	mvaddch(y, x, symbol);
}

void Terminal::draw_text(int x, int y, const std::string& text)
{
	mvaddstr(y, x, text.c_str());
}

void Terminal::clear()
{
	::clear();
}

void Terminal::close()
{
	endwin();
	curs_set(1);
	exit(0);
}


void Terminal::sleep(int ms)
{
	napms(ms);
}

char Terminal::get_key() const
{
	return wgetch(stdscr);
}
