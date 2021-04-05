#include <chrono>
#include "Terminal.h"
#include "Game.h"
#include "curses.h"
//#include <Windows.h>
//void makenoises() {
//for (int i = 0; i < 5; i += 1) {
//		Beep(415.30, 150);
//		Sleep(10);
//		Beep(440.00, 150);
//		Sleep(10);
//		Beep(466.16, 150);
//		Sleep(10);
//		Beep(493.88, 150);
//		Sleep(10);
//		Beep(523.25, 150);
//	}
//}


int main()
{
	
    Terminal term(100, 25);
	
    Game game(term);

    using namespace std::chrono;
    using fmilli = duration<float, seconds::period>;

    auto t0 = high_resolution_clock::now();
    auto t1 = high_resolution_clock::now();

    while (!game.isDone()) {
        t0 = t1;
        t1 = high_resolution_clock::now();
        game.update(fmilli(t1 - t0).count());
        game.draw();
    }

    term.close();
    return 0;
}
