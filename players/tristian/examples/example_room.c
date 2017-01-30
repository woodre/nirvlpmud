/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Example Room to help me code
//  Create Date:  2005.06.03
*/

/*defines TP as an efun for this player's name*/
#define TP this_player()
/*defines TPN as the efun that calls the player object and returns thier name*/
#define TPN this_player()->query_name()
/*defines TPP as the efun that returns the he/she/it of the player object calling the function*/
#define TPP this_player()->query_possessive()
/*includes all the definitions of the ansi file located in the directory specified*/
#include "/players/tristian/lib/ansi.h"
/*this line includes all the code from the file specified, in this case room/room..could be armor, weps, etc*/
inherit "room/room";

/*reset is used to set up the inital state of the object*/
reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Encampment"; 

long_desc =
    " The trees thin out into an open clearing. Crude tents dot the landscape,\n"+
    "almost as numerous as the trash and debris that litter the area. Small cook\n"+
    "fires seem haphazardly placed between the tents. The forest looms large\n"+
    "behind you.\n";

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
/*
this line states in english, if this object (goblin) is not present, then move this object (goblin) 
//when its cloned (gives path of object to clone) to this object (the room)
*/
    if(!present("goblin1",this_object()))
        move_object(
            clone_object("/players/tristian/realms/goblin/monsters/goblin_regular.c"),
        this_object());

    if(!present("goblin2",this_object()))
        move_object(
            clone_object("/players/tristian/realms/goblin/monsters/goblin_regular.c"),
        this_object());

    if(!present("goblin3",this_object()))
        move_object(
            clone_object("/players/tristian/realms/goblin/monsters/goblin_regular.c"),
        this_object());
/*
this gives all the paths to the other objects you can goto from this object
*/
    dest_dir = ({

        "/players/tristian/realms/goblin/rooms/g_room5.c",    "south",
        "/players/tristian/realms/goblin/rooms/g_room2.c",     "east",
        "/players/tristian/realms/goblin/rooms/g_room4.c",    "southeast",
        "/players/tristian/realms/goblin/rooms/g_room3.c",     "west",
        "/players/tristian/realms/goblin/rooms/g_room6.c",    "southwest",
        "/room/forest9.c",                          "north",
});
}

/*
//this starts the function calls for this object and add smell, listen and search
*/

      init() {
/*
//::init() includes all the funtion from the inherit room/room above, to not include those..leave this line out
*/
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



