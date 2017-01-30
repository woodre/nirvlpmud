#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#include "/players/jaraxle/ansi.h"
inherit "room/room";
object owner;
reset(arg) {
if(!present("templar_mage")){
	owner = clone_object("/players/jaraxle/templar/mobs/templar_mage.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = HIW+"A magical laboratory ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM;
long_desc =
"  The laboratory of the castle is set deep within the fortress. Along\n"+
"the walls are numerous shelves and racks, each covered in bottles and\n"+
"vials of magical solutions. There are a few tables set about the room\n"+
"with equipment placed upon them. A stairway ascends to the main level\n"+
"of the castle.\n";

items = ({
"walls",
"Dark walls of crude stone",
"shelves",
"Wooden shelves containing numerous bottles and vials",
"racks",
"Steel racks with numerous bottles and vials scattered across them",
"bottles",
"Bottles filled with differently colored magical potions",
"vials",
"Small vials with powerful magical essences",
});

dest_dir = ({
  "/players/boltar/templar/private","up"
});

}

init(){
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


realm(){ return "NT"; }

