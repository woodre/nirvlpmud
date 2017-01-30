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
   "one side the bank is narrow and there is no space between the wall\n"+
   "and the water.  The other side curves around the castle and a wide \n"+
   "walkway leads in that direction.  A huge ring bolted on the castle\n"+
   "entrance catches your attention.\n";
   
   items = ({
         "moat","A deep trench, filled with muddy water",
         "tree","An old tree, with limbs spread wildly",
          });

   dest_dir = ({
 "/players/brittany/xanth/mag3.c","walk",
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
tp->move_player("step#/players/brittany/xanth/magicastle.c");
return 1; }
