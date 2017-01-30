#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Grand Ave North of the Gate";
long_desc =
  "    Just west is the visitors center but it's entrance is to the south.\n"+
  "Further north along the road you can see the entrance to the creche.\n"+
  "Off to the east is the bazzar, it's entrance as well lies to the south.\n";

items = ({
  "road","This dirt road is wide and looks as if it sees quite a bit of traffic",
});

dest_dir = ({
	AREA+"103-150.c","north",
        AREA+"101-150.c","south",
});

}
