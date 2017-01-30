inherit "room/room";
#include "definitions.h"

int check;

init() {
add_action("search","search");
::init();
}

reset(arg) {

        check=0;
        if(!present("sithi")) {
          move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),this_object());
          }

        if(!arg) {
        check=0;
        set_light(1);
        short_desc="Main hall, northern end";
        long_desc=
"     You stand in the middle of the main hall.  A small desk lies off\n"+
"to the side of the room.  The torches in the hall are arranged in\n"+
"a fiery pattern about three horns written in blood.  A gruesome\n"+
"sight indeed.\n";

   dest_dir=({
        CASTLEROOM+"/room1.c","south"  ,
        CASTLEROOM+"/dining.c","west"  ,
        CASTLEROOM+"/fountain.c","north"  ,
            });

   items=({
        "desk",
"     The desk is made of rosewood.  The sharp red color seems normal\n"+
"for rosewood at first, but you notice many bloodstains upon the desk\n"+
"as well.  Perhaps a closer look will reveal something",
   });
   }   }

search(str) {
        if (!str) {
                write("What do you search?\n");
                return 1;}
if (str == "bloodstains") {
                write(
"     The bloodstains permanently stain the rosewood.  Off in the\n"+
"corner of the desk, you see the words:\n"+
"\n"+
"        In depths of darkness, dost he dwell;\n"+
"        With might and power, he will sell;\n"+
"        We strive for him, our lord and father;\n"+
"        By blood and sacrifice, Kilrthwech Demosater.....\n");
                return 1;}
        if (str == "desk") {
          if (check==0) {
            move_object(clone_object(CASTLEOBJECT+"/knife.c"),this_object());
            write("You find a nice weapon!\n");
            }
          if (check==1) {
            write("The desk has already been rummaged through.\n");
            }
          check=1;
          return 1;}
}

