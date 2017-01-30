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
The tall mushrooms sway in the gentle breeze.  To the east\n\
the trail takes a turn behind some large fungi.  North and south\n\
also have bends of their own; one to the west, the other to the\n\
east.  Birds can be heard in the distance as light rays illuminate\n\
the worn pathway.\n";

  items = ({
    "fungi","They are oversized and very colorful",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg2.c","south",
    PATH+"mg4.c","north",
    PATH+"mg11.c","east",
  });

}

init(){
  ::init();
  add_action("listen","listen");
}

int listen(){
  write("You hear the chirp of birds in the distance.\n");
  return 1;
}
