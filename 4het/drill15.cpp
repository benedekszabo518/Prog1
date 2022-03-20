/* 
g++ drill15.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o main `fltk-config --ldflags --use-images`

*/
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

using namespace Graph_lib;


double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main ()
{

    Point t1 {100, 100};
    Simple_window win {t1, 600, 600, "Function graphs."};
    

    Axis xa {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	win.attach(xa);
    xa.set_color(Color::red);

	Axis ya {Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
	ya.set_color(Color::red);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();

    constexpr int r_min = -10;
    constexpr int r_max = 11;

    constexpr int num_points = 400;

    constexpr int x_scale = 20;
    constexpr int y_scale = 20;

    const Point orig {300, 300};

    Function f1 {one, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function f2 {slope, r_min, r_max, orig, num_points, x_scale, y_scale};
    Function f3 {[](double x) { return x * x; },
            r_min, r_max, orig, num_points, x_scale, y_scale};
    Function f4 {cos, r_min, r_max, orig, num_points, x_scale, y_scale};
    f4.set_color(Color::blue);
    Function f5 {[](double x) { return cos(x) + slope(x); },
            r_min, r_max, orig, num_points, x_scale, y_scale};

    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);

    win.wait_for_button();
    
}