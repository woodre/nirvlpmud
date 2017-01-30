#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
object thug;
reset(arg) {
if(!present("thug", this_object())){
thug = clone_object("/players/maledicta/cont/ltown/mobs/lthug.c");
	move_object(thug, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "A dark alley in "+HIG+"Terk'ula"+NORM+"";
long_desc =
"  This is a short dark alley between the wall and a hut. Piles\n"+
"of deep trash litter the ground here. A terrible smell wafts\n"+
"up from the filthy ground. To the west is the main road.\n";
items = ({
  "street",
  "A dirt road that leads through the center of town",
  "piles",
  "Large piles of filth",
  "trash",
  "Huge piles of trash, some of which move slightly",
  "hut",
  "A small mud and wood hut that is probably a private residence.\n"+
  "It has a large pool of water that extends out of the backside",
  "road",
  "A dirt road that leads through the center of town",
  "wall",
  "A tall wooden wall that defends the village from attacks",
});

dest_dir = ({
  "/players/maledicta/cont/ltown/rooms/l5.c", "west",

});

}

