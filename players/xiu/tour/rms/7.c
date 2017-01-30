#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "NirvanAH Music Festival";
long_desc =
"The main stage is easily accessible from this location.\n"+
" The main stage is closer now to the north.\n"+
 "Large speakers reach toward the sky.\n"+
"There is a hospitality table in the corner with items for the artists.\n";


items = ({
"tents",
"Pup tents, backpacking tents, and a few army house tents are set up",
"dust",
"A thick dust created by the dry climate and thousands of people walking",
"people",
"All sorts of hippy looking people wander about",
"flag",
"The ole right white and blue",
  });

move_object(clone_object("/players/xiu/tour/mobs/phish.c"), this_object());
dest_dir = ({
 "/players/xiu/tour/rms/6.c","south",
  });
}
