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
Large colorful mushrooms line the pathway.  To the north you\n\
can see the trail bend, and to the southwest you see a split.\n\
Birds chirp from atop the mushrooms and dust rays filter\n\
through the underbrush.\n";

  items = ({
    "birds","They are small colorful birds with strong lungs",
    "rays","They filter through the underbrush",
    "dust","Rays of it filter through the underbrush",
    "underbrush","Rays of dust filter through it",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg9.c","north",
    PATH+"mg4.c","southwest",
  });
}

init(){
    ::init();
    add_action("listen","listen");
}

int listen(){
  write("You can hear birds chirping.\n");
  return 1;
}
