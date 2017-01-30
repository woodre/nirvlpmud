inherit "room/room";
#include "definitions.h"


init()
{
  add_action("goplace","west");
  add_action("goplace","w");
  ::init();
}


reset (arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Beginning south road";
    long_desc=
"     The swamp air here is completely still. So still that you smell the\n"+
"stale air. Ferns and trees tower above you. Their dark trunks end in\n"+
"gnarled forms of wood. The path from the north ends here. Odd tracks\n"+
"lie scattered upon the ground. Above you, the swamp seems to have a\n"+
"ceiling of treetops that stretch out and lace across the sky. To the\n"+
"south, the trees grow thicker and more numerous, and so block out more\n"+
"light. You notice a thin layer of mist upon the ground. The trees\n"+
"must block out enough of the sun to prevent this mist from evaporating.\n";

    dest_dir=({
        CASTLEROOM+"/swampentrance.c","north"  ,
        CASTLEROOM+"/sroad1.c","south"  ,
    });

    items=({
"tracks","     The tracks are all of four-toed beings. You notice one trail\n"+
         "of such tracks leads off west. Another trail of tracks leads\n"+
         "south, but they seem to grow fainter the further south they go.\n"+
         "It is as if the southern tracks were purposely destroyed.\n"+
"\n"+
"              _\|/   _\|/                       \n"+
"                \\     \\          _\|/         \n"+
"                                     \\   _\|/  \n"+
"                                            \\  \n"+
"                        _\|/   \n"+
"                   _\|/   \\   \n"+
"                     \\        \n"+
"",
        "trees", "     The trees are thick and have soft bark",
        "ferns", "     The ferns grow thick and sturdy like trees",
        "mist",  "     The mist swirls gently with wafts of wind",
        "trunks","     They end into the murky waters of the swamp",
    });
  }
}


goplace()
{
   say(TPN+" steps into the bushes.\n");
   write("You enter the bushes.\n");
   move_object(TP, CASTLEROOM+"/bush.c");
   return 1;
}
