#include <iostream>
#include <string>
#include <unistd.h>

#include "Util.h"
#include "profile_timer.h"

using namespace std;

int main(int argc, char** argv){
	cout << "hoge" << endl;

	string t1 = "hoge1";
	while(true){
		profile_timer::count_fps();
		float fps = profile_timer::get_fps();
		
		profile_timer::start(t1, 30);
		usleep(1000*20);
		profile_timer::end(t1);
		double ave = profile_timer::get_average(t1);
		cout << "fps: " << fps << ",  ave: " << ave << endl;
	}
	return 0;
}
