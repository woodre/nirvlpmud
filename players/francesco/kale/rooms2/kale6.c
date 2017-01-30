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
     ""+HIR+"   A circu"+HIB+"lar room, "+HIR+"with sever"+HIB+"al mirrors"+HIR+" on the wa"+HIB+"lls.  Ther"+HIR+"e is a\n"+
     ""+HIR+"projector "+HIB+"positioned"+HIR+" on a trip"+HIB+"od in the "+HIR+"center of "+HIB+"the room w"+HIR+"hich sends\n"+
     ""+HIR+"a beam of "+HIB+"light thro"+HIR+"ugh a colo"+HIB+"red glass "+HIR+"towards th"+HIB+"e mirrors."+HIR+"  Due to\n"+
     ""+HIR+"the multip"+HIB+"le reflect"+HIR+"ions on th"+HIB+"e mirrors "+HIR+"the same p"+HIB+"attern of "+HIR+"light can\n"+
     ""+HIR+"be seen wi"+HIB+"th the sam"+HIR+"e shape an"+HIB+"d the same"+HIR+" colors re"+HIB+"gardless t"+HIR+"he position\n"+
     ""+HIR+"of the spe"+HIB+"ctator wit"+HIR+"hin the ro"+HIB+"om.  By us"+HIR+"ing suitab"+HIB+"le mechani"+HIR+"sms the\n"+
     ""+HIR+"mirrors ca"+HIB+"n be rotat"+HIR+"ed and shi"+HIB+"fted one a"+HIR+"gainst the"+HIB+" others in"+HIR+" order to\n"+
     ""+HIR+"produce ot"+HIB+"her patter"+HIR+"ns, differ"+HIB+"ently shap"+HIR+"ed and col"+HIB+"ored.  Oth"+HIR+"er patterns\n"+
     ""+HIR+"of light a"+HIB+"re visible"+HIR+" from the "+HIB+"north, eas"+HIR+"t, south a"+HIB+"nd west di"+HIR+"rections."+NORM+"\n",
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

