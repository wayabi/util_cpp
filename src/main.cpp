#include <iostream>
#include <string>
#include <unistd.h>

#include "Util.h"
#include "profile_timer.h"

using namespace std;

int main(int argc, char** argv){
	cout << "hoge" << endl;

	string t1 = "t1";
	string t2 = "t2";
	string t3 = "t3";
	string t4 = "t4";

	while(true){
		profile_timer::wait_fps(30);
		profile_timer::start(t2, 30);
		profile_timer::start(t4, 30);
		profile_timer::count_fps();
		float fps = profile_timer::get_fps();
		profile_timer::end(t4);
		
		profile_timer::start(t1, 30);
		usleep(1000*20);
		profile_timer::end(t1);
		profile_timer::start(t3, 30);
		double ave1 = profile_timer::get_average(t1);
		//double ave2 = 0;
		//double ave3 = 0;
		double ave2 = profile_timer::get_average(t2);
		double ave3 = profile_timer::get_average(t3);
		double ave4 = profile_timer::get_average(t4);
		profile_timer::end(t3);
		cout << "fps: " << fps << ",  ave1: " << ave1 << ", ave2: " << ave2 << ", ave3: " << ave3 << ", ave4: " << ave4 << endl;
		profile_timer::end(t2);
		profile_timer::start("dump", 10);
		profile_timer::dump(cout);
		profile_timer::end();
	}
	return 0;
}
