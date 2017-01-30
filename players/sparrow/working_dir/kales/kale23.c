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
     "   "+HIM+"The kaleidosco"+HIY+"pe is an optic"+HIM+"al toy consist"+HIY+"ing of a tube\n"+
     "conta"+HIM+"ining two plan"+HIY+"e mirrors plac"+HIM+"ed at an angle"+HIY+" of 60 degrees.\n"+
     "They ar"+HIM+"e mounted so t"+HIY+"hat a symmetri"+HIM+"cal pattern pr"+HIY+"oduced by\n"+
     "multiple "+HIM+"reflection can"+HIY+" be observed t"+HIM+"hrough a peeph"+HIY+"ole at \n"+
     ""+HIY+"one end of "+HIM+"the kaleidosco"+HIY+"pe itself.  Ho"+HIM+"wever, this ha"+HIY+"ppens \n"+
     ""+HIY+"only when obj"+HIM+"ects (such as "+HIY+"pieces of colo"+HIM+"ured glass) at"+HIY+" the\n"+
     "o"+HIY+"ther end are s"+HIM+"uitably illumi"+HIY+"nated.  When t"+HIM+"he two mirrors"+HIY+" are\n"+
     ""+HIM+"rot"+HIY+"ated or shifte"+HIM+"d one against "+HIY+"the other, the"+HIM+" pattern will\n"+
     "chang"+HIY+"e, thus produc"+HIM+"ing an almost "+HIY+"endless combin"+HIM+"ation of shapes\n"+
     "and col"+HIY+"ors."+NORM+"\n",

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

