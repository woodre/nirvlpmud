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
     "   "+HIB+"The "+NORM+"kaleidoscope is"+HIR+" an opti"+NORM+"cal toy consist"+HIY+"ing of a "+NORM+"tube\n"+
     ""+HIB+"contain"+NORM+"ing two plane m"+HIR+"irrors p"+NORM+"laced at an ang"+HIY+"le of 60 "+NORM+"degrees.\n"+
     ""+HIB+"They ar"+NORM+"e mounted so th"+HIR+"at a sym"+NORM+"metrical patter"+HIY+"n produce"+NORM+"d by\n"+
     ""+HIB+"multipl"+NORM+"e reflection ca"+HIR+"n be obs"+NORM+"erved through a"+HIY+" peephole"+NORM+" at \n"+
     ""+HIW+"one end"+NORM+" of the kaleido"+HIW+"scope it"+NORM+"self.  However,"+HIW+" this hap"+NORM+"pens \n"+
     ""+HIB+"only wh"+NORM+"en objects (suc"+HIR+"h as pie"+NORM+"ces of coloured"+HIY+" glass) a"+NORM+"t the\n"+
     ""+HIB+"other e"+NORM+"nd are suitably"+HIR+" illumin"+NORM+"ated.  When the"+HIY+" two mirr"+NORM+"ors are\n"+
     ""+HIB+"rotated"+NORM+" or shifted one"+HIR+" against"+NORM+" the other, the"+HIY+" pattern "+NORM+"will\n"+
     ""+HIB+"change,"+NORM+" thus producing"+HIR+" an almo"+NORM+"st endless comb"+HIY+"ination o"+NORM+"f shapes\n"+
     ""+HIB+"and col"+NORM+"ors.\n",

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

