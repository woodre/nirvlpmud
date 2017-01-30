#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = CYN+"Enchanted Woods"+NORM;
   long_desc =
   "     The trees begin to spread further apart.  In the distance some\n"+
   "smoke can be seen coming from chimneys in a small village.  The path\n"+
   "leads south into the village of Ulthar, with its colored roofs and\n"+
   "cobbled walkways.\n";
   
   items = ({
         "cobbled walkways","The cobblestone path leading through the village",
         "walkways","The cobblestone path leading through the village",
         "roofs","The multi-colored roofs on top of the village taverns",
         "trees","Permanent woody plants, with supported trunks and groping boughs",
         "trunks","The huge main stems of the gigantic trees",
 "boughs","Long limbs extending 15-20 feet from the tree trunk",
         "taverns","Sea taverns made of stone",
         "path","The path is ridged and made of cobblestone",
         "smoke","A black vapor is coming out of the chimneys",
         "chimneys","A vertical structure made of stone, on top of the roofs",
         "village","A small merchant village, with colored roofs on the taverns and",
         "cobbled walkways",
         "woods","The end of the Enchanted woods, a path leads south to a\n"+
         "small village",
          });

   dest_dir = ({
          "/players/brittany/kadath/k20.c","north",
          "/players/brittany/kadath/k22.c","south",
          });
   
}

   init(){
  ::init();
   add_action("search","search");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
