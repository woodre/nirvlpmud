/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

static int gate, door;

reset(arg) {
     if(arg) return;
     set_light(1);

     gate = 0; door = 0;

     short_desc = "The Gateroom";
     long_desc =
"    Metal walls and a huge steel door show the desire for security\n\
here.  From above, a shielded command room looks over the entire area.\n\
In the center of the room a big metal ramp leads up to a platform that\n\
holds the object that dominates the room...  The Stargate.\n";

     items = ({
     "stargate","The stargate is a huge flat ring with symbols all around it.\n\
You can see right through it, it must be closed",
     "door","The massive structure looks like it belongs on\n\
a bank vault.  There is no visible means to open it however",
     "walls","If you're starring at the walls you're looking the wrong direction",
     "room","The command room looks out over this room but there's no way in from here",
     "ramp","The wide ramp is firmly affixed to the platform",
     "platform","It solidly supports the immense stargate",
     "symbols","You cannot decipher there meaning",
});

     dest_dir = ({});
}

init(){
     ::init();

     add_action("enter_gate", "enter");
     add_action("go_west","west");
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
go_west(){
     string hall;

     hall = ROOM + "hall4.c";

     if(query_door()){
        this_player()->move_player( "through the door#" + hall);
        return 1;
     }else{
        write("The door is closed tight, there seems to be no way to open it!\n");
        say(capitalize(this_player()->query_name())+"tries in vain to open the huge door.\n");
        return 1;
     }

     return 1;
}

query_gate(){ return gate; }
query_door(){ return door; }

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
set_door(){
     if(door) {
        door=0;
        items[3]="The massive structure looks like it belongs on\n\
a bank vault.  There is no visible means to open it however";
     } else {
        door=1;
        items[3]="The massive structure looks like it belongs on\n\
a bank vault.  Fortunatly for you, it's open";
     }
}

