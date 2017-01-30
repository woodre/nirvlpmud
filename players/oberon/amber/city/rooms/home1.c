#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
  ::reset(arg);
	if(arg) return;
	set_light(1);
  short_desc = "Villigar's Home";
  long_desc =
    "Inside a home.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/necorner","north",
		"/players/oberon/amber/city/rooms/eastwall2","south",
	});
}
