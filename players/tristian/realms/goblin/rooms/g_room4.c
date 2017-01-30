#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Encampment"; 

long_desc =
    " The clearing continues to stretch in front of you. More tents and\n"+
    "trash litter the landscape in equal numbers. Sparse grass covers the area,\n"+
    "and far overhead there is a bird circling amongst the sporadic clouds.\n";

items = ({

    "tents", 
        "Crude tents that leak at the seams, made from some\n"+
        "unknown tanned material",
    "material",
        "If you had to guess you would think this was tanned human hides\n"+
        "sewn together with other animal hides intermixed",
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
    "bird",
	  "A large black bird, maybe a vulture?",
    "clouds",
       "White puffy clouds, does that one look like an alligator?",
    "alligator",
       "A puffy cloud, nothing more, it was your imagination that made it look like an alligator",
    "forest",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
    "trees",
        "Tall pines, probably been growing since this forest was new.", 
    "clearing",
        "An open area of the woods, mostly beaten down grass and dirt",
    "grass",
        "Beaten down grass, mostly dead and sparrodic at best",
    "dirt", 
        "Dirt. Plain old ordinary dirt",
    "trash",
        "Common debris and garbage, made up of half eaten meals, broken arrows, and other broken equipment",
    "debris",
        "Common trash and garbage, made up of half eaten meals, broken arrows, and other broken equipment",
    "garbage", 
        "GARBAGE - you know GARBAGE!",
    "arrows",
        "Broken arrows, they are of no use to anyone",
    "equipment",
        "Smelly equipment that is broken and torn, it is of no use to anyone and has no value",
    "tumbleweeds",
        "Like tumbleweeds, but it is just garbage",

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

        RMS+"g_room13.c",    "south",
        RMS+"g_room1.c",     "northwest",

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



