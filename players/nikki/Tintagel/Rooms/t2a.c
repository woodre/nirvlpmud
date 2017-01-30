#include "/players/nikki/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";
int dr;

reset(arg) {
  dr = 0;
   if(!arg) {
set_light(1);
short_desc = GRY+"Tower Entrance"+NORM;
long_desc = GRY+
 "   The room is bare except for the stairs leading up to the rest of\n"+
 "the tower.  The floor and walls are immaculately clean.  One would be\n"+
 "hard pressed to find even a speck of dirt anywhere.  A small table and\n"+
 "two chairs sit next to the door, perhaps it is for the guards to rest\n"+
 "during their watch.\n"+NORM;

items = ({
  "table","The wooden table sits next to the door.  A carafe and a bowl of\n"+
          "bread are placed in the middle of the table",
  "carafe","The carafe is made of dark marbled wood",
  "bowl","The large wooden bowl contains a few rolls of bread inside",
  "bread","The bread is dark brown and looks fresh",
  "stairs","Each step is about two feet high and ascend high into the tower",
  "floor","The floor shines from constant cleaning and buffing",
  "chairs","A pair of wooden chairs sit next to the table",
  "tower","The enormous tower is made from colossal boulders molded together",
  "boulders","The gray boulders are rough from the salt air slowly penetrating\n"+
             "the rock over the years",
  "stones","Hand sculpted boulders have been strategically stacked on top\n"+
           "of each other to create the tower",
  "walls","The walls of the tower are circular in shape. They gleam from\n"+
          "being kept so clean",
  "door","A gigantic door made from thick wood seems to be the only exit\n"+
         "from the tower",
  
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t2.c", "outside",
    "players/nikki/Tintagel/Rooms/t2b.c", "up",
   
});
}}

init() {
  ::init();
  add_action("open","open");
  add_action("outside","outside");
  
}

open(str) {
if(str == "door") {
    if(dr == 1) { 
      write("The door is already open..\n"); 
      return 1; 
       }
  write("You open the door.  It is now possible to leave the tower.\n");
  say(TPN+" opens the door.\n");
  dr = 1;
  return 1; 
   }
}

outside() {
        if(dr == 0) { 
        write("The door is closed.\n"); 
        return 1; 
         }
      if(dr == 1) { 
        write("\nYou step outside of the tower.\n");
        TP->move_player("the tower#players/nikki/Tintagel/Rooms/t2.c");
        return 1; 
         }
 
}

realm() { return "NT"; }