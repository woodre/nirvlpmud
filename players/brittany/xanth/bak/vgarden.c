#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A veggie garden"+NORM;
   long_desc =
  "     Leaves of spinach grows along the path. Other vegetables are growing\n"+
  "inside the garden to include turnips, radishes and onions.  At the end of\n"+
  "the trail a patch of cabbages are along the path.\n";
   
   items = ({
         "spinach","A herbaceous annual, with succulent leaves",         
         "leaves","Bushels of spinach leaves",
         "turnips","Thick, fleshy, edible roots",
         "radishes","Crisp, pungent, edible roots",
         "cabbages","A patch of cruciferous plants, with short stems and leaves formed into\n"+
         "a compact, edible head",
         "patch","Cabbages growing in patches",
         "path","A trail through a vegetable garden",
          });

   dest_dir = ({
         "/players/brittany/xanth/gar3.c","west",
         "/players/brittany/xanth/vgar.c","east",
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
