inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  if(arg) return;
  set_light(1);

  short_desc = HIR+"The Mushroom Clearing"+NORM;
  long_desc =
"   \
This is a small little clearing in the grove.  Mushrooms surround\n\
the area and gentle grass grows all around.  There is a small pool\n\
of water within the meadow and birds can be heard off in the\n\
distance along with other woodland creatures.\n";

  items = ({
    "mushrooms","They are oversized and very colorful",
    "grass","It's very soft and blows in the wind",
  });

  dest_dir = ({
    PATH+"mg9.c","west",
  });

  move_object(clone_object("/players/wocket/mushrooms/newbiepool.c"),this_object());
}

init(){
    ::init();
    add_action("listen","listen");
}

int listen(){
    write("You can hear birds and other woodland creatures in the distance.\n");
  return 1;
}
