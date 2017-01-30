#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;


short_desc = ""+BLU+"Bathroom"+NORM+"";
long_desc =
  "    The bathroom is very small.  The floor is covered with a white\n"+
  "tile.  The walls are covered with a white wallpaper with a floral\n"+
  "pattern.  The toilet is a white porcelain and is located on the north\n"+
  "wall, with the sink on the east wall.   There is a small mirror above\n"+
  "the sink.  A combination shower and bath is on the south wall.\n";
set_light(1);

items = ({
"handle","A small handle on the toilet to flush it.  To use a person would 'flush toilet'",
"wallpaper","A plain white wallpaper covers the walls",
"walls","A plain white wallpaper covers the walls",
"wall","A plain white wallpaper covers the wall",
"floor","The floor is covered with a porcelain white tile",
"tile","A porcelain white tile that covers the floor",
"porcelain tile","A porcelain white tile that covers the floor",
"toilet","A white porcelain toilet, with a small handle to flush the toilet",
"sink","A small beige colored sink, with a mirror above it",
"mirror","A mirror with an image of you in it",
"shower","A shower combination bath on the south wall",
"bathtub","The bathtub is made of a heavy-duty white plastic with a drain at one end",
"bath","The bathtub is made of a heavy-duty white plastic with a drain at one end",
"drain","A normal drain in the button of the bath tub",
"door","A sliding door for the combination bath and shower",
"floral pattern","Flowers scattered across the white wallpaper",
"pattern","Flowers scattered across the white wallpaper",
"flowers","Flowers scattered across the white wallpaper",
"south wall","The wall is covered with wallpaper, with a combination shower and bath on it",
"east wall","The wall is covered with wallpaper, with a sink on it",
"north wall","The wall is covered with wallpaper, with a toilet against it",
"sliding door","A sliding door for the combination bath and shower",
});

dest_dir = ({
  "/players/pestilence/amity/room/madhouse1.c","west",
});
}

init () {
   ::init() ;
     add_action ("flush_toilet","flush");
     }

flush_toilet(arg) {
   if(!arg) { notify_fail("Flush what?\n");
       return 0;}
   if(arg == "toilet"){

     write("You push the handle down and flush the toilet.\n"+
           "You hear the water wooshing down the drain.\n");
     return 1;}
else
{
       notify_fail("You may only flush the toilet.\n");
      return 0;
}
}
