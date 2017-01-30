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
   "     Some small bushes are between gigantic trunks throughout the\n"+
   "woods.  A small twig is sticking out of a mound on the ground.  An\n"+
   "arrow is carved into one of the trees.\n";
   
   items = ({

         "ground","A small twig is sticking out of a mound on the solid surface,\n"+
         "maybe you could 'remove' it",
         "fungi","A green glowing fungus",
         "trunks","The huge main stems of the gigantic trees",
         "trunk","The huge main stem of the gigantic trees",
         "twig","A slender branch of the tree, divided in two",
         "path","The path is scattered with tree branches",
"boughs","Long limbs extending 15-20 feet from the tree trunk",
         "branches","The long limbs are 15-20 feet, scattered on the path",
         "aisles","The aisles are narrowed along the path",
         "mound","A mound of dirt with a twig stuck into it, maybe you can 'remove' it",             
         "huge mound","A mound of dirt with a twig stuck into it, maybe you can 'remove' it",
         "dirt","Loose soil piled into mounds",
         "gigantic trees","Permanent woody plants, with supported trunks and groping boughs",
         "bushes","Low bushes with many branches, arising near the ground",
         "small bushes","Low plants with many branches, arising near the ground",
         "trees","Permanent woody plants, with supported trunks and groping boughs",
         "woods","Gigantic trunks trail through the woods",
         "arrow","An arrow carved into the tree points 'south', some\n"+
         "markings are scribe below it",
         "markings","Markings scribe below the arrow, maybe you should 'read' it",
          });

   dest_dir = ({
         "/players/brittany/kadath/k10.c","south",
          });
}
init(){
::init();
add_action("remove","remove");
add_action("read","read");
add_action("search","search");
}

remove(str){
if(!str || str !="twig"){
  notify_fail("What do you want to remove?\n");
  return 0; }
 
  write("You remove the twig, the mound collapses and you SLIIIP and\n"+
        "FALLL into a hole.\n\n");
    say(tpn+"  F A L L S  into a hole.\n");
    tp->move_player("into the hole#/players/brittany/kadath/k12.c");
return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "markings") {
        notify_fail("What do you want to read?\n");
        return 0; }
 
    write(
     "South of here is the entrance to the Enchanted Woods.\n\n");
     return 1;
}
