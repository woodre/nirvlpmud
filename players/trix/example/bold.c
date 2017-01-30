#include "/players/boltar/things/esc.h"
#include "/obj/clean.c"

id(str) { return str == "sign" || str == "neon" || str == "light"; }
short() {
   return esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mA very important sign to read"+esc+"[0m";
	}
long() { cat("/players/mizan/new/main-map"); }
init() { add_action("read","read"); }
read(str) {
	if(!str) return 0;
	if(str != "sign") return 0;
	cat("/players/mizan/new/main-map");
}
