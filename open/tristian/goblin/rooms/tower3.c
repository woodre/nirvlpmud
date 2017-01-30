#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";

    reset(arg) {
        if(arg) return;

    set_light(1);

    short_desc = "Goblin Sentry Tower Northeast";
    long_desc =
        " Having climbed into the tower, there is a decent view\n"+
        "of the whole camp from here. You can look in every\n"+
        "major direction.\n";

    items = ({
        "down",
            "You see the ground down below you, its not very far away by\n"+
            "your standards",
        "d",
            "You see the ground down below you, its not very far away by\n"+
            "your standards",
        "u",
            "A blue sky with some whispy white clouds",
        "up",
            "A blue sky with some whispy white clouds",
        "clouds",
            "Big puffy clouds, you think you see an alligator shape",
        "alligator",
            "It's not really an alligator, just a puffy white cloud",
        "s",
            "Looking south there can be seen the whole of the goblin\n"+
            "camp, there is the corrals and beyond that a circle of\n"+
            "larger tents and a fire pit farther south are more tents\n"+
            "and the trash heap",
        "south",
            "Looking south there can be seen the whole of the goblin\n"+
            "camp, there is the corrals and beyond that a circle of\n"+
            "larger tents and a fire pit farther south are more tents\n"+
            "and the trash heap",
        "e",
            "Looking east, back the way you came, there can be seen the\n"+
            "corals and beyond that another tower",
        "east",
            "Looking east, back the way you came, there can be seen the\n"+
            "corals and beyond that another tower",
        "w",
            "Looking west there can be seen more of the forest, a very\n"+
            "old forest of pines. The goblins can see any approaching\n"+
            "enemy in that direction from here",
        "west",
            "Looking west there can be seen more of the forest, a very\n"+
            "old forest of pines. The goblins can see any approaching\n"+
            "enemy in that direction from here",
        "n",
            "Looking north there can be seen more of the forest, a very \n"+
            "old forest of pines. The goblins can see any approaching enemy\n"+
            "in that direction from here",
        "north",
            "Looking north there can be seen more of the forest, a very \n"+
            "old forest of pines. The goblins can see any approaching enemy\n"+
            "in that direction from here",            
        "pines",
            "Evergreen pines well over 100' tall",
        "forest",
            "An array of hardwoods and evergreens with a dazzaling display\n"+
            "of light that falls down through the tree tops that tower far above",
        "trees",
            "Tall pines, probably been growing since this forest was new",
        "grass",
            "Taller grass, about waist high for you, but it makes a perfect hiding\n"+
            "area for a goblin",
        "tower",
             "A crude tower that the goblins use to survey the surrounding area",

    });

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry1.c"),
        this_object());
 
    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
        this_object());

    dest_dir = ({
        RMS+"g_room16.c", "down",
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
            write("The smells of damp wood and dirty goblin's wafts through the air.\n");
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



