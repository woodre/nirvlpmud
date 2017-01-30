#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

status lid;

reset(arg) {
  lid = 1;

 if(!present("creature")) {   
    move_object(clone_object("/players/brittany/kadath/NPC/sages.c"),this_object());
   }

   if(arg) return;
   set_light(1);

   short_desc = BLU+"A STraNGe Tree"+NORM;
   long_desc =

   "     Inside of the tree is high and hollowed.  Lined neatly on clefts,\n"+
   "carved into the inner trunk are honeycombs and some bottles.  The\n"+
   "ground is free of any debris.\n";
   
   items = ({
         "sap","Fermented sap, squeezed from the haunted tree\n"+
                "grown from a seed dropped from the moon\n",
   "tree","The inside is high and hollowed",
         "clefts","Large clefts made into the inner trunk, resembling shelves",
         "shelves","The large clefts made into the trunk, resembles shelves",
         "bottles","The bottles are filled with sap, but one bottle\n"+
         "has something different inside",
         "bottle","This bottle has a symbol on the lid and a medallion\n"+
         "inside, maybe you should 'twist' it off",
         "symbol","The symbol is of a pentagram",
         "lid","The symbol that is on the lid is the same symbol on the tree",
         "burrows","The burrows looks like tunnels dug into the ground",
         "honeycombs","Honey formed inside an hexagonal cell",
         "trunk","The inner trunk have large clefts carved into it",
         "opening","The hollow opening leading back to the woods",
         "ground","The ground is free of any debris",
          });

   dest_dir = ({
          "/players/brittany/kadath/k18.c","out",
          });
}

init(){
::init();
add_action("twist_lid","twist");
add_action("search","search");
}

twist_lid(str){
 if(!str || str !="lid"){
 notify_fail("Twist what?\n");
 return 0; }

   if(present("sage",this_object())) {
  notify_fail("The sage blocks your way.\n");
  return 0; }
   if(lid) {
  write("You twist the lid,  "+HIW+"  P O O F "+NORM+"  the bottle\n"+
  "disappears and you are left with the medallion.\n");
  move_object(clone_object("/players/brittany/kadath/OBJ/medallion.c"),this_player());
     lid = 0;
   }
   else write("The lid has already been twisted.\n");
  return 1; }

 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
