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
     ""+HIG+"   A circular room, wit"+HIW+"h several mirrors on th"+HIR+"e walls.  There is a\n"+
     ""+HIG+"projector positioned on"+HIW+" a tripod in the center"+HIR+" of the room which sends\n"+
     ""+HIG+"a beam of light through"+HIW+" a colored glass toward"+HIR+"s the mirrors.  Due to\n"+
     ""+HIG+"the multiple reflection"+HIW+"s on the mirrors the sa"+HIR+"me pattern of light can\n"+
     ""+HIG+"be seen with the same s"+HIW+"hape and the same color"+HIR+"s regardless the position\n"+
     ""+HIG+"of the spectator within"+HIW+" the room.  By using su"+HIR+"itable mechanisms the\n"+
     ""+HIG+"mirrors can be rotated "+HIW+"and shifted one against"+HIR+" the others in order to\n"+
     ""+HIG+"produce other patterns,"+HIW+" differently shaped and"+HIR+" colored.  Other patterns\n"+
     ""+HIG+"of light are visible fr"+HIW+"om the north, east, sou"+HIR+"th and west directions."+NORM+"\n",
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

