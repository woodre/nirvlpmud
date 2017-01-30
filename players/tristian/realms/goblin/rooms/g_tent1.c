#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(0);

short_desc = "Goblin Shamans Tent"; 

long_desc =
    " This is one of the larger tents in the area, there is a dirt floor with \n"+
    "strange symbols drawn in the dirt. In the center of the room is a brazier\n"+
    "with glowing coals in it. Strange scents waft around the area from the\n"+
    "brazier.  Voodoo dolls and other instruments of black magic can be seen\n"+
    "strewn across the space.\n";

items = ({

    "tent", 
        "A Better made tent than the previous ones, you suspect it was\n"+
        "pillaged from some unlucky caravan",
    "brazier", 
        "A brass pot resting in a three legged stand",
    "stand",
        "A three legged stand holding up the brazier, the legs are carved in arcane\n"+
        "runes",
    "symbols",
        "Arcane runes drawn to focus the goblin god's power",
    "runes",
        "Symbols of the goblin gods, a lightning bolt, and some clouds",
    "lightning bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "lightning",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "clouds",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "cloud",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "dolls",
         "A well used doll with many pins stuck in it, the doll is\n"+
         "wearing some minature armor and holding a swort sword",
    "instrument",
         "A couple of shrunken heads, and some bat wings, and other\n"+
         "items you associate with black magic",
    "heads",
         "Some unfortunate souls who became experiments for the shaman",
    "wings",
         "The wings off of an ordinary fruit bat",
});

    if(!present("goblin",this_object()))
        move_object(
            clone_object(NPC+"goblin_shaman.c"),
        this_object());


    dest_dir = ({

        RMS+"g_room7.c",    "out",

    });

  }

