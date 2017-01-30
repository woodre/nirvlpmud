#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
if(!random(2)) {
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/kale/mobs/superkale"+(1+random(2))+".c"),
	this_object());  } }
if(!random(4)) {
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c"),
	this_object());  } }
set_light(1);

short_desc = ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"" ;
long_desc =
     ""+HIB+""+HIW+" "+HIB+"  T"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIB+"pe "+HIW+"i"+HIB+"s a"+HIR+"n optical toy consisting of a tube"+NORM+"\n"+
     ""+HIB+"co"+HIW+"n"+HIB+"tai"+HIW+"n"+HIB+"ing"+HIW+" "+HIB+"two"+HIW+" "+HIB+"pla"+HIW+"n"+HIB+"e m"+HIW+"i"+HIB+"rr"+HIW+"ors placed at an angle of 60 degrees."+NORM+"\n"+
     ""+HIB+""+HIW+"T"+HIB+"hey"+HIW+" "+HIB+"are"+HIW+" "+HIB+"mou"+HIW+"n"+HIB+"ted"+HIW+" "+HIB+"so "+HIW+"t"+HIB+"hat"+HIW+" "+HIR+"a symmetrical pattern produced by"+NORM+"\n"+
     ""+HIB+"mu"+HIW+"l"+HIB+"tip"+HIW+"l"+HIB+"e r"+HIW+"e"+HIB+"fle"+HIW+"c"+HIB+"tio"+HIW+"n"+HIB+" ca"+HIW+"n"+HIB+" b"+HIW+"e observed through a peephole at"+NORM+" \n"+
     ""+HIB+""+HIW+"o"+HIB+"ne "+HIW+"e"+HIB+"nd "+HIW+"o"+HIB+"f t"+HIW+"h"+HIB+"e k"+HIW+"a"+HIB+"lei"+HIW+"d"+HIB+"osc"+HIW+"o"+HIR+"pe itself.  However, this happens"+NORM+" \n"+
     ""+HIW+"only when objects (such as pieces of coloured glass) at the"+NORM+"\n"+
     ""+HIR+"other end are suitably illuminated.  When the two mirrors are"+NORM+"\n"+
     ""+HIW+"rotated or shifted one against the other, the pattern will"+NORM+"\n"+
     ""+HIR+"change, thus producing an almost endless combination of shapes"+NORM+"\n"+
     ""+HIW+"and colors."+NORM+"\n",

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

