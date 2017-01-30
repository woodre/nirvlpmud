inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  int i;
  i = random(2);
  if(i == 1){
    for(i=0 ; i < random(2)+1 ; i++){
      move_object(clone_object("/players/wocket/mushrooms/nonge.c"),this_object());
    }
  }
  if(arg) return;
  set_light(1);

  short_desc = HIR+"The Mushroom Grove"+NORM;
  long_desc =
"   \
The trail wanders into a dead end with a small hut at its\n\
finale.  The mushrooms seem to grow denser here letting only\n\
delicate rays of light pass through.  To the northeast the\n\
pathway continues on, and from the looks of it many have traveled\n\
that distance.\n";

  items = ({
    "rays","They filter through the dense mushroom growth",
    "light","Rays of it filter through the dense mushroom growth",
    "hut","A small hut that has been carved from a mushroom",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mghut.c","enter",
    PATH+"mg5.c","northeast",
  });
}
