#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include <time.h>
#include <stdlib.h>

using namespace Graph_lib;

int main ()
{
	try {
		//1
		Point t1{50,50};
		Simple_window win {t1,800,1000,"Simple_window"};
		win.wait_for_button();

		//2
		Lines grid;
		int x_size = 800;
		int y_size = 800;

		for(int i=100;i<=800;i+=100)
		{
			grid.add(Point{i,0}, Point{i,y_size});
			grid.add(Point{0,i}, Point{x_size,i});
		}
		win.attach(grid);
		win.wait_for_button();

		//3
		Vector_ref<Rectangle> vr;
		for(int i=0;i<8;i++)
		{
			vr.push_back(new Rectangle(Point{100*i,100*i},100,100));
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
		}
		win.wait_for_button();

		//4
		Image im1(Point(0,400),"badge.jpg");
		im1.set_mask(Point(100,100), 200,200);
		win.attach(im1);

		Image im2(Point(400,600),"badge.jpg");
		im2.set_mask(Point(100,100), 200,200);
		win.attach(im2);

		Image im3(Point(0,600),"badge.jpg");
		im3.set_mask(Point(100,100), 200,200);
		win.attach(im3);
		win.wait_for_button();

		Image im4(Point(0,0),"100.jpg");
		win.attach(im4);
		win.wait_for_button();

		//5 
		int a[3],b[3];
		for(int i=0;i<3;i++)
		{
			srand(time(0));
			a[i] = (rand() % 8 )  ;
			cout << a[i] <<endl;

			b[i] = (rand() % 8 ) ;
			cout << b[i]<<endl;
			if(a[i]!=b[i])
			{
				if(a[i]==0)
				{
					im4.move(a[i],b[i]*100);
					win.wait_for_button();
					im4.move(0,0);
				}
				else if(b[i]==0)
				{
					im4.move(a[i]*100,b[i]);
					win.wait_for_button();
					im4.move(0,0);
				}
				im4.move(a[i]*100,b[i]*100);
				win.wait_for_button();
				im4.move(0,0);
			}
			else if(a[i] == 7 || b[i]== 7)
			{
				a[i]--;
				im4.move(a[i]*100,b[i]*100);
				win.wait_for_button();	
				im4.move(0,0);
			}
		}


		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		return 2;
	}
}