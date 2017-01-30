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
     "   The circular shape of this room acts in a singular way:  if\n"+
     "you turn around you always see the same image.  Matter of fact,\n"+
     "there is a projector, positioned on a stand in the middle of the\n"+
     "room, which sends a beam of light through a colored glass towards\n"+
     "a mirror positioned in front of it:  in turn, this secondary mirror \n"+
     "reflects the light towards other mirrors and so on, in an endless \n"+
     "chain of light.  The result is that the same pattern can be seen,\n"+
     "with the same shape and the same colors, produced by the multiple\n"+
     "reflections, regardless the position of the viewer within the room.\n"+
     "Interesting to say, the mirrors can be rotated and shifted one against \n"+
     "the others and thus can produce other patterns, differently shaped and\n"+
     "colored.  This principle is the same which allows the kaleidoscope to \n"+
     "show an endless combinations of colors and shapes.\n\n"+
     "   The circular shape of this room acts in a singular way:  if\n"+
     "you turn around you always see the same image.  Matter of fact,\n"+
     "there is a projector, positioned on a stand in the middle of the\n"+
     "room, which sends a beam of light through a colored glass towards\n"+
     "some mirrors positioned alongside the walls.  The result is that,\n"+
     "the same pattern can be seen, with the same shape and the same \n"+
     "colors, produced by the multiple reflections, regardless the position \n"+
     "of the viewer within the room.  Interesting to say, the mirrors can\n"+
     "be rotated and shifted one against the others and thus can produce\n"+
     "other patterns, differently shaped and colored.  This principle is \n"+
     "the same which allows the kaleidoscope to show an endless combinations \n"+
     "of colors and shapes.\n\n"+
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
  "/players/francesco/kale/rooms/entrance.c","north",
  "/players/francesco/kale/rooms/entrance.c","east",
  "/players/francesco/kale/rooms/entrance.c","south",
  "/players/francesco/kale/rooms/entrance.c","west"
/*
  "","north",
  "","east",
  "","south",
  "","west"
*/
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

