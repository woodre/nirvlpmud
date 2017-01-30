#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  The shade from the trees is cool and refreshing.  The path splits\n"+
  "here, going off in various directions.\n";

items = ({
  "path","A dirt path through the trees",
  "shade","Shadows cast by the tree canopy overheard",
});

dest_dir = ({
  "players/eurale/Glade/eg16.c","north",
  "players/eurale/Glade/eg3.c","south",
  "players/eurale/Glade/eg1.c","west",
});

}
