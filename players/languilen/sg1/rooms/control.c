/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
#define GATEROOM ROOM + "gate.c"
#define HALL ROOM+"hall4.c"
#define GATE call_other(GATEROOM, "query_gate")
#define DOOR call_other(GATEROOM, "query_door")

inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Control Center";
     long_desc =
"    Along one wall of this small room a long window \n\
looks out over another room.  Below the window rests a\n\
long metal counter containing a lever and two buttons,\n\
one above the other.\n";

     items = ({
     "window","In the next room you can see the stargate\n\
and the door, both closed",
     "lever","You could pull it, or push it",
     "button","Press the top or the bottom one",
     });

     dest_dir = ({
     ROOM + "hall3.c","west",
});

}

init(){
     ::init();

     add_action("pull_lever","pull");   /* turns it on 1  */
     add_action("push_lever","push");   /* turns it off 0  */
     add_action("press_button","press");
}

pull_lever(str){
     string gateroom;
     gateroom = GATEROOM;

     if(!str || str==""){
        notify_fail("Pull what?");
        return 0;
     }
     if(str!="lever"){
        notify_fail("Are you trying to pull the lever?\n");
        return 0;
     }
     if(GATE){
        write("The lever is already pulled!\n");
        say(capitalize(TPN)+" pulls the lever but it dosen't move.\n", TP);
        return 1;
     }
     if(DOOR){
        write("The lever won't move for some reason.\n");
        say(capitalize(TPN)+" tries to pull the lever but can't!\n", TP);
        return 1;
     }
     write("You pull the lever toword you all the way.\n");
     say(capitalize(TPN)+" pulls on the lever.\n", TP);
     tell_room(this_object(), "Through the glass you see the stargate open!\n");
     gateroom->set_gate();
     tell_room(gateroom, "The stargate opens!\n");
     items[1]="In the next room you see that the door is closed but the\n\
stargate appears active";
     return 1;
}
push_lever(str){
     string gateroom;

     gateroom = GATEROOM;

     if(!str || str==""){
        notify_fail("Push what?");
        return 0;
     }
     if(str!="lever"){
        notify_fail("Are you trying to push the lever?\n");
        return 0;
     }
     if(!GATE){
        write("The lever is already pushed!\n");
        say(capitalize(TPN)+" pushes the lever but it dosen't move.\n", TP);
        return 1;
     }
     write("You push the lever away from you all the way.\n");
     say(capitalize(TPN)+" pushes on the lever.\n", TP);
     tell_room(this_object(), "Through the glass you see the stargate close!\n");
     gateroom->set_gate();
     tell_room(gateroom, "The stargate closes!\n");
     if(DOOR){ items[1]="In the next room you see that the door is open but the\n\
stargate appears inactive";
     } else { items[1]="Through the window you can see the stargate and the door,\n\
both of them closed";
     }
     return 1;

}
press_button(str){            /* top opens the door, bottom closes it  */
     string gateroom;
     gateroom = GATEROOM;

     if(!str || str==""){
        notify_fail("Press what?");
        return 0;
     }
     if(str=="button"){
        notify_fail("Do you want to press the top or the bottom button?\n");
        return 0;
     }
     if(str=="top" || str=="top button"){
        if(GATE || DOOR){
           write("You press the top button but nothing happens.\n");
           say(capitalize(TPN)+" presses the top button but nothing happens.\n", TP);
           return 1;
        }
        write("You press the top button.\n");
        say(capitalize(TPN)+" presses a button.\n", TP);
        gateroom->set_door();
        call_other(HALL,"set_door","open");
        tell_room(this_object(),"Through the glass you can see the door open!\n");
        if(!GATE){ items[1]="In the next room you see that the door is open but the\n\
stargate appears inactive";
        }
        return 1;
     }
     if(str=="bottom" || str=="bottom button"){
        if(!DOOR){
           write("You press the bottom button but nothing happens.\n");
           say(capitalize(TPN)+" presses the bottom button but nothing happens.\n", TP);
           return 1;
        }
        if(DOOR){
           write("You press the bottom button.\n");
           say(capitalize(TPN)+" presses a button!\n");
           gateroom->set_door();
           call_other(HALL,"set_door","close");
           tell_room(this_object(), "Through the glass you can see the door swing closed!\n");
           if(GATE){ items[1]="In the next room you see that the door is closed but the\n\
stargate appears active";
           } else { items[1]="Through the window you can see the stargate and the door,\n\
both of them closed";
           }
           return 1;
        }
     }
     notify_fail("There's no "+str+" here to press.\n");
     return 0;
}

