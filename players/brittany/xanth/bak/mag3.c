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
   
   short_desc = BLU+"Good Magician"+NORM;
   long_desc =
   "     The castle walls are massive.  A spiral staircase leads up high\n"+
   "into the castle.  The windows are painted with colorful designs and\n"+
   "the ceilings are vaulted.  A door in the back of the room looks\n"+
   "to be bolted.\n";
   
   items = ({
         "stones","Small flat stones in the shape of feet",
         "moat","A deep trench, filled with muddy water",
         "tree","An old tree, with limbs spread wildly",
         "windows","Tall painted windows with colorful designs",
         "walls","The walls are 50 feet high",
         "ceilings","The ceilings are high and vaulted",
         "door","A huge door that is bolted, you will need a key to 'unlock' it",
          });

   dest_dir = ({
 "/players/brittany/xanth/mag2.c","out",
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("unlock_door","unlock");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

unlock_door(str) {
   if(!present("castle_key",this_player())) {
      notify_fail("What?\n");
      return 0; }
 
   if(!str || str != "door") {
      notify_fail("Unlock what?\n");
return 0; }
      if(X==0) {
         write("The key breaks as the door unlocks.\n");
destruct(present("castle_key",this_player()));
         X ++;
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
