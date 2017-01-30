inherit "room/room";
#include <ansi.h>

reset(arg)
{
  if(!present("polls"))
  {
    move_object(clone_object("/players/dune/voting/polls.c"),
    this_object());
  }

  if(!present("filer"))
  {
    move_object(clone_object("/players/dune/filer.c"),
    this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc=HIY+"Ib"+HIG+"i"+HIR+"za"+HIM+"!!!"+NORM;
    long_desc=
"     Are you ready to party? The airplanes are flying in,\n"+
"the hipster beauties are suntanning topless at Bora Bora,\n"+
"the sky is clear blue, the Mediterranean is aqua, and it's\n"+
"going to be a very very very long night of vibing to the best\n"+
"of European house.\n";

    items=({
      "walkway", "The wide walkway is made of obsidian",
      "flames","Spires of shooting flame surround you on all sides",
      "waves","You can see the bending waves of heat"
    });

    dest_dir=({
      "/room/post.c", "drink",
    });
  }
}
