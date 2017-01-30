/*
 *      File:                   02_style.txt
 *      Function:               
 *      Author(s):              Jareel@Nirvana
 *      Copyright:              Copyright (c) 2004 Jareel
 *                                      All Rights Reserved.
 *      Source:                 05/07/2004
 *      Notes:                  A no teleport, playerkilling area
 *                              Monsters are random,aggro,exit blocking
 *                              gear in the area has some power, all of
 *                              the decent gear needs multiple pieces or
 *                              a level req to use.  This is the Troll
 *                              Kygor Litor/Zorak Zoron addition that will
 *                              foreshadow two of the gods that will show 
 *                              up in my guilds.
 *      Change History:
 */

inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/caves/trolls/"

int monsters;

  reset(arg) {
  
  if(arg) return;
          
  short_desc=(HIK+"Troll Cavern"+NORM);
  add_property("no_teleport");
  add_property("fight_area");
  set_light(-10);
  long_desc=
    ""+HIK+"@@@@@"+NORM+"   This cavern is surreal; either this is going to be your biggest nightmare or your\n"+
    "---"+HIK+"@@"+NORM+"   greatest adventure. Miles of long, dark, cold, twisting, wet, dragon breath glass\n"+
    "R"+HIK+"@"+NORM+"|"+BOLD+"X"+NORM+"E   walled caverned walls.  Once you're in, there are no directions, your next step is\n"+
    "--|"+HIK+"@@"+NORM+"   either forward into the unknown, or back to where you came from.  The pathway is\n"+ 
    "|"+HIK+"@"+NORM+"|R"+HIK+"@"+NORM+"   treacherous; a path of very ragged, rough, uneven molten rock enclaved by mounds \n"+ 
    "        of boulders.\n";
  items = ({
    "cavern","The walls of the cavern are covered with a slimy mucus",
    "wall","The wall has a thin mucus film coating it",
    "mucus","The substance drips down the wall, off the moss as you look at it",
    "moss","A basic form of plant life that coats a lot of the wall",
    "rocks","Chips of stone can be found in the caverns corners",
    "chips","Pieces of the cavern walls litter the floor",
    "light","A light illuminates the room to the south",
    "east","the cavern leads off that way",
    "south","It appears to be a room illuminated by some light source",
    "flower","Several small purple flower blossom in the moss",
    "blossom","The flower looks very delicate",
  });

dest_dir = ({
  "/players/jareel/areas/chaos/cave/grid1/hall4.c","west",
  "/players/jareel/areas/chaos/cave/cave_enter.c","east",
  });

get_monsters(); }

get_monsters() {
  int i;
    i = random(100);
    monsters = 1;

  switch(i) {


    case 0..5:
      getmonsters_00to05();
    break;


    case 6..20:
      getmonsters_06to20();
    break;


    case 21..75: 
      getmonsters_21to75();
    break;

    
    case 76..90: 
    break;

    
    default:
      getmonsters_default();
    break; 
    }
}

getmonsters_00to05() {

   move_object(clone_object(MON+"greattroll.c"),this_object());

   if(random(2) == 1) move_object(clone_object(MON+"trollkin.c"),this_object());
}

getmonsters_06to20() {

  move_object(clone_object(MON+"darktroll.c"),this_object());

  if(random(5) == 1) {
    move_object(clone_object(MON+"troll1.c"),this_object());

  if(random(3) == 1)
    move_object(clone_object(MON+"troll2.c"),this_object());
  }
}

getmonsters_21to75() {

  if(1 == random(3))
    move_object(clone_object(MON+"trollkin.c"),this_object());

  if(1 == random(5))
    move_object(clone_object(MON+"zorakzoronlord.c"),this_object());

  if(1 == random(4))
    move_object(clone_object(MON+"kygorlitorlord.c"),this_object());

  if(1 == random(4))
    move_object(clone_object(MON+"trollshamon.c"),this_object());

  if(1 == random(6))
    move_object(clone_object(MON+"scarab.c"),this_object());

  if(1 == random(5)) {
    move_object(clone_object(MON+"troll1.c"),this_object());

  if(random(3)==1)
    move_object(clone_object(MON+"troll2.c"),this_object());
  }
}

getmonsters_default() {

  if(random(50)==1)  move_object(clone_object(MON+"greattroll.c"),this_object());

  if(random(20)==1)  move_object(clone_object(MON+"zorakzoronlord.c"),this_object());

  if(random(17)==1){  move_object(clone_object(MON+"troll1.c"),this_object());

  if(random(2)==1) move_object(clone_object(MON+"troll2.c"),this_object()); }

  if(random(15)==1)  move_object(clone_object(MON+"darktroll.c"),this_object());

  if(random(10)==1)  move_object(clone_object(MON+"kygorlitorlord.c"),this_object());

  if(random(7)==1)  move_object(clone_object(MON+"trollshamon.c"),this_object());

  if(random(5)==1)  move_object(clone_object(MON+"troll1.c"),this_object());

  if(random(5)==1)  move_object(clone_object(MON+"troll2.c"),this_object());

  if(random(3)==1)  move_object(clone_object(MON+"trollkin.c"),this_object());
}
 

init() {
  ::init();
 
  add_action("Search","search");
  }

Search(str) {

  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
