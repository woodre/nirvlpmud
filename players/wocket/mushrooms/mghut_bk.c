inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg){
  if(!present("priest",this_object()))
    move_object(clone_object("/players/wocket/mushrooms/hpnonge.c"),this_object());
  if(!present("guard",this_object()))
    move_object(clone_object("/players/wocket/mushrooms/guard.c"),this_object());
  if(arg) return;
  set_light(1);

  short_desc = HIR+"A Mushroom Hut"+NORM;
  long_desc =
"   \
This is a small hut carved out of one of the giant mushrooms.\n\
Light filters through holes that have been cut out of the ceiling,\n\
only to illuminate a small wooden altar.  Pictures hang around\n\
the walls and a small fire is lit in the middle to warm the air.\n";

  items = ({
    "light","It filters through holes in the ceiling",
    "ceiling","It looks like the top of a mushroom",
    "holes","They have been cut in the ceiling to let the light through",
    "altar","A small wooden altar to preform nonge rituals",
    "pictures","Images of nonge legends fill them",
    "fire","A small fire in the middle of the hut warms the room",
    "walls","They are formed from the mushroom",
  });

  dest_dir = ({
    PATH+"mg6.c","out",
  });

}
