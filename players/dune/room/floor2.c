inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Second Floor";
    long_desc=
HIY+
"           __    \n"+
"         _|__|   \n"+
"        |___|_\n"+
"       |_____|_\n"+
"       |_______|__\n"+
"       ||_________|_\n"+
"       | \__________|_\n"+
"       |  \___________|_ \n"+
"       |   \____________|_\n"+
"       |     |____________|\n"+OFF+
"\n"+
"     The staircase spirals upward. The broad\n"+
"green stone stairs are easy to ascend. Hundreds of\n"+
"large pictures and runes line the walls. All of them\n"+
"are strange and beyond your comprehension.\n";

    items=({
 "walls", "The walls are filled with runes and other symbols",
 "staircase","The huge 20' wide green staircase swirls round and round",
 "floor","The stairs are of pale green stone, soft to the touch",
 "pictures","The pictures depict fire, air, water, and earth",
 "runes","You cannot read the runes",
    });

    dest_dir=({
 "/players/dune/room/floor3.c","up",
 "/players/dune/room/floor1.c","down",
    });
  }
}


realm() { return "NT"; }
