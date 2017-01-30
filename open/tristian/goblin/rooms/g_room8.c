#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Training Grounds"; 

long_desc =
    " The clearing is strangly bare here, the absence of tents notable.\n"+
    "Rows of straw dummies, the hard packed ground and the rows of wooden\n"+
    "swords and spears makes it apparent that training goes on here.\n";

items = ({

    "dummies",
        "These straw dummies, riddled with slashes and holes, have seen\n"+
        "better days",
    "rows",
	   "Wooden spears and swords all arranged neatly in rows",
    "ground",
        "Dirt, packed down hard from lots of foot traffic",
    "slashes",
        "You would guess from a sword",
    "holes",
        "A spear probably made this hole",
    "swords",
        "These are wooden practice swords, they would be of little value\n"+
        "to an adventurer such as yourself",
    "spears",
        "These are wooden practice spears, they would be of little value\n"+
        "to an adventurer such as yourself",
    "clearing",
        "An open area of the woods, hard packed dirt",
    "dirt", 
        "Dirt. Plain old ordinary dirt packed down hard",
    "trash",
        "Debris and garbage",
    "debris",
        "Trash and garbage",
    "garbage", 
        "GARBAGE - you know GARBAGE!",

});

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_trainee.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_trainee.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_trainee.c"),
        this_object());


    dest_dir = ({

        RMS+"g_room7.c",      "north",
        RMS+"g_room9.c",       "west",

});

}

      init() {
        ::init();
           add_action("Smell","smell");
           add_action("Search","search");
           add_action("Listen","listen");
}

  Smell(str) {
        if(!str || str == "air") {
            write("The smells of wood smoke and dirty goblin wafts through the air.\n");
    return 1;
}
    return 1;
}

  Search() {
        write("You find nothing special.\n");
    return 1;
}

  Listen() {
        write("The general din of the goblin camp, and off further into the forest,\n"+
              "the sounds of birds chirping float on the afternoon breeze.\n");
    return 1;
}



