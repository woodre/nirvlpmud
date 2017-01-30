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
     "   A circular room, with seve"+HIW+"ral"+NORM+" mirrors on the walls.  There is a\n"+
     "projector positioned on a "+HIW+"tripod in"+NORM+" the center of the room which sends\n"+
     "a beam of light through"+HIW+" a colored glas"+NORM+"s towards the mirrors.  Due to\n"+
     "the multiple reflect"+HIW+"ions on the mirrors t"+NORM+"he same pattern of light can\n"+
     "be seen with the "+HIW+"same shape and the same col"+NORM+"ors regardless the position\n"+
     "of the spectator wit"+HIW+"hin the room.  By usi"+NORM+"ng suitable mechanisms the\n"+
     "mirrors can be rotated "+HIW+"and shifted one"+NORM+" against the others in order to\n"+
     "produce other patterns, di"+HIW+"fferently"+NORM+" shaped and colored.  Other patterns\n"+
     "of light are visible from the"+HIW+" no"+NORM+"rth, east, south and west directions."+NORM+"\n",
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

