inherit "room/room";
#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/mushrooms/"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

reset(arg) {
  int i;
  if(!present("turtlesign",this_object())){
  move_object(clone_object("/players/wocket/turtleville/OBJ/sign.c"),this_object());
  }
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
Mushrooms line the well worn pathway giving shade to weary\n\
travelers.  Dust sparkles as the light filters through the\n\
grove.  To the east you can begin to see the dim forest through\n\
the tops of large mushrooms.  North the trail continues and splits.\n";

  items = ({
    "dust","It sparkles as the light hits it",
    "light","Dust sparkles as the light filter through the mushrooms",
    "dim forest","To the east lies the dim forest.  You can just make it out over the large\nmushrooms",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg1.c","east",
    PATH+"mg3.c","north",
    "/players/wocket/turtleville/tepath3.c","southwest",
  });
}
