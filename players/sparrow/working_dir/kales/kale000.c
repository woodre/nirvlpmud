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
     "   The kaleidoscope is an optical toy consisting of a tube\n"+
     "containing two plane mirrors placed at an angle of 60 degrees.\n"+
     "They are mounted so that a symmetrical pattern produced by\n"+
     "multiple reflection can be observed through a peephole at \n"+
     "one end of the kaleidoscope itself.  However, this happens \n"+
     "only when objects (such as pieces of coloured glass) at the\n"+
     "other end are suitably illuminated.  When the two mirrors are\n"+
     "rotated or shifted one against the other, the pattern will\n"+
     "change, thus producing an almost endless combination of shapes\n"+
     "and colors.\n",

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

