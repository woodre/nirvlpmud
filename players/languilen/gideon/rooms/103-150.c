#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
#define FUNHOUSE "/players/languilen/areas/city/funhouse/rooms/inside.c"
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Grand Ave at the Creche";
     long_desc =
"    Just west is the creche, it's a place for the newborns of the city to\n\
grow a little in thier own way.  They won't let you in there if your too\n\
old.  A huge gatehouse can be seen some distance south of here.\n";

     items = ({
     "creche","It looks like a blast inside",
     "gatehouse","The immense structure can bee seen even from here",
});

     dest_dir = ({
     AREA+"104-150.c","north",
     AREA+"102-150.c","south",
     AREA+"103-149.c","west",
});

}
init(){
     ::init();
     add_action("west","west");
}
west(){
     if( this_player()->query_level()>5 ){
        write("You're too big to go in there!\n");
        return 1;
     }
}

