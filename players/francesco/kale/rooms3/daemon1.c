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
   "mirrors","The mirrors reflect the light in infinite positions",
   "walls","The walls are completely covered my mirrors",
   "projector","A cube which emits light from a peephole",
   "peephole","A small orifice at one end of the projector",
   "tripod","The tripod has three legs and is about four feet high",
   "glass","It is a stained glass, with several colors",
   "pattern","The combo of shapes and colors you get when you look at the room",
   "patterns","A combo of shapes and colors coming from afar",
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

long(str) {
  string new_long, old_long;
  object blah;
  new_long= "players/francesco/kale/rooms3/daemon.c"->long_descr();
  old_long= "players/francesco/kale/rooms3/nocolor.c"->long_descr();
  if(!str) {
/*   if(present("glass",this_player()))*/
   blah=present("glass",this_player());
   if(blah && blah->query_worn())
/*   if(present("glass",this_player())->query_worn())*/
    write(new_long);
    else
    write(old_long);
   if(member_array("out", dest_dir) != -1) 
    write("    There are five obvious exits, north, south, east, west, and out\n"); 
    else 
    write("    There are four obvious exits: north, south, east, west\n");}
    else
   ::long(str);
}

init() {
    ::init();
    add_action("random_move","n");
    add_action("random_move","e");
    add_action("random_move","s");
    add_action("random_move","w");
}

random_move() {
   this_player()->move_player("to look at another pattern of light#players/francesco/kale/rooms3/kale"+random(100)+".c");
   return 1;
} 

