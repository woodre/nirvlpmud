#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("zoog", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/kadath/NPC/zoogs.c"),
      this_object());
    }
  }

   if(arg) return;
   set_light(0);
   
   short_desc = GRN+"A burrow"+NORM;
   long_desc =
   "     You enter another burrow hidden under the ground of the\n"+
   "tunnel.  More half-eaten honeycombs are scattered all over\n"+
   "the place and fungi is dripping down the walls.\n";
   
   items = ({
         "honeycombs","Honey formed inside an hexagonal cell, half-eaten all over the place",
         "fungi","A phosphorescent spongy abnormal growth.",
         "walls","Fungi is dripping down the walls",
         "tunnel","A small passageway, dug into the burrow",
         "burrow","A hole in the ground",
         "passageway","A small tunnel, dug into the burrow",
         "ground","Honeycombs are scattered all over the ground",
          });

   dest_dir = ({
         "players/brittany/kadath/k15.c","climb",
          });
   }

   
init(){
::init();
add_action("climb","climb");
add_action("search","search");
}

climb(str){
  tp->move_player("climb#/players/brittany/kadath/k15.c");
  return 1; }

 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
