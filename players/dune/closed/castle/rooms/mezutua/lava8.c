inherit "room/room";
#include "definitions.h"

init () {
   int rnd;
   int ste;
   int sta;
   ::init();
   ste= target->query_attrib("ste");
   sta= target->query_attrib("sta");
   rnd = random(100);
   if (rnd <= 40) { write("You swelter in the intense heat.\n"); }
   if (rnd <= 40) {
      if (ste <= 15) {
         write(
"     You slip and fall, but manage to grab hold of the edge.  Your mistake \n"+
"is a very painful one.  A spray of magma hits you on the back and sizzles \n"+
"your flesh.\n");
         target->hit_player( (20-ste)/2 );
         return 1;}
       if (ste <= 8) {
         write(
"     You slip and fall straight into the magma.  Your 80 foot fall has probably\n"+
"cost you your life.\n");
         target->hit_player(200);
         return 1;}
      }
   if (rnd <=25) {
      if (sta<=15) {
         write("The heat drains you of energy.\n");
         target->add_spell_point(-30);
         return 1;}
      if (sta<=8) {
         write("The heat is overwhelming.\n");
         target->add_spell_point(-100);
         return 1;}
         }
}


reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc=("Lake of Magma");
        long_desc=
"     A huge lake of magma boils eternally beneath you.  The only places to\n"+
"step are on tall columns of blackened rock.  Bubbles of magma pop and\n"+
"splash upon the sides of the columns.  Any fall, and you could be \n"+
"history.\n";

   dest_dir=({
        CASTLEROOM+"/lavapit.c","north"  ,
        CASTLEROOM+"/lava7.c","east"  ,
        CASTLEROOM+"/lava2.c","west"  ,
            });

   items=({
        "lake",
"     The lake of magma is huge, covering about half a square mile.\n"+
"As you look closer, you can see movements in the magma \n"+
"characteristic of humanoid-like beings",
        "columns","     The columns stand about 80 feet above the lake",
        "rock","     The rock is some sort of durable obsidian",
   });
   }   }
