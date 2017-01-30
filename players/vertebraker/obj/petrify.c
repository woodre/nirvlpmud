#include "../define.h"
int p;
inherit ITEM;
extra_look() {
   if(!p) write(USER->QN+" can't move.\n");
   if(p == 1) write(BOLD+BLK+USER->QN+"'s legs have turned to stone.\n"+NORM);
   if(p == 2) write(BOLD+BLK+USER->QN+"'s legs and torso are petrified.\n"+NORM);
   if(p == 3) write(BOLD+BLK+USER->QN+" has turned to stone.\n"+NORM);
}
init() {
   ::init();
   add_action("blah"); add_xverb(""); }

blah() {
   if(TPRN != "vertebraker") {
      write("You have been turned to stone.\n");
      return 1; }
}

set_petrify(sp) {
   object obj;
   p = sp;
   if(p == 3) {
      obj = clone_object("/obj/treasure");
      obj->set_weight(10000);
      obj->set_short("A statue of "+USER->QN);
      obj->set_long(
         "  This is the petrified statue of "+USER->QN+".  He was\n"+
         "petrified by Vertebraker at "+ctime()+".\n");
      obj->set_id("statue");
      MO(obj,ENV(USER));
      MO(USER,obj);
      return 1; 
   }
}
drop() { return 1; }
id(str) { return str == "petrify_obj"; }
