/* ========================================================================== */
/*                                                                            */
/*   upeast2.c                                                                */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Upstairs room with secret door in King Maxim's castle                    */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  if(present("door", this_object())){
    object obj;
    obj = present("door", this_object());
    destruct(obj);
  }
  set_light(1);
  short_desc = "Upstairs in King Maxim's castle";
  long_desc =
"     You are standing in a bedroom. This appears to be the quarters\n"+
"of the King. There is a grand feather bed in the middle of the room.\n"+
"On each wall, there are burning torches. There are three different \n"+
"animal pelts covering the stone floor. A fire burns in a beautiful \n"+
"marble fireplace set into one of the walls.\n";
  items = ({
    "bedroom", "It is lavishly decorated. Gold and satin everywhere",
    "bed", "It is huge. It appears very comfortable",
    "feather bed", "It is huge. It appears very comfortable",
    "torches", "They burn and illuminate the room nicely",
    "pelts", "They cover the stone floor",
    "animal pelts", "They cover the stone floor",
    "fire", "A hearty fire that keeps the room warm",
    "fireplace", "An ornately spectacular fireplace made from marble",
    "marble fireplace", "An ornately spectacular fireplace made from marble"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/upeast1", "north"
  });
}

void init(){
  ::init();
  add_action("lay", "lay");
  add_action("lay", "lie");
}

mixed lay(string str){
  if(str=="on bed" || str=="on feather bed"){
    write("You dare not lay on the King's bed.\n");
    return 1;
  }
  return;
}  
