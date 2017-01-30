#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Command Area"; 

long_desc =
    " The center of the camp looms about. The ground has been beaten\n"+
    "down so that only dirt remains. Vegetation is sparse in this area, almost\n"+
    "nonexistant. The largest tent in the camp stands directly ahead and\n"+
    "a huge firepit sits just off to the side. Muffled sounds can be heard when\n"+
    "the afternoon breeze blows open the front flap of the tent.\n";

items = ({

    "tent", 
        "Better made tents than the previous ones, you suspect they were\n"+
        "pillaged from some unlucky caravan",
    "flap",
        "The part of the tent that covers the opening",
    "evergreen", 
        "Trees far off in every direction",
    "ground",
        "Hard packed dirt with little vegetation",
    "forest",
        "An array of hardwoods and evergreens with a dazzaling display\n"+
        "of light that falls down through the tree tops that tower far above",
    "firepit",
        "You see some bones, and a humanoid skull of some unknown creature",
    "bones",
        "The leg bone and part of a ribcage from some creature that you can't discern\n",
    "ribcage",
        "The left half of a ribcage, 1...2...3...4 ribs left, you notice that all the\n"+
        "bone marrow has been sucked from each one\n",
    "skull",
        "A bleached white skull, it has apparently been left in the sun for\n"+
        "quite some time",    
    "trees",
        "Trees far off in every direction", 
    "clearing",
        "An open area of the woods, mostly beaten down grass and dirt",
    "grass",
        "Beaten down grass, mostly dead and sparrodic at best",
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
            clone_object(NPC+"goblin_sentry1.c"),
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

        RMS+"g_room1.c",    "north",
        RMS+"g_room7.c",     "east",
        RMS+"g_room11.c",   "west",
        RMS+"g_tent.c",      "tent",

});

}

   init()   {
       ::init();
           add_action("trist_tent","tent");
           add_action("Smell","smell");
           add_action("Search","search");
           add_action("Listen","listen");
}

    trist_tent() {
        if(present("goblin_sentry")) {
            write("The goblin sentries prevent you from entering the tent.\n");
        return 1; }
    return 0;
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
