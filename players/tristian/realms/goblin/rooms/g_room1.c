#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Encampment"; 

long_desc =
    " The trees thin out into an open clearing. Crude tents dot the\n"+
    "landscape, almost as numerous as the trash and debris that litter\n"+
    "the area. Small cookfires seem haphazardly placed between the\n"+
    "tents. The forest looms large behind you.\n";

items = ({

    "tents", 
        "Crude tents that leak at the seams, made from some\n"+
        "unknown tanned material",
    "material",
        "Tanned hides, possibly human mixed with other animals",
    "fires",
        "Small fires surrounded by stones used for the day to day cooking",
    "cook fires",
        "Small fires surrounded by stones used for the day to day cooking",
    "stones",
        "Round stones about the size of your fist used to contain the cook fires",
    "paintings",
        "Crude stick figure paintings depicting battles and pillaging",
    "pines", 
        "Evergreen pines well over 100' tall",
    "forest",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
    "trees",
        "Tall pines, that have probably been growing since this forest was new", 
    "clearing",
        "An open area of the woods, mostly beaten down grass and dirt with tents strewn around",
    "grass",
        "Beaten down grass, mostly dead and sporadic at best",
    "dirt", 
        "Dirt. Plain old ordinary dirt",
    "trash",
        "Common debris and garbage, made up of half eaten meals, broken arrows, and other broken equipment",
    "debris",
        "Common trash and garbage, made up of half eaten meals, broken arrows, and other broken equipment",
    "garbage", 
        "GARBAGE - you know GARBAGE!",
    "arrows",
        "Broken arrows, they are of no use to you",
    "equipment",
        "Smelly equipment that is broken and torn, it is of no use to you and has no value",

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

        RMS+"g_room5.c",    "south",
        RMS+"g_room2.c",     "east",
        RMS+"g_room4.c",    "southeast",
        RMS+"g_room3.c",     "west",
        RMS+"g_room6.c",    "southwest",
        "/room/forest9.c",                          "north",

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



