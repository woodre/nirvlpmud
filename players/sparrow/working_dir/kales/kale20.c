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
     "   "+HIM+"The k"+NORM+"aleidosco"+HIM+"pe is"+NORM+" an optic"+HIM+"al to"+NORM+"y consist"+HIM+"ing o"+NORM+"f a tube\n"+
     "conta"+HIM+"ining"+NORM+" two plan"+HIM+"e mir"+NORM+"rors plac"+HIM+"ed at"+NORM+" an angle"+HIM+" of 6"+NORM+"0 degrees.\n"+
     "They ar"+HIM+"e mou"+NORM+"nted so t"+HIM+"hat a"+NORM+" symmetri"+HIM+"cal p"+NORM+"attern pr"+HIM+"oduce"+NORM+"d by\n"+
     "multiple "+HIM+"refle"+NORM+"ction can"+HIM+" be o"+NORM+"bserved t"+HIM+"hroug"+NORM+"h a peeph"+HIM+"ole a"+NORM+"t \n"+
     ""+HIM+"on"+NORM+"e end of "+HIM+"the k"+NORM+"aleidosco"+HIM+"pe it"+NORM+"self.  Ho"+HIM+"wever"+NORM+", this ha"+HIM+"ppens"+NORM+" \n"+
     ""+HIM+"only"+NORM+" when obj"+HIM+"ects "+NORM+"(such as "+HIM+"piece"+NORM+"s of colo"+HIM+"ured "+NORM+"glass) at"+HIM+" the"+NORM+"\n"+
     "o"+HIM+"ther "+NORM+"end are s"+HIM+"uitab"+NORM+"ly illumi"+HIM+"nated"+NORM+".  When t"+HIM+"he tw"+NORM+"o mirrors"+HIM+" are"+NORM+"\n"+
     "rot"+HIM+"ated "+NORM+"or shifte"+HIM+"d one"+NORM+" against "+HIM+"the o"+NORM+"ther, the"+HIM+" patt"+NORM+"ern will\n"+
     "chang"+HIM+"e, th"+NORM+"us produc"+HIM+"ing a"+NORM+"n almost "+HIM+"endle"+NORM+"ss combin"+HIM+"ation"+NORM+" of shapes\n"+
     "and col"+HIM+"ors."+NORM+"\n",

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

