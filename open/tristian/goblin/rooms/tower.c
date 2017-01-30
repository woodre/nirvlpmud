#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";

    reset(arg) {
        if(arg) return;

    set_light(1);

    short_desc = "Goblin Sentry Tower Southwest";
    long_desc =
        " Having climbed into the tower, there is a decent view\n"+
        "of the whole camp from here. You can look in every\n"+
        "major direction.\n";

    items = ({
        
        "down",
            "You see the ground down below, its not very far away by human\n"+
            "standards",
        "d",
            "You see the ground down below, its not very far away by human\n"+
            "standards",
        "u",
            "A blue sky with some whispy white clouds",
        "up",
            "A blue sky with some whispy white clouds",
        "clouds",
            "Big puffy clouds, is that a face in the clouds?",
        "face",
            "It's not really a face, just a puffy white cloud",
        "n",
            "Looking north you see: the whole of the goblin camp,\n"+
            "there is a circle of larger tents and a firepit up\n"+
            "aways and beyond that are more tents and what appear\n"+
            "to be corrals",
        "north",
            "Looking north you see: the whole of the goblin camp,\n"+
            "there is a circle of larger tents and a firepit up\n"+
            "aways and beyond that are more tents and what appear\n"+
            "to be corrals",
        "e",
            "Looking east you see: a clearing and beyond that another tower\n",
        "east",
            "Looking east you see: a clearing and beyond that another tower\n",
        "w",
            "Looking west you see: more of the forest you were in, a very\n"+
            "old forest of pines. The goblins can see any approaching enemy\n"+
            "in that direction from here",
        "west",
            "Looking west you see: more of the forest you were in, a very\n"+
            "old forest of pines. The goblins can see any approaching enemy\n"+
            "in that direction from here",
        "s",
            "Looking south you see: more of the forest, a very old forest\n"+
            "of pines. The goblins can see any approaching enemy in that\n"+
            "direction from here",
        "south",
            "Looking south you see: more of the forest, a very old forest\n"+
            "of pines. The goblins can see any approaching enemy in that\n"+
            "direction from here",            
        "pines",
            "Evergreen pines well over 100' tall",
        "forest",
            "An array of hardwoods and evergreens with a dazzaling display\n"+
            "of light that falls down through the tree tops that tower far above",
        "trees",
            "Tall pines, probably been growing since this forest was new",
        "grass",
            "Taller grass, about waist high for normal humans, but it makes a\n"+
            "perfect hiding area for a goblin",
        "tower",
             "A crude tower that the goblins use to survey the surrounding area",
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
    clone_object(NPC+"goblin_sentry1.c"),
        this_object());


    dest_dir = ({
       RMS+"g_room3.c", "down",

});

}



