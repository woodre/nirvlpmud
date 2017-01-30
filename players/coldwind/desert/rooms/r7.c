#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("farha", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/farha.c"), this_object());
}
  if(arg) return;
set_light(1);
short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    Peace fills your heart and mind as you stand in this holy place.\n"+
"The wooden walls are painted white, while green rags cover the floor.\n"+
"There are two small windows on the north and south walls.  An opened\n"+
"door takes most of the west side, and you couldn't miss the beautiful\n"+
"writings on the ceiling.\n";

items = ({
  "walls",
  "The walls are painted white. You notice two lamp holders next each\n"+
  "window",
  "holders",
  "They are fixed two the wall next to the windows. The White wooden\n"+
  "holders are carrying oil lamps",
  "lamp holders",
  "They are fixed two the wall next to the windows. The White wooden\n"+
  "holders are carrying oil lamps",
  "lamps",
  "These are old oil lamps, placed on holders to lit the place at \n"+
  "night time",
  "rags",
  "Small plain green rags placed next to each other to cover the floor",
  "floor",
  "The entire floor is covered with green rags",
  "door",
  "A large opened door leading outside",
  "windows",
  "The green windows are closed to avoid the sandy wind from blowing in",
  "glass",
  "The glass is blocking most of the sunlight and allowing emerald\n"+
  "light to come throug. The emerald light gives you a sense of peace",
  "cieling",
  "The ceiling is painted white and decorated with beautiful writings",
  "writings",
  "Beautiful Writings decorate the ceiling, but you aren't able to read",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/r6.c","out",
});

}
query_no_fight() { return 1; }
