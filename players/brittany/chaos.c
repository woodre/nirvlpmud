#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = GRN+"CoUrTs of ChaOs"+NORM;
   long_desc =
   
   "	Before there was an Amber, before the Unicorn and Dworkin\n"+
   "changed reality forever, the Courts of Chaos stood as the pole\n"+
   "of the universe, the center of the universe, the final reality.\n"+
   "Even after the creation of the Pattern, Chaos was not relegated\n"+
   "to second best. The forces of Order and Chaos, the grand opposing\n"+
   "forces square off in an eternal chessgame. While Amber is well\n"+
   "described and known by the descendants of Oberon, what of the Courts?\n"+
   "What is it like in a land where the sky changes color...where shadow\n"+
   "is molded into Ways, and the politics and intrigue of Amber\n"+
   "are molded into an art and amplified a hundred fold?\n";

move_object(clone_object("/players/brittany/kadath/OBJ/unicorn.c"),this_object());
   
   items = ({
           });

   dest_dir = ({
  ""/players/brittany/..,"back",
              });
}

init() {
  add_action("back","back");
  add_action("touch_horn","horn");
  }

touch_horn(str) {
    if(!str || str != "horn") {
        notify_fail("Wait, you are not a virgin!\n");
        return 0; }
write("You touch the unicorn's horn and enter the realm of Amber.\n\n");
say(this_player()->query_name()+" touches the unicorn's horn and disappears.\n");
this_player()->move_player("amber#/players/brittany/amber/k1.c");
return 1; }

back(str){
this_player()->move_player("back#/players/brittany/..");
return 1; }
