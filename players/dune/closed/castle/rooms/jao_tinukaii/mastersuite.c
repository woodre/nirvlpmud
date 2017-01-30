inherit "room/room";
#include "definitions.h"

init() {
add_action("search","search");
add_action("goplace","south");
add_action("goplace","s");
::init();
}

reset(arg) {

   if (!present("sithi"))
     move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
   if (!present("nymfotrites"))
     move_object(clone_object(CASTLEMONSTER+"/devil_lessern.c"),this_object());

        if(!arg) {
        set_light(1);
        short_desc="Master suite";
        long_desc=
"     The walls here are draped with green silken cloth.  A green\n"+
"fluffy rug lies underneath.  However, the only furniture in this\n"+
"room is a mattress made of leaves.  The room is fairly bright.\n"+
"As you look up, you see a glowing orb high up on the ceiling.\n"+
"No torches light this room.  You sense that whoever lives in\n"+
"this room thinks very differently from the rest of the people\n"+
"in this temple, save but for one other person.\n";

   dest_dir=({
        CASTLEROOM+"/upnorth.c","west"  ,
            });

   items=({
        "mattress","     The mattress is 6 inches of dry leaves",
        "orb","     The orb lights the room well, with no fuel",
        "cloth","     You look at the cloth, and get curious",
   });
   }   }

goplace() {
   say(TPN+" leaves into the drapes.\n");
   write("You find a secret passage behind the drapes.\n");
   move_object(TP, CASTLEROOM+"/sidesuite.c");
   return 1;
}

search(str) {
        if (!str) {
           write("What do you search?\n");
           return 1;}
        if (str == "cloth") {
           write("The cloth hides a secret exit to the south.\n");
return 1;}
}
