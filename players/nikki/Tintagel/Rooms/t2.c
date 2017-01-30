#include "/players/nikki/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";
int dr;

reset(arg) {
  dr = 0;
   if(!arg) {
set_light(1);
short_desc = HIG+"Magan Halomors Tower"+NORM;
long_desc = YEL+
 "   The entrance to the tower is usually strongly protected from any\n"+
 "intruders.  The tower looms high into the sky.  It's made from large\n"+
 "stones that appear to have tarnished with wear from the heavily salted\n"+
 "air.  Even so, the tower is strong and defends the castle with an under-\n"+
 "lying power that raidates from from it's walls.  There is an oversized\n"+
 "door barring the entrance to the inside of the tower.\n"+NORM;

items = ({
  "tower","The enormous tower is made from colossal boulders molded together",
  "boulders","The gray boulders are rough from the salt air slowly penetrating\n"+
             "the rock over the years",
  "stones","Hand sculpted boulders have been strategically stacked on top\n"+
           "of each other to create the tower",
  "walls","The walls of the tower are circular in shape and rise high above\n"+
          "the city",
  "door","A gigantic door made from thick wood seems to be the only entrance\n"+
         "into the tower",
  "entrance","The entrance into the tower is blockaded by the door",
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/street1.c", "backward",
    "players/nikki/Tintagel/Rooms/t1a.c", "enter",
   
});
}}

init() {
  ::init();
  add_action("open","open");
  add_action("enter","enter");
  
}

open(str) {
if(str == "door") {
    if(dr == 1) { 
      write("The door is already open..\n"); 
      return 1; 
       }
  write("You open the door.  It is now possible to enter the tower.\n");
  say(TPN+" opens the door.\n");
  dr = 1;
  return 1; 
   }
}

enter() {
        if(dr == 0) { 
        write("The door is closed.\n"); 
        return 1; 
         }
      if(dr == 1) { 
        write("\nYou step into the tower.\n");
        write("There are stairs leading up into the higher levels of the tower.\n");
	TP->move_player("into the tower#players/nikki/Tintagel/Rooms/t2a.c");
        return 1; 
         }
 
}