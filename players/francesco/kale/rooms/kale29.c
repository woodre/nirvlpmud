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
	this_object()); 
  move_object(clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c"),
	this_object());   } }
set_light(1);

short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;
long_desc =
     "   "+HIB+"The kaleidosco"+HIR+"pe is an optic"+HIB+"al toy consist"+HIR+"ing of a tube\n"+
     "conta"+HIB+"ining two plan"+HIR+"e mirrors plac"+HIB+"ed at an angle"+HIR+" of 60 degrees.\n"+
     "They ar"+HIB+"e mounted so t"+HIR+"hat a symmetri"+HIB+"cal pattern pr"+HIR+"oduced by\n"+
     "multiple "+HIB+"reflection can"+HIR+" be observed t"+HIB+"hrough a peeph"+HIR+"ole at \n"+
     ""+HIR+"one end of "+HIB+"the kaleidosco"+HIR+"pe itself.  Ho"+HIB+"wever, this ha"+HIR+"ppens \n"+
     ""+HIR+"only when obj"+HIB+"ects (such as "+HIR+"pieces of colo"+HIB+"ured glass) at"+HIR+" the\n"+
     "o"+HIR+"ther end are s"+HIB+"uitably illumi"+HIR+"nated.  When t"+HIB+"he two mirrors"+HIR+" are\n"+
     ""+HIB+"rot"+HIR+"ated or shifte"+HIB+"d one against "+HIR+"the other, the"+HIB+" pattern will\n"+
     "chang"+HIR+"e, thus produc"+HIB+"ing an almost "+HIR+"endless combin"+HIB+"ation of shapes\n"+
     "and col"+HIR+"ors."+NORM+"\n",

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

