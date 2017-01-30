
/* Heavy influence from code used from Maledicta, with his permission
4/15/02. */

#include "/players/jaraxle/define.h"

id(str) { return str == "scroll" || str == "enchantment" || str == "scroll of enchantment" || str == "enchantment_scroll"; }

short() { return "A Scroll of "+HIM+"Enchanting"+NORM+""; }

long() {
   write("A rolled up scroll with a "+HIM+"magenta ribbon"+NORM+" tied around it.\n Just "+HIM+"<"+HIW+"enchant"+HIM+">"+NORM+" a "+HIM+"<"+HIW+"piece of armor"+HIM+">"+NORM+" to use it.\n");
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
   add_action("enchant_it"); add_verb("enchant");
}

enchant_it(str) {
   object arm;
   object ob;
   
   if (!str) return 0;
   ob=present(str,this_player());
   if(!ob) ob = present(str,this_object());
   if(!ob) {
      write("You do not have that.\n");
      return 1;
   }
   
   if(!ob->armor_class()){ write("You don't think that is a armor.\n"); return 1; }
   
   if(ob->query_worn()){ 
      write("You must remove the armor before an enchantment can be cast.\n");
      
      return 1;
   }
   if(ob->query_shadowed()){ write(capitalize(str)+" is already enchanted!\n"); return 1; }
   
   arm = clone_object("/players/jaraxle/templar/magic/fireshad.c");
   arm->add_shadow(ob);
   write("You recite the words of the enchantment for an "+str+". . .\n"+
      "A "+HIM+"glowing aura"+NORM+" radiates from the "+str+".\n");
   say(TPN+" recites the words of enchantment for an "+str+". . .\n"+
      "A "+HIM+"glowing aura"+NORM+" begins to radiate from "+POS+" "+str+".\n");
   destruct(this_object());
   return 1;
}
