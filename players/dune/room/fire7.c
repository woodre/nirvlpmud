inherit "room/room";
#include <ansi.h>


reset(arg)
{

  if (!present("firedragon"))
  {
    int i;
    int a;
    a = random(2) + 1;
    for(i = 1; i<=a; i++)
      move_object(clone_object("/players/dune/monsters/firedragon.c"),
        this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Fire";
    long_desc=
RED+
"     f                                                   \n"+
"    ff                            f                      \n"+
"   ff        f                    ff        f       f    \n"+
"   ff        f                  ffff       f      ff     \n"+
"   fff      ff        f        ffffff      ff     ffff   \n"+
"    ffff   ffff      ff     ffffffffff    ffff    ffffff \n"+OFF+
"     You are on the walkway of flames. The temperature\n"+
"is very hot here. You can feel the waves of heat\n"+
"emitting from the fire columns.\n";

    items=({
 "walkway", "The wide walkway is made of obsidian",
 "flames","Spires of shooting flame surround you on all sides",
 "waves","You can see the bending waves of heat",
    });

    dest_dir=({
 "/players/dune/room/fire8.c","north",
 "/players/dune/room/fire5.c","south",
 "/players/dune/room/fire6.c","west",
    });
  }
}


realm() { return "NT"; }
