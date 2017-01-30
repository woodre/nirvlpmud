#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "An Access Road";
long_desc =
"    The road is not too wide but there is space enough for a small\n\
vehicle.  A steel door mounted in the front of the warehouse impedes\n\
progress east.  To the north the bazaar awaits but the entrance is\n\
to the west.  The towering gate house rising from the southwest is an\n\
unmistakable landmark.\n";

items = ({
  "road","A small access road, deeply rutted by many caravans filled with goods",
  "door","The heavy steel door is big enough for a small transport",
  "warehouse","this building stores goods coming into the city for consumption or sale\n\
at the bazaar",
});

dest_dir = ({
        AREA+"101-150.c","west",
        AREA+"101-152.c","east",
});

}

init(){
     ::init();
     add_action("opendoor","open");
     add_action("east","east");
}

opendoor(string str){
     if(!str || str != "door"){
        notify_fail("Are you trying to 'open' the 'door'?\n");
        return 0;
     }
     write("The door is locked up tight, apparently from inside.\n");
     return 1;
}
east(){
     write("The heavy steel door of the warehouse prevents you from going that way.\n");
     say(TPN+" tries to go east but is stopped by the closed warehouse door.\n");
     return 1;
}

