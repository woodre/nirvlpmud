
#include "/players/jaraxle/define.h"

id(str) { return str == "scroll" || str == "enchantment" || str == "scroll of enchantment" || str == "enchantment_scroll"; }

short(){ return HIW+"Holy Ground"+NORM; }

long() {
   write("Holy ground.\n");
}
query_weight() { return 1; }
query_value()  { return 2000; }
get() { return 1; }
take() { return 1; }
drop(){
   write("As you drop the scroll, it explodes in a puff of smoke!\n");
   destruct(this_object());
   return 1; }
query_save_flag() { return 1; }

init() { 
   add_action("enchant_it"); add_verb("holy_ground");
}

enchant_it(){
   object shadow;
   
   shadow = clone_object("/players/jaraxle/templar/doc/room_shadow.c");
if(present("holy@ground", environment(this_player()))){ write(HIW+"The ground has already been sanctified.\n"+NORM); return 1; }
   shadow->start(environment(this_player()));
   write("You kneel to the ground placing one hand upon it, fingers outstretched...\n"+
      "\tYou stretch your other palm out to the area and murmur...\n"+
      "\t\t'Sanctify this ground and may evil fear the aura...'\n");
   say(TPN+" kneels to the ground placing one hand upon it, fingers outstretched...\n"+
      "\t"+TPN+" stretches the other palm out to the area and murmurs...\n"+
      "\t\t'Sanctify this ground and may evil fear the aura...'\n");
   destruct(this_object());
   return 1;
}
