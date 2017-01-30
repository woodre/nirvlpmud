#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#include "/players/jaraxle/ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("templar_mess", this_object())){
move_object(clone_object("players/jaraxle/templar/mobs/templar_mess"), this_object());
	}
	if(!present("bulletinboard", this_object())){
		move_object(clone_object("players/boltar/templar/board"), this_object());
	}
  if(arg) return;
set_light(1);

short_desc = HIW+"Community Room ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
    "  The spacious room is well lit by the large windows that provide a\n"+
    "view of the beautiful gardens, and several banners bearing the cross\n"+
    "of the Templars ripple gently in the soft breeze that drifts in from\n"+
    "the windows. There are comfortable chairs and plush sofas set within\n"+
    "the room, though most are placed beside the fireplace. A table beside\n"+
    "the wall holds platters of sweets, a coffee carafe, and some tea. A\n"+
    "softly glowing "+GRN+"portal"+NORM+" leading to the Tower of Hope is open near the\n"+
    "northern wall.\n";
items = ({
  "portal",
  "The portal glow fluctuates with power. You may "+GRN+"enter"+NORM+" the "+GRN+"portal"+NORM+" to\n"+
  "reach the tower",
  "windows",
  "The windows are unbarred and open to the air. They extend a great\n"+
  "length, nearly from ceiling to floor. They are curtained with thick,\n"+
  "velvety material",
  "chairs",
  "The chairs are wide and upholstered with soft padding for comfort",
  "banners",
  "The silk banners bearing the red cross of the Templars hang proudly\n"+
  "from the ceiling",
  "sofas",
  "The plush sofas are wide enough for two or three people",
  "table",
  "A beautiful oak table, hand carved and finished to a warm shine",
  "platters",
  "Sweet platters, plated with gold and adorned with sparkling gems",
  "sweets",
  "Delicate sweets dipped in chocolate or decorated with powdered sugar",
  "coffee",
  "The coffee carafe holds an aromatic coffee, rich and full of flavor",
  "tea",
  "A pot of tea, made of a delicate china",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway2.c","south",
  "/players/jaraxle/templar/rooms/equipment.c", "up",
  "/players/jaraxle/templar/rooms/shop.c", "east",
  "/players/jaraxle/templar/rooms/warroom.c","west",
});

}

init(){
 ::init();
   add_action("enter", "enter");
   add_action("up","up");
  add_action("west", "west");
   add_action("title", "title");
/*
   this_player()->set_fight_area();
*/
   }

up(){
if(!present("KnightInvite",this_player())){
write("You are not allowed access.\n");
return 1; }
}

west(){
                   if(tp->query_guild_rank() < 9){
 write("Something blocks you from moving in that direction.\n");
 return 1; }
if(!present("KnightInvite",this_player())){
write("You are not allowed access.\n");
return 1; }
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
  this_player()->move_player("into the portal#players/jaraxle/hope/rooms/hportal");
  return 1;
  }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



