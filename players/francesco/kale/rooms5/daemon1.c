#include "/players/francesco/univ/ansi.h"
inherit "room/room";
int blah;

reset(arg) {
  if(arg) return;
if(!random(4)) {
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c"),
	this_object());  } }
set_light(1);

short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;

long_desc = " ";

items = ({
   "room","The room is circular, about fifteen feet in diameter",
   "mirrors","The mirrors reflect the light one against the others",
   "walls","The walls are completely covered my mirrors",
   "beams","Blades of light running across the room",
   "screen","A white screen where the patterns of light are focused",
   "projector","A cube which emits light from a peephole",
   "peephole","A small orifice at one end of the projector",
   "tripod","The tripod has three legs and is about four feet high",
   "glass","It is a stained glass, with several colors",
   "pattern","The combo of shapes and colors you get when you look at the room",
   "patterns","A combo of shapes and colors coming from afar",
   "actuators","Rods and leverages to move the mirrors",
   "rods","The rods are metallic, about one foot long",
   "leverages","The leverages are connected to the rods, to move the mirrors",
});

blah=random(6);
if(!blah){
dest_dir = ({
  "",""+HIR+"n"+NORM+"",
  "",""+HIC+"e"+NORM+"",
  "",""+HIM+"s"+NORM+"",
  "",""+HIY+"w"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c","out"+NORM+""
});}
else
dest_dir = ({
  "",""+HIR+"n"+NORM+"",
  "",""+HIC+"e"+NORM+"",
  "",""+HIM+"s"+NORM+"",
  "",""+HIY+"w"+NORM+""
});
}

long(str) {
  string new_long;
  new_long= "players/francesco/kale/rooms5/description.c"->long_descr();
  if(!str) {
    write(blah+"\n");
    write(new_long);
   if(!blah)
/*   if(member_array("out", dest_dir) == -1)  */
    write("    There are five obvious exits, "+HIR+"north"+NORM+","+HIC+" east"+NORM+","+HIM+" south"+NORM+", "+HIY+"west"+NORM+" and out"+NORM+"\n"); 
    else 
    write("    There are four obvious exits: "+HIR+"north"+NORM+","+HIC+" east"+NORM+","+HIM+" south"+NORM+" and "+HIY+"west"+NORM+"\n");}
    else
   ::long(str);
}

init() {
    ::init();
    add_action("random_move","n");
    add_action("random_move","e");
    add_action("random_move","s");
    add_action("random_move","w");
    add_action("out","out");
}

random_move() {
   this_player()->move_player("to look at another pattern of light#players/francesco/kale/rooms3/kale"+random(100)+".c");
   return 1;
} 

out(){
   if(!blah) 
   this_player()->move_player("to look at another pattern of light#players/francesco/kale/rooms/entrance.c");
   return 1;
} 