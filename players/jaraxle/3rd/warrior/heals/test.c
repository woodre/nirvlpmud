
inherit "/obj/treasure.c";
int NM;
#include "/players/zeus/closed/all.h"
reset(arg){
NM = 2;

set_short(HIB+"Teen"+HIR+"om"+NORM+" Fruit");
  set_weight(1);
  set_value(400);
  set_long(
"This is a small, oval sized fruit.  The skin is tough, like leather.\n"+
"The villagers say you can "+HIB+"squeeze"+NORM+" the juice out of\n"+
"these "+HIR+"fruit"+NORM+"s for a refreshing drink.\n");
}

id(str){ return str == "fruit" || str == "teenom"; }

is_heal(){			return "soak";  }
query_potence(){	return 20;      }
query_save_flag(){	return 1;       }

void init() {
  ::init();
add_action("squeeze_cmd","squeeze");
}

squeeze_cmd(str){
if(NM == 2){
if(environment(TO) != TP) return 0;
  if(str != "teenom" && str != "fruit") return 0;
  if(!call_other(TP,"drink_soft", 7)) return 1;
  this_player()->heal_self(20);
write("You squeeze hard on the "+HIB+"Te"+HIR+"enom"+NORM+" fruit.\n");
write("The juice flows into your mouth, a bit dribbling down your cheek.\n");
write(HIB+"HP "+HIR+"("+HIW+""+TP->query_hp()+""+HIB+"/"+HIW+""+TP->query_mhp()+""+HIR+")  "+HIB+"SP "+HIR+"("+HIW+""+TP->query_hp()+""+HIB+"/"+HIW+""+TP->query_msp()+""+HIR+")\n"+NORM);
say(TP->QN+" squeezes some juice from a "+HIB+"Te"+HIR+"enom"+NORM+" fruit.\n");

  this_player()->recalc_carry();
NM -= 1;
return 1; }

if(NM == 1){
  if(environment(TO) != TP) return 0;
  if(str != "teenom" && str != "fruit") return 0;
  if(!call_other(TP,"drink_soft", 7)) return 1;
write("You squeeze the last drink out of the "+HIB+"Te"+HIR+"enom"+NORM+" fruit.\n");
  this_player()->heal_self(20);
write(HIB+"HP "+HIR+"("+HIW+""+TP->query_hp()+""+HIB+"/"+HIW+""+TP->query_mhp()+""+HIR+")  "+HIB+"SP "+HIR+"("+HIW+""+TP->query_hp()+""+HIB+"/"+HIW+""+TP->query_msp()+""+HIR+")\n"+NORM);


say(TP->QN+" squeezes the last drink out of a "+HIB+"Te"+HIR+"enom"+NORM+" fruit.\n");
  destruct(this_object());
  this_player()->recalc_carry();
 return 1; }
}

