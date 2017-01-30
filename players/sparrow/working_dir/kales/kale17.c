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
     "   "+HIB+"The k"+NORM+"aleidosco"+HIB+"pe is"+NORM+" an optic"+HIB+"al to"+NORM+"y consist"+HIB+"ing o"+NORM+"f a tube\n"+
     "conta"+HIB+"ining"+NORM+" two plan"+HIB+"e mir"+NORM+"rors plac"+HIB+"ed at"+NORM+" an angle"+HIB+" of 6"+NORM+"0 degrees.\n"+
     "They ar"+HIB+"e mou"+NORM+"nted so t"+HIB+"hat a"+NORM+" symmetri"+HIB+"cal p"+NORM+"attern pr"+HIB+"oduce"+NORM+"d by\n"+
     "multiple "+HIB+"refle"+NORM+"ction can"+HIB+" be o"+NORM+"bserved t"+HIB+"hroug"+NORM+"h a peeph"+HIB+"ole a"+NORM+"t \n"+
     ""+HIB+"on"+NORM+"e end of "+HIB+"the k"+NORM+"aleidosco"+HIB+"pe it"+NORM+"self.  Ho"+HIB+"wever"+NORM+", this ha"+HIB+"ppens"+NORM+" \n"+
     ""+HIB+"only"+NORM+" when obj"+HIB+"ects "+NORM+"(such as "+HIB+"piece"+NORM+"s of colo"+HIB+"ured "+NORM+"glass) at"+HIB+" the"+NORM+"\n"+
     "o"+HIB+"ther "+NORM+"end are s"+HIB+"uitab"+NORM+"ly illumi"+HIB+"nated"+NORM+".  When t"+HIB+"he tw"+NORM+"o mirrors"+HIB+" are"+NORM+"\n"+
     "rot"+HIB+"ated "+NORM+"or shifte"+HIB+"d one"+NORM+" against "+HIB+"the o"+NORM+"ther, the"+HIB+" patt"+NORM+"ern will\n"+
     "chang"+HIB+"e, th"+NORM+"us produc"+HIB+"ing a"+NORM+"n almost "+HIB+"endle"+NORM+"ss combin"+HIB+"ation"+NORM+" of shapes\n"+
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

