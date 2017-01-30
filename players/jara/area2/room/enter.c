/* Whack-A-Wiz Land- Entrance. Created <6/19/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc=HIY+"Whack"+HIW+"-"+HIY+"A"+HIW+"-"+HIY+"Wiz Land"+HIW+": Entrance"+NORM;
  long_desc=
    "  The entrance to "+HIY+"Whack"+HIW+"-"+HIY+"A"+HIW+"-"+HIY+"Wiz Land"+NORM+" resides on a large, fluffy cloud.\n"+
    "The fence that borders the park opens up to a gate here, and continues\n"+
    "to both the east and west. A tower looms in the distance, and a vendor\n"+
    "has parked his cart just off the path.\n";
  items=({
    "fence",
    "A metal fence, black in color, that is approximately six feet high.\n"+
    "The bars are close together and each bar has an ornately designed\n"+
    "spike atop the fence",
    "crest",
    "A crest of a lion, colored a bright red, and a white unicorn",
    "gate",
    "A wide gate, made of a black metal, approximately seven feet high.\n"+
    "The gate arches and an ornate crest is centered in the frame of the\n"+
    "gate. The bars of the gate are close together, and each bar has\n"+
    "a spike atop the fence",
    "tower",
    "A crystal tower that seems to change color at every angle",
    "cart",
    "A small, wooden cart, with wide wagon wheels. The brightly colored\n"+
    "canopy shields the goods from the brightness of the sun. There is\n"+
    "a sign nailed to the front of the cart",
    "goods",
    "An assortment of maps and guidebooks",
    "sign",
    "You may"+HIW+" read"+NORM+" the"+HIW+" sign"+NORM+" on the cart",
    "canopy",
    "The fabric of the canopy is decorated in a bold red and white pattern",
    "cloud",
    "The delicate white clouds seem to shift and move with the breeze" });
  dest_dir=({ 
    PATH+"path1","north",
    "/room/south/sforst11.c","return" });
}
