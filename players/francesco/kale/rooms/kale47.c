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
     ""+HIM+"   The k"+HIY+"aleidosc"+HIM+"ope is a"+HIY+"n optica"+HIM+"l toy co"+HIY+"nsisting"+HIM+" of a tu"+HIY+"be\n"+
     ""+HIM+"conta"+HIY+"ining tw"+HIM+"o plane "+HIY+"mirrors "+HIM+"placed a"+HIY+"t an angl"+HIM+"e of 60 "+HIY+"degrees.\n"+
     ""+HIM+"Th"+HIY+"ey are m"+HIM+"ounted s"+HIY+"o that a"+HIM+" symmetr"+HIY+"ical patt"+HIM+"ern prod"+HIY+"uced by\n"+
     ""+HIY+"multiple"+HIM+" reflect"+HIY+"ion can "+HIM+"be obser"+HIY+"ved thro"+HIM+"ugh a pe"+HIY+"ephole a"+HIM+"t \n"+
     ""+HIY+"one e"+HIM+"nd of th"+HIY+"e kaleid"+HIM+"oscope i"+HIY+"tself.  "+HIM+"However,"+HIY+" this ha"+HIM+"ppens \n"+
     ""+HIY+"on"+HIM+"ly when "+HIY+"objects "+HIM+"(such as"+HIY+" pieces "+HIM+"of colour"+HIY+"ed glass"+HIM+") at the\n"+
     ""+HIM+"other "+HIY+"end are "+HIM+"suitably"+HIY+" illumin"+HIM+"ated.  W"+HIY+"hen the "+HIM+"two mirr"+HIY+"ors are\n"+
     ""+HIM+"rot"+HIY+"ated or "+HIM+"shifted "+HIY+"one agai"+HIM+"nst the "+HIY+"other, t"+HIM+"he patte"+HIY+"rn will\n"+
     ""+HIY+"change, "+HIM+"thus pro"+HIY+"ducing a"+HIM+"n almost"+HIY+" endless"+HIM+" combina"+HIY+"tion of "+HIM+"shapes\n"+
     ""+HIY+"and c"+HIR+"olors."+NORM+"\n",

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

