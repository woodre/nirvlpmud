#include "/obj/ansi.h"
inherit "/obj/treasure.c";

#define tp this_player()
#define tpn this_player()->query_name()

reset (arg) {
  set_id("pill");
  set_alias("drug");
  set_short("A small "+BOLD+GRN+"green"+NORM+" pill");
  set_long(
 "  A small green pill. Hrmm, I wonder what it does.\n");
  set_value(100);
  set_weight(1);
  }

init(){
  ::init();
   add_action("eatem","eat");
   add_action("eatem","swallow");
   }

eatem(string str){
 object crap;
  if(!str) { notify_fail("eat what?\n"); return 0; } /* changed to return 0 */
 if(str == "pill"){
 if(present("drug_fun", tp)){
   tell_room(environment(tp),
   capitalize(tpn)+ " eats a small pill!\n", ({tp})); 
   tell_object(tp,
   "\nYou swallow a small pill and immediately start to feel diffferent.\n");
   destruct(this_object());
   return 1; }

 tell_room(environment(tp),
 capitalize(tpn)+" eats a pill!\n", ({tp}));
 tell_object(tp,
 "You swallow a small pill and immediately start to feel different.\n");            
  crap = clone_object("/players/fred/toys/drug.c");
  move_object(crap, environment(this_object()));
  destruct(this_object());
  return 1;
  }
}
