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
     "   "+HIC+"The k"+NORM+"aleidosco"+HIC+"pe is"+NORM+" an optic"+HIC+"al to"+NORM+"y consist"+HIC+"ing o"+NORM+"f a tube\n"+
     "conta"+HIC+"ining"+NORM+" two plan"+HIC+"e mir"+NORM+"rors plac"+HIC+"ed at"+NORM+" an angle"+HIC+" of 6"+NORM+"0 degrees.\n"+
     "They ar"+HIC+"e mou"+NORM+"nted so t"+HIC+"hat a"+NORM+" symmetri"+HIC+"cal p"+NORM+"attern pr"+HIC+"oduce"+NORM+"d by\n"+
     "multiple "+HIC+"refle"+NORM+"ction can"+HIC+" be o"+NORM+"bserved t"+HIC+"hroug"+NORM+"h a peeph"+HIC+"ole a"+NORM+"t \n"+
     ""+HIC+"on"+NORM+"e end of "+HIC+"the k"+NORM+"aleidosco"+HIC+"pe it"+NORM+"self.  Ho"+HIC+"wever"+NORM+", this ha"+HIC+"ppens"+NORM+" \n"+
     ""+HIC+"only"+NORM+" when obj"+HIC+"ects "+NORM+"(such as "+HIC+"piece"+NORM+"s of colo"+HIC+"ured "+NORM+"glass) at"+HIC+" the"+NORM+"\n"+
     "o"+HIC+"ther "+NORM+"end are s"+HIC+"uitab"+NORM+"ly illumi"+HIC+"nated"+NORM+".  When t"+HIC+"he tw"+NORM+"o mirrors"+HIC+" are"+NORM+"\n"+
     "rot"+HIC+"ated "+NORM+"or shifte"+HIC+"d one"+NORM+" against "+HIC+"the o"+NORM+"ther, the"+HIC+" patt"+NORM+"ern will\n"+
     "chang"+HIC+"e, th"+NORM+"us produc"+HIC+"ing a"+NORM+"n almost "+HIC+"endle"+NORM+"ss combin"+HIC+"ation"+NORM+" of shapes\n"+
     "and col"+HIC+"ors."+NORM+"\n",

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

