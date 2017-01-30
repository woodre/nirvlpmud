inherit "room/room";
#include "definitions.h"

int table;
int h;

init() {
add_action("search","search");
::init();
}

reset(arg) {

     table=0;
     if(!present("sithi")) {
       for(h=1;h<=3;h++)
       move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),this_object());
     if (!present("knight"))
     move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());
     }

        if(!arg) {
        table=0;
        set_light(1);
        short_desc="Deck";
        long_desc=
"     The stairs lead to an open area on the roof of the temple.\n"+
"Broken building walls lie around you.  The roof is gone, and above\n"+
"you stands tall sagging trees.  As you look around the room, you see\n"+
"A wooden table with several finely carved wooden chairs around it.\n"+
"You sense this must be a meeting place of some sort.\n"+
"Down along the side of the stone wall, several vines stretch across\n"+
"to create a possible way to scale down the wall.  But, you cannot\n"+
"see through the vegetation as to where it leads.\n";

   dest_dir=({
        CASTLEROOM+"/spiral_stairs.c","down"  ,
            });

   items=({
        "trees","     The trees are thick and soft-barked",
        "chairs","     The chairs are made of dark red wood",
        "table",
"     The oak table stands thick and sturdy.  You see a little piece of\n"+
"leather sticking out from underneath",
   });
   }   }


search(str) {
   if(!str) {
        write("What do you search?\n");
        return 1;}
   if(str == "table") {
     if (table==0) {
     write(
     "You feel a leather strap, pull it, and something falls to the ground.\n");
     move_object(clone_object(CASTLEOBJECT+"/potion.c"),this_object());
     table=1;}
     else {
     write("A leather strap lies unbuttoned under the table.\n");
     }
     return 1;}
}
