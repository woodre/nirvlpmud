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
     "   The kaleidoscope is an "+HIB+"optical"+NORM+" toy consisting of a tube\n"+
     "containing two plane m"+HIB+"irrors "+NORM+"pla"+HIB+"ced at "+NORM+"an angle of 60 degrees.\n"+
     "They are mounted s"+HIB+"o that "+NORM+"a symmetric"+HIB+"al patt"+NORM+"ern produced by\n"+
     "multiple refle"+HIB+"ction c"+NORM+"an be observed thro"+HIB+"ugh a p"+NORM+"eephole at \n"+
     "one end of"+HIB+" the ka"+NORM+"leidoscope itself.  However"+HIB+", this "+NORM+"happens \n"+
     "only when obje"+HIB+"cts (su"+NORM+"ch as pieces of col"+HIB+"oured g"+NORM+"lass) at the\n"+
     "other end are suit"+HIB+"ably il"+NORM+"luminated. "+HIB+" When t"+NORM+"he two mirrors are\n"+
     "rotated or shifted one"+HIB+" agains"+NORM+"t t"+HIB+"he othe"+NORM+"r, the pattern will\n"+
     "change, thus producing an al"+HIB+"most en"+NORM+"dless combination of shapes\n"+
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

