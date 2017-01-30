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
   "     Awful spinach grows all about, along with turnips, radishes and\n"+
   "onions.  Other terrible stuff is growing in the garden, the kind of\n"+
   "stuff that existed only to nauseate someone.  A patch of cabbages\n"+
   "trails further east along the path.\n";
   
   items = ({
         "spinach","A herbaceous annual, with succulent leaves",         
         "turnips","Thick, fleshy, edible roots",
         "radishes","Crisp, pungent, edible roots",
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
