#include "/players/boltar/things/esc.h"
id(str) { return str == "thing";}

init() {
        add_action("mc","mc");
}

mc(str) {
        cd(esc+"["+esc+"["+str); 
	return 1;
}
