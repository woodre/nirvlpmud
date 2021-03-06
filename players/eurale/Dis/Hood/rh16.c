#define tp this_player()->query_name()
#include "/open/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = GRN+"Sherwood Forest"+NORM;
long_desc =
	"  You are in Sherwood Forest.  The huge, old hardwoods have\n"+
	"grown uncontested for decades.  Their massive trunks and\n"+
	"sprawling branches provide both protection and cover for the\n"+
	"many forest inhabitants.\n";

items = ({
	"hardwoods","Oak, Walnut, Hickory and Ask",
	"trunks","Mammoth-sized with large, scaley bark",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh13.c","north",
	"players/eurale/Dis/Hood/rh14.c","northeast",
	"players/eurale/Dis/Hood/rh17.c","east",
	"players/eurale/Dis/Hood/rh18.c","southwest",
	"players/eurale/Dis/Hood/rh15.c","west",
	"players/eurale/Dis/Hood/rh12.c","northwest",
});

}
