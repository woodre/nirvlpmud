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
     "   "+HIC+"The "+NORM+"kaleidoscope is"+HIC+" an opti"+NORM+"cal toy consist"+HIC+"ing of a "+NORM+"tube\n"+
     ""+HIC+"contain"+NORM+"ing two plane m"+HIC+"irrors p"+NORM+"laced at an ang"+HIC+"le of 60 "+NORM+"degrees.\n"+
     ""+HIC+"They ar"+NORM+"e mounted so th"+HIC+"at a sym"+NORM+"metrical patter"+HIC+"n produce"+NORM+"d by\n"+
     ""+HIC+"multipl"+NORM+"e reflection ca"+HIC+"n be obs"+NORM+"erved through a"+HIC+" peephole"+NORM+" at \n"+
     ""+HIC+"one end"+NORM+" of the kaleido"+HIC+"scope it"+NORM+"self.  However,"+HIC+" this hap"+NORM+"pens \n"+
     ""+HIC+"only wh"+NORM+"en objects (suc"+HIC+"h as pie"+NORM+"ces of coloured"+HIC+" glass) a"+NORM+"t the\n"+
     ""+HIC+"other e"+NORM+"nd are suitably"+HIC+" illumin"+NORM+"ated.  When the"+HIC+" two mirr"+NORM+"ors are\n"+
     ""+HIC+"rotated"+NORM+" or shifted one"+HIC+" against"+NORM+" the other, the"+HIC+" pattern "+NORM+"will\n"+
     ""+HIC+"change,"+NORM+" thus producing"+HIC+" an almo"+NORM+"st endless comb"+HIC+"ination o"+NORM+"f shapes\n"+
     ""+HIC+"and col"+NORM+"ors.\n",

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
    add_action("random_move","north");
    add_action("random_move","east");
    add_action("random_move","south");
    add_action("random_move","west");
}

random_move() {
   this_player()->move_player("to look at another pattern of the kaleidoscope#players/francesco/kale/rooms/kale"+random(50)+".c");
   return 1;
} 

