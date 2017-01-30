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
   "     This is a narrow bank between the moat and the castle wall.  On\n"+
   "one side the bank narrowed until there was no space between the wall\n"+
   "and the water.  The other side curved around the castle.  A path \n"+
   "leads in that direction west of here.\n";
   
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
