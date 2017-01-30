inherit "/obj/treasure";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  if(arg) return;
  set_id("skin");
  set_alias("groucho35");          
  set_short("A rat skin");
  set_long(
  "  A small rat skin. You might be able to "+YEL+"form"+NORM+" something\n"+
  "from them if you had enough of them and the right tools.\n");
  set_weight(1);
  set_value(240);
  set_dest_flag(1);
}

  init(){
   ::init();
    add_action("whoopty", "form");
    if(TP){
     TP->recalc_carry();
    }
   }

whoopty(str){
 if(!str){ write("Please use form skins.\n"); return 1; }
 if(str == "skins" || str == "skin" || str == "rat skins"){
  object MMmm, poop, yada, hrmm, plop, flop;
  MMmm = present("groucho35 4", TP);
  poop = present("groucho35 3", TP);
  yada = present("groucho35 2", TP);
  hrmm = present("groucho35", TP);
  plop = present("poopy21", TP);
  flop = present("silkygoodness", TP);

 if(MMmm && plop && flop){
   destruct(flop);
   destruct(MMmm);
   destruct(poop);
   destruct(yada);
   destruct(hrmm);
   write("You quickly sew the skins together to make some nifty gloves!\n");
   move_object(clone_object("/players/fred/asylum/obj/ratmits.c"), TP);
   return 1; }
 if(MMmm && flop){
   write("You still appear to be missing something.\n");
   return 1; }
 if(MMmm && plop){
   write("You still appear to be missing something.\n");
   return 1; }
 if(MMmm){ write("You don't have all the right tools yet.\n"); return 1; }
 if(poop){ write("It looks like you still need 1 more skin.\n"); return 1; }
 if(yada){ write("It looks like you still need 2 more skins.\n"); return 1; }
 if(hrmm){ write("It looks like you still need 3 more skins.\n"); return 1; }
 }
}
 
