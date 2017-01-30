#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(0);

short_desc = "Goblin Command Tent"; 

long_desc =
    " Upon entering the largest tent in the area, there is visible a table with\n"+
    "maps and some closed chests in the corner. A rug on the floor and some chairs\n"+
    "around the table. Trash and debris lay strewn about this area as well.  Thinking\n"+
    "that you have entered the command tent for the goblin army it brings a curious thought\n"+
    "to mind, 'Are goblins this organized?'\n";

items = ({

    "tent", 
        "A better made tent than the previous ones, leading one to suspect they\n"+
        "were pillaged from some unlucky caravan",
    "rug", 
        "A beautifully woven rug of oriental design, you suspect was pillaged\n"+
        "from some unlucky caravan",
    "table",
        "A standard table found in any inn, but with the legs hacked off so it\n"+
        "is lower to the ground",
    "chair",
        "A standard chair found in any inn, but with the legs hacked off so it\n"+
        "is lower to the ground",
    "maps",
        "Crude drawings showing the general layout of the forest",
    "floor",
        "Dirt and more dirt, except for the area covered by the rug",
    "dirt",
        "Its dirt, come on and give a guy a break on discriptors already",
    "chairs",
        "Standard chairs found in any inn, but with the legs hacked off so it\n"+
        "is lower to the ground",
    "trash",
        "Debris and garbage",
    "debris",
        "Trash and garbage",
    "garbage", 
        "GARBAGE - you know GARBAGE!",
    "chest",
        "Wooden chests that seem to hold the goblin booty",
    "chests",
        "Wooden chests that seem to hold the goblin booty",
    "booty",
        "Shiney bits of glass, colorful rocks and other useless items.\n"+
        "What is booty to a goblin is junk to you",

});

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_general.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_captain.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_lieutenant.c"),
        this_object());


    dest_dir = ({

        RMS+"g_room5.c",    "out",

    });

  }

