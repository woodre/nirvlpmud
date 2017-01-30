#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Dragonland"+NORM;
   long_desc =
   "     A large passage leads you through the mountains.  At the end\n"+
   "of the passage, you notice a huge net starting to form on the wall.\n"+
   "In the corner of the passage you notice a large throne.  A RED+"sign"+\n"+
   "NORM is on the wall next to the net.\n";
   
   items = ({
         "throne","A high dias with a diamond twisted into the armrest",
         "diamond","A precious gem in the armrest, maybe you could 'twist' it",
         "armrest","A support for the forearm at the side of the dias",
         "net","The net resembles a door, maybe you could 'open' it",
         "passage","An opening through the mountains",
          "mountains","A large mass of the earth's surface",
          "sign","A warning sign, maybe you should "read" it before going further.",          
          });

   dest_dir = ({
         "/players/brittany/xanth/dragonland.c","east",
         "/players/brittany/xanth        
              });
}

init() {
   ::init();
   add_action("search","search");
   add_action("twist_diamond","twist");
   add_action("twist_gem","twist");
  }

search(str) {
 notify_fail("You find nothing of interest.\n");
 return 0;
}

twist_diamond(str) {
   if(!str || str != "diamond") {
      notify_fail("What do you want to twist?\n");
      return 0; }
   write(
  "You twist the diamond and the dias moves to the side, something rises.\n");
   say(tpn+"  twist the diamond.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/dragonlady.c"), this_object()); mob = 1; }
   return 1;
}

twist_gem(str) {
   if(!str || str != "gem") {
      notify_fail("What do you want to twist?\n");
      return 0; }
   write(
   "You twist the gem and the dias moves to the side, something rises.\n");
   say(tpn+"  twist the diamond.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/dragonlady.c"), this_object()); mob = 1; }
   return 1;
}
