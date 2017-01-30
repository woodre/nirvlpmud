#include "/players/pestilence/define.h"
inherit "/players/vertebraker/closed/std/room";
int OPEN,OPENN,UNLOCK,LOCK;

reset(arg) {
  OPEN = 0;
  UNLOCK = 0;
  OPENN = 0;
  LOCK = 0;
  if(arg) return;

short_desc = "behind "+HIK+"Pesty's"+NORM+"";
long_desc =
  "    This is a small alley way.  It's a deadend to the west, with\n"+
  "tell alley extending to the east.  On the north side of the alley,\n"+
  "there is a very large brick building with no windows.  To the\n"+
  "is the backdoor to the strip club.  In the middle of the alley\n"+
  "there is a small manhole cover.\n";
add_property("NT");
/*
add_property("PK");
*/
set_light(0);

items = ({
  "deadend","A brick wall is at the end of the alley",
  "manhole cover","A small circular cover leading down to the sewer",
  "cover","A small circular cover leading down to the sewer",
  "manhole","A small circular cover leading down to the sewer",
  "wall","A brick wall that stands ten feet tall",
  "building","A very large brick building to the north",
  "door","A door leading back into the strip club",
  "backdoor","A door leading back into the strip club",
  "brick","Large bricks, that make up the wall and building",
});

dest_dir = ({
"/players/pestilence/club2/room/parking.c","east",
});

}

init() {
  ::init();
add_action("stop","quit");
add_action("open","open");
add_action("enter","enter");
add_action("unlock","unlock");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}

open(arg){

 if(arg == "manhole cover"  || arg == "cover"  || arg == "manhole"){
    write("You open the manhole.\n");
    say(TPN+" opens the manhole!\n");
OPEN +=1;
return 1; }

else  if(LOCK == 0){ write("It would be easier to open the door if it was unlocked.\n"); return 1; }

else if(arg == "door"  || arg == "north"  || arg == "north door"){
    write("You open the back door.\n");
    say(TPN+" opens the back door!\n");
OPENN +=1;
return 1; }
    write("Open what?\n");
return 1; }

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

enter(arg){
  if((arg == "manhole") && (OPEN == 1)){
    write("You leave down the manhole ladder.\n");
 move_object(this_player(), "/players/pestilence/club/room/sewer.c");  
  command("look",this_player());
return 1; }
else  if((arg == "door") && (OPENN == 1)){
    write("You leave out the door.\n");
 move_object(this_player(), "/players/pestilence/club2/room/backstage.c");  
  command("look",this_player());
LOCK = 0;
OPENN = 0;
return 1; }
else  if((!arg)  || ((OPEN == 0) && (OPENN == 0)) || (LOCK == 0)  || (("door") && (OPENN == 0))){
       notify_fail("You can't enter that right now.\n");
       return 0;
}
}
