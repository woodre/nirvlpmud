/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "A Wide Hallway";
     long_desc =
"    This is the southern end of the wide hallway.  In\n\
the east wall a HUGE circular door stands over twelve feet\n\
tall.\n";

     items = ({
     "door","The massive structure looks like it belongs on\n\
a bank vault.  There is no visible means to open it however",
     });

     dest_dir = ({
     ROOM + "hall3.c","north",
});

}

init(){
     ::init();

     add_action("go_east","east");
}

go_east(){
     string gateroom;

     gateroom = ROOM + "gate.c";

     if(gateroom->query_door()){
        this_player()->move_player( "through the door#" + gateroom);
        return 1;
     }else{
        write("The door is closed tight, there seems to be no way to open it!\n");
        say(capitalize(this_player()->query_name())+"tries in vain to open the huge door.\n");
        return 1;
     }
     return 1;
}
set_door(str){
     if(!str || str==""){ return; }
     if(str=="open"){
        items[1]="The massive structure looks like it belongs on\n\
a bank vault.  Fortunatly for you, it's open";
     }
     if(str=="close"){
        items[1]="The massive structure looks like it belongs on\n\
a bank vault.  There is no visible means to open it however";
     }
     return;
}

