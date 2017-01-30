#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Encampment"; 

long_desc =
    " The clearing in this area is populated with randomly placed tents\n"+
    "and sparrodic grasses. Cook fires are scattered around the tents and\n"+
    "trash and debris blow in the breeze. A random tree stump can be seen\n"+
    "here and there, showing that clearing of this area is still ongoing.\n"+
    "The forest presses in close to the west, almost hiding a low picket\n"+
    "running just inside of the tree line.\n";

items = ({

    "tents", 
        "Crude tents that leak at the seams, made from some\n"+
        "unknown tanned material",
    "picket",
        "A low fence of sticks, twigs and small logs that prevents\n"+
        "going out into the forest, but more importantly prevents\n"+
        "intruders from coming in that way",
    "line",
        "A low fence of sticks, twigs and small logs that prevents\n"+
        "going out into the forest, but more importantly prevents\n"+
        "intruders from coming in that way",
    "paintings",
        "Crude stick figure paintings depicting battles and pillaging",
    "pines", 
        "Evergreen pines well over 100' tall",
        "forest",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
    "fires",
        "Little cook fires, about 1 fire for every 5 tents",
    "trees",
        "Tall pines, probably been growing since this forest was new.", 
    "clearing",
        "An open area of the woods, mostly beaten down grass and dirt",
    "grass",
        "Beaten down grass, mostly dead and randomly scattered",
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
            clone_object(NPC+"goblin_regular.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_regular.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_regular.c"),
        this_object());

    dest_dir = ({

        RMS+"g_room14.c",     "southeast",
        RMS+"g_room6.c",      "north",

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



