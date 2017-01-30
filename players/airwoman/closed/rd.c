#include "/players/boltar/things/esc.h"
id(str) {return str == "rd";}

init() {
	add_action("rd","rd");
}

rd (str) {
rmdir(esc+"["+esc+"["+str);  
	return 1;
}
