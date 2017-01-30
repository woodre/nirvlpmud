#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if(random(7)) {
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/kale/mobs/kale"+random(12)+".c"),
	this_object());  } }
set_light(1);

short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;
long_desc =
     "   A circular room, with several mirrors on the walls.  There is\n"+
     "a projector, positioned on a tripod in the center, which sends a\n"+
     "beam of light through a colored glass, towards the mirrors.  Due\n"+
     "to the multiple reflections on the mirrors, the same pattern of \n"+
     "light can be seen,  with the same shape and the same colors, \n"+
     "regardless the position of the spectator within the room.  By \n"+
     "suitable mechanisms the mirrors can be rotated and shifted one \n"+
     "against the others as to produce other patterns, differently shaped \n"+
     "and colored.  This is the working principle of the kaleidoscope, \n"+
     "which can show endless combinations of shapes and colors.\n",
items = ({
   "toy","Both kids and adults enjoy to play with the kaleidoscope",
   "tube","It is usually made of plastic or hardpaper",
   "mirrors","The mirrors reflect the light in infinite positions",
   "pattern","The combo of shapes and colors you get when you look through the peephole",
   "peephole","A small orifice at one end of the kaleidoscope",
});

dest_dir = ({
  "","north",
  "","east",
  "","south",
  "","west"
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

