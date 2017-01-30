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
     "   The ka"+HIR+"leidoscope is an optical toy consisting o"+NORM+"f a tube\n"+
     "containin"+HIR+"g two plane mirrors placed at an angle of"+NORM+" 60 degrees.\n"+
     "They are "+HIR+"mounted"+NORM+" so that a symmetrical patt"+HIR+"ern pro"+NORM+"duced by\n"+
     "multiple "+HIR+"reflect"+NORM+"ion can be observed through"+HIR+" a peep"+NORM+"hole at \n"+
     "one end o"+HIR+"f the k"+NORM+"aleidoscope itself.  Howeve"+HIR+"r, this"+NORM+" happens \n"+
     "only when"+HIR+" object"+NORM+"s (such as pieces of colour"+HIR+"ed glas"+NORM+"s) at the\n"+
     "other end"+HIR+" are su"+NORM+"itably illuminated.  When t"+HIR+"he two "+NORM+"mirrors are\n"+
     "rotated o"+HIR+"r shifted one against the other, the patt"+NORM+"ern will\n"+
     "change, t"+HIR+"hus producing an almost endless combinati"+NORM+"on of shapes\n"+
     "and colors.\n",

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

