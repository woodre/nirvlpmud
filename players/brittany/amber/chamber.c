#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"Chamber"+NORM;
   long_desc =
   "     A long hallway which appears to have a reception chamber on one\n"+
   "side.  There is a moving staircase at the end of the hallway.  Large\n"+
   "sconces with candles hang on each side of the hallway, lighting the way.\n"+
   "The only way out of this room is 'out' or the staircase.n";
   
   items = ({
         "hallway","A long hallway",
         "staircase","A moving staircase, maybe you can 'step staircase'",
         "sconces","Large sconces hanging on the wall filled with candles",
         "sconce","A large sconce hanging on the wall with a candle in it",
         "candles","Candles lit inside the sconces",
         "candle","A candle lit inside a sconce",
         });

   dest_dir = ({
         "/players/brittany/amber/courtyard.c","out",
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("step_staircase","step");
   add_action("out","out");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

out(str){
  tp->move_player("out#/players/brittany/amber/courtyard.c");
  return 1; }

step_staircase(str){
if(!str || str != "staircase") {
        notify_fail("Where do you want to step?\n");
        return 0; }
 
write("You  S T E P  on the staircase and move to the second floor.\n");
   say(tpn+"  S T E P  on the staircae and move to the second floor.\n");
tp->move_player("step#/players/brittany/amber/complexroom.c");
return 1; }
