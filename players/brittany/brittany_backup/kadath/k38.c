#include "/open/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status hand;

reset(arg) {
   if(arg) return;
   hand = 1;
   
   short_desc = WHT+"The First Gate"+NORM;
   long_desc =
   "     Inside of a glowing light a cloudy pageantry of shapes and\n"+
   "scenery changes rapidly.  On the wall a sculptured hand draws\n"+
   "your attention.\n";


   items = ({
         "wall","A sculptured hand sticking out of the wall",
         "hand","The hand is very large and made out of stone, maybe you could 'grab' it",
         "shapes","Living things moving through vistas of unknown dimensions",
         "scenery","A mass of features giving character to the landscape",
         "landscape","The scenery forms into a clear picture",
         "pageantry","Illusions of shapes and scenary moving inside of a cloudy glowing light",
         "images","The images do not bare a likeness to anything known",
         "light","A glowing light in the middle of the dimension",
         "dimension","An entity where age and location have no significance",
         "chaos","A state of utter confusion",
          });

   dest_dir = ({
         "/players/brittany/kadath/k33.c","out",
      });
}
   
init(){
  ::init();
  add_action("grab_hand","grab");
  add_action("search","search");
}

grab_hand(str){
   if(!str ||  str != "hand") {
   notify_fail("Grab what?\n");
   return 0; }
 
   if(hand) {
 write("You feel the hand twitch and grasp you slightly.\n\n");
     say(tpn+"     DISappears into the wall.\n");
     tp->move_player("disappears#/players/brittany/kadath/k39.c");
     hand = 0;
   }
   else write("Nothing happens.\n");
   return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
