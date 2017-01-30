#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Command Area"; 

long_desc =
    " The clearing in this area is almost completely barren, dirt and\n"+
    "trash cover the majority of the free space. The only noteworthy\n"+
    "thing is the tent directly in the middle. Strangely enough, nothing\n"+
    "seems to be within fifty feet of the tent. Strange chanting can be\n"+
    "heard coming from the tent when the afternoon breezes blow the flap aside.\n";

items = ({

    "tent", 
        "A larger tent than the rest with strange symbols of lightning\n"+
        "bolts and clouds painted on the sides",
    "flap",
        "The piece of the tent that comes over the opening sealing it\n"+
        "from the elements",
    "symbols",
        "Crude paintings of lightning bolts and clouds",
    "lightning bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "lightning",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "clouds",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "cloud",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "pines", 
        "Evergreen pines well over 100' tall",
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
        "Debris and garbage",
    "debris",
        "Trash and garbage",
    "garbage", 
        "GARBAGE - you know GARBAGE!",

});

    if(!present("goblin1",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
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

        RMS+"g_room8.c",    "south",
        RMS+"g_room5.c",      "west",
        RMS+"g_tent1.c",      "tent",

});

}

    init()   {
        ::init();
            add_action("trist_tent","tent");
            add_action("Smell","smell");
            add_action("Search","search");
            add_action("Listen","listen");
}

   trist_tent()   {
        if(present("goblin")) {
            write("The goblin sentries prevent you from entering the tent.\n");
        return 1; }
    return 0;
}

  Smell(str) {
        if(!str || str == "air") {
            write("The smells of wood smoke and dirty goblins waft through the air.\n");
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



