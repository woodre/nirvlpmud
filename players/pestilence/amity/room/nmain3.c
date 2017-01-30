#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"North Main Street"+NORM+"";
long_desc =
  "    This is the main street through Amity.  There is a bar on the\n"+
  "west side of the street.  On the east side there is a restaurant.\n"+
  "The street continues to the north and south.  The street is bare here.\n"+
  "There is no action around here.  There are several cars overturned in\n"+
  "the street.\n";
set_light(1);

items = ({
"car","A blue Chevy Cavalier is overturned, blocking the roadway to the north",
"cavalier","A blue 1991 Chevy Cavalier, with four doors",
"taurus","A two door, red 1992 Ford Taurus", 
"restaurant","This is the popular Texas Hot's restaurant located east of here",
"cars","A Ford Taurus and a Chevy Cavalier are overturned in the road",
"street","The street is paved and leads to the north and south",
"bar","A local bar is located west from here",
});

dest_dir = ({
"/players/pestilence/amity/room/nmain2.c","south",
"/players/pestilence/amity/room/blabhlbha","north",
"/players/pestilence/amity/room/bar.c","west",
"/players/pestilence/amity/room/texashot.c","east",
});
}


init () {
   ::init() ;
     add_action ("blocked","north");
     }

blocked(str) {
     write("This part of the street is blocked by an overturned car and is impassable.\n");
     return 1;}
