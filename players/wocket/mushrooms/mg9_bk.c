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
The mushrooms fill the area giving nice shade and filtering the\n\
light through them.  To the east looks to be a small clearing\n\
filled with grass.  The pathway looks well worn from much use.\n";

  items = ({
    "clearing","There is a small grassy clearing to the east",
    "shade","It looks very cooling",
    "light","It filters through the mushrooms",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg10.c","east",
    PATH+"mg8.c","south",
  });
}
