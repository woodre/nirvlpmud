#include "/players/jaraxle/define.h"

id(str) { return str == "scroll" || str == "purify" || str == "scroll of purification" || str == "purify_scroll"; }

short() { return "A Scroll of "+HIB+"Purification"+NORM+""; }

long() {
   write("A rolled up scroll with a "+HIB+"blue ribbon"+NORM+" tied around it.\n Just "+HIB+"<"+HIW+"purify"+HIB+">"+NORM+" a "+HIB+"<"+HIW+"player"+HIB+">"+NORM+" to use it.\n");
}
query_weight() { return 1; }
query_value()  { return 2000; }
get() { return 1; }
take() { return 1; }
drop(){
   write("As you drop the scroll is explodes in a puff of smoke!\n");
   destruct(this_object());
   return 1; }
query_save_flag() { return 1; }

init() { 
   add_action("purify"); add_verb("purify");
}

purify(str) {
   object victim;
   object poison, next;
   string a,b;
   
   if (!str) victim = TP;
   else victim = present(str, environment(TP));
   if(!victim) { write(capitalize(victim)+" is not here.\n"); return 1; }
   
   poison = first_inventory(victim);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison") || poison->id("toxin") || poison->id("hcl") || poison->id("toxin2") ) {
         destruct(poison);
}
      poison = next;
   }
   write("You recite the words of "+HIB+"purification"+NORM+" from the scroll.\n");
   tell_object(victim,
     "A hazy "+MAG+"purple"+NORM+" aura rains softly over you,\n"+
    "\ta soothing sensation covers your body as the "+MAG+"aura"+NORM+" covers you.\n");
   tell_room(environment(TP),TP->query_name()+
     " recites words from a "+HIB+"purification"+NORM+" scroll for ");
   if (victim == TP)
      tell_room(environment(TP),
      TP->query_objective()+"self.\n");
   else tell_room(environment(TP),victim->query_name()+".\n");
destruct(this_object());
   return 1;
}
