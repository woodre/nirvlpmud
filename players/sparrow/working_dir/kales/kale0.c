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
     ""+HIG+"   The kaleidoscope"+HIW+" is an optical toy c"+HIR+"onsisting of a tube\n"+
     ""+HIG+"containing two plan"+HIW+"e mirrors placed at "+HIR+"an angle of 60 degrees.\n"+
     ""+HIG+"They are mounted so"+HIW+" that a symmetrical "+HIR+"pattern produced by\n"+
     ""+HIG+"multiple reflection"+HIW+" can be observed thr"+HIR+"ough a peephole at \n"+
     ""+HIG+"one end of the kale"+HIW+"idoscope itself.  Ho"+HIR+"wever, this happens \n"+
     ""+HIG+"only when objects ("+HIW+"such as pieces of co"+HIR+"loured glass) at the\n"+
     ""+HIG+"other end are suita"+HIW+"bly illuminated.  Wh"+HIR+"en the two mirrors are\n"+
     ""+HIG+"rotated or shifted "+HIW+"one against the othe"+HIR+"r, the pattern will\n"+
     ""+HIG+"change, thus produc"+HIW+"ing an almost endles"+HIR+"s combination of shapes\n"+
     ""+HIG+"and colors."+NORM+"\n",

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
  "/players/francesco/kale/rooms/kale"+random(50)+".c","north",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","east",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","south",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","west",
  "/players/francesco/kale/rooms/entrance.c","out"
});}
else {
dest_dir = ({
  "/players/francesco/kale/rooms/kale"+random(50)+".c","north",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","east",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","south",
  "/players/francesco/kale/rooms/kale"+random(50)+".c","west"
});}
}
