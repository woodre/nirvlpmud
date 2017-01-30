/*  10/09/06 - Rumplemintz
      Moved inherit to top of file, removed trailing ; from #include statement
*/

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
The worn pathway seems to come to an end as the grass takes its\n\
place instead.  To the northeast a small cave seems visible through\n\
the parting of the huge mushrooms.  As to the west, the path\n\
continues to a split.  Squirrels move through the underbrush\n\
rustling leaves and chippering.\n";

  items = ({
    "squirrels","They are only shadows as they move through the underbrush",
    "underbrush","It moves as squirrels move through it",
    "grass","It grows a brillant green and is very lush",
    "cave","A cave can been seen to the northeast",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });
 
  dest_dir = ({
    PATH+"mg12.c","northeast",
    PATH+"mg3.c","west",
  });

}

init(){
    ::init();
    add_action("listen","listen");
}

int listen(){
  write("You can hear the rustling of leaves as squirrel move through the underbrush.\n");
  return 1;
}
