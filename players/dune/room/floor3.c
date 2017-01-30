inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Third Floor";
    long_desc=
HIY+
"                     _     \n"+
"                    |_|_   \n"+
"                     |__|_ \n"+
"                     _|___|\n"+
"                  __|_____|\n"+
"              ___|_______||\n"+
"           __|__________/ |\n"+
"        __|___________/   |\n"+
"     __|____________/     |\n"+
"____|____________|________|\n"+OFF+
"\n"+
"     The staircase spirals upward. The broad\n"+
"green stone stairs are easy to ascend. Hundreds of\n"+
"large pictures and runes line the walls. All of them\n"+
"are strange and beyond your comprehension. You are\n"+
"far above the tower's bottom floor. In the side of the\n"+
"wall, you see a small hallway. It leads straight into the\n"+
"tower's wall.\n";

    items=({
 "walls", "The walls are filled with runes and other symbols",
 "staircase","The huge 20' wide green staircase swirls round and round",
 "floor","The stairs are of pale green stone, soft to the touch",
 "pictures","The pictures depict fire, air, water, and earth",
 "runes","You cannot read the runes",
 "hallway","It looks as if it leads to a room",
    });

    dest_dir=({
 "/players/dune/room/center.c","up",
 "/players/dune/closed/castle/rooms/doctor.c","hallway",
 "/players/dune/room/floor2.c","down",
    });
  }
}


realm() { return "NT"; }
