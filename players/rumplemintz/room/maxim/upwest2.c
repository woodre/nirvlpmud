/* ========================================================================== */
/*                                                                            */
/*   upwest2.c                                                                */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Hidden lever in room to create door to hidden room and populate key      */
/*   to prison area cells in King Maxim's castle                              */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types
#include "/obj/door.h"

inherit "/room/room.c";
object obj_1, obj_2;
int pulled;

void reset(status arg){
  if(arg) return;
  pulled = 0;
  set_light(1);
  short_desc = "Western tower of King Maxim's castle";
  long_desc =
"     You are in the western tower of the castle. There are cobwebs and\n"+
"dust all over. There is a single table and chair in the center of the\n"+
"room. A small amount of light is beaming in through the only window in\n"+
"the room.\n";
  items = ({
    "tower", "You can see outside and the surrounding area",
    "cobwebs", "They are covering everything in the tower",
    "dust", "It hasn't been disturbed in quite awhile",
    "table", "It appears someone used to use this room as a study",
    "chair", "It matches the table, they're probably a set",
    "window", "Light beams in and illuminates the room",
    "lever", "A small wooden lever was hidden by the neglect"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/upwest1", "north"
  });
}

void init(){
  ::init();
  add_action("search1", "search");
  add_action("lever_pull", "pull");
  add_action("lever_pull", "move");
}

status pl1(){
  write("You hear a loud clanking noise coming from the east.\n");
  say("You hear a loud clanking noise coming from the east.\n");
  call_out("pl2",2);
  return 1;
}

status pl2(){
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/upeast2", "west",
    "/players/rumplemintz/room/maxim/treasury", "east",
    "secret",
    "maxim",
    "This is a magic door",
    1,
    0,
    0
  );
  return 1;
} 

status search1(string str){
  if(str=="dust" || str=="cobwebs"){
    write("Your search turned up a lever hidden in the "+str+"\n"); 
    return 1;
  }
  return 0;
}

status lever_pull(string str){
  if(!str || str != "lever") return 0;
  if(pulled==1){
    write("You cannot pull the lever anymore.\n");
    return 1;
  }
  else {
    pulled=1;
    write("You pull the lever.\n");
    call_out("pl1",2);
    return 1;
  }
}
