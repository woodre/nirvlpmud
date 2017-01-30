#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Corrals"; 

long_desc =
    " The camp is bare here, a large corral dominates this area of\n"+
    "the clearing. Some tents stand over by the corral these tents\n"+
    "are slightly larger the rest in the camp. The ground is bare; even\n"+
    "the ever present garbage seems absent. Some water troughs stand over\n"+
    "by the corral and a half eaten carcass can be seen in the middle.\n";

items = ({

    "tents", 
        "Crude tents made from some unknown tanned material",
    "corral",
        "A low corral made from small logs and brush, but goblins don't\n"+
        "ride horses, do they?",
    "logs",
        "Small pines set in a tight circle, forming a corral",
    "brush",
        "Sticks and other brush used to fill the spaces in the logs of the corral",
    "troughs", 
        "Wooden watering troughs for whatever is kept in the corrals",
    "water toughs",
        "Wooden watering troughs for whatever is kept in the corrals",
    "carcass",
        "A grisly torn up carcass of some undiscernable creature",
    "ground",
        "Dirt and stones",
    "dirt",
        "Ordinary run of the mill dirt",

});

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_rider.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_rider.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_rider.c"),
        this_object());


    dest_dir = ({

        RMS+"g_room10.c",    "west",
        RMS+"g_room8.c",      "east",

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



