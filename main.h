#ifndef SORT_VISUALIZER_MAIN_H_
#define SORT_VISUALIZER_MAIN_H_

#include <string>

void gameloop(int);
void render();
void update();

//program mode state
enum class SortingAlg
{
	BUBBLE,
	MERGE,
	RESET,
	STOP
};

extern SortingAlg mode;

inline std::string enumToString(SortingAlg alg);  //convert enum state to screen text

extern bool fullscreen;  //window fullscreen mode state
extern bool sorting;  //sorting state (sorting, stopped)
extern int sorting_speed;  //time between sorting ticks in ms
extern const int w, h;  //default window width, height
#endif  // SORT_VISUALIZER_MAIN_H_
