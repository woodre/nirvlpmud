#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int NUMBER, iscroll;
reset(arg)  {
   if(arg) return;
   NUMBER = 1;
   
   set_weight(1);
   set_value(450);
}
id(str){ return str == "tome" || str == "tome of purification" || str == "purify tome"; }
query_save_flag(){ return 1; }

short(){ return "Tome of "+HIB+"Purification"+NORM+" "+HIM+"["+HIG+NUMBER+HIM+"]"+NORM+""; }
long(){
   write("A Tome used to keep multiple volumes of scrolls of "+HIB+"purification"+NORM+".\nYou can "+HIB+"<"+HIW+"add purification to tome"+HIB+">"+NORM+" to add to the book.\nJust "+HIB+"<"+HIW+"purify"+HIB+">"+NORM+" a "+HIB+"<"+HIW+"player"+HIB+">"+NORM+" to use a page.\nYou have "+HIB+"["+HIW+NUMBER+HIB+"]"+NORM+" scrolls left in the tome.\n"); return 1; }


init(){
   ::init();
   add_action("add_it","add");
   add_action("purify","purify");
}

add_it(str){
  if(str != "purification to tome"){ write(HIB+"<"+HIW+"add purification to tome"+HIB+">"+NORM+"\n"); return 1; }
   iscroll = present("purify_scroll",environment());
   if(!iscroll){ write("You do not have the proper scroll to put into the book.\n"); return 1; }
   
   NUMBER +=1;
   write("You carefully add the scroll to the book.\n"+
      "You now have "+HIB+"["+HIW+NUMBER+HIB+"]"+NORM+" volumes.\n");
   say(TPN+" adds a volume of purification to their tome.\n");
   destruct(iscroll);
   return 1; }

purify(str) {
   object victim;
   object poison, next;
   string a,b;
   
   if (!str) victim = TP;
   else victim = present(str, environment(TP));
if(NUMBER == 0){ write("There are no more volumes of "+HIB+"Purification"+NORM+" in the tome.\n"); return 1; }
   if(!victim) { write(capitalize(victim)+" is not here.\n"); return 1; }
   
   poison = first_inventory(victim);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison") || poison->id("toxin") || poison->id("hcl") || poison->id("toxin2") ) {
         destruct(poison);
}
      poison = next; }
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
NUMBER -=1;
   return 1;
}

