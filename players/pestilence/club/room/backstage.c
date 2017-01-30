#include "/players/pestilence/define.h"
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
add_action("enter","enter");
add_action("open","open");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}

unlock(arg){          
  if(LOCK == 1){ write("The door is already unlocked.\n"); return 1; }
  if(arg == "door"){
    if (!present("club key", this_player())) {
        if (present("key", this_player()))
            write("You don't have the right key.\n");
        else
            write("You need a key.\n");
        return 1;
    }

    write("You unlock the door.\n"+
          "Maybe you could open the door and go outside.\n");        
LOCK +=1;
return 1; }
    write("Unlock what?\n");
return 1; }

open(arg){
  if(LOCK == 0){ write("It would be easier to open the door if it was unlocked.\n"); return 1; }

  if(arg == "door"  || arg == "north"  || arg == "north door"){
    write("You open the back door.\n");
    say(TPN+" opens the back door!\n");
OPEN +=1;
return 1; }
    write("Open what?\n");
return 1; }

enter(arg){
  if(OPEN == 0){ write("It would be easier if the door was open?\n"); return 1; }

  if(arg == "door"  || arg == "north"  || arg == "north door"){
    write("You leave out the door.\n");
 move_object(this_player(), "/players/pestilence/club/room/alley.c");  
  command("look",this_player());
LOCK = 0;
OPEN = 0;
return 1; }
    write("Enter what?\n");
return 1; }
