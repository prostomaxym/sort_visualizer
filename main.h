#ifndef SORT_VISUALIZER_MAIN_H_
#define SORT_VISUALIZER_MAIN_H_

#include <string>

void gameloop(int);
void render();
void update();

//Toggle sorting algorithm
enum class SortingAlg
{
	BUBBLE,
	MERGE,
	RESET,
	STOP
};

extern SortingAlg mode;

inline std::string enumToString(SortingAlg alg);

extern bool fullscreen;
extern bool sorting;
extern int sorting_speed;
extern const int w, h;
#endif  // SORT_VISUALIZER_MAIN_H_
