#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard5 "/players/maledicta/town/mobs/guard5.c"
#define guard6 "/players/maledicta/town/mobs/guard6.c"
inherit "room/room";

int i;

reset(arg) {
if(!find_object(guard5)){
move_object(guard5, this_object());
}
if(!find_object(guard6)){
move_object(guard6, this_object());
}		
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  You stand before the Tower of the Jedi. A beautiful oak door leads\n"+
"within, colored glass framing its finished form. Looking straight up\n"+
"you see that the structure is made of white stone, steel lining and\n"+
"strengthening its entire being. A glimmering field of energy dances\n"+
"across its surface, sending light reflecting outward. Small glass\n"+
"windows dot the towers walls. A path leads south back to the main\n"+
"gate and the towns road.\n";

items = ({
  "tower",
  "A huge and beautiful structure, it is made of stone and steel, and its\n"+
  "surface reflects light, giving a sense of wonder to its being",
  "door",
  "A sturdy door made of oak, it's dark wood is finished and crafted\n"+
  "beautifully. Perhaps you could open it?",
  "glass",
  "Beautiful colored glass that reflects the light and softens the area",
  "stone",
  "Beautiful white stone, fashioned perfectly",
  "steel",
  "Used to reinforce the structure, it is polished and strong",
  "field",
  "A powerful energy field that surrounds and protects the tower",
  "windows",
  "Small windows that dot the towers walls. Each is carefully made and\n"+
  "set with colored glass",
  "path",
  "A small path made of stone. It is exceptionally clean and yet well-used",
 
   
});

dest_dir = ({
  "/players/maledicta/town/rooms/t4.c","south",
});

}
init(){
  ::init();
  add_action("open_it", "open");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
open_it(string str){
if(!str){
	write("Open what?\n"); 
	return 1;
        }
if(str == "door"){
	write("You try to open the door but find it will not budge, yet.\n");
	return 1;
   }
}
		