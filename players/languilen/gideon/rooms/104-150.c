#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
   if(arg) return;
   set_light(1);

   short_desc = "Grand Ave";
   long_desc =
"    The door to the magic carpet rental office is just north of.\n\
here.  The entrance to the creche is further south and just ahead\n\
on the other side of the street is the entrance to a large mall.\n";

   items = ({
      "street","the dirt is packed hard from generations of traffic",
});

   dest_dir = ({
        AREA+"105-150.c","north",
        AREA+"103-150.c","south",
});

}
init(){
    ::init();
    add_action("read_sign","read");
}
read_sign(str){
     if(!str || str != "sign"){
        notify_fail("Are you trying to 'read' the 'sign'?\n");
        return 0;
     }
     write("\n     MAGIC CARPET RENTALS!"+
"     Entrance \n"+
" /_________________\n"+
" \\                     \n");
     return 1;
}

