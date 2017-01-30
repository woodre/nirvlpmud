inherit "/obj/treasure.c";
int NM, AMNT;
#include "/players/jaraxle/define.h"
reset(arg){
NM = 3;
AMNT = 15;

  set_weight(1);
}
long(){ write("A bag of enchanted "+HIB+"blue"+NORM+" dust.\nYou can 'sprinkle dust (sd)' or you can 'mix' it with another bag.\nYou have "+HIB+"["+HIW+""+NM+""+HIB+"]"+NORM+" uses left.\n"); }
short(){ return ""+HIB+"Enchanted dust"+NORM+""; }

query_value(){ return NM * 180; }
id(str){ return str == "dust" || str == "sp_heal"; }

is_heal(){                      return "food";  }
query_potence(){        return 15;      }
query_save_flag(){      return 1;       }

void init() {
  ::init();
add_action("eat_cmd","sprinkle dust");
add_action("eat_cmd","sd");
add_action("mix","mix");
}

eat_cmd(){
if(NM > 1){
if(environment(TO) != TP) return 0;
  if(!call_other(TP,"eat_food", 3)) return 1;
  if(!call_other(TP,"drink_soft", 4)) return 1;
  this_player()->add_spell_point(AMNT);
NM -= 1;
 write("You sprinkle some of the dust over your hands.\n");
 write(HIB+"HP "+HIW+"("+NORM+""+TP->query_hp()+""+HIB+"/"+NORM+""+TP->query_mhp()+""+HIW+")  "+HIB+"SP "+HIW+"("+NORM+""+TP->query_sp()+""+HIB+"/"+NORM+""+TP->query_msp()+""+HIW+")\n"+NORM);
 write("You have "+HIW+"["+HIB+""+NM+""+HIW+"]"+NORM+" uses left.\n");
  say(TPN+" sprinkles "+HIB+"blue dust"+NORM+" over their hands.\n");
  this_player()->recalc_carry();
return 1; }

if(NM == 1){
  if(environment(TO) != TP) return 0;
  if(!call_other(TP,"eat_food", 4)) return 1;
  if(!call_other(TP,"drink_soft", 3)) return 1;
 write("You use the last bit of dust.\n");
  this_player()->add_spell_point(AMNT);
 write("You sprinkle some of the dust over your hands.\n");
 write(HIB+"HP "+HIW+"("+NORM+""+TP->query_hp()+""+HIB+"/"+NORM+""+TP->query_mhp()+""+HIW+")  "+HIB+"SP "+HIW+"("+NORM+""+TP->query_sp()+""+HIB+"/"+NORM+""+TP->query_msp()+""+HIW+")\n"+NORM);
 say(TPN+" sprinkles "+HIB+"blue dust"+NORM+" over their hands.\n");
  destruct(this_object());
  this_player()->recalc_carry();
return 1; }
}
mix(arg){
object obj;
obj = present("sp_heal 2",TP); 

if(!obj){ write("You need more than one bag to mix.\n"); return 1; }
if(arg == "heals"){  
write("You mix the two bags to make a more potent heal.\n");
AMNT += 15;
destruct(obj);
return 1; }
}

