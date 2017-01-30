#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A veggie garden"+NORM;
   long_desc =
   "     The vegetable garden continues to grow along the path.  The.\n"+
   "landscape looks desolate and a strange looking tree is on one side of\n"+
   "the path.  Another patch of cabbages trails further along the path.\n";
   
   items = ({
         "tree","A huge blue tree with red leaves growing from its branches,\n"+
         "maybe you could 'climb' up",
         "cabbages","A patch of cruciferous plants, with short stems and leaves formed\n"+
         "into a compact, edible head",
         "leaves","Red leaves hanging from the branches, maybe you could\n"+
         "'pick' one",
          });
         "path","A trail through a vegetable garden",

   dest_dir = ({
         "/players/brittany/xanth/vgarden","west",
         "/players/brittany/xanth/vgar1.c","east",
              });
}

init() {
::init();
   add_action("climb","climb");
   add_action("search","search");
   add_action("pick_leaf","pick");
   add_action("pick_leaves","pick");
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
 
climb(str){
if(!str || str != "tree") {    
        notify_fail("What do you want to climb?\n");
        return 0; }

write("You  C L I M B  the tree.\n");    
   say(tpn+"  C L I M B S  the tree and disappears.\n");
tp->move_player("climb#/players/brittany/xanth/fen.c");
return 1; }

pick_leaf(str) {
   if(!str || str != "leaf") {
      notify_fail("What do you want to pick?\n");
      return 0; }
   write(
    "You pick a leaf and it moves.\n");
   say(tpn+"  picks a leaf.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/lobster.c"), this_object()); mob = 1; }
   return 1;
}

pick_leaves(str) {
   if(!str || str != "leaves") {
      notify_fail("What do you want to pick?\n");
      return 0; }
   write(
    "You pick the leaves and it moves.\n");
   say(tpn+"  picks the leaves.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/lobster.c"), this_object()); mob = 1; }
   return 1;
}
