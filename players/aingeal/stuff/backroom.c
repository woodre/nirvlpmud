#define tp this_player()->query_name()
#include "/players/humble/area1/defs.h"
inherit "room/room";
int i;
reset(int arg){
if(!present("banshee")) {
move_object(clone_object("open/aingeal/banshee.c"),this_object());}
 if(!arg){
  set_light(1);
short_desc=CYN+"Backroom"+NORM;
long_desc=
"This is the backroom. There are large rafter with dozens of\n"+
"pallets stacked on top of them.  There is a forklift back here\n"+
"along with numerous carts containing random items.\n"+
"You spot in the corner a desk equipped with a computer\n"+
"and a printer. There is a large door that looks like it could\n"+
"be opened. THere is also a set of doors nearby the desk.\n";

items =
  ({
"desk","This is the desk that holds the printer and computer which tracks orders and invoices",
"printer","This is used to print invoices and orders",
"computer","This is Debbie's computer, I wouldn't touch it if I were you",
"doors","This is a set of doors, perhaps you could enter the "+BLU+"Dairy Cooler"+NORM+" from here",
"door","This is a large grey door with a huge handle on it, maybe you could open it",
 });
dest_dir=
    ({
    RPATH+"aisle12",        "out",
    });
  }
}
init(){
 ::init();
    add_action("enter_cooler","enter_cooler");
    add_action("enter_dairy","enter_dairy");
}

enter_cooler(){
if(present("banshee")){
write("Debbie rushes over and shoves you to the ground.\n");
write("Debbies screams: STAY OUT OF MY DAIRY COOLER!\n");
say("Debbie rushes over and shoves "+tp+" to the ground.\n");
say("Debbie screams; STAY OUT OF MY DAIRY COOLER!\n");
return 1; }
call_other(this_player(),"move_player","enter_cooler#players/humble/area1/rooms/backroom.c");
say(tp+" pushes his way into the dairy cooler.\n");
return 1; }
