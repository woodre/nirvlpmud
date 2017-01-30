#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
  "  "+BLK+BOLD+"A flat landing at the end of the pyramid.  The view\n"+
  "of the pyramid is very imposing from here, a large\n"+
  "stairway can be seen to the west, an archway, massive\n"+
  "and overwhelming has been built on the end of this room.\n"+
  "Looming columns on the east, rise flush to the ceiling.\n"+NORM+"";

items = ({
  "landing","A large flat, overseeing most of the pyramid",
  "pyramid","A large structure made from clay stone",
  "columns","Thick columns of stacked clay cylinder blocks",
  "stairway","A stairway can be seen down to the west",
  "archway","A large archway, with inscriptions across the top",
  "ceiling","A large flat ceiling high overhead",
  "inscriptions","Beyond, the darkness prevails over the light.\nThrough the archway, slave to the night.\nThe mouth of madness consumes the meek.\nThe strong will prevail, pray for the weak",
});

MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/roome3.c","east",
  "/players/jaraxle/3rd/pyramid/rooms/room2.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","southwest",
  "/players/jaraxle/3rd/pyramid/rooms/roome2.c","southeast",
});
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("enter","enter");
}

enter(arg){
if(arg == "archway"){

if(TP->query_level() < 16){
  write("An invisible field blocks your entrance to the archway.\n");
return 1; }
write("You bravely enter the archway.\n");                       
say(TPN+" bravely enters the archway.\n");move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/archway.c");  
command("look", this_player());
say(TPN+" enters through the archway.\n");
return 1; }
write("Enter where?\n");
return 1;   /* Rumplemintz - 10/24/07 */
}
