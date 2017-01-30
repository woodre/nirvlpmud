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
     "   "+HIR+"The k"+NORM+"aleidosco"+HIR+"pe is"+NORM+" an optic"+HIR+"al to"+NORM+"y consist"+HIR+"ing o"+NORM+"f a tube\n"+
     "conta"+HIR+"ining"+NORM+" two plan"+HIR+"e mir"+NORM+"rors plac"+HIR+"ed at"+NORM+" an angle"+HIR+" of 6"+NORM+"0 degrees.\n"+
     "They ar"+HIR+"e mou"+NORM+"nted so t"+HIR+"hat a"+NORM+" symmetri"+HIR+"cal p"+NORM+"attern pr"+HIR+"oduce"+NORM+"d by\n"+
     "multiple "+HIR+"refle"+NORM+"ction can"+HIR+" be o"+NORM+"bserved t"+HIR+"hroug"+NORM+"h a peeph"+HIR+"ole a"+NORM+"t \n"+
     ""+HIR+"on"+NORM+"e end of "+HIR+"the k"+NORM+"aleidosco"+HIR+"pe it"+NORM+"self.  Ho"+HIR+"wever"+NORM+", this ha"+HIR+"ppens"+NORM+" \n"+
     ""+HIR+"only"+NORM+" when obj"+HIR+"ects "+NORM+"(such as "+HIR+"piece"+NORM+"s of colo"+HIR+"ured "+NORM+"glass) at"+HIR+" the"+NORM+"\n"+
     "o"+HIR+"ther "+NORM+"end are s"+HIR+"uitab"+NORM+"ly illumi"+HIR+"nated"+NORM+".  When t"+HIR+"he tw"+NORM+"o mirrors"+HIR+" are"+NORM+"\n"+
     "rot"+HIR+"ated "+NORM+"or shifte"+HIR+"d one"+NORM+" against "+HIR+"the o"+NORM+"ther, the"+HIR+" patt"+NORM+"ern will\n"+
     "chang"+HIR+"e, th"+NORM+"us produc"+HIR+"ing a"+NORM+"n almost "+HIR+"endle"+NORM+"ss combin"+HIR+"ation"+NORM+" of shapes\n"+
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

