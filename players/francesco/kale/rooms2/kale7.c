#include "/players/francesco/univ/ansi.h"
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
     ""+HIY+"   A circu"+HIM+"lar room, "+HIY+"with sever"+HIM+"al mirrors"+HIY+" on the wa"+HIM+"lls.  Ther"+HIY+"e is a\n"+
     ""+HIY+"projector "+HIM+"positioned"+HIY+" on a trip"+HIM+"od in the "+HIY+"center of "+HIM+"the room w"+HIY+"hich sends\n"+
     ""+HIY+"a beam of "+HIM+"light thro"+HIY+"ugh a colo"+HIM+"red glass "+HIY+"towards th"+HIM+"e mirrors."+HIY+"  Due to\n"+
     ""+HIY+"the multip"+HIM+"le reflect"+HIY+"ions on th"+HIM+"e mirrors "+HIY+"the same p"+HIM+"attern of "+HIY+"light can\n"+
     ""+HIY+"be seen wi"+HIM+"th the sam"+HIY+"e shape an"+HIM+"d the same"+HIY+" colors re"+HIM+"gardless t"+HIY+"he position\n"+
     ""+HIY+"of the spe"+HIM+"ctator wit"+HIY+"hin the ro"+HIM+"om.  By us"+HIY+"ing suitab"+HIM+"le mechani"+HIY+"sms the\n"+
     ""+HIY+"mirrors ca"+HIM+"n be rotat"+HIY+"ed and shi"+HIM+"fted one a"+HIY+"gainst the"+HIM+" others in"+HIY+" order to\n"+
     ""+HIY+"produce ot"+HIM+"her patter"+HIY+"ns, differ"+HIM+"ently shap"+HIY+"ed and col"+HIM+"ored.  Oth"+HIY+"er patterns\n"+
     ""+HIY+"of light a"+HIM+"re visible"+HIY+" from the "+HIM+"north, eas"+HIY+"t, south a"+HIM+"nd west di"+HIY+"rections."+NORM+"\n",
items = ({
   "room","The room is circular, about fifteen feet in diameter",
   "mirrors","The mirrors reflect the light in infinite positions",
   "walls","The walls are completely covered my mirrors",
   "projector","A cube which emits light from a peephole",
   "peephole","A small orifice at one end of the projector",
   "tripod","The tripod has three legs and is about four feet high",
   "glass","It is a stained glass, with several colors",
   "pattern","The combo of shapes and colors you get when you look at the room",
   "patterns","A combo of shapes and colors coming from afar",
   "mechanisms","Rods and leverages to move the mirrors",
   "rods","The rods are metallic, about one foot long",
   "leverages","The leverages are connected to the rods, to move the mirrors",
});

blah=random(6);
if(!blah){
dest_dir = ({
  "","north",
  "","east",
  "","south",
  "","west",
  "/players/francesco/kale/rooms/entrance.c","out"
});}
else
dest_dir = ({
  "","north",
  "","east",
  "","south",
  "","west",
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
   this_player()->move_player("to look at another pattern of the kaleidoscope#players/francesco/kale/rooms2/kale"+random(70)+".c");
   return 1;
} 

