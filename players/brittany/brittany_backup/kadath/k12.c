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
   "     The room is dark.  It seems you have entered a hidden\n"+
   "burrow.  The same fungi in the forest is growing all over\n"+
   "the walls.  Half-eaten honeycombs are scattered all over the\n"+
   "place, the fluttering sounds seem to be real close now.  The\n"+
   "only way out is to 'climb' out.\n";
   
   items = ({
         "walls","The walls are covered with the strange fungi from the woods",
         "ground","Honeycombs are scattered all over the ground",
         "burrow","It is too dark",
         "honeycombs","Honey formed inside an hexagonal cell.",
        "fungi","A phosphorescent spongy abnormal growth.",
          });

   dest_dir = ({
          });
}

init(){
add_action("climb","climb");
add_action("search","search");
add_action("listen","listen");
}

listen() {
write("You hear something fluttering about the room.\n");
return 1; }

climb(str) {
   this_player()->move_player("climb#/players/brittany/kadath/k11.c");
   return 1;
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
