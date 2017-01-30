#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/tristian/ansi.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int climb;
int rope;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Goblin Sentry Outpost";
long_desc =
    "You have entered an are where the grass is a little taller and\n"+
    "there is a crude tower built from logs and stones. The main camp\n"+
    "is back the way you came and the forest presses in close in\n"+
    "every other direction.\n";

items = ({
    "pines",
    "Evergreen pines well over 100' tall",
    "forest",  
    "A dazzaling display of light falls down through the tree tops that\n"+
    "tower far above your head",
    "trees",
    "Tall pines, probably been growing since this forest was new",
    "grass",
    "Taller grass, about waist high for you, but it makes a perfect\n"+
    "hiding area for a goblin",
    "tower",
    "A crude tower with a ladder hanging from it",
    "ladder",
    "A rope ladder with wodden rungs, perhaps you can 'climb' it.",
});

if(!present("goblin1",this_object()))
    move_object(
        clone_object("/players/tristian/Goblin/Monsters/goblin_sentry1.c"),
    this_object());
if(!present("goblin2",this_object()))
    move_object(
        clone_object("/players/tristian/Goblin/Monsters/goblin_sentry2.c"),
    this_object());
if(!present("goblin3",this_object()))
    move_object(
        clone_object("/players/tristian/Goblin/Monsters/goblin_sentry1.c"),
    this_object());
if(!present("goblin4",this_object()))
    move_object(
        clone_object("/players/tristian/Goblin/Monsters/goblin_sentry2.c"),
    this_object());

dest_dir = ({
    "/players/tristian/Goblin/Rooms/g_room1.c", "west",
    });
}

init() {
    ::init();
    add_action("climb","climb");
}

climb(str) {
    if(!str) {
    write("Climb what?\n");
    return 1;
        }
    if(str == "rope") {
    write("You climb up into the tower.\n");
    say (this_player()->query_name() +" climbs the rope into the tower.\n");
    move_object(this_player(),"/players/tristian/Goblin/Rooms/tower.c");
    command("look",this_player()); 
    return 1; 
        }
    write("Climb what?\n");
    return 1;
}
