#include <ansi.h>
#include "/players/fred/defs.h"
int p;
inherit "obj/treasure";
extra_look() {
    if(!p) write(ENV()->QN+" can't move.\n");
   if(p == 1) write(BOLD+YEL+ENV()->QN+"'s legs have turned to stone.\n"+NORM);
   if(p == 2) write(BOLD+YEL+ENV()->QN+"'s legs and torso are petrified.\n"+NORM);
   if(p == 3) write(BOLD+YEL+ENV()->QN+" has turned to stone.\n"+NORM);
}
init() {
   ::init();
   add_action("blah"); add_xverb(""); }

blah() {
   if(TPRN != "fred"){
      write("You have been turned to stone.\n");
      return 1; }
}

set_petrify(sp) {
   object obj;
   p = sp;
   if(p == 3) {
      obj = clone_object("/obj/treasure");
      obj->set_weight(10000);
      obj->set_short("A statue of "+ENV()->QN);
      obj->set_long(
         "  This is the petrified statue of "+ENV()->QN+". "+ENV()->POS+" was\n"+
         "petrified by Fred at "+ctime()+".\n");
      obj->set_id("statue");
      MO(obj,ENV(USER));
      MO(USER,obj);
      return 1; 
   }
}
drop() { return 1; }
id(str) { return str == "petrify_obj"; }
