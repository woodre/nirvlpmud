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
     "   "+HIB+"The k"+NORM+"aleidosco"+HIR+"pe is"+NORM+" an optic"+HIB+"al to"+NORM+"y consist"+HIR+"ing o"+NORM+"f a tube\n"+
     "conta"+HIR+"ining"+NORM+" two plan"+HIB+"e mir"+NORM+"rors plac"+HIR+"ed at"+NORM+" an angle"+HIB+" of 6"+NORM+"0 degrees.\n"+
     "They ar"+HIB+"e mou"+NORM+"nted so t"+HIR+"hat a"+NORM+" symmetri"+HIB+"cal p"+NORM+"attern pr"+HIR+"oduce"+NORM+"d by\n"+
     "multiple "+HIR+"refle"+NORM+"ction can"+HIB+" be o"+NORM+"bserved t"+HIR+"hroug"+NORM+"h a peeph"+HIB+"ole a"+NORM+"t \n"+
     ""+HIR+"on"+NORM+"e end of "+HIB+"the k"+NORM+"aleidosco"+HIR+"pe it"+NORM+"self.  Ho"+HIB+"wever"+NORM+", this ha"+HIR+"ppens"+NORM+" \n"+
     ""+HIB+"only"+NORM+" when obj"+HIR+"ects "+NORM+"(such as "+HIB+"piece"+NORM+"s of colo"+HIR+"ured "+NORM+"glass) at"+HIB+" the"+NORM+"\n"+
     "o"+HIR+"ther "+NORM+"end are s"+HIB+"uitab"+NORM+"ly illumi"+HIR+"nated"+NORM+".  When t"+HIB+"he tw"+NORM+"o mirrors"+HIR+" are"+NORM+"\n"+
     "rot"+HIB+"ated "+NORM+"or shifte"+HIR+"d one"+NORM+" against "+HIB+"the o"+NORM+"ther, the"+HIR+" patt"+NORM+"ern will\n"+
     "chang"+HIR+"e, th"+NORM+"us produc"+HIB+"ing a"+NORM+"n almost "+HIR+"endle"+NORM+"ss combin"+HIB+"ation"+NORM+" of shapes\n"+
     "and col"+HIB+"ors."+NORM+"\n",

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

