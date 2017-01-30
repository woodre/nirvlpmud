/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

static int gate;

reset(arg) {
     if(arg) return;
     set_light(1);

     gate = 0;

     short_desc = "Apophis's Gateroom";
     long_desc =
"    .\n";

     items = ({
     "stargate","The stargate is a huge flat ring with symbols all around it.\n\
You can see right through it, it must be closed",
     "walls","If you're starring at the walls you're looking the wrong direction",
     "room","The command room looks out over this room but there's no way in from here",
     "ramp","The wide ramp is firmly affixed to the platform",
     "platform","It solidly supports the immense stargate",
     "symbols","You cannot decipher there meaning",
});

     dest_dir = ({
     ROOM+"annex.c", "east",
     });
}

init(){
     ::init();

     add_action("enter_gate", "enter");
}

enter_gate(str){
     string gateroom;

     gateroom = ROOM + "gate2.c";

     if(!str || str==""){
        notify_fail("What do you want to enter?\n");
        return 0;
     }
     if(str=="stargate" || str=="gate"){
        if(query_gate()){
           this_player()->move_player( "through the gate#" + gateroom);
           return 1;
        }else{
           write("You jump through the gate but nothing happens!\n");
           say(capitalize(this_player()->query_name())+"leaps through the gate and lands on the other side.\n");
           return 1;
        }
     }
     notify_fail("Are you trying to enter the stargate?\n");
     return 1;
}

query_gate(){ return gate; }

set_gate(){
     if(gate){
        gate=0;
        items[1]="The stargate is a huge flat ring with symbols all around it.\n\
You can see right through it, it must be closed";
     } else {
        gate =1;
        items[1]="The stargate is a huge flat ring with symbols all around it.\n\
The center looks liquid, like a blue pool standing on edge";
     }
}

