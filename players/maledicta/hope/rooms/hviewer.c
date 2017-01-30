#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("viewing_cystal", this_object())){
move_object(clone_object("/players/maledicta/templar/obj/viewer.c"), this_object());
}
  if(arg) return;
set_light(1);
short_desc = "Viewing Chamber "+BOLD+"["+HIY+"Tower of Hope"+NORM+BOLD+"]"+NORM;
long_desc = 
"  This is the magical viewing chamber of the Alliance. The walls\n"+
"here are smooth and made of a shining platinum. In the center of\n"+
"the room is a large white crystal.  A stairway leads down into\n"+
"the inner chamber.\n"; 

items = ({
"walls",
"The walls here are made of a shining platinum metal, and reflect the\n"+
"available light",
"stairway",
"A stone stairway leading down to the inner chamber"
});


dest_dir = ({
  "/players/maledicta/hope/rooms/hinner.c","down",
});

}

no_hunter(){ return 1; }
