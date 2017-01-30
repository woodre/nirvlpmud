inherit "room/room";
#include <ansi.h>


reset(arg)
{
  int i, o;

  if (!present("merman"))
  {
    o = random(3)+3;
    for(i = 1; i<=o; i++)
      move_object(clone_object("/players/dune/monsters/merman.c"),
        this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Water";
    long_desc=
CYAN+
"  ~ ~~~      ~~~~~~    ~~~~~~    ~~~~~~ ~~~   ~~~~~ ~~  \n"+
"    ~~~~~~~ ~~~~   ~~    ~~ ~~~~~   ~~~~~~   ~~~     ~~~\n"+
"________________________________________________________\n"+
"\n"+
"\n"+
"\n"+
"________________________________________________________\n"+
"   ~~ ~~~~  ~~~      ~~~~     ~    ~~~   ~~      ~~ ~   \n"+
"~ ~~~    ~~  ~~~~~~~~   ~~~ ~~~~   ~~~ ~      ~~ ~~ ~   \n"+OFF+
"     The walkway curves around tidal pools and expanses\n"+
"of rough sea. As you look above you, you are amazed at\n"+
"what you see. An entire ocean is directly above your head.\n"+
"You are between two oceans. Yet, the water above does not\n"+
"come crashing down on top of you, like you think it would.\n";

    items=({
 "walkway", "The wide walkway is made of coral",
 "ocean","You are between twin oceans",
 "pools","The pools have swarms of small sea-life in them",
 "sea","The sea is rough and too dangerous to swim in",
    });

    dest_dir=({
 "/players/dune/room/water1.c","northeast",
 "/players/dune/room/water3.c","west",
    });
  }
}


realm() { return "NT"; }
