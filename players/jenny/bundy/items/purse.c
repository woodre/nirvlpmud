#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
int x;
reset(int arg) {
   if(arg) return;
   set_id("purse");
   set_alias("purse");
   set_short(WHT+"A purse"+NORM);
   set_long(
      "This is a plain looking white purse.  It has lots of zippers and\n"+
      "pockets.  Who knows, if you 'rummage' through it, you might find\n"+
      "something.\n");
   
   
   set_weight(1);
   set_value(500); }
init() {        
   ::init();  
   add_action("purse","rummage");
}

purse(arg) { 
   if(TP->query_attrib("luc") < 16) {
      x = 400+random(250);
   }
   if(TP->query_attrib("luc") > 15) {
      x = 750+random(500);
   }
   if(!arg) { return 0; }
   write(""+CYN+"You rummage through the purse and find "+x+" coins.\n"+
      "You throw the empty purse away."+NORM+"\n");
   say(""+CYN+""+TPN+" rummages through the purse and finds some coins.\n"+
      ""+TPN+" Throws the empty purse away."+NORM+"\n");
   TP->add_money(x);
   destruct(this_object()); TP->recalc_carry();
   return 1; }
