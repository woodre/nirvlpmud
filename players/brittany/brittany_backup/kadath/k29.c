#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     You have entered a underground cave.  Natural formations and tons\n"+
   "of ancient fossils form the cave.  In the corner a stream of water runs\n"+
   "down the cave walls.  A vault of some kind is on another area of the\n"+
   "wall.\n";
 
   items = ({
         "water","A glowing stream of water",
         "vault","A passage surrounded by heavy earth",
         "cave","The cave is formed with formations and fossils",
         "formations","Rocks forming into different shapes",
         "natural formations","Rocks forming into different shapes",
         "fossils","Stone with shapes of leaves, embedded into them",
         "ancient fossils","Veins are embedded into the rocks",
         "shapes","The rocks are different shapes and sizes",
         "veins","Strands of vascular tissue",
         "corner","Water runs down the wall",
         "stream","A small stream of water",
         "walls","The walls are rugged and rough",
         "rocks","The rocks are rugged and formed into different shapes",
          });

   dest_dir = ({
        "/players/brittany/kadath/k27.c","west",
         "/players/brittany/kadath/k30.c","vault",
          });
   
}
  init(){ 
  ::init();
   add_action("search","search");
   add_action("vault","vault");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

vault(str){
   write("You enter the vault.\n\n");
   say(tpn+" ENTERS the vault.\n");
  tp->move_player("vault#/players/brittany/kadath/k30.c");
  return 1; }
