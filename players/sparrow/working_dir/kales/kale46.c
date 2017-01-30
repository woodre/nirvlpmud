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
     ""+HIR+"   The k"+HIY+"aleidosc"+HIR+"ope is a"+HIY+"n optica"+HIR+"l toy co"+HIY+"nsisting"+HIR+" of a tu"+HIY+"be\n"+
     ""+HIR+"conta"+HIY+"ining tw"+HIR+"o plane "+HIY+"mirrors "+HIR+"placed a"+HIY+"t an ang"+HIR+"le of 60"+HIY+" degrees.\n"+
     ""+HIR+"Th"+HIY+"ey are m"+HIR+"ounted s"+HIY+"o that a"+HIR+" symmetr"+HIY+"ical pat"+HIR+"tern pro"+HIY+"duced by\n"+
     ""+HIY+"multipl"+HIR+"e reflec"+HIY+"tion can"+HIR+" be obse"+HIY+"rved thr"+HIR+"ough a p"+HIY+"eephole "+HIR+"at \n"+
     ""+HIY+"one "+HIR+"end of t"+HIY+"he kalei"+HIR+"doscope "+HIY+"itself. "+HIR+" However"+HIY+", this h"+HIR+"appens \n"+
     ""+HIY+"o"+HIR+"nly when"+HIY+" objects"+HIR+" (such a"+HIY+"s pieces"+HIR+" of colo"+HIY+"ured gla"+HIR+"ss) at the\n"+
     ""+HIR+"other"+HIY+" end are s"+HIR+"uitably "+HIY+" illumi"+HIR+"nated.  "+HIY+"When the"+HIR+" two mir"+HIY+"rors are\n"+
     ""+HIR+"ro"+HIY+"tated or"+HIR+" shifted"+HIY+" one aga"+HIR+"inst the"+HIY+" other, "+HIR+"the patt"+HIY+"ern will\n"+
     ""+HIY+"change,"+HIR+" thus pr"+HIY+"oducing "+HIR+"an almos"+HIY+"t endles"+HIR+"s combin"+HIY+"ation of"+HIR+" shapes\n"+
     ""+HIY+"and "+HIR+"colors."+NORM+"\n",

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

