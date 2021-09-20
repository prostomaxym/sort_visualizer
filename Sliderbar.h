#ifndef SORT_VISUALIZER_SLIDERBAR_H_
#define SORT_VISUALIZER_SLIDERBAR_H_

#include <glut.h>

class Sliderbar
{
public:
	Sliderbar();
	Sliderbar(int x, int y, int val, float maxval);
	
	void drawSlider();
	void setValue(float x);
	int getSliderSize();
	int isClicked(int x, int y);

private:
	int value;
	const int slider_length = 100;
	int xpos, ypos;
	float max_value;

	void drawValue();
};
#endif  // SORT_VISUALIZER_SLIDERBAR_H_

