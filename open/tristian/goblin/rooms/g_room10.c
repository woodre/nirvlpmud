#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Training Grounds"; 

long_desc =
    " The clearing is bare here, some practice dummies are off to\n"+
    "one side. Straw is strewn about the ground around the dummies, it\n"+
    "probably came from inside the dummies at one point. Some training\n"+
    "circles are inscribed into the hard packed dirt. Trash and debris blow\n"+
    "about the area, although none is evident in the training circles.\n";

items = ({

    "dummies",
        "The practice dummies strung up on wooden supports. They bear alot of\n"+
        "cuts and holes and their stuffing lays mostly on the ground",
    "stuffing",
        "Straw and grasses",
    "straw",
        "Ordinary straw used to stuff the dummies",
    "grass",
        "Long grasses that can be found all around the outskirts of the camp\n"+
        "used to stuff the dummies",
    "supports",
        "Crude wooden supports used to hold the practice dummies in an upright position",
    "circles",
        "Practice circles about 10-12 feet in diameter used for the goblins to work\n"+
        "work on sword and spear work",
    "clearing",
        "An open area of the woods, mostly hard packed dirt from alot of foot traffic",
    "dirt", 
        "Dirt. Plain old ordinary dirt",
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

        RMS+"g_room11.c",    "north",
        RMS+"g_room9.c",      "east",

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
            write("The smells of wood smoke and dirty goblins wafts through the air.\n");
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


