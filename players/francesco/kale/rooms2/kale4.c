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
long_desc =
     ""+HIM+"   A circular room, wit"+HIY+"h several mirrors on th"+HIB+"e walls.  There is a\n"+
     ""+HIM+"projector positioned on"+HIY+" a tripod in the center"+HIB+" of the room which sends\n"+
     ""+HIM+"a beam of light through"+HIY+" a colored glass toward"+HIB+"s the mirrors.  Due to\n"+
     ""+HIM+"the multiple reflection"+HIY+"s on the mirrors the sa"+HIB+"me pattern of light can\n"+
     ""+HIM+"be seen with the same s"+HIY+"hape and the same color"+HIB+"s regardless the position\n"+
     ""+HIM+"of the spectator within"+HIY+" the room.  By using su"+HIB+"itable mechanisms the\n"+
     ""+HIM+"mirrors can be rotated "+HIY+"and shifted one against"+HIB+" the others in order to\n"+
     ""+HIM+"produce other patterns,"+HIY+" differently shaped and"+HIB+" colored.  Other patterns\n"+
     ""+HIM+"of light are visible fr"+HIY+"om the north, east, sou"+HIB+"th and west directions."+NORM+"\n",
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

init() {
    ::init();
    add_action("random_move","n");
    add_action("random_move","e");
    add_action("random_move","s");
    add_action("random_move","w");
}

random_move() {
   this_player()->move_player("to look at another pattern of the kaleidoscope#players/francesco/kale/rooms2/kale"+random(70)+".c");
   return 1;
} 

