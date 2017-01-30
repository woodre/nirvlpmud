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
   "     The woods thicken with bushes and more fungi covers the trees.\n"+
   "To the west is a huge clearing.  The trees begin to form into a\n"+
   "circle.\n";
   
   items = ({
"bushes","Low plants with many branches, arising near the ground", 
 "trees","Permanent woody plants, with supported trunks and groping boughs", 
 "boughs","Long limbs extending 15-20 feet from the tree trunk",
"trunks","The huge main stems of the gigantic trees",
         "tree","A permanent woody plant, with a self supported trunk and groping branches",
         "groping boughs","Long limbs extending 15-20 feet from the tree trunk",
         "village","A village is west of here",
         "fungi","A phosphorescent abnormal growth",
         "honeycombs","Honey formed inside a hexagonal cell",
         "clearing","The center of the area is clear of trees or branches",
         "woods","The huge groping boughs, following a path to a village",
         "circle","The trees are formed at an equal distance from the center",
         "sort.  You can barely see what is going on from here",
          });

   dest_dir = ({
         "/players/brittany/kadath/k13.c","east",
         "/players/brittany/kadath/k18.c","west",
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
