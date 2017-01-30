#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#include "/players/maledicta/ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("templar_mess", this_object())){
move_object(clone_object("players/maledicta/templar/mobs/templar_mess"), this_object());
	}
	if(!present("bulletinboard", this_object())){
		move_object(clone_object("players/boltar/templar/board"), this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Templar Inner-Chamber "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  This is the Knights Inner Chamber.  Here the decisions for the\n"+
"guild are made and plans for war are conducted. The walls are covered\n"+
"in maps of the realm as well as banners proudly displaying the cross\n"+
"of the Templars. To the south is a door leading to the main hall. A\n"+
"stairway leads up to the War Room.  A "+HIY+"Portal"+NORM+" stands along the north\n"+
"wall which leads to the Tower of Hope.\n";
items = ({
  "portal",
  "A large glowing portal that you can enter",
  "walls",
  "Made of a finely cut white stone, they are well constructed",
  "maps",
  "Large maps used in the defense of the realm",
  "banners",
  "Huge banners that hang from the ceiling. They are white and"+
  "portray the large red cross of the Templars",
  "door",
  "A simple wood door that leads out to the main hall"
});

dest_dir = ({
  "/players/maledicta/templar/rooms/hallway2.c","south",
  "/players/maledicta/templar/rooms/warroom.c", "up",
  "/players/jaraxle/templar/rooms/shop.c", "east",
});

}

init(){
 ::init();
   add_action("enter", "enter");
   add_action("title", "title");
   this_player()->set_fight_area();
   }

title(){
if(this_player()->query_real_name() != "handy") return;
this_player()->set_title(BOLD+"["+HIG+"Templar"+NORM+BOLD+"] "+HIR+"J"+HIY+"e"+HIB+"S"+HIM+"t"+HIW+"e"+HIG+"R"+NORM+"");
return 1;
}

enter(str){
  if(!str){ write("Enter what?\n"); return 1; }
  if(str != "portal"){ write("Enter what?\n"); return 1; }
  if(!present("KnightInvite", this_player())){
     write("The portal rejects you!\n");
     return 1;
     }
  tell_object(this_player(),
  HIY+"THERE IS A FLASH OF LIGHT! You find yourself somewhere else...\n"+NORM);
  this_player()->move_player("into the portal#players/maledicta/hope/rooms/hportal");
  return 1;
  }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



