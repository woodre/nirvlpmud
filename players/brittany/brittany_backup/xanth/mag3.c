#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
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
          });

   dest_dir = ({
              });
}

init() {
   ::init();
   add_action("search","search");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
