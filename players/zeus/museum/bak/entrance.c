/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
 if(arg) return;

 short_desc="The Museum";
 long_desc=
"This is the entrance room to the museum.  The entire room is made of a\n"+
"clear material similar to glass, through which the blackness of space can\n"+
"be seen, dotted with stars.  Behind you is a large teleporter.  There is\n"+
"a sign mounted on the west wall of the room.  The ceiling is glowing\n"+
"with a soft light.  The hallway continues to the north.\n";  
 set_light(1);
 items=({
	 "walls",
"The walls are made of a clear material similar to glass.  They are\n"+
"perfectly clear.  Looking through them you can see the infinite blackness\n"+
"of space, scattered with many distant stars",
     "floor",
"The floor is made of a clear material similar to glass.  Beneath you\n"+
"the infinite blackness of space can be seen, scattered with stars",
     "space",
"Outer space is very black, with many stars",
     "stars",
"The beautiful stars are all very far away, and thus very tiny",
     "sign",
"The digital sign hanging from the west wall shows that the lounge area\n"+
"is to the north, with an arrow pointing in that direction",
     "teleporter",
"There is a circular metal teleporter sitting on the floor behind you.\n"+
"If you wish to 'leave' the museum you should walk into it",
     "ceiling",
"The ceiling is perfectly clear, and through it space can be seen.  However\n"+
"the ceiling itself is glowing softly, providing light for the museum",
 });
 dest_dir=({
	 "/players/zeus/realm/main.c", "leave",
	 "/players/zeus/museum/hall3.c", "north",
 });
}

void init(){
  ::init();
  add_action("leave_cmd", "leave");
}

status leave_cmd(){
   write(
"\nYou walk onto the teleporter...  A flash of light consumes you...\n\n\n");
   TR(environment(TP), 
   TP->QN+" walks onto the teleporter..."+
   "A flash of light consumes "+TP->OBJ+"...\n",
   ({ TP }));
   MO(TP, "/players/zeus/realm/main.c");
  TR(environment(TP), 
   TP->QN+" steps out of the portal in a flash of light.\n", ({TP}));
  command("look", TP);
  return 1;
}


