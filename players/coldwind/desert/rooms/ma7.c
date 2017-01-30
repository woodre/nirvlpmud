#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("witch", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/witch.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You have entered what looks like an unholy altar placed in the \n"+
"mountain.  The room is large with ancient paintings on it's smooth\n"+
"walls.  Purple light sends a soothing feeling to your soul and fills\n"+
"the square room with mystery.  A blue carpet covers the floor totally. \n"+ 
"You can no longer hear the echo of your footsteps or breathing. \n"+ 
"You can hear your heartbeats in the quiet room...\n";

items = ({
  "cave",
  "Someone spent a great deal of time and effort to make an altar out of the cave",
  "altar",
  "The evil paintings on the walls makes you think that this is an unholy altar",
  "paintings",
  "Uknown language is used to describe the pictures, but you can\n"+
  "easily understand the pictures. The devil and demons are making\n"+
  "deals with Ashgan and members of her family. Sacrifices were\n"+
  "given in return for evil powers",
  "pictures",
  "It shows the deals made with dark forces. Sacrifices of animals, \n"+
  "humans and body parts were made by many members of Ashgan's\n"+
  "family including herself. In return, those dark enchanters have\n"+
  "attained the knowledge of powerful spells as well as many useful spells",
  "room",
  "A square room with smooth walls and ancient paintings covering them",
  "walls",
  "Ancient paintings cover the smooth walls. A small hole in the east wall\n"+
  "leading outside, but blocked with a pile of rocks",  
  "hole",
  "A small hole in the east wall leading outside the cave",
  "rocks",
  "They are blocking the exit to the cave. Looking at them won't help, you\n"+
  "should start searching",
  "pile",
  "A pile of brown rocks is blocking your way out",
  "light",
  "You are not sure where this purple light is coming from, as it fills the room\n"+
  "equally",
  "carpet",
  "A deep blue carpet covers the floor completely",
  "floor",
  "A blue carpet covers the floor completely, but on a closer look you notice\n"+
  "a small opening that you almost missed",
  "opening",
  "A small opening by the west wall. There are some stairs leading down",
  "stairs",
  "Wooden stairs leading down!",
  
});


}

init(){
  ::init();
  add_action("search_rock", "search");
  add_action("around_rock", "around");
  add_action("down_stairs", "stairs");
   add_action("down_stairs", "down");
  add_action("down_stairs", "d");
 }
 down_stairs(){
 move_object(this_player(), "/players/coldwind/desert/rooms/ma8.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

  search_rock(){
write("You notice a small "+HIW+"opening"+NORM+" in the floor and some rocks are almost\n"+
"blocking the exit, but maybe you can go "+HIW+"around"+NORM+" them.\n");
return 1;
}	

around_rock(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma5.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

	