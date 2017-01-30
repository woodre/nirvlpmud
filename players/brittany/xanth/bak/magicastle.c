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
    "     You sink through the fluid and land on firm ground.  You are\n"+
   "standing in sight of the Good Magician's castle.  A drawbridge\n"+
   "crosses over a muddy moat.  Under a spreading tree there are\n"+
   "several small stones.  Cross the moat to enter the castle.\n";
   
   items = ({
         "stones","Small flat stones in the shape of feet, maybe\n"+
         "you should 'step' on them",
         "drawbridge","An old wooden drawbridge about 3 feet wide",
         "moat","A deep trench, filled with muddy water",
         "tree","An old tree, with limbs spread wildly",
          });

   dest_dir = ({
         "/players/brittany/xanth/vgar1.c","out",
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("step_stones","step");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

step_stones(str){
if(!str || str != "stones") {
        notify_fail("Where do you want to step?\n");
        return 0; }
 
write("You  S T E P  on the stones and walk across the moat.\n");
   say(tpn+"  S T E P  on the stones and walk across the moat.\n");
tp->move_player("step#/players/brittany/xanth/mag2.c");
return 1; }
