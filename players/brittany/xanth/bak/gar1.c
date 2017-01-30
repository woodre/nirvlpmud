#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A garden"+NORM;
   long_desc =
   "     The ground begins to get marshy and many trees surrounds the\n"+
   "the terrain.  You see a big nest in a low_branching trunk and some\n"+
   "huge tracks are on the terrain.  The tracks comes to an end in front\n"+
   "of the low-branched trunk.\n";
   
   items = ({
         "ground","The ground is marshy and surrounded with trees",
         "trunk","A big tree with low branches",
         "tracks","Huge tracks that end in front of the trunk, maybe you can 'climb' it",
         "terrain","The terrain is marshy and have a lot trees on them",
         "nest","A big nest rested in a low tree trunk, maybe you could 'shake' it",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden.c","south",
              });
}

init() {
::init();
  add_action("search","search");
   add_action("shake_nest","shake");
  add_action("climb","climb");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

shake_nest(str) {
   if(!str || str != "nest") {
      notify_fail("What do you want to shake?\n");
      return 0; }
   write(
 "You shake the trunk and something falls to the ground.\n");
   say(tpn+"  shake the trunk.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/samphire.c"), this_object()); mob = 1; }
   return 1;
}

climb(str){
if(!str || str != "tree") {
        notify_fail("What do you want to climb?\n");
        return 0; }
 
write("You  C L I M B  the tree.\n");
   say(tpn+"  C L I M B S  the tree and disappears.\n");
tp->move_player("climb#/players/brittany/xanth/dragonland.c");
return 1; }
