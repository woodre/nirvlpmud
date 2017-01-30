inherit "room/room";
#include <ansi.h>


reset(arg)
{
  if (!present("digger"))
  {
    int i;
    int o;
    o = random(4)+2;
    for(i = 1; i<=o; i++)
      move_object(clone_object("/players/dune/monsters/digger.c"),
        this_object());
  }

  if(!arg)
  {
    set_light(0);
    short_desc="Earth lord";
    long_desc=
YEL+
"__/-----------------\\_____________              /----\n"+
" |    |    ||  |        |    |  | \\___________/|  |  \n"+
"                                    | |  |            \n"+
" \n"+
" \n"+
"           ____|__|_|___||___/---\\__|_               \n"+
"----------/                           \\____|__|__|___\n"+OFF+
"     The walkway leads down into a large cavern. The\n"+
"cavern has no other passageways connected to it, yet\n"+
"it is very spacious and wide. Stalagtites hang upon\n"+
"the ceiling above, and stalagmites protrude like needles\n"+
"from the floor.\n";

    items=({
 "walkway", "The short walkway is made of limestone",
 "stalagtites","The stalagtites hang down several feet",
 "stalagmites","The stalagmites are massive pillars of rock",
 "cavern","The cavern is huge, maybe it's a monster's lair",
    });

    dest_dir=({
 "/players/dune/room/center.c","north",
 "/players/dune/room/earth2.c","south",
    });
  }
}


realm() { return "NT"; }
