#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/tristian/lib/ansi.h"
#define TPP this_player()->query_possessive()
inherit "room/room";


reset(arg) {

  if(arg) return;

set_light(1);

short_desc = "Artic Tundra"; 

long_desc =
    " XXXXXXXXXXXXXXXXXXXXXXXXXX\n";

items = ({

    "lights",
        "Strange lights that dance across the darkened sky off to the north",
    "northern lights",
        "Strange lights that dance across the darkened sky off to the north",
    "snow",
        "White, Wet, COLD!",

});


 dest_dir = ({

        "/players/tristian/realms/town/rooms/pretown1.c",     "up",


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
            write("The freezing cold air carries no smell that you can discern.\n");
    return 1;
}
    return 1;
}

  Search() {
        write("Digging thru the snow makes your hands cold but, you find nothing special.\n");
    return 1;
}

  Listen() {
        write("You hear the howl of the fierce blowing wind and not much else.\n");
    return 1;
}

