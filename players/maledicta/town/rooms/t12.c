#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("civilian", this_object())) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }

  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"   Following the perimeter of the wall, which surrounds the city, you see a\n"+
"small shop which lays to the south, a sign hanging in its window. Along the\n"+
"road you see several houses, their yards leading up to the road. To the south,\n"+
"standing tall over the trees and houses in the area, you see a huge tower\n"+
"in the center of the town. The road continues west and east.\n";

items = ({
  "wall",
  "Made of stone and steel, it is reinforced with an energy field. It is nearly\n"+
  "unbreakable",
  "road",
  "Well-kept and clean, it is made of stone",
  "shop",
  "A small shop made of white stone. A sign hangs above its doorway",
  "sign",
  "A steel sign with black lettering. Perhaps you should try\n"+
  "reading it?\n",
  "houses",
  "Small to medium in size, they are very warm and quaint",
  "yards",
  "Green and healthy, each yard is well trimmed",
  "trees",
  "Tall trees that are healthy and full",
  "tower",
  "A beautiful white tower made of stone and steel. It glimmers in the light",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t13.c","west",
  "/players/maledicta/town/rooms/t11.c","east",
  "/players/maledicta/town/rooms/t18.c","shop"
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
  	write("            The Travelers Shield\n\n");
  	return 1;
        }
  return;
  }		 