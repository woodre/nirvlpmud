#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIR+"Kardiapyr's Chamber"+NORM;
long_desc = HIR+
 "   The momentary terror that one could be burned alive shoots towards the\n"+
 "entrance from the center of the room.  In the center of this magnificent\n"+
 "chamber sits an extravagant bed.  Shadowed in red silk sheets and pillows,\n"+
 "the platinum framed bed gives the impression of liquid fire bubbling from\n"+
 "the depths of Gehenna.  Chests and baskets of elegant jewelry, clothing\n"+
 "and precious metals are scattered about the room.  The overwhelming but\n"+
 "pleasing scent of roses and vanilla musk lingers in the air.\n"+NORM;

items = ({
  "entrance",RED+"A wide opening into this chamber"+NORM,
  "room",RED+"A bed and several chests are arranged around the room"+NORM,
  "chamber",RED+"The chamber is obviously the living quarters for someone"+NORM,
  "bed",HIR+"The bed frame is made from platinum. The crimson silk of the\n"+
            "sheets and pillows compliment the frame, giving the perception\n"+
            "of boiling lava swirling around in the center of the room"+NORM,
  "sheets",HIR+"The sheets lay sprawled across the bed"+NORM,
  "pillows",HIR+"Thick heavy downed pillows are uncaringly tossed on the bed"+NORM,
  "chests","The chests are made from marbled wood and have intricate designs\n"+
           "carved into them",
  "designs","Pictures of sperpents, dragons and the Goddes are carved into\n"+
            "the chests",
  "wood","It is hard to identify what type of wood is used for these chests",
  "baskets","The baskets are tightly woven from reeds",
  "jewelry",RED+"Rubies"+NORM+","+HIB+" Sapphires"+NORM+","+HIW+" Diamonds"+NORM+" and every other conceivabel stone\n"+
            "are in abundance here",
  "clothing","Dresses, stockings, veils, and various types of headdresses\n"+
             "spill forth from the chests",
  "frame",HIW+"The platinum frame looks sturdy and shines brightly"+NORM,

  
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t1b.c", "down",
   
});
}}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
  if(str != "air") {
     write("What are you trying to smell?\n");
     return 1;
      }    
  if(str == "air") {
     write("\nThe aroma of fresh roses and vanilla assault your nose.\n\n");
     return 1;
     }
}

realm() { return "NT"; }