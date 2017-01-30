#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("destinee")) {
  move_object(clone_object("/players/pestilence/club/mob/destinee.c"),
        this_object()); }
if (!present("bambi")) {
  move_object(clone_object("/players/pestilence/club/mob/bambi.c"),
        this_object()); }
short_desc = ""+HIK+"Stripper's Stage"+NORM+"";
long_desc =
  "    This is a large stage where the strippers dance and remove\n"+
  "thier clothing.  The floor is a hardwood floor with a steel pole\n"+
  "going from the floor to the ceiling.  There is a small beer bottle\n"+
  "on the edge of the stage, that was used during the last dance.  At\n"+
  "the northern part of the stage is the entrance to the backstage area.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "bottle","An old Labatt's Blue bottle, you don't even want to think about how it was used",
  "pole","A steel pole used by strippers to flip upside down to show the money shot",
  "stage","A wooden stage for the strippers to dance on",
  "floor","A Hardwood floor",
  "ceiling","A high white cathedral type ceiling",
});

dest_dir = ({
"/players/pestilence/club/room/pervert.c","south",
"/players/pestilence/club/room/backstage.c","north",
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
