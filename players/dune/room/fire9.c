inherit "room/room";
#include <ansi.h>


reset(arg)
{

  if (!present("Saal"))
  {
    move_object(clone_object("/players/dune/monsters/saal.c"),
      this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Fire Lord";
    long_desc=
RED+
"  f                          f                      f  \n"+
"   ff                        f                    ff   \n"+
"    ff       f               ff          f       ff    \n"+
"    fff       f             fff         f      fff     \n"+
"    fffff     ff           fffff       ff     ffff     \n"+
"   fffffff    fff        ffffffff     ffff    ffffff   \n"+OFF+
"*******************************************************\n"+
"     The walkway ends in a bowl-shaped pit. Columns\n"+
"of white hot fire surround the edges of the bowl.\n"+
"The pit floor is smooth, and seems to be made of a\n"+
"bronze-like metal.\n";

    items=({
 "walkway", "The wide walkway is made of obsidian",
 "fire","The white fire bursts from circular funnels",
 "columns","The columns of fire ring the pit",
 "floor","The floor slopes downward to the center",
 "metal","The metal nearly burns your feet",
    });

    dest_dir=({
 "/players/dune/room/fire8.c","west",
    });
  }
}


realm() { return "NT"; }
