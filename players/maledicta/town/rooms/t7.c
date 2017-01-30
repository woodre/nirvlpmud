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
"  Here the road leads to the north and south, following along the east\n"+
"side of the town.  A small restaurant stands to the west, a sign\n"+
"hanging over its entryway. A huge white building can be seen in the\n"+
"center of the town, dominating the view to the west.\n";

items = ({
  "road",
  "Well-kept, this stone road is clean and expertly constructed",
  "restaurant",
  "A small restaurant, pleasant smells drift from its open doorway and into\n"+
  "the street. A white overhang stands over several tables and chairs outside\n"+
  "of the building. A sign hangs over the entryway of the building",
  "overhang",
  "Made of steel and wood, it blocks the sunlight from the restaurants customers",
  "tables",
  "Handmade in wood, each is sturdy and strong",
  "chairs",
  "Whitewash and made of wood, each chair is very sturdy",
  "sign",
  "Perhaps you should try reading it?",
  "entryway",
  "Standing open, the entryway is made of finished oak and has beautiful colored\n"+
  "glass on both sides",
  "building",
  "The tallest building in the town, it is made of steel and white stone. Several\n"+
  "pane glass windows can be seen along its surface"
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t8.c","north",
  "/players/maledicta/town/rooms/t6.c","south",
  "/players/maledicta/town/rooms/t9.c","west"
});

}


init(){
  ::init();
  add_action("read_it", "read");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	
read_it(string str){
	if(!str){ write("Read what?\n"); return 1; }
	  if(str = "sign"){
  	write("      The sign reads.....\n\n");
  	write("            The "+HIM+"Careful Wanderer"+NORM+"\n\n");
  	return 1;
        }
  return;
  }		
	