#include "/open/ansi.h"
#define TP this_player()
/*
inherit "/players/vertebraker/closed/std/room";
*/
inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

reset(arg) {
  if(arg) return;

if (!present("jason")) {
  move_object(clone_object("/players/pestilence/club/mob/jason.c"),
        this_object()); }
if (!present("harley")) {
  move_object(clone_object("/players/pestilence/club/mob/harley.c"),
        this_object()); }

short_desc = ""+HIK+"Pervert Row"+NORM+"";
long_desc =
  "    This is just before the stage.  A line of tables follow the\n"+
  "edge of the stage.  This area is also called pervert row.  On one\n"+
  "of the tables there is a purple g-string.  To the northwest, west,\n"+
  "and east are the lap dance rooms, where the customers can get a\n"+
  "private dance with thier favorite stripper.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "tables","A row of tables go along the length of the stage",
  "g-string","A purple g-string with a white stain in the crotch",
  "chairs","A set of chairs at each table, for comfortable viewing pleasure",
  "rooms","Two rooms on the east and west for private dances",
  "dance rooms","Two rooms on the east and west for private dances",
  "lap dance rooms","Two rooms on the east and west for private dances",
  "stage","A wooden stage for the strippers to dance on",
});

dest_dir = ({
"/players/pestilence/club/room/inside.c","south",
"/players/pestilence/club/room/lap2.c","east",
"/players/pestilence/club/room/lap1.c","west",
"/players/pestilence/club/room/lap3.c","northeast",
"/players/pestilence/club/room/stage.c","north",
});

}

init() {
  ::init();
add_action("stop","quit");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
