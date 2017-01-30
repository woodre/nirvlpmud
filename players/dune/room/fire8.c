inherit "room/room";
#include <ansi.h>


reset(arg)
{

  if (!present("firedragon"))
  {
    int i;
    int a;
    a = random(3) + 3;
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
"   f                              f                    \n"+
"   ff        f                   f                f    \n"+
"   ff        f        f          ff        f      ff   \n"+
"  ffff      ff        f          fff      ff    ffff   \n"+
" fffffff    fff      fff       ffff     ffff    ffffff \n"+OFF+
"     You are on the walkway of flames. The temperature\n"+
"is very hot here. You can feel the waves of heat\n"+
"emitting from the fire columns.\n";

    items=({
 "walkway", "The wide walkway is made of obsidian",
 "flames","Spires of shooting flame surround you on all sides",
 "waves","You can see the bending waves of heat",
    });

    dest_dir=({
 "/players/dune/room/fire9.c","east",
 "/players/dune/room/fire7.c","south",
    });
  }
}


realm() { return "NT"; }
