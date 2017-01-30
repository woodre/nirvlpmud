#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";
int climb;
int rope;

    reset(arg) {
     if(arg) return;
    set_light(1);

    short_desc = "Goblin Sentry Outpost";

    long_desc =
        " This area is almost fully forested. Still, grass and moss grow\n"+
        "on the ground. Stacks of logs show that the clearing of this area\n"+
        "proceeds at an amazing rate. A crude tower built from logs and \n"+
        "stones stands over to the east. The main camp is back the other\n"+
        "direction and the forest presses in close in every other direction.\n";

    items = ({

        "pines",
            "Evergreen pines well over 100' tall",
        "forest",
            "An array of hardwoods and evergreens with a dazzaling display\n"+
            "of light that falls down through the tree tops that tower far above",  
        "trees",
            "Tall pines, probably been growing since this forest was new",
        "grass",
            "Taller grass, about waist high for normal people, but it makes a\n"+
            "perfect hiding area for a goblin",
        "logs",
            "Freshly cut logs stacked in neat piles, waiting to be used to\n"+
            "fortify the area",
        "moss",
            "Green fuzzy moss, growing on the north side of trees and rocks",
        "rocks",
            "Small rocks with fuzzy green moss growing on them",
        "tower",
            "A crude tower with a rope ladder hanging from it",
        "ladder",
            "A rope ladder with wooden rungs, perhaps you can 'climb' the 'rope'",
        "rope",
            "A rope ladder with wooden rungs, perhaps you can 'climb' the 'rope'",
    });

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry1.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry1.c"),
        this_object());


    dest_dir = ({

        RMS+"g_room14.c",    "east",

    });
}

    init() {
        ::init();
           add_action("climb","climb");
           add_action("Smell","smell");
           add_action("Search","search");
           add_action("Listen","listen");
        }

    climb(str) {
        if(!str) {
            write("Climb what?\n");
        return 1;
        }

    if(str == "rope") {
        write("You climb up into the tower.\n");
        say (this_player()->query_name() +" climbs the rope into the tower.\n");
    move_object(this_player(),"/players/tristian/realms/goblin/rooms/tower3.c");
    command("look",this_player()); 
        return 1; 
            }

    write("Climb what?\n");
        return 1;

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

