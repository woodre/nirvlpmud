#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object key;
int open;
int X;
reset(arg) {
open = 0;
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     The steps finally come to the last landing and lead into a\n"+
   "large room, dug out of the cavern floor.  Roots are dangling from\n"+
   "the ceiling.  To the west is a heavy wooden door, and a small cave-\n"+
   "like opening leads off to the east.\n";
   
   items = ({
         "roots","The roots of some wild flowers",
         "ceiling","The ceiling is cut high into the cavern walls\n"+
         "and has roots dangling from it",
         "room","The room is large and dug out of the cavern floor",
         "large room","The room is large and dug out of the cavern floor",
         "floor","Dug into the floor is a large room",
         "cavern floor","Dug into the floor is a large room",
         "opening","A small cave-like opening leads off to the east",
         "door","A heavy solid wood door",
         "wooden door","A heavy wooden door is west of here",
         "heavy wooden door","A heavy wooden door is west of here",
         "walls","There are entrances on the east and west walls",
         "hallway","Torches line the hallway made of brimstone",
"door","If the door is locked it must be unlocked with a key and 'open'",
         "landing","The bottom landing that stops on the cavern floor",
         "steps","The steps are steep and narrow, leading 'up'",
});
   
   
   dest_dir = ({
"/players/brittany/kadath/k4.c","up",
"/players/brittany/kadath/k6.c","east",
"/players/brittany/kadath/k7.c","west",

});
   
   
}
init() {
   ::init();
   add_action("open_door","open");
   add_action("unlock_door","unlock");
   add_action("west","west");
   add_action("search","search");
}
west(str) {
if(!open){
write("The door is closed.\n");
return 1;
}
   this_player()->move_player("west#/players/brittany/kadath/k7.c");
return 1; }

unlock_door(str) {
   if(!present("temple_key",this_player())) {
      notify_fail("What?\n");
      return 0; }
   
   if(!str || str != "door") {
      notify_fail("Unlock what?\n");
return 0; }
      if(X==0) {
         write("The key breaks as the door unlocks.\n");
destruct(present("temple_key",this_player()));
         X  = 1;
         return 1; }
   }
   
open_door(str) {
if(!str || str != "door") {
         notify_fail("Open what?\n");
         return 0; }
      
      if(X==0) {
         notify_fail("The door is locked.\n");
         return 0; }
      
      if(X==1) {
         write("The door opens.\n");
open = 1;
         X ++;
         return 1; }
      
      if(X==2) {
         notify_fail("The door is already open.\n");
         return 0; }
   }
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
