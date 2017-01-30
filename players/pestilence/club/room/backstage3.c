#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";
int LOCK,OPEN;

reset(arg) {
  LOCK = 0;
    OPEN = 0;
  if(arg) return;

if (!present("shelly")) {
  move_object(clone_object("/players/pestilence/club/mob/shelly.c"),
        this_object()); }

if (!present("jeff")) {
  move_object(clone_object("/players/pestilence/club/mob/jeff.c"),
        this_object()); }

short_desc = "Backstage"+NORM+"";
long_desc =
  "    This is the room directly north of the stage.  The room has a\n"+
  "large mirror on the east wall.  A bunch of lockers are placed\n"+
  "against the west wall.  To the north is a door.  The walls are\n"+
  "white, with what looks like phone numbers written over the walls.\n";
  "on the east wall.  A bunch of lockers are placed against the west wall.  To\n"+
  "the north is a door.  The walls are white, with what looks like phone numbers\n"+
  "written over the walls.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "mirror","A large mirror the strippers use to do their makeup",
  "walls",""+HIR+"555-6969       555-0690"+NORM+"",
  "wall",""+HIR+"555-6969       555-0690"+NORM+"",
  "locker","A gray locker used for holding the stripper's normal clothes",
  "lockers","Gray lockers used for holding the stripper's normal clothes",
  "door","A door on the north side of the room, possibly leading out back",
  "stage","A wooden stage to the south where the stripper's dance",
  "numbers",""+HIR+"555-6969        555-0690"+NORM+"",
 });

dest_dir = ({
"/players/pestilence/club/room/stage.c","south",
});

}

init() {
  ::init();
add_action("stop","quit");
add_action("unlock","unlock");
add_action("open","open");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
