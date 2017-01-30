#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Command Area"; 

long_desc =
    " More of the clearing surrounds you in this area, the camp is\n"+
    "mysteriously quiet here except for the occasional chanting and\n"+
    "explosions that can be heard coming from the lone tent that stands\n"+
    "here. The ground is dirt and short scrub grasses, and there is\n"+
    "garbage and debris blowing about. The sun feels warm on your face\n"+
    "as you survey the area.\n";


items = ({

    "tent", 
        "A large well made tent that has seen better days, it probably\n"+
        "started life as a tent in a caravan, chanting can be heard from\n"+
        "within when the breeze blows open the flap",
    "sun",
        "A large blazing ball of fire in the sky, hopefully this isnt\n"+
        "the first time in your life you have stopped to look at the sun\n"+
        "and marvel at its wonderous beauty", 
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

        RMS+"g_room10.c",    "south",
        RMS+"g_room5.c",      "east",
        RMS+"g_tent2.c",     "tent",

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



