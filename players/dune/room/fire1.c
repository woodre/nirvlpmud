inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Fire";
    long_desc=
RED+
"      f                                                \n"+
"     ff                              f                 \n"+
"   ff         f                    ff         f       f\n"+
"   ff        f         f          fff        f      ff \n"+
"   fff      ff        f        fffff       ff     ffff \n"+
"   fffff    fff      ff     ffffffff     ffff    ffffff\n"+OFF+
"     You are on the walkway of flames. The temperature\n"+
"is very hot here. You can feel the waves of heat\n"+
"emitting from the fire columns.\n";

    items=({
 "walkway", "The wide walkway is made of obsidian",
 "flames","Spires of shooting flame surround you on all sides",
 "waves","You can see the bending waves of heat"
    });

    dest_dir=({
 "/players/dune/room/center.c","south",
 "/players/dune/room/fire2.c","west",
    });
  }
}


realm() { return "NT"; }
