#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIG+"Concupiscetia's Chamber"+NORM;
long_desc = GRN+
 "   The soft harp music and scent of opium dances thickly in the air.  The\n"+
 "room seems to be floating in a trance.  The soft light glows majestically,\n"+
 "adding to the arousing atmosphere.  There is a large bed in the center of\n"+
 "the room.  It is covered in sheer, veil like, curtains and yards of green,\n"+
 "silk sheets.  The bed is very enticing as the opaque, perfumed, mist slowly\n"+
 "caresses the chamber. There are large embroidered pillows tossed all over\n"+
 "the lavishly carpeted floor.\n"+NORM;

items = ({
  "room",HIG+"The room is very sensual and comforting"+NORM,
  "chamber",HIG+"The chamber is obviously the living quarters for someone"+NORM,
  "bed",HIG+"The emerald silk of the sheets glimmer brightly against the\n"+ 
            "gold framed bed, contributing to the sultry dream before you"+NORM,
  "sheets",HIG+"The sheets lay sprawled across the bed"+NORM,
  "curtains",HIG+"The curtains swoop down from the top of the frame onto the bed"+NORM,
  "pillows",HIG+"Large embroidered pillows are uncaringly tossed on the floor"+NORM,
  "frame",HIY+"The gold frame looks sturdy and sparkles brightly"+NORM,
  "floor","Oriental rugs cover the floor",
  "rugs","Plush, green and gold rugs cover the cold stone floors",
  "mist","The mist wafts slowly across the room",
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t2b.c", "down",
   
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
     write("\nThe scent of opium and floral perfume fondle your senses.\n\n");
     return 1;
     }
}

realm() { return "NT"; }