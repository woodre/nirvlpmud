#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";

    reset(arg) {
        if(arg) return;

    set_light(1);

    short_desc = "Goblin Sentry Tower Northwest";
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
            "Big puffy clouds, you think you see a bunny shape",
        "bunny",
            "It's not really a bunny, just a puffy white cloud",
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
        "w",
            "Looking west, back the way you came, you see the corrals\n"+
            "and beyond that another tower",
        "west",
            "Looking west, back the way you came, you see the corrals\n"+
            "and beyond that another tower",
        "e",
            "Looking east there can be seen more of the forest, a very\n"+
            "old forest of pines. The goblins can see any approaching\n"+
            "enemy in that direction from here",
        "east",
            "Looking east there can be seen more of the forest, a very\n"+
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
            clone_object(NPC+"goblin_sentry1.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
        this_object());
 
    if(!present("goblin3",this_object()))
        move_object(
            clone_object(NPC+"goblin_sentry2.c"),
        this_object());


    dest_dir = ({
        RMS+"g_room15.c", "down",
    });
}



