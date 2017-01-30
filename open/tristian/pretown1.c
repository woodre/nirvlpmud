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
    " Trudging across the snowy plain, the snow blowing so hard that visability is\n"+
    "restricted to about 6 inches in any direction.  All across the horizon the northern \n"+
    "lights give you a faint hope of going in the right direction.\n";

items = ({

    "lights",
        "Strange lights that dance across the darkened sky off to the north",
    "northern lights",
        "Strange lights that dance across the darkened sky off to the north",
    "snow",
        "White, Wet, COLD!",

});


 dest_dir = ({

        "/players/tristian/realms/town/rooms/pretown2.c",     "north",
        "/players/tristian/castle.c",                        "south",


});

}

      exit()  {
        int x;
          x = TP->query_attrib("dex");
     
        if(x + random(100) > 40) {

              write("The ground gives way and you fall through the ice into a cave below.\n");
                 say(TPN +"falls through the ice into what looks like a cave below.\n");

              move_object(this_player(),"/players/tristian/realms/town/rooms/pretown4.c");
                 command("look",this_player());
}}  
        

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

