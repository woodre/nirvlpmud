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
     ""+HIR+"   A circu"+NORM+YEL+"lar room, "+HIY+"with sever"+HIG+"al mirrors"+HIB+" on the wa"+HIM+"lls.  Ther"+HIR+"e is a\n"+
     ""+HIR+"projector "+NORM+YEL+"positioned"+HIY+" on a trip"+HIG+"od in the "+HIB+"center of "+HIM+"the room w"+HIR+"hich sends\n"+
     ""+HIR+"a beam of "+NORM+YEL+"light thro"+HIY+"ugh a colo"+HIG+"red glass "+HIB+"towards th"+HIM+"e mirrors."+HIR+"  Due to\n"+
     ""+HIR+"the multip"+NORM+YEL+"le reflect"+HIY+"ions on th"+HIG+"e mirrors "+HIB+"the same p"+HIM+"attern of "+HIR+"light can\n"+
     ""+HIR+"be seen wi"+NORM+YEL+"th the sam"+HIY+"e shape an"+HIG+"d the same"+HIB+" colors re"+HIM+"gardless t"+HIR+"he position\n"+
     ""+HIR+"of the spe"+NORM+YEL+"ctator wit"+HIY+"hin the ro"+HIG+"om.  By us"+HIB+"ing suitab"+HIM+"le mechani"+HIR+"sms the\n"+
     ""+HIR+"mirrors ca"+NORM+YEL+"n be rotat"+HIY+"ed and shi"+HIG+"fted one a"+HIB+"gainst the"+HIM+" others in"+HIR+" order to\n"+
     ""+HIR+"produce ot"+NORM+YEL+"her patter"+HIY+"ns, differ"+HIG+"ently shap"+HIB+"ed and col"+HIM+"ored.  Oth"+HIR+"er patterns\n"+
     ""+HIR+"of light a"+NORM+YEL+"re visible"+HIY+" from the "+HIG+"north, eas"+HIB+"t, south a"+HIM+"nd west di"+HIR+"rections."+NORM+"\n",
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

