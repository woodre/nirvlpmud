#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;
reset(arg) {
if(!present("civilian", this_object())) {
    for(i=0; i < 4; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  }		
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  You find yourself on the west side of town. To either side of the road\n"+
"are numerous trees, and small houses. The defense wall is in plain view\n"+
"here, its surface glimmering brightly with energy. To the east is a huge\n"+
"white tower, its structure standing tall over the buildings below.  The\n"+
"road continues to the north and south.\n";

items = ({
  "road",
  "A well-used street that is exceptionally clean and well made",
  "trees",
  "Ranging from large to small, each tree is very healthy and full",
  "houses",
  "Made of white stone, each house is very quaint and warm",
  "wall",
  "The cities perimeter defense, it glimmers with the power of an energy field",
  "energy",
  "It pulses and waves across the stone and steel wall",
  "tower",
  "A large structure made of stone and steel, it glimmers in the light",
  "buildings",
  "Ranging from medium to small, there is a small blend of houses and\n"+
  "and businesses here",
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t14.c","north",
  "/players/maledicta/town/rooms/t16.c","south",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	