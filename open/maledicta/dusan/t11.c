#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;
reset(arg) {
if(!present("civilian", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  }	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"   This is the northeast corner of town. Looking about you see several\n"+
"houses and small businesses. To the southwest, in the center of town,\n"+
"stands a huge white tower. The road continues to the west and south,\n"+
"following the towns perimeter.\n";

items = ({
  "houses",
  "Small white houses made of stone, they are very warm and quaint",
  "businesses",
  "Similar in look to the houses, they are medium and small in size,\n"+
  "supplying the town with its needs",
  "tower",
  "A huge and beautiful tower. It is made of white stone and steel, and\n"+
  "seems to glimmer in the light. A huge crystalling dome can be seen\n"+
  "from here",
  "road",
  "A well-kept and expertly constructed road. It is very clean and well-used",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t12.c","west",
  "/players/maledicta/town/rooms/t8.c", "south",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	