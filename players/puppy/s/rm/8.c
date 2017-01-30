#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_long(
      "The tables and chairs made from tree stumps and branches have\n"+
      "been tightly tied together by vines.  A well off to the side\n"+
      "looks like it has seen better days, but still manages to\n"+
      "provide a few buckets filled with water.  A pot over the\n"+
      "campfire has one of the chefs latest concoctions simmering\n"+
      "inside of it.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell something delicious simmering in the pot.");
   items = ({
         "path", "A path where travelers have walked",
         "grass", "Trampled grass making out a path",
         "well", "A rather old looking well",
         "tree stumps", "Tables cut from the base of trees",
         "stumps", "Tables cut from the base of trees",
         "stump", "The base of a tree made into a table",
         "branches", "Pieces of wood tied be vines to form makeshift chairs",
         "branch", "Part of one of the makeshift chairs",
         "vines", "Long strands of vegitation",
         "tables", "Tables cut from the base of trees",
         "vine", "A strand of vegetation used to hold wood in place",
         "table", "A table cut from the base of a tree",
         "chairs", "Wooden chairs attached with vines",
         "chair", "A wooden chair made from wood and vines",
         "vines", "Strands of vegetation used to tie things",
         "well", "A well with crumbling stones",
         "buckets", "Wooden buckets filled with water",
         "bucket", "A wooden bucket willed with water",
         "water", "Cold liquid used for putting out fires",
         "pot", "A black pot used to make delicious dishes",
         "You wonder what is being cooked inside of it?",
         "campfire", "A small fire built for cooking"});
   dest_dir = ({
         "/players/puppy/s/rm/3.c", "east"});
   move_object(clone_object("/players/puppy/s/mob/cook.c"), this_object());
   return 1; }

init(){
   ::init();
   { add_action("opot", "open"); }
}
opot(str){
   if(!str){ notify_fail("What are you trying to open?\n"); return 0; }
   if(str == "pot") {
      write("Cook Smurf slaps your hand with his spatula.\n"+
         "Cook Smurf says: No peeking!\n");
      return 1; }
   notify_fail("What are you trying to open?\n"); return 0; }
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [e]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [e]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [e]";
}
