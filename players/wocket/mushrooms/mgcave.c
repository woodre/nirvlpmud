/*  10/09/06 - Rumplemintz
      Moved inherit to top of file, removed trailing ; from #include
*/

inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  move_object(clone_object("/players/wocket/mushrooms/jennie.c"),this_object());
  if(arg) return;
  set_light(1);

  short_desc = HIR+"A Cave"+NORM;
  long_desc =
"   \
A large musky cave encases you.  There is a small opening which\n\
provides the only light source.  The air smells of death and begins\n\
to press down upon you.  The walls are covered with slime and the \n\
ground is filled with jagged, sharp rocks.\n";

  items = ({
    "walls","They are covered with slime",
    "slime","It's green and it's icky",
    "rocks","They litter the ground with their sharp edges",
    "cave","It encases you",
    "opening","It is the only sourse of light, as well as the only exit",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg12.c","out",
  });
}

init(){
  ::init();
  add_action("smell","smell");
}

int smell(){
  write("The air smells of death.\n");
  return 1;
}
