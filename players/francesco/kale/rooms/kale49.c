#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
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
     "   "+HIB+"The kaleidoscope is an optical toy consisting of a a tube"+HIY+"\n"+
     "containin"+HIB+"g two plane mirrors placed at an angle of 60"+HIY+" degrees.\n"+
     "They are mounte"+HIB+"d so that a symmetrical pattern "+HIY+"produced by\n"+
     "multiple reflection c"+HIB+"an be observed throu"+HIY+"gh a peephole at \n"+
     "one end of the kaleidoscope "+HIW+"itself. "+HIY+" However, this happens \n"+
     "only when objects (su"+HIR+"ch as pieces of colo"+HIY+"ured glass) at the\n"+
     "other end are s"+HIR+"uitably illuminated.  When the tw"+HIY+"o mirrors are\n"+
     "rotated o"+HIR+"r shifted one against the other, the pattern "+HIY+"will\n"+
     "cha"+HIR+"nge, thus producing an almost endless combination of shap"+HIY+"es\n"+
     "a"+HIR+"nd colors."+NORM+"\n",

items = ({
   "toy","Both kids and adults enjoy to play with the kaleidoscope",
   "tube","It is usually made of plastic or hardpaper",
   "mirrors","The mirrors reflect the light in infinite positions",
   "pattern","The combo of shapes and colors you get when you look through the peephole",
   "peephole","A small orifice at one end of the kaleidoscope",
});

blah=random(6);
if(!blah){
dest_dir = ({
  "/players/francesco/kale/rooms/entrance.c",""+HIR+"north"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIC+"east"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIM+"south"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIY+"west"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c","out"
});}
else
dest_dir = ({
  "/players/francesco/kale/rooms/entrance.c",""+HIR+"north"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIC+"east"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIM+"south"+NORM+"",
  "/players/francesco/kale/rooms/entrance.c",""+HIY+"west"+NORM+""
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

