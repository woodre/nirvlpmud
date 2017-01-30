inherit "room/room";
#include "definitions.h"


void init()
{
  write(
"     You have come upon the Sithi grand treasure hall. It does not\n"+
"look protected in any way... but do not underestimate the magick of the\n"+
"Sithi.\n");
  add_action("touch","touch");
  ::init();
}


reset(arg)
{
  if (!present("wraith"))
  {
    move_object(clone_object(CASTLEMONSTER+"/wraith.c"),this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Hall of Treasure";
    long_desc=
"     Dazzling reds, blues, and greens fill your sight. As your eyes recover\n"+
"from all the shining colors, you see mounds and mounds of treasure...\n"+
"Heaps of coins, glowing swords, shimmering armor, blazing staves,\n"+
"and countless gems... You feel as if you must touch the treasure.\n"+
"Then you might have it all! The treasure hall ends in a bright room to the\n"+
"east.\n";

    dest_dir=({
        CASTLEROOM+"/lava7.c","northwest"  ,
        CASTLEROOM+"/firelord.c","east"  ,
    });

    items=({
        "treasure","     The treasure must hold countless riches",
        "colors",  "     The colors are emitted from the gems",
        "gems",    "     The gems could make you very rich!",
    });
  }
}


int touch (string str)
{
  if (!str)
  {
    write("What do you touch?\n");
    return 1;
  }
  if (str == "treasure" || str == "gems" || str == "the treasure")
  {
    write("You touch the FORBIDDEN TREASURE!\n");
    command("drop all", target);
    say("**"+RN+"** touches the FORBIDDEN TREASURE!\n");
    say("**"+RN+"** disintegrates from view!\n");
    write("You are thrown across space and time!!\n\n");
    move_object(TP, "room/church.c");
    return 1;
  }
  return 0;
}
