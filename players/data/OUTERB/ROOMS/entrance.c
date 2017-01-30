/* ***********************************************
 * entrance.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 
 * 
 *
 * **********************************************/
#include <ansi.h>

inherit "/room/room";
reset(arg) {

  object monster;
  if(arg) 
    return ;    
  set_light(1); 
  short_desc = HIG+"A Green Light"+NORM;
  long_desc  = GRN+"The area is dark and putrid, and only the dead could live here \n"+
                   "comfortably.  A green light suffuses the air, giving it an almost \n"+
                   "uncomfortable sensation.\n"+NORM;

items=({
 "light", "The area is covered in a green light",
 });

 	add_listen("main", "The gentle breeze whispers of an ancient well.");

	add_taste("main", "What do you want to taste?");

	add_smell("main", "What do you want to smell?");



  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room4.c", "north",

  });
if(!present("figure", this_object())){
    move_object(clone_object("players/data/OUTERB/MOBS/figure.c"),this_object());
  };
if(!present("well", this_object())){
    move_object(clone_object("players/data/sliph.c"),this_object());
  };
}
query_no_fight()
 { 
 return 1;
 }