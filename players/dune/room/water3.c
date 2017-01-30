inherit "room/room";
#include <ansi.h>


reset(arg)
{

  if (!present("Hydra"))
  {
    move_object(clone_object("/players/dune/monsters/hydra.c"),
      this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Water lord";
    long_desc=
CYAN+
"  ~          ~~~      ~~~~~~       ~ ~~~~~    ~~~~~ ~~ \n"+
"    ~~~~~~~      ~~~~   ~~   ~~~ ~~      ~~~   ~~~~~~  \n"+
"_________________________..~.._________________________\n"+
"                         ~...~ \n"+
"                      ... |~| ...\n"+
"                   ...... |.| ......\n"+
"_________________________~...~__________________________\n"+
"   ~~~~~~  ~~~      ~~~~  ~~~ ~~     ~~~~~~~      ~~~   \n"+
"~ ~~~    ~~       ~~~~   ~~~~~~~    ~~~~       ~~~~ ~   \n"+OFF+
"     The walkway ends in what looks like a water spout\n"+
"connecting the two oceans. The spout is huge and spins\n"+
"swiftly. At the outer edges of the spout, whitened salt water\n"+
"flies off and creates a mist around the spout.\n";

    items=({
 "walkway", "The wide walkway is made of coral",
 "oceans","You are between twin oceans",
 "spout","The spout spans for miles upward, connecting to the ocean above",
 "water","The salt water creates a white mist around the spout",
    });

    dest_dir=({
 "/players/dune/room/water2.c","east",
    });
  }
}


realm() { return "NT"; }
