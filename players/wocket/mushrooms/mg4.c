/*  10/09/06 - Rumplemintz
      Moved inherit to top of file, removed trailing ; in #include statement
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
A split in the well worn pathway has formed.  To the northeast\n\
the soft dirt trail continues as does it to the west.  Mushrooms\n\
continue to surround you and the dirt below your feet is soft to\n\
the touch.\n";

  items = ({
    "trail","It is well worn from use",
    "mushrooms","They are oversized and very colorful",
    "pathway","It is well worn from use",
  });

  dest_dir = ({
    PATH+"mg5.c","west",
    PATH+"mg3.c","south",
    PATH+"mg8.c","northeast",
  });

}
