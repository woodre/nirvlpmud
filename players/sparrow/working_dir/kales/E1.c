#include "/players/francesco/univ/ansi.h"
inherit "room/room";
int blah;

reset(arg) {
  if(arg) return;
if(!random(5)) {
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c"),
	this_object());  } }
set_light(1);

short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;
long_desc =
  "A triangular room with mirrors on the walls.  There is a projector positioned\n"+
 "on a tripod in the center which sends a beam of light toward the mirrors through\n"+
 "a colored glass.  This beam creates a wonderful, everchanging pattern.\n";
items = ({
   "room","The room is circular, about fifteen feet in diameter",
   "mirrors","The mirrors reflect the light in infinite positions",
   "walls","The walls are completely covered my mirrors",
   "projector","A cube which emits light from a peephole",
   "peephole","A small orifice at one end of the projector",
   "tripod","The tripod has three legs and is about four feet high",
   "glass","It is a stained glass, with several colors",
   "pattern","The combo of shapes and colors you get when you look at the room",
   "mechanisms","Rods and leverages to move the mirrors",
   "rods","The rods are metallic, about one foot long",
   "leverages","The leverages are connected to the rods, to move the mirrors",
});

blah=random(6);
if(!blah){
dest_dir = ({
  "","north",
  "","east",
  "","south",
  "","west",
  "/players/francesco/kale/rooms/entrance.c","out"
});}
else
dest_dir = ({
  "","north",
  "","east",
  "","south",
  "","west",
});
}

init() {
    ::init();
    add_action("random_move","n");
    add_action("random_move","e");
    add_action("random_move","s");
    add_action("random_move","w");
}

random_move() {
   this_player()->move_player("to look at another pattern of the kaleidoscope#players/francesco/kale/rooms/kale"+random(50)+".c");
   return 1;
} 

