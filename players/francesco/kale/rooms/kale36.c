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
     "   "+HIB+"The kal"+NORM+"eidoscope is an optical toy consisting of a "+HIB+"a tube"+NORM+"\n"+
     "containin"+HIB+"g two p"+NORM+"lane mirrors placed at an angl"+HIB+"e of 60"+NORM+" degrees.\n"+
     "They are mounte"+HIB+"d so th"+NORM+"at a symmetrical pa"+HIB+"ttern "+NORM+"produced by\n"+
     "multiple reflection c"+HIB+"an be ob"+NORM+"serve"+HIB+"d throu"+NORM+"gh a peephole at \n"+
     "one end of the kaleidoscope "+HIB+"itself. "+NORM+" However, this happens \n"+
     "only when objects (su"+HIB+"ch as p"+NORM+"ieces "+HIB+"of colo"+NORM+"ured glass) at the\n"+
     "other end are s"+HIB+"uitably"+NORM+" illuminated.  When"+HIB+" the tw"+NORM+"o mirrors are\n"+
     "rotated o"+HIB+"r shift"+NORM+"ed one against the other, the p"+HIB+"attern "+NORM+"will\n"+
     "cha"+HIB+"nge, th"+NORM+"us producing an almost endless combination "+HIB+"of shap"+NORM+"es\n"+
     "and colors.\n",

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

