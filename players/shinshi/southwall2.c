#include <ansi.h>
inherit "/room/room";

reset(arg) {
	::reset(arg)
	if(arg) return;
	set_light(1);
	set_short("Inside the South Gate of Amber");
	set_long("Along the southern wall.");
	dest_dir = ({
			"/players/oberon/amber/city/rooms/southgate", "east",
	});
}
