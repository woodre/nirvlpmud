#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
  ::reset(arg);
	if(arg) return;
	set_light(1);
  short_desc = "Northeast Corner of Amber";
  long_desc =
    "This is the northeast corner in the city of Amber.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/eastwall1", "south",
		"/players/oberon/amber/city/rooms/northwall4", "west",
	});
}
