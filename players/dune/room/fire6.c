inherit "room/room";
#include <ansi.h>


reset(arg)
{

  if (!present("firedrake"))
  {
    int i;
    int a;
    a = random(4)+2;
    for(i = 1; i<=a; i++)
      move_object(clone_object("/players/dune/monsters/firedrake.c"),
        this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Fire";
    long_desc=
RED+
"   f                                                   \n"+
"   ff                            f                     \n"+
"   ff        f                  ff        f      f     \n"+
"   ff        f        f        fff        f      ff    \n"+
"  ffff      ff        f       fffff       ff     ffff  \n"+
" fffffff    fff      fff    ffffffff     ffff    ffffff\n"+OFF+
"     You are on the walkway of flames. The temperature\n"+
"is very hot here. You can feel the waves of heat\n"+
"emitting from the fire columns.\n";

    items=({
 "walkway", "The wide walkway is made of obsidian",
 "flames","Spires of shooting flame surround you on all sides",
 "waves","You can see the bending waves of heat",
    });

    dest_dir=({
 "/players/dune/room/fire7.c","east",
 "/players/dune/room/fire4.c","south",
    });
  }
}


realm() { return "NT"; }
