inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if (!present("digger"))
  {
    int i;
    int o;
    o = random(2)+2;
    for(i = 1; i<=o; i++)
      move_object(clone_object("/players/dune/monsters/digger.c"),
       this_object());
  }

  if (!present("Urdlen"))
  {
    move_object(clone_object("/players/dune/monsters/urdlen.c"),
      this_object());
  }

  if (!present("gem"))
  {
    move_object(clone_object("/players/dune/objects/gem.c"),
      this_object());
  }

  if(!arg)
  {
    set_light(0);
    short_desc="Earth lord";
    long_desc=
YEL+
"__/----\\         ______                         \n"+
" |    | |\\______/    | \\_______/-----\\_______/\n"+
"                           | |  |                \n"+
" \n"+
" \n"+
"           ____|__/----\\___/---\\__|_           \n"+
"----------/                           \\__|__|___\n"+OFF+
"     The walkway leads down into a large cavern. The\n"+
"cavern has no other passageways connected to it, yet\n"+
"it is very spacious and wide. Stalagtites hang upon\n"+
"the ceiling above, and stalagmites protrude like needles\n"+
"from the floor. In the middle of the floor, there is a\n"+
"large clearing. Perhaps something has lived here for\n"+
"a very long time.\n";

    items=({
 "walkway", "The short walkway is made of limestone",
 "stalagtites","The stalagtites hang down several feet",
 "stalagmites","The stalagmites are massive pillars of rock",
 "cavern","The cavern is huge, maybe it's a monster's lair",
 "clearing","The clearing is of finely packed dirt, void of stalagmites.",
    });

    dest_dir=({
 "/players/dune/room/earth1.c","north",
    });
  }
}


realm() { return "NT"; }
